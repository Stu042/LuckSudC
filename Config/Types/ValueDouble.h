//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_VALUEDOUBLE_H
#define CONFIG_VALUEDOUBLE_H

typedef struct VALUE_DOUBLE {
	char *Name;
	double Value;
} ValueDouble;


ValueDouble *NewValueDouble(const char *name, double value);

void FreeValueDouble(ValueDouble *valueDouble);


#endif //CONFIG_VALUEDOUBLE_H
