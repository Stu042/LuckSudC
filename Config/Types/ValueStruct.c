//
// Created by Stu on 05/05/2024.
//

#include <malloc.h>
#include "ValueStruct.h"
#include "../String.h"


typedef struct TxetFile TxetFile;

ValueStruct *NewValueStruct() {
	ValueStruct *valueStruct = (ValueStruct *) malloc(sizeof(ValueStruct));
	valueStruct->ValueTypes = ListNew();
	return valueStruct;
}


void FreeValueStruct(ValueStruct *valueStruct) {
	if (valueStruct == NULL) {
		return;
	}
	// empty valueStruct->ValueTypes
	ListFree(valueStruct->ValueTypes);
	valueStruct->ValueTypes = NULL;
	free(valueStruct);
}



ValueStruct *ReadValueStruct(TextFile *file, int ch) {
	if (ch != '{') {
		return NULL;
	}
	ValueStruct *valueStruct = NewValueStruct();
	while ((ch = TextFileReadChar(file)) != EOF) {
		if (ch == '}') {
			return valueStruct;
		}

	}
	return valueStruct;
}


void FreeValueStructs(List *valueStructs) {
	if (valueStructs == NULL || valueStructs->Count <= 0) {
		return;
	}
	for (int i = 0; i < valueStructs->Count; i++) {
		FreeValueStruct((ValueStruct  *)valueStructs->Items[i]);
	}
	ListFree(valueStructs);
}


ValueStruct *ValueStructParse(const char *name, TextFile *file){
	
}