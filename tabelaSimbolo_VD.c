#include "tabelaSimbolo_VD.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cmp.h"

stablevd *stablevd_create()
{
    stablevd *S;
    S = malloc(sizeof(stablevd));
    S->vect = malloc(3 * sizeof(item));
    S->lfree = 0;
    return S;
}

int stablevd_find(stablevd *table, char *x)
{
    int i, found;
    for (i = 0; !found && i < table->lfree; i++)
    {
        if (strcmp(table->vect[i].key, x))
            found = 1;
    }
    if (found)
        return i;
    return -1;
}

void stablevd_insert(stablevd *table, char *x)
{
    int pos;
    if ((pos = stablevd_find(table, x)) >= 0)
    {
        (table->vect[pos].val)++;
    }
    else
    {
        if (table->lfree == table->size)
        {
            item *tmp;
            table->size *= 2;
            tmp = realloc(table->vect, table->size);
            if (!tmp)
                exit(-1);
            table->vect = tmp;

            table->vect[table->lfree].key = x;
            table->vect[table->lfree].val = 1;
            table->lfree++;
        }
        else
        {
            table->vect[table->lfree].key = x;
            table->vect[table->lfree].val = 1;
            table->lfree++;
        }
    }
}

void stablevd_destroy(stablevd *table)
{
    int i;
    for (i = 0; i < table->lfree; i++)
        free(table->vect[i].key);
    free(table->vect);
    free(table);
}


void stablevd_print(stablevd *table, char mode)
{
    int i;
    if (mode == 'A')
        qsort(table->vect, table->size, sizeof(item), comp_a);
    else
        qsort(table->vect, table->size, sizeof(item), comp_n);

    for (i = 0; i < table->size; i++)
        printf("%s %d", table->vect[i].key, table->vect[i].val);
}
