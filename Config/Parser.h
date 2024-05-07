//
// Created by Stu on 04/05/2024.
//

#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include "Config.h"
#include "TextFile.h"


typedef enum PARSER_TOKEN_TYPE {
	PTT_INT,
	PTT_FLOAT,
	PTT_STRING,
	PTT_LABEL,
	PTT_OPEN_BRACE,
	PTT_CLOSE_BRACE,
	PTT_OPEN_SQUARE_BRACKET,
	PTT_CLOSE_SQUARE_BRACKET,
	PTT_EQUALS,
	PTT_COMMA,
	PTT_FORMATTING
} ParserTokenType;


typedef union PARSER_TOKEN_UNION {
	long Long;
	double Float;
	char *String;
}ParserTokenUnion;


typedef struct PARSER_TOKEN {
	ParserTokenType Type;
	ParserTokenUnion Value;
} ParserToken;


List *ParseFile(ConfigFile *conf, TextFile *file);


#endif //CONFIG_PARSER_H
