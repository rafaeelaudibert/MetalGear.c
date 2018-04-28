#include "main.h"

///Tenta ler o mapa retornando 0 se não conseguir abrir, e 1 se conseguir abrir
int leMapa(char mapa[HEIGHT][WIDTH], HEROI* heroi, SAIDA* saida, INIMIGOS* inimigos, CHAVE* chave)
{
    char str[81];
    int i=0, j=0;
    FILE *arq;

    //Pointer to the file read
    arq = fopen("data/mapa.txt", "r");

    //Testa se o arquivo abriu
    if(arq == NULL)
    {
        printf("ERRO: O mapa não pode ser aberto\n");
        fclose(arq);
        return 0;
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
                decodificaMapa(i, j, &str[j], heroi, saida, inimigos, chave);
                mapa[i][j] = str[j];
            }

            i++;
        }
    }
    fclose(arq);

    return 1;
}

///Laço 'for' simples para printar SOMENTE as paredes do mapa
void printaParedes(char mapa[HEIGHT][WIDTH])
{
    int i, j;

    // Printa somente as paredes
    for(i=0; i<HEIGHT; i++)
        for(j=0; j<WIDTH; j++)
            if (mapa[i][j] == '#')
                putchxy(i, j, '#');

    return;

}

/// Decodifica as representações do mapa
void decodificaMapa(int x, int y, char* c, HEROI* heroi, SAIDA* saida, INIMIGOS* inimigos, CHAVE* chave)
{
    switch(toupper(*c))
    {
    case '@': //Inimigos
        if (inimigos->qtde < MAX_INIMIGOS) //Somente adicionarei novos inimigos se eu ainda tiver espaço na array
        {
            inimigos->listaInimigos[inimigos->qtde].x = x;
            inimigos->listaInimigos[inimigos->qtde].y = y;
            inimigos->listaInimigos[inimigos->qtde].t_sono = 0;
            inimigos->listaInimigos[inimigos->qtde].estado = 1;
            inimigos->listaInimigos[inimigos->qtde].ciclos = 0;
            inimigos->qtde++;
        }
        break;
    case 'X': //Saída
        if(!saida->x && !saida->y)
        {
            *c = '#';
            saida->x = x;
            saida->y = y;
        }
        break;
    case 'O': //Decodifica o heroi
        if (!heroi->x && !heroi->y)
        {
            heroi->x = x;
            heroi->y = y;
        }
        break;
    case 'K': //Chave
        if(!chave->x && !chave-y)
        {
            chave->x = x;
            chave->y = y;
        }
        break;
    }


}
