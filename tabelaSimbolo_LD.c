#include "linkedList.h"
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
    }
    else
        insert_first(start, x);
}

pointer stableld_create()
{
    return new_list();
}

/*FALTAQ FAZER ELE PRINTAR */
void stableld_print_o(pointer start)
{
    pinter p;
    for (p = start; p; p = p->next)
        printf("");
}

void stableld_print_a(pointer start)
{
    pinter p;
    for (p = start; p; p = p->next)
        printf("");
}
