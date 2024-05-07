//
// Created by Stu on 04/05/2024.
//

#include <string.h>
#include <malloc.h>
#include <ctype.h>



char *NewString(const char *str) {
	size_t length = strlen(str);
	char *copy = (char *) malloc(length + 1);
	strcpy(copy, str);
	copy[length] = '\0';
	return copy;
}

void FreeString(char *str) {
	if (str != NULL) {
		free(str);
	}
}

