#include "tabelaSimbolo_VO.h"
#include <stdlib.h>
#include <string.h>

stablevo *stablevo_create()
{
    stablevo *S;
    S = malloc(sizeof(stablevo));
    S->vect = malloc(3 * sizeof(item));
    S->lfree = 0;
    return S;
}

int find_place(stablevo *table, char *x, int stt, int fsh, int mid)
{
    int aux = strcmp(x, table->vect[mid].key);
    if ((fsh - stt) == 0)
    {
        if(aux > 0)
            return mid + 1;
        else
            return mid - 1;
    }

    if (aux > 0)
        return find_place(table, x, mid + 1, fsh, (mid + 1 + fsh)/2);
    return find_place(table, x, stt, mid - 1, (mid + 1 + fsh)/2);

}

void stablevo_insert(stablevo *table, char *x)
{
    int i, pos;
    item *aux;
    if (aux = stablevo_find(table, x))
        (aux->val)++;
    else
    {
        pos = find_place(table, x, 0, table->size - 1, (table->size - 1)/2);

        if (table->lfree == table->size)
        {
            item *tmp;
            table->size *= 2;
            tmp = realloc(table->vect, table->size);
            if (!tmp)
                exit(-1);
            table->vect = tmp;

            for(i = table->lfree - 1; i > pos; i--)
                table->vect[i+1] = table->vect[i];
            table->vect[pos].key = x;
            table->vect[pos].val = 1;
            table->lfree++;
        }
        else
        {
            for(i = table->size - 1; i > pos; i--)
                table->vect[i+1] = table->vect[i];
            table->vect[pos].key = x;
            table->vect[pos].val = 1;
            table->lfree++;
        }

    }

}

item *stablevo_find(stablevo *table, char *x)
{
    return (item *) bsearch(x, table->vect, table->size, sizeof(item),item);
}

void stablevo_destroy(stablevo *table)
{
    int i;
    for (i = 0; i < table->lfree; i++)
        free(table->vect[i].key);
    free(table->vect);
    free(table);
}


