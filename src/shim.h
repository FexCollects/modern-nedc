#pragma once

void nedclib_version(void);

#define RAW2BMP_MAJOR 1
#define RAW2BMP_MINOR 4
int bmp2raw(char *bmpfile, char *rawfile);
int is_bmp(char *bmpfile);
int raw2bmp(char *rawfile, char *bmpfile);

extern int MultiStrip;
extern int smooth;
extern int dpi_multiplier;
