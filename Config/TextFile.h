//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_TEXTFILE_H
#define CONFIG_TEXTFILE_H


#include <stdio.h>


typedef struct TEXT_FILE {
	FILE *File;
	char *Line;
	fpos_t LineStart;
	fpos_t NextLineStart;
	int LineIndex;
	int LineLength;
	char CurrentChar;
} TextFile;

typedef struct TEXT_FILE_MARK {
	int LineIndex;
	fpos_t LineStart;
} TextFileMark;


TextFile *TextFileOpen(const char *fileName);

void TextFileClose(TextFile *textFile);

int TextFileReadChar(TextFile *textFile);


TextFileMark *TextFileSetMark(TextFile *textFile);

void TextFileGoToMark(TextFile *textFile, TextFileMark *textFileMark);

void TextFileDiscardMark(TextFileMark *textFileMark);

void TextFileNextLine(TextFile *textFile);


#endif //CONFIG_TEXTFILE_H
