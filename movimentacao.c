#include "main.h"

void moveHero(HEROI* heroi, char mapa[HEIGHT][WIDTH])
{
    putchxy(heroi->y, heroi->x, CHAR_ESPACO); //Apaga a posi��o atual

    switch(heroi->direcao)
    {
    case PARADO:
        break;
    case CIMA:
        if (mapa[heroi->y-1][heroi->x] != '#')
            heroi->y--;
        break;
    case BAIXO:
        if (mapa[heroi->y+1][heroi->x] != '#')
            heroi->y++;
        break;
    case ESQUERDA:
        if (mapa[heroi->y][heroi->x-1] != '#')
            heroi->x--;
        break;
    case DIREITA:
        if (mapa[heroi->y][heroi->x+1] != '#')
            heroi->x++;
        break;
    }

    heroi->direcao = PARADO; //Reseta a direcao do heroi, j� que j� usamos a anterior
    heroi->ciclos = CICLOS_HEROI; //Coloca seus ciclos de volta no maximo, para dar o tempo certo da sua movimenta��o

    putchxy(heroi->y, heroi->x, CHAR_HEROI); //Printa o heroi na sua nova posi��o

    return;
}
