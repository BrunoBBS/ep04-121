/*Bruno Boaventura Scholl*/

#ifndef TABELASIMBOLO_LD
#define TABELASIMBOLO_LD
#include "linkedList.h"

/*Essa funcao recebe um ponteiro para o inicio da lista e uma string e
 * retorna um ponteiro para um item que corresponde a string ou nulo caso nao
 * haja correspondencia*/
pointer stableld_find(pointer start, char *x);

/*A funcao recebe um ponteiro para um ponteiro para o inicio da lista, uma string
 * e a insere na lista*/
void stableld_insert(pointer *start, char *x);

/*A funcao retorna um ponteiro para o primeiro item da lista*/
pointer stableld_create();

/*A funcao recebe um ponteiro para um ponteiro para o comeco de
 * uma lista e a destroi*/
void stableld_destroy(pointer *start);

/*Essa funcao recebe um ponteiro para o comeco da lista e imprime-a ordenada por
 * ordem numerica*/
void stableld_print_o(pointer *start);

/*Essa funcao recebe um ponteiro para o comeco da lista imprime-a ordenada por
 * ordem alfabetica*/
void stableld_print_a(pointer *start);

#endif
