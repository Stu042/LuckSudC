//
// Created by Stu on 04/05/2024.
//
#include "Config.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Parser.h"
#include "String.h"
#include "TextFile.h"


ConfigFile *newConfigFile(const char *fileName);



ConfigFile *ConfigFileOpen(const char *fileName) {
	ConfigFile *conf = newConfigFile(fileName);
	if (conf == NULL) {
		ConfigFileClose(conf);
		return NULL;
	}
	TextFile *file = TextFileOpen(fileName);
	if (file == NULL) {
		ConfigFileClose(conf);
		return NULL;
	}
	ParseFile(conf, file);
	TextFileClose(file);
	return conf;
}


void ConfigFileClose(ConfigFile *conf) {
	if (conf == NULL) {
		return;
	}
	FreeString(conf->FileName);
	free(conf);
}



//******************************
// private functions

ConfigFile *newConfigFile(const char *fileName) {
	if (fileName == NULL || strlen(fileName) == 0) {
		return NULL;
	}
	ConfigFile *conf = (ConfigFile *) malloc(sizeof(ConfigFile));
	conf->FileName = NewString(fileName);
	conf->StructValue = NULL;
	return conf;
}

