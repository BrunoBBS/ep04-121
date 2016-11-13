/*Bruno Boaventura Scholl*/

#ifndef TABELASIMBOLO_AB
#define TABELASIMBOLO_AB

#include "types.h"

treeptr *stableab_create();

void stableab_insert(treeptr *root, char *x);

void stableab_print_o(treeptr root);

void stableab_print_a(treeptr root);

treeptr stableab_find(treeptr root, char *x);

void stableab_destroy(treeptr *root);

#endif
