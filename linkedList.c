#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

void insert_first(pointer *start, char *x)
{
    pointer k;
    k = malloc(sizeof(struct knot));
    k->key = malloc(strlen(x) * sizeof(char));
    strcpy(k->key, x);
    k->val = 0;
    k->next = *start;
    *start = k;
}

pointer find(pointer start, char *x)
{
    pointer k;
    for (k = start; k && k->key != x; k = k->next)
        ;
    return k;
}

pointer new_list()
{
    return NULL;
}
