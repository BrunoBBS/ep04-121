/*Bruno Boaventura Scholl*/

#include "auxFuncs.h"
#include "tabelaSimbolo_AB.h"
#include "tabelaSimbolo_LD.h"
#include "tabelaSimbolo_LO.h"
#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_VO.h"
#include "types.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nextWord(FILE *input);

void stable_VD(FILE *input, char mode)
{
    char *word;
    stablevd *table = stablevd_create();
    for (word = nextWord(input); word[0] > 0; word = nextWord(input))
        stablevd_insert(table, word);

    stablevd_print(table, mode);
    stablevd_destroy(table);
}

void stable_VO(FILE *input, char mode)
{
    char *word;
    stablevo *table = stablevo_create();
    for (word = nextWord(input); word[0] > 0; word = nextWord(input))
        stablevo_insert(table, word);

    stablevo_print(table, mode);
    stablevo_destroy(table);
}

void stable_LD(FILE *input, char mode)
{
    char *word;
    pointer table = stableld_create();
    for (word = nextWord(input); word[0] > 0; word = nextWord(input))
        stableld_insert(&table, word);

    if (mode == 'a')
        stableld_print_a(&table);
    else
        stableld_print_o(&table);

    stableld_destroy(&table);
}

void stable_LO(FILE *input, char mode)
{
    char *word;
    pointer table = stablelo_create();
    for (word = nextWord(input); word[0] > 0; word = nextWord(input))
        if (word[0] > 0)
            stablelo_insert(&table, word);

    if (mode == 'a')
        stablelo_print_a(table);
    else
        stablelo_print_o(&table);

    stablelo_destroy(&table);
}

void stable_AB(FILE *input, char mode)
{
    char *word;
    treeptr root;
    for (word = nextWord(input); *word > 0; word = nextWord(input))
        stableab_insert(&root, word);

    if (mode == 'a')
        stableab_print_a(root);
    else
        stableab_print_o(root);

    stableab_destroy(&root);
}

char *nextWord(FILE *input)
{
    int i = 0, wsz = 5;
    char *newWord2, currc, *newWord = malloc(5 * sizeof(char));
    if (!newWord)
        exit(-1);
    do
    {
        if (i == wsz)
        {
            wsz *= 2;
            newWord2 = realloc(newWord, wsz);
            if (!newWord2)
                exit(-1);
            newWord = newWord2;
        }

        currc = fgetc(input);
        if (i == 0 && isalpha(currc))
            newWord[i] = tolower(currc);

        else if (i != 0 && isalnum(currc))
            newWord[i] = tolower(currc);
        else if (i == 0 && currc != -1)
            continue;
        else
            break;

        i++;

    } while (1);
    return newWord;
}

int main(int argc, char *argv[])
{
    FILE *input;
    char ord, *mode = malloc(3 * sizeof(char));

    /*Termina o programa com erro caso numero de argumentos seja incorreto*/
    if (argc < 4)
    {
        printf("Poucos argumentos. Uso: %s <entrada> <estrutura> <ordenação>\n", argv[0]);
        return -1;
    }
    else if (argc > 4)
    {
        printf("Argumentos demais. Uso: %s <entrada> <estrutura> <ordenação>\n", argv[0]);
        return -1;
    }

    /*Abre o aruivo de entrada*/
    input = fopen(argv[1], "ro");
    if (input == 0)
        printf("Erro ao abrir arquivo de entrada: '%s'.\n", argv[1]);

    ord = tolower(argv[3][0]);

    /*le a implementacao da tabela*/
    strncpy(mode, argv[2], 2);

    if (!strcmp(mode, "VD"))
        stable_VD(input, ord);

    else if (!strcmp(mode, "VO"))
        stable_VO(input, ord);

    else if (!strcmp(mode, "LD"))
        stable_LD(input, ord);

    else if (!strcmp(mode, "LO"))
        stable_LO(input, ord);

    else if (!strcmp(mode, "AB"))
        stable_AB(input, ord);

    return 0;
}
