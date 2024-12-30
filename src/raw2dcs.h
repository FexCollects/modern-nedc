#pragma once

#include <stdio.h>

int count_raw(FILE *f);
int read_next_raw(FILE *f, unsigned char *rawdata);
