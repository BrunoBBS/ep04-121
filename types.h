#ifndef TYPES_H
#define TYPES_H

typedef struct item_s
{
    char *key;
    int val;
} item;

struct stable_s
{
    item *vect;
    int lfree;
    int size;
};

typedef struct knot *pointer;

struct knot
{
    char *key;
    int val;
    pointer next;
};

typedef struct knot_AB *node;
struct knot_AB
{
    char *key;
    int val;
    node right;
    node left;
}

#endif
