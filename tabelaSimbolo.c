#include "tabelaSimbolo_AB.h"
#include "tabelaSimbolo_LD.h"
#include "tabelaSimbolo_LO.h"
#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_VO.h"
#include <ctype.h>
#include <stdio.h>

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
        tabelaSimbolo_VD();

    else if (!strcmp(mode, "VO"))
        tabelaSimbolo_VO();

    else if (!strcmp(mode, "LD"))
        tabelaSimbolo_LD();

    else if (!strcmp(mode, "LO"))
        tabelaSimbolo_LO();

    else if (!strcmp(mode, "AB"))
        tabelaSimbolo_AB();
}
