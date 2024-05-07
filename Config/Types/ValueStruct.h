//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_VALUESTRUCT_H
#define CONFIG_VALUESTRUCT_H

#include <stdio.h>
#include "Collections.h"
#include "../TextFile.h"


typedef struct VALUE_STRUCT {
	/// List of type ValueType
	List *ValueTypes;
} ValueStruct;


ValueStruct *NewValueStruct();

void FreeValueStruct(ValueStruct *valueStruct);

ValueStruct *ReadValueStruct(TextFile *file, int ch);

void FreeValueStructs(List *valueStructs);

ValueStruct *ValueStructParse(const char *name, TextFile *file);


#endif //CONFIG_VALUESTRUCT_H
