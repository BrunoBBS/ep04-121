#include "auxFuncs.h"
#include "types.h"
#include <string.h>

int comp_vect_a(const void *a, const void *b)
{
    if (a != NULL && b != NULL)
        return strcmp(((item *)a)->key, ((item *)b)->key);
    return a ? -1 : 1;
}

int comp_vect_n(const void *a, const void *b)
{
    return ((item *)a)->val - ((item *)b)->val;
}

int comp_list_n(const void *a, const void *b)
{
    return (*(pointer *)a)->val - (*(pointer *)b)->val;
}

int comp_list_a(const void *a, const void *b)
{
    return strcmp((*(pointer *)a)->key, (*(pointer *)b)->key);
}
