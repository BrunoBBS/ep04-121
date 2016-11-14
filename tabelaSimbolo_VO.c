/*Bruno Boaventura Scholl*/

#include "tabelaSimbolo_VO.h"
#include "auxFuncs.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stablevo *stablevo_create()
{
    stablevo *S;
    S = malloc(sizeof(stablevo));
    S->vect = malloc(3 * sizeof(item));
    S->size = 3;
    S->lfree = 0;
    return S;
}

int find_place(stablevo *table, char *x, int stt, int fsh, int mid)
{
    int aux;
    if (mid == 0 && fsh == -1)
        return 0;
    aux = strcmp(x, table->vect[mid].key);
    if (fsh == stt)
    {
        if (aux > 0)
            return mid + 1;
        else
            return mid;
    }

    if (aux > 0)
        return find_place(table, x, mid + 1, fsh, (mid + 1 + fsh) / 2);
    return find_place(table, x, stt, mid, (stt + mid) / 2);
}

void stablevo_insert(stablevo *table, char *x)
{
    int i, pos;
    pos = stablevo_find(table, x, 0, table->lfree - 1, table->lfree / 2);
    if (pos >= 0)
    {
        (table->vect[pos].val) += 1;
        free(x);
    }
    else
    {
        pos = find_place(table, x, 0, table->lfree - 1, (table->lfree - 1) / 2);
        if (table->lfree == table->size)
        {
            item *tmp;
            table->size *= 2;
            tmp = realloc(table->vect, table->size * sizeof(item));
            if (!tmp)
                exit(-1);
            table->vect = tmp;

            for (i = table->lfree - 1; i >= pos; i--)
                table->vect[i + 1] = table->vect[i];
            table->vect[pos].key = x;
            table->vect[pos].val = 1;
            (table->lfree)++;
        }
        else
        {
            for (i = table->lfree - 1; i >= pos; i--)
                table->vect[i + 1] = table->vect[i];
            table->vect[pos].key = x;
            table->vect[pos].val = 1;
            (table->lfree)++;
        }
    }
}

int stablevo_find(stablevo *table, char *x, int stt, int fsh, int mid)
{

    int aux;
    if (mid >= table->lfree)
        return -1;
    aux = strcmp(x, table->vect[mid].key);
    if (aux == 0)
        return mid;
    if (stt >= fsh)
        return -1;
    if (aux > 0)
        return stablevo_find(table, x, mid + 1, fsh, (mid + 1 + fsh) / 2);
    return stablevo_find(table, x, stt, mid, (stt + mid) / 2);
}

void stablevo_destroy(stablevo *table)
{
    int i = 0;
    for (i = 0; i < table->lfree; i++)
        free((table->vect[i]).key);
    free(table->vect);
    free(table);
}

void stablevo_print(stablevo *table, char mode)
{
    int i;
    if (mode == 'o')
        qsort(table->vect, table->lfree, sizeof(item), comp_vect_n);

    for (i = 0; i < table->lfree; i++)
        printf("%s %d\n", table->vect[i].key, table->vect[i].val);
}
