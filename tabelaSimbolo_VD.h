#ifndef TABELASIMBOLO_VD
#define TABELASIMBOLO_VD

typedef struct item_s
{
    char *key;
    int val;
} item;

typedef struct stablevd_s
{
    item *vect;
    int lfree;
    int size;
} stablevd;

stablevd *stablevd_create();

void stablevd_insert(stablevd *table, char *x);

int stablevd_find(stablevd *table, char *x);

void stablevd_destroy(stablevd *table);

void stablevd_print(stablevd *table, char *mode);

#endif
