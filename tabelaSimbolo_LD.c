#include "auxFuncs.h"
#include "linkedList.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pointer stableld_find(pointer start, char *x)
{
    return find(start, x);
}

void stableld_insert(pointer *start, char *x)
{
    pointer p = stableld_find(*start, x);
    if (p)
    {
        p->val += 1;
        free(x);
    }
    else
        insert_first(start, x);
}

pointer stableld_create()
{
    return NULL;
}

void stableld_print_o(pointer *start)
{
    int i, j;
    pointer p, *vect;
    for (i = 0, p = *start; p; p = p->next, i++)
        ;

    vect = malloc(i * sizeof(pointer));
    for (j = 0; j < i; j++)
        vect[i] = p;

    qsort(vect, i, sizeof(pointer), comp_list_n);

    for (j = 0; j < i; j++)
        printf("%s %d", vect[j]->key, vect[j]->val);
}

void stableld_print_a(pointer *start)
{
    int i, j;
    pointer p, *vect;
    for (i = 0, p = *start; p; p = p->next, i++)
        ;

    vect = malloc(i * sizeof(pointer));
    for (j = 0; j < i; j++)
        vect[i] = p;

    qsort(vect, i, sizeof(pointer), comp_list_a);

    for (j = 0; j < i; j++)
        printf("%s %d", vect[j]->key, vect[j]->val);
}

void stableld_destroy(pointer *start)
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
