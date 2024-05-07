//
// Created by Stu on 04/05/2024.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Parser.h"
#include "Config.h"
#include "String.h"
#include "TextFile.h"


List *parseScanner(TextFile *file);

List *ParseFile(ConfigFile *conf, TextFile *file) {
	if (conf == NULL || file == NULL) {
		return NULL;
	}
	List *tokens = parseScanner(file);
	return NULL;
}




//******************************
// private functions

bool IsCharA(char c, const char delimiter[], int delimiterCount) {
	for (int d = 0; d < delimiterCount; d++) {
		if (c == delimiter[d]) {
			return true;
		}
	}
	return false;
}

char *ReadStringUpToAny(TextFile *file, const char delimiter[], int delimiterCount) {
	char buf[1024];
	int i = 0;
	int c = (int) file->CurrentChar;
	if (!IsCharA((char) c, delimiter, delimiterCount)) {
		do {
			buf[i++] = (char) c;
			c = TextFileReadChar(file);
		} while (c != EOF && i < 1024 && !IsCharA((char) c, delimiter, delimiterCount));
	}
	buf[i] = '\0';
	char *string = NewString(buf);
	return string;
}


char *ReadStringAllWhiteSpace(TextFile *file) {
	const int bufSize = 1023;
	char buf[bufSize + 1];
	int i = 0;
	int c = (int) file->CurrentChar;
	if (isspace(c)) {
		do {
			buf[i++] = (char) c;
			c = TextFileReadChar(file);
		} while (c != EOF && i < bufSize && isspace(c));
	}
	buf[i] = '\0';
	char *string = NewString(buf);
	return string;
}

char *ReadStringLabel(TextFile *file) {
	const int bufSize = 1023;
	char buf[bufSize + 1];
	int i = 0;
	int c = (int) file->CurrentChar;
	if (isalpha(c) || c == '_') {
		do {
			buf[i++] = (char) c;
			c = TextFileReadChar(file);
		} while (c != EOF && i < bufSize && isalnum(c) || c == '_');
	}
	buf[i] = '\0';
	char *string = NewString(buf);
	return string;
}

char *ReadNumberString(TextFile *file, char buf[], int bufSize) {
	int i = 0;
	int c = (int) file->CurrentChar;
	if (isdigit(c)) {
		do {
			buf[i++] = (char) c;
			c = TextFileReadChar(file);
		} while (c != EOF && i < bufSize && isdigit(c) || c == '.');
	}
	buf[i] = '\0';
	char *string = NewString(buf);
	return string;
}


ParserToken *TokenSimpleNew(ParserTokenType type) {
	ParserToken *token = malloc(sizeof(ParserToken));
	token->Type = type;
	return token;
}


ParserToken *TokenStringNew(TextFile *file, char *str, ParserTokenType type) {
	ParserToken *token = malloc(sizeof(ParserToken));
	token->Type = type;
	token->Value.String = str;
	return token;
}

ParserToken *TokenNumberNew(char *str) {
	ParserToken *token = malloc(sizeof(ParserToken));
	token->Type = PTT_INT;
	char *out;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.') {
			token->Type = PTT_FLOAT;
		}
	}
	if (token->Type == PTT_FLOAT) {
		token->Value.Float = strtod(str, &out);
	}else {
		token->Value.Long = strtol(str, &out, 10);
	}
	return token;
}

void TokenFree(ParserToken *token) {
	if (token == NULL) {
		return;
	}
	switch (token->Type) {
		case PTT_STRING:
		case PTT_FORMATTING:
		case PTT_LABEL:
			if (token->Value.String != NULL) {
				free((char *) token->Value.String);
			}
		default:
			free(token);
	}
}


ParserToken *parseScanNext(TextFile *file) {
	int c = file->CurrentChar;
	switch (c) {
		case '=': {
			ParserToken *equals = TokenSimpleNew(PTT_EQUALS);
			TextFileReadChar(file);
			return equals;
		}
		case '[': {
			ParserToken *openSquare = TokenSimpleNew(PTT_OPEN_SQUARE_BRACKET);
			TextFileReadChar(file);
			return openSquare;
		}
		case ']': {
			ParserToken *closedSquare = TokenSimpleNew(PTT_CLOSE_SQUARE_BRACKET);
			TextFileReadChar(file);
			return closedSquare;
		}
		case '{': {
			ParserToken *openBrace = TokenSimpleNew(PTT_OPEN_BRACE);
			TextFileReadChar(file);
			return openBrace;
		}
		case '}': {
			ParserToken *closeBrace = TokenSimpleNew(PTT_CLOSE_BRACE);
			TextFileReadChar(file);
			return closeBrace;
		}
		case '"': {
			char delim[] = {'"'};
			char *str = ReadStringUpToAny(file, delim, 1);
			ParserToken *quote = TokenStringNew(file, str, PTT_STRING);
			return quote;
		}
		case '#': {
			char delim[] = {'\n'};
			char *str = ReadStringUpToAny(file, delim, 1);
			ParserToken *quote = TokenStringNew(file, str, PTT_FORMATTING);
			return quote;
		}
		case ',': {
			ParserToken *comma = TokenSimpleNew(PTT_COMMA);
			TextFileReadChar(file);
			return comma;
		}
		case EOF: {
			return NULL;
		}
		default: {
			char buf[64];
			if (isdigit(c)) {
				char *str = ReadNumberString(file, buf, 64);
				ParserToken *number = TokenNumberNew(str);
				FreeString(str);
				return number;
			}
			if (isspace(c)) {
				char *str = ReadStringAllWhiteSpace(file);
				ParserToken *formatting = TokenStringNew(file, str, PTT_FORMATTING);
				return formatting;
			}
			if (isalpha(c) || c == '_') {
				char *str = ReadStringLabel(file);
				ParserToken *label = TokenStringNew(file, str, PTT_LABEL);
				return label;
			}
			char str[2] = {file->CurrentChar, '\0'};
			ParserToken *formatting = TokenStringNew(file, str, PTT_FORMATTING);
			return formatting;
		}
	}
}


List *parseScanner(TextFile *file) {
	List *tokens = ListNew();
	while (file->CurrentChar != EOF) {
		ParserToken *token = parseScanNext(file);
		if (token != NULL) {
			ListAddLast(tokens, token);
		}
	}
	return tokens;
}

