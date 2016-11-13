/*Bruno Boaventura Scholl*/

#include "linkedList.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>

void insert_first(pointer *start, char *x)
{
    pointer k;
    k = malloc(sizeof(struct knot));
    k->key = x;
    k->val = 1;
    k->next = *start;
    *start = k;
}

pointer find(pointer start, char *x)
{
    pointer k;
    for (k = start; k && strcmp(k->key, x) != 0; k = k->next)
        ;
    return k;
}

pointer new_list()
{
    return NULL;
}

void insert_sorted(pointer *start, char *x)
{
    pointer p, old, new;

    new = malloc(sizeof(struct knot));
    new->key = x;
    new->val = 1;
    p = *start;
    old = NULL;
    while (p && strcmp(p->key, x) < 0)
    {
        old = p;
        p = p->next;
    }
    if (!old)
    {
        new->next = *start;
        *start = new;
    }
    else
    {
        old->next = new;
        new->next = p;
    }
}
