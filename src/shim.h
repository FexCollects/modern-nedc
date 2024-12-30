#pragma once

// raw2bmp
extern int MultiStrip;
extern int smooth;
extern int dpi_multiplier;

int bmp2raw(char *bmpfile, char *rawfile);
int is_bmp(char *bmpfile);
int raw2bmp(char *rawfile, char *bmpfile);

