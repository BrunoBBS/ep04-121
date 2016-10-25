#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

void insertFirst(knot *start, char *x)
{
    knot k;
    k = malloc(sizeof(struct knot_s));
    k->key = malloc(strlen(x) * sizeof(char));
    strcpy(k->key, x);
    k->val = 0;
    k->next = *start;
    *start = k;
}

knot find(knot start, char *x)
{
    knot k;
    for (k = start; k && k->key != x; k = k->next)
        ;
    return k;
}

knot newList()
{
    knot k = NULL;
    return k;
}
