#ifndef TABELASIMBOLO_AB
#define TABELASIMBOLO_AB

pointer *stableab_create();

void stableab_insert(pointer table, char *x);

void stableab_print_o(pointer table);

pointer stableab_find(pointer table, char *x);
#endif
