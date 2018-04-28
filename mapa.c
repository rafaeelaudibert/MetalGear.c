#include "main.h"

///Lê o mapa
int leMapa(char mapa[HEIGHT][WIDTH])
{
    char str[81];
    int i=0, j=0;
    FILE *arq;

    //Pointer to the file read
    arq = fopen("data/mapa.txt", "r");

    //Tests the file opening
    if(arq == NULL)
    {
        printf("ERRO: O mapa não pode ser aberto\n");
        fclose(arq);
        return 1;
    }


    //Lê cada linha do arquivo
    while(fgets(str, WIDTH + 1, arq) != NULL || i<HEIGHT)
    {
        //Se não for uma linha em branco
        if(str[0] != '\n')
        {
            //Adiciona a linha no mapa
            for(j=0; j<WIDTH; j++)
            {
                mapa[i][j] = str[j];
            }

            i++;
        }
    }
    fclose(arq);

    return 0;
}
