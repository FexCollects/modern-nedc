#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define sprintf_s(string, size, format, ...) sprintf(string, format, __VA_ARGS__)
#define vsprintf_s(string, size, format, ...) vsprintf(string, format, __VA_ARGS__)
#define _stricmp(str1, str2) strcmp(str1, str2) 

int fopen_s(FILE ** f, char *name, char *spec);
