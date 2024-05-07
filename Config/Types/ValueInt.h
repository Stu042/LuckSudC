//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_VALUEINT_H
#define CONFIG_VALUEINT_H

typedef struct VALUE_INT {
	char *Name;
	int Value;
} ValueInt;


ValueInt *NewValueInt(const char *name, int value);

void FreeValueInt(ValueInt *valueInt);


#endif //CONFIG_VALUEINT_H
