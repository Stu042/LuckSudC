//
// Created by Stu on 05/05/2024.
//

#include <malloc.h>
#include "ValueString.h"
#include "../String.h"


ValueString *NewValueString(const char *name, const char *value) {
	ValueString *valueString = (ValueString *) malloc(sizeof(ValueString));
	valueString->Name = NewString(name);
	valueString->Value = NewString(value);
	return valueString;
}


void FreeValueString(ValueString *valueString) {
	if (valueString == NULL) {
		return;
	}
	FreeString(valueString->Name);
	FreeString(valueString->Value);
	free(valueString);
}
