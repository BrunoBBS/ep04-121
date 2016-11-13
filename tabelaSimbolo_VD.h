/*Bruno Boaventura Scholl*/

#ifndef TABELASIMBOLO_VD
#define TABELASIMBOLO_VD

#include "types.h"

typedef struct stable_s stablevd;

stablevd *stablevd_create();

void stablevd_insert(stablevd *table, char *x);

int stablevd_find(stablevd *table, char *x);

void stablevd_destroy(stablevd *table);

void stablevd_print(stablevd *table, char mode);

#endif
