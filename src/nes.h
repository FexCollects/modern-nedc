#pragma once

int make_nes(unsigned char *nesdata);
unsigned short nes_enc(unsigned short NMI_vector);
unsigned short nes_dec(unsigned short NMI_vector);
int is_nes(unsigned char *nesdata);
