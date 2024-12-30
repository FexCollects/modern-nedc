#pragma once

extern unsigned long bits_written;
extern int best_move;
extern int best_size;
extern int skip_huffman;
extern int skip_lz77;

int NVPK_compress (unsigned char *buf, int size, int compression_level, int lzwindow, int lzsize, int method, FILE *f, unsigned char *bitdata=NULL);
int vpk_decompress (unsigned char *vpk, FILE *f);
