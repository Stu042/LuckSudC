//
// Created by Stu on 05/05/2024.
//

#include <malloc.h>
#include "ValueDouble.h"
#include "../String.h"



ValueDouble *NewValueDouble(const char *name, double value) {
	ValueDouble *valueDouble = (ValueDouble *) malloc(sizeof(ValueDouble));
	valueDouble->Name = NewString(name);
	valueDouble->Value = value;
	return valueDouble;
}


void FreeValueDouble(ValueDouble *valueDouble) {
	if (valueDouble == NULL) {
		return;
	}
	FreeString(valueDouble->Name);
	free(valueDouble);
}
