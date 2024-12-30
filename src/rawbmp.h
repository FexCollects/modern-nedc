#pragma once

extern int dpi_multiplier;
extern int MultiStrip;
extern int smooth;

int bmp2raw(char *bmpfile, char *rawfile);
int is_bmp(char *bmpfile);
int raw2bmp(char *rawfile, char *bmpfile); 
