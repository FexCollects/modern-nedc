#pragma once

#define BIN_TYPE_NEDC_SINGLE 0
#define BIN_TYPE_NEDC_MULTI 1
#define BIN_TYPE_DRPD_MULTI 2
//There is no DRPD single format, as there is no way to know how big each of them will be
//with certainty.

extern int signature;
extern unsigned char signature_str[];

int bin2raw(char *binfile, char *rawfile);
int bin2raw_d(unsigned char *bin, unsigned char *raw, int size);
int bin2raw_f(unsigned char *bin, char *rawfile, int size);
int raw2bin(char *rawfile, char *binfile);
int fixraw(char *rawfile);
