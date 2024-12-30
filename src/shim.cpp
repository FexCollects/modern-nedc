#include "shim.h"

void nedclib_version(void) {}

int bmp2raw(char *bmpfile, char *rawfile) { return 0; }
int is_bmp(char *bmpfile) { return 0; }
int raw2bmp(char *rawfile, char *bmpfile) { return 0; }

int MultiStrip;
int smooth;
int dpi_multiplier;
