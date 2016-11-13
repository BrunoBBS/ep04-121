/*Bruno Boaventura Scholl*/

#include "tabelaSimbolo_VD.h"
#include "auxFuncs.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stablevd *stablevd_create()
{
    stablevd *S;
    S = malloc(sizeof(stablevd));
    S->vect = malloc(3 * sizeof(item));
    S->lfree = 0;
    S->size = 3;
    return S;
}

int stablevd_find(stablevd *table, char *x)
{
    int i, found = 0;
    for (i = 0; !found && i < table->lfree; i++)
    {
        if (strcmp(table->vect[i].key, x) == 0)
            found = 1;
    }
    if (found)
        return i-1;
    return -1;
}

void stablevd_insert(stablevd *table, char *x)
{
    int pos;
    if ((pos = stablevd_find(table, x)) >= 0)
    {
        (table->vect[pos].val)++;
        free(x);
    }
    else
    {
        if (table->lfree == table->size)
        {
            item *tmp;
            table->size *= 2;
            tmp = realloc(table->vect, table->size * sizeof(item));
            if (!tmp)
                exit(-1);
            table->vect = tmp;

            table->vect[table->lfree].key = x;
            table->vect[table->lfree].val = 1;
            (table->lfree)++;
        }
        else
        {
            table->vect[table->lfree].key = x;
            table->vect[table->lfree].val = 1;
            (table->lfree)++;
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
    if (mode == 'a')
        qsort(table->vect, table->size, sizeof(item), comp_vect_a);
    else
        qsort(table->vect, table->size, sizeof(item), comp_vect_n);

    for (i = 0; i < table->lfree; i++)
        printf("%s %d\n", (table->vect[i]).key, (table->vect[i]).val);
}
