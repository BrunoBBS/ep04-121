#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"

/*This function receives a pointer to a poiter to the first item of the
 * linked list, and a string to put into the list, and puts it at the
 * start of the list*/
void insert_first(pointer *start, char *x);

/*Receives a pointer to a pointer to the first item of a sorted linked list
 * and a string to insert in the list, and puts it in the appropriate position
 * to keep the list sorted.*/
void insert_sorted(pointer *start, char *x);

/*This function receives a poiter to the first item of a linked list and a
 * string to find in the list and returns a pointer to the item if it 
 * exists or NULL if not.*/
pointer find(pointer start, char *x);

/*Creates a new linked list and returns a poiter to its first item*/
pointer new_list();

#endif
