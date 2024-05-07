//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_VALUETYPE_H
#define CONFIG_VALUETYPE_H

#include "ValueInt.h"
#include "ValueDouble.h"
#include "ValueString.h"
#include "ValueArray.h"
#include "ValueStruct.h"
#include "ValueTypeFormat.h"


typedef union VALUE_TYPES {
	ValueInt IntValue;
	ValueDouble FloatValue;
	ValueString StringValue;
	ValueArray ArrayValue;
	ValueStruct StructValue;
} ValueTypes;


typedef struct VALUE_TYPE {
	ValueTypeFormat Type;
	ValueTypes Value;
} ValueType;


#endif //CONFIG_VALUETYPE_H
