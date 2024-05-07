//
// Created by Stu on 05/05/2024.
//

#ifndef CONFIG_VALUESTRING_H
#define CONFIG_VALUESTRING_H

typedef struct VALUE_STRING {
	char *Name;
	char *Value;
} ValueString;


ValueString *NewValueString(const char *name, const char *value);

void FreeValueString(ValueString *valueString);


#endif //CONFIG_VALUESTRING_H
