//
// Created by Stu on 05/05/2024.
//

#include <malloc.h>
#include <string.h>
#include "TextFile.h"


const int FILE_BUFFER_SIZE = 1024;



TextFile *TextFileOpen(const char *fileName) {
	FILE *fptr = fopen(fileName, "r");
	if (fptr == NULL) {
		return NULL;
	}
	TextFile *confFile = malloc(sizeof(TextFile));
	confFile->File = fptr;
	confFile->Line = malloc(sizeof(char) * FILE_BUFFER_SIZE);
	if (confFile->Line == NULL) {
		perror("Out of memory");
		exit(1);
	}
	TextFileNextLine(confFile);
	return confFile;
}

void TextFileClose(TextFile *textFile) {
	if (textFile == NULL) {
		return;
	}
	if (textFile->Line != NULL) {
		free(textFile->Line);
	}
	fclose(textFile->File);
	free(textFile);
}


int TextFileReadChar(TextFile *textFile) {
	if (textFile == NULL) {
		return EOF;
	}
	textFile->LineIndex++;
	if (textFile->LineIndex >= textFile->LineLength) {
		TextFileNextLine(textFile);
	}
	textFile->CurrentChar = textFile->Line[textFile->LineIndex];
	return (int) textFile->CurrentChar;
}


TextFileMark *TextFileSetMark(TextFile *textFile) {
	int markedIndex = textFile->LineIndex;
	fpos_t markedLineStart = textFile->LineStart;
	TextFileMark *textFileMark = malloc(sizeof(TextFileMark));
	textFileMark->LineStart = markedLineStart;
	textFileMark->LineIndex = markedIndex;
	return textFileMark;
}

void TextFileGoToMark(TextFile *textFile, TextFileMark *textFileMark) {
	if (textFileMark == NULL || textFile == NULL) {
		return;
	}
	fsetpos(textFile->File, &textFileMark->LineStart);
	TextFileNextLine(textFile);
}

void TextFileDiscardMark(TextFileMark *textFileMark) {
	if (textFileMark == NULL) {
		return;
	}
	free(textFileMark);
}


void TextFileNextLine(TextFile *textFile) {
	fgetpos(textFile->File, &textFile->LineStart);
	fgets(textFile->Line, FILE_BUFFER_SIZE, textFile->File);
	fgetpos(textFile->File, &textFile->NextLineStart);
	textFile->LineLength = (int) strlen(textFile->Line);
	textFile->LineIndex = 0;
	textFile->CurrentChar = textFile->Line[textFile->LineIndex];
}


//******************************
// private functions


