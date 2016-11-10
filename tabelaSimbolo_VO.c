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
    if (mid == 0)
        return 0;
    aux = strcmp(x, table->vect[mid].key);
    if ((fsh - stt) == 0)
    {
        if (aux > 0)
            return mid + 1;
        else
            return mid - 1;
    }

    if (aux > 0)
        return find_place(table, x, mid + 1, fsh, (mid + 1 + fsh) / 2);
    return find_place(table, x, stt, mid - 1, (mid + 1 + fsh) / 2);
}

void stablevo_insert(stablevo *table, char *x)
{
    int i, pos;
    item *aux;
    aux = stablevo_find(table, x);
    printf("Procurou  na tabela e achou o end %d \n", aux);
    if (aux)
    {
        (aux->val)++;
        free(x);
    }
    else
    {
        pos = find_place(table, x, 0, table->lfree - 1, (table->lfree - 1) / 2);
        printf("Procurou o lugar e achou o end %d\n", pos);

        if (table->lfree == table->size)
        {
            printf("A tablea n tinha espaqco\n");
            item *tmp;
            table->size *= 2;
            tmp = realloc(table->vect, table->size);
            if (!tmp)
                exit(-1);
            table->vect = tmp;

            for (i = table->lfree - 1; i > pos; i--)
                table->vect[i + 1] = table->vect[i];
            table->vect[pos].key = x;
            table->vect[pos].val = 1;
            table->lfree++;
        }
        else
        {
            printf("A tabela tem espaco, vai passar td pro lado pra por no lugar\n");
            for (i = table->size - 1; i > pos; i--)
                table->vect[i + 1] = table->vect[i];
            printf("Passou td pro lado\n");
            table->vect[pos].key = x;
            table->vect[pos].val = 1;
            table->lfree++;
            printf("Colocou na tabela e o ultimo livre é %d\n", table->lfree);
        }
    }
}

item *stablevo_find(stablevo *table, char *x)
{
    printf("Vai procurar na tabela\n");
    printf("\n");
    return (item *)bsearch(x, table->vect, table->lfree, sizeof(item), comp_vect_a);
}

void stablevo_destroy(stablevo *table)
{
    int i;
    for (i = 0; i < table->lfree; i++)
        free(table->vect[i].key);
    free(table->vect);
    free(table);
}

void stablevo_print(stablevo *table, char mode)
{
    int i;
    if (mode == 'o')
        qsort(table->vect, table->size, sizeof(item), comp_vect_n);

    for (i = 0; i < table->size; i++)
        printf("%s %d\n", table->vect[i].key, table->vect[i].val);
}
