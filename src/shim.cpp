#include "shim.h"

// raw2bmp
int MultiStrip;
int smooth;
int dpi_multiplier;

int bmp2raw(char *bmpfile, char *rawfile) { return 0; }
int is_bmp(char *bmpfile) { return 0; }
int raw2bmp(char *rawfile, char *bmpfile) { return 0; }

// nevpk
int verbose;
unsigned long bits_written;
int best_move;
int best_size;
int skip_huffman;
int skip_lz77;

FILE* ne_log;
int NVPK_compress (unsigned char *buf, int size, int compression_level, int lzwindow, int lzsize, int method, FILE *f, unsigned char *bitdata) { return 0; }
int vpk_decompress (unsigned char *vpk, FILE *f) {return 0; }
void log_write(char* str, ...) {}
