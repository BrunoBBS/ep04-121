/*Bruno Boaventura Scholl*/

#ifndef TABELASIMBOLO_AB
#define TABELASIMBOLO_AB

#include "types.h"

/*A funcao retorna um ponteiro para um ponteiro para a raiz da arvore*/
treeptr *stableab_create();

/*A funcao recebe um ponteiro para um ponteiro para a raiz da arvore, uma string
 * e a insere na arvore*/
void stableab_insert(treeptr *root, char *x);

/*Essa funcao recebe um ponteiro para a raiz da arvore e imprime-a ordenada por
 * ordem numerica*/
void stableab_print_o(treeptr root);

/*Essa funcao recebe um ponteiro para a raiz da arvore e imprime-a ordenada por
 * ordem alfabetica*/
void stableab_print_a(treeptr root);

/*Essa funcao recebe um ponteiro para a raiz da arvore binaria e uma string e
 * retorna um ponteiro para um item que corresponde a string ou nulo caso nao
 * haja correspondencia*/
treeptr stableab_find(treeptr root, char *x);

/*A funcao recebe um ponteiro para um ponteiro para a raiz da arvore e a destroi*/
void stableab_destroy(treeptr *root);

#endif
