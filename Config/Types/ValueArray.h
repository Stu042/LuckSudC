//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_VALUEARRAY_H
#define CONFIG_VALUEARRAY_H

#include "Collections.h"
#include "ValueTypeFormat.h"


/// @brief ValueArray Holds an array of values, values can be int, double, string, struct or array.
typedef struct VALUE_ARRAY {
	ValueTypeFormat Type;
	/// List of ValueTypes
	List *ValueTypes;
} ValueArray;



#endif //CONFIG_VALUEARRAY_H
