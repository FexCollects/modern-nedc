#pragma once

extern unsigned short dotcodelen;
extern unsigned short bmplen;

extern int dpi_multiplier;

extern unsigned long addr[2];
extern unsigned char raw[28][104];
extern unsigned char dcsbmp[7912][352];
extern unsigned char _810mod[28][130];
extern unsigned char bmpheader[];
extern unsigned char bmpheader1[];
extern unsigned char bmpheader2[];
extern unsigned char bmpdata[352][992];
//extern unsigned char bmpdata1[44][0x7C];
//extern unsigned char bmpdata2[44][80];
extern unsigned char modtable[];
extern unsigned char demodtable[32];
//extern unsigned short addressbar[2][29];

extern int bmp_invert;
