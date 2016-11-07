#ifndef CMP_H
#define CMP_H

int comp_a(const void *a, const void *b)
{
    return strcmp(((item *)a)->key, ((item *)b)->key);
}

int comp_n(const void *a, const void *b)
{
    return ((item *)a)->val - ((item *) b)->val;
}

#endif
