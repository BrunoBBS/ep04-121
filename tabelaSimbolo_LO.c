#include "auxFuncs.h"
#include "linkedList.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pointer stablelo_find(pointer start, char *x)
{
    return find(start, x);
}

pointer stablelo_insert(pointer *start, char *x)
{
    pointer p = stablelo_find(*start, x);
    if (!p)
        insert_sorted(start, x);
    else
    {
        p->val += 1;
        free(x);
    }
}

pointer stablelo_create()
{
    return NULL;
}

void stablelo_destroy(pointer *start)
{
    pointer p, old = NULL;
    for (p = *start; p->next; p = p->next)
    {
        if (old)
        {
            free(old->key);
            free(old);
        }
        old = p;
    }
    free(p->key);
    free(p);
    *start = NULL;
}

void stablelo_print_a(pointer start)
{
    pointer p;
    for (p = start; p; p = p->next)
        printf("%s %d\n", p->key, p->val);
}

void stablelo_print_o(pointer *start)
{
    int i, j;
    pointer p, *vect;
    for (i = 0, p = *start; p; p = p->next, i++)
        ;
    printf("Contou a lista\n");
    vect = malloc(i * sizeof(pointer));
    printf("alocou a o vetro\n");
    for (j = 0, p = *start; j < i; p = p->next, j++)
        vect[j] = p;
    printf("copiou a lista no vetor\n");

    printf("vai dar qsort\n");
    qsort(vect, i, sizeof(pointer), comp_list_n);
    printf("fez qsort\n");

    printf("vai pritar a lista\n");
    for (j = 0; j < i; j++)
        printf("%s %d\n", vect[j]->key, vect[j]->val);

    printf("printou a lista\n");
}
