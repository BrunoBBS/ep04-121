#ifndef TABELASIMBOLO_VO
#define TABELASIMBOLO_VO

typedef struct item_s
{
    char *key;
    int val;
} item;

typedef struct stablevo_s
{
    item *vect;
    int lfree;
    int size;
} stablevo;

stablevo *stablevo_create();

void stablevo_insert(stablevo *table, char *x);

item *stablevo_find(stablevo *table, char *x);

void stablevo_destroy(stablevo *table);

void stablevo_print(stablevo *table, char mode);

#endif
