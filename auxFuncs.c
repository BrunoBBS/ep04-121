/*Bruno Boaventura Scholl*/

#include "auxFuncs.h"
#include "types.h"
#include <stdio.h>
#include <string.h>

int comp_vect_n(const void *a, const void *b)
{
    return -(((item *)a)->val - ((item *)b)->val);
}

int comp_list_n(const void *a, const void *b)
{
    return -((*(pointer *)a)->val - (*(pointer *)b)->val);
}

int comp_list_a(const void *a, const void *b)
{
    return strcmp((*(pointer *)a)->key, (*(pointer *)b)->key);
}

int comp_bst_n(const void *a, const void *b)
{
    return -((*(treeptr *)a)->val - (*(treeptr *)b)->val);
}
