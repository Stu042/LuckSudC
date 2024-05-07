//
// Created by Stu on 05/05/2024.
//

#include <malloc.h>
#include <stdio.h>
#include "ValueInt.h"
#include "../String.h"
#include "../TextFile.h"


ValueInt *NewValueInt(const char *name, int value) {
	ValueInt *valueInt = (ValueInt *) malloc(sizeof(ValueInt));
	valueInt->Name = NewString(name);
	valueInt->Value = value;
	return valueInt;
}


void FreeValueInt(ValueInt *valueInt) {
	if (valueInt == NULL) {
		return;
	}
	FreeString(valueInt->Name);
	free(valueInt);
}

// ch first character of ints name
// in the format of "name = value", whitespace optional.
ValueInt *ValueIntParse(const char *name, TextFile *file) {
	TextFileMark *mark = TextFileSetMark(file);
	int c = TextFileReadChar(file);
	if (c == EOF) {
		TextFileDiscardMark(mark);
		return NULL;
	}
	
}
