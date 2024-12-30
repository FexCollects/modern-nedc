#pragma once

// raw2bmp
extern int MultiStrip;
extern int smooth;
extern int dpi_multiplier;

int bmp2raw(char *bmpfile, char *rawfile);
int is_bmp(char *bmpfile);
int raw2bmp(char *rawfile, char *bmpfile);

// nevpk
#include <stdio.h>

extern int verbose;
extern FILE *ne_log;
extern unsigned long bits_written;
extern int best_move;
extern int best_size;
extern int skip_huffman;
extern int skip_lz77;

int NVPK_compress (unsigned char *buf, int size, int compression_level, int lzwindow, int lzsize, int method, FILE *f, unsigned char *bitdata=NULL);
int vpk_decompress (unsigned char *vpk, FILE *f);
void log_write(char* str, ...);
