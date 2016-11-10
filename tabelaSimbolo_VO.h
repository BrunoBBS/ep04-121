#ifndef TABELASIMBOLO_VO
#define TABELASIMBOLO_VO
#include "types.h"

typedef struct stable_s stablevo;

stablevo *stablevo_create();

void stablevo_insert(stablevo *table, char *x);

item *stablevo_find(stablevo *table, char *x);

void stablevo_destroy(stablevo *table);

void stablevo_print(stablevo *table, char mode);

#endif
