#pragma once

#include <stdio.h>

extern int verbose;
extern FILE *ne_log;
void log_write(char* str, ...);
void log_only_write(char* str, ...);
