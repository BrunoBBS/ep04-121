/*Bruno Boaventura Scholl*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"

/*Essa funcao recebe um ponteiro para um ponteiro do comeco da lista ligada, 
 * uma string e a insere na primeira posicao da lista ligada*/
void insert_first(pointer *start, char *x);

/*Essa funcao recebe um ponteiro para um ponteiro do comeco da lista ligada, 
 * uma string e a insere na posicao apropriada para que a lista continue 
 * ordenada*/
void insert_sorted(pointer *start, char *x);

/*Essa funcao recebe um ponteiro para o inicio da lista ligada e uma string
 * e retorna um ponteiro para a posicao da string na lista ou nulo caso ela
 * nao esteja na lista.*/
pointer find(pointer start, char *x);

/*Cria uma nova lista e retorna um ponteiro para seu primeiro item*/
pointer new_list();

#endif
