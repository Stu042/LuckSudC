//
// Created by Stu on 04/05/2024.
//

#ifndef CONFIG_CONFIG_H
#define CONFIG_CONFIG_H

#include "Types/ValueStruct.h"


typedef struct CONFIG_FILE {
	char *FileName;
	ValueStruct *StructValue;
} ConfigFile;


/// @brief Open and parse a config file. Returns a ConfigFile type with full details of values stored in the config file.
ConfigFile *ConfigFileOpen(const char *fileName);
void ConfigFileClose(ConfigFile *conf);


#endif //CONFIG_CONFIG_H
