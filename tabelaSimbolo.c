#include "tabelaSimbolo_AB.h"
#include "tabelaSimbolo_LD.h"
#include "tabelaSimbolo_LO.h"
#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_VO.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nextWord(FILE *input);

void stableLD(FILE *input)
{
    char *word;
    pointer *ld;
    word = nextWord(input);
    stableld_insert(ld, word);
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
            newWord[i] = currc;

        else if (isalnum(currc))
            newWord[i] = currc;
        else
            break;

        i++;
    } while (1);
    return newWord;
}

int main(int argc, char *argv[])
{
    FILE *input;
    char *mode = malloc(3 * sizeof(char));

    /*Termina o programa com erro caso numero de argumentos seja incorreto*/
    if (argc < 4)
    {
        printf("Poucos argumentos. Uso: ep4 <entrada> <estrutura> <ordenação>\n");
        return -1;
    }
    else if (argc > 4)
    {
        printf("Argumentos demais. Uso: ep4 <entrada> <estrutura> <ordenação>\n");
        return -1;
    }

    /*Abre o aruivo de entrada*/
    input = fopen(argv[1], "ro");
    if (input == 0)
        printf("Erro ao abrir arquivo de entrada: '%s'.\n", argv[1]);

    /*le a implementacao da tabela*/
    strncpy(mode, argv[2], 2);
    if (!strcmp(mode, "VD"))
        stable_VD(input);

    else if (!strcmp(mode, "VO"))
        stable_VO(input, argv[3]);

    else if (!strcmp(mode, "LD"))
        stable_LD(input);

    else if (!strcmp(mode, "LO"))
        stable_LO(input, argv[3]);

    else if (!strcmp(mode, "AB"))
        stable_AB(input);
}
