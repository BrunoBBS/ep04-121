#include "tabelaSimbolo_AB.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

treeptr *stableab_create()
{
    return NULL;
}

void stableab_insert(treeptr *root, char *x)
{
    treeptr new, t, old = NULL;
    treeptr found = stableab_find(*root, x);
    if (!found)
    {
        new = malloc(sizeof(struct node));
        new->key = x;
        new->val = 1;
        new->left = new->right = NULL;
        if (!*root)
            *root = new;
        else
        {
            t = *root;
            while (t)
            {
                old = t;
                if (strcmp(x, t->key) > 0)
                    t = t->right;
                else
                    t = t->left;
            }
            if (strcmp(x, old->key) > 0)
                old->right = new;
            else
                old->left = new;
        }
    }
    else
    {
        (found->val)++;
    }
}

treeptr stableab_find(treeptr root, char *x)
{
    treeptr t;
    for (t = root; t && strcmp(t->key, x);)
    {
        if (strcmp(x, t->key) > 0)
            t = t->right;
        else
            t = t->left;
    }
    return t;
}

void stableab_print_a(treeptr root)
{
    if (root)
    {
        stableab_print_a(root->left);
        printf("%s %d\n", root->key, root->val);
        stableab_print_a(root->right);
    }
}

void stableab_destroy(treeptr *root)
{
    if (*root)
    {
        stableab_destroy(&(*root)->left);
        stableab_destroy(&(*root)->right);
        free(*root);
    }
}
