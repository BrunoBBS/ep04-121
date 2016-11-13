/*Bruno Boaventura Scholl*/

#ifndef TABELASIMBOLO_VO
#define TABELASIMBOLO_VO
#include "types.h"

typedef struct stable_s stablevo;

stablevo *stablevo_create();

void stablevo_insert(stablevo *table, char *x);

int stablevo_find(stablevo *table, char *x, int stt, int fsh, int mid);

void stablevo_destroy(stablevo *table);

void stablevo_print(stablevo *table, char mode);

#endif
