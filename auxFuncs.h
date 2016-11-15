/*Bruno Boaventura Scholl*/

#ifndef AUXFUNCS_H
#define AUXFUNCS_H

/*Essa funcao recebe ponteiros para itens de um vetor e devolve negativo
 *se a vem antes de b, 0 se são equivalentes e positivo se a vem depois
 *de b*/
int comp_vect_a(const void *a, const void *b);

/*Essa funcao recebe ponteiros para itens de um vetor e devolve negativo
 *se a vem antes de b, 0 se são equivalentes e positivo se a vem depois
 *de b*/
int comp_vect_n(const void *a, const void *b);

/*Essa funcao recebe ponteiros para itens de uma lista ligada e devolve
 *negativo se a vem antes de b, 0 se são equivalentes e positivo se a
 *vem depois de b*/
int comp_list_n(const void *a, const void *b);

/*Essa funcao recebe ponteiros para itens de uma lista ligada e devolve
 *negativo se a vem antes de b, 0 se são equivalentes e positivo se a
 *vem depois de b*/
int comp_list_a(const void *a, const void *b);

/*Essa funcao recebe ponteiros para itens de uma arvore binaria e devolve
 *negativo se a vem antes de b, 0 se são equivalentes e positivo se a
 *vem depois de b*/
int comp_bst_n(const void *a, const void *b);

#endif
