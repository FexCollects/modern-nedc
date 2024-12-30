#include <stdio.h>

#ifndef DCS
#define DCS



unsigned short dotcodelen;
unsigned short bmplen;

unsigned long addr[2] = { 0,0x3FF };

unsigned char raw[28][104];
unsigned char dcsbmp[7912][352];

unsigned char _810mod[28][130];

unsigned char bmpheader[62] = 
{
    0x42, 0x4D, 0x8E, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x28, 0x00, 
    0x00, 0x00, 0xDD, 0x03, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x50, 0x15, 0x00, 0x00, 0x23, 0x2E, 0x00, 0x00, 0x23, 0x2E, 0x00, 0x00, 0x02, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 
};
/*
unsigned char bmpheader2[62] = 
{
    0x42, 0x4D, 0xFE, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x28, 0x00, 
    0x00, 0x00, 0x7F, 0x02, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xC0, 0x0D, 0x00, 0x00, 0xC2, 0x1E, 0x00, 0x00, 0xC2, 0x1E, 0x00, 0x00, 0x02, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 
} ;*/

unsigned char bmpdata[352][992];


//unsigned char bmpdata1[44][0x7C];
//unsigned char bmpdata2[44][0x50];

int bmp_invert;




unsigned char modtable[16] = {
0x00, //00000
0x01, //00001
0x02, //00010
0x12, //10010
0x04, //00100
0x05, //00101
0x06, //00110
0x16, //10110
0x08, //01000
0x09, //01001
0x0A, //01010
0x14, //10100
0x0C, //01100
0x0D, //01101
0x11, //10001
0x10, //10000
};

unsigned char demodtable[32] = {
//{
0x00,0x01,0x02,0xFF,0x04,0x05,0x06,0xFF,0x08,0x09,0x0A,0xFF,0x0C,0x0D,0xFF,0xFF,
0x0F,0x0E,0x03,0xFF,0x0B,0xFF,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
/*},
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0xFF,0x0B,0xFF,0x03,0x0E,0x0F,
0xFF,0xFF,0x0D,0x0C,0xFF,0x0A,0x09,0x08,0xFF,0x06,0x05,0x04,0xFF,0x02,0x01,0x00,
}*/};

/*
unsigned short addressbar[2][29] = { {
0x9866,  //Left most address bar
0xD316,
0x45F6,
0x604E,
0xF6AE,
0xBDDE,
0x2B3E,
0x4141,
0xD7A1,
0x9CD1,
0x0A31,
0x2F89,
0xB969,
0xF219,
0x64F9,
0xE0C5,
0x7625,
0x3D55,
0xABB5,
0x8E0D,
0x18ED,
0x539D,
0xC57D,
0x1183,
0x8763,
0xCC13,
0x5AF3,
0x7F4B,
0xE9AB, //Right most address bar
}, {
0x6920,
0x2250,
0xB4B0,
0x9108,
0x07E8,
0x4C98,
0xDA78,
0x5E44,
0xC8A4,
0x83D4,
0x1534,
0x308C,
0xA66C,
0xED1C,
0x7BFC,
0xAF02,
0x39E2,
0x7292,
0xE472,

},
};*/

#endif

extern unsigned short dotcodelen;
extern unsigned short bmplen;

//extern int dpi_multiplier;

extern unsigned long addr[2];
extern unsigned char raw[28][104];
extern unsigned char dcsbmp[7912][352];
extern unsigned char _810mod[28][130];
extern unsigned char bmpheader1[];
extern unsigned char bmpheader2[];
extern unsigned char bmpdata[352][992];
//extern unsigned char bmpdata1[44][0x7C];
//extern unsigned char bmpdata2[44][80];
extern unsigned char modtable[];
extern unsigned char demodtable[32];
//extern unsigned short addressbar[2][29];

extern int bmp_invert;

void clear_dcs(void);
void eight_ten_modulate(void);
void init_dcs(void);
void flipbmp(void);
void makebmp(void);
void make_dcs(void);

void eight_ten_demodulate(void);
void reversebmp(void);
void reverse_dcs(void);
int read_bmp(FILE *f);

int correct_address(unsigned long *addr_data);
void calc_addr(int address);