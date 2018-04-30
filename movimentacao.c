#include "main.h"

void moveHero(HEROI* heroi, char mapa[HEIGHT][WIDTH])
{
    putchxy(heroi->x, heroi->y, CHAR_ESPACO); //Apaga a posição atual

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

    colisaoPontos(heroi, mapa);
    heroi->direcao = PARADO; //Reseta a direcao do heroi, já que já usamos a anterior
    heroi->ciclos = CICLOS_HEROI; //Coloca seus ciclos de volta no maximo, para dar o tempo certo da sua movimentação

    putchxy(heroi->x, heroi->y, CHAR_HEROI); //Printa o heroi na sua nova posição

    return;
}

void colisaoPontos(HEROI* heroi, char mapa[HEIGHT][WIDTH]){

    //Colisão com o Refém
    if(mapa[heroi->y][heroi->x] == '0'){
        mapa[heroi->y][heroi->x] = ' ';
        heroi->pontos+=100;
    }

    //Colisão com o Bonus de tiros
    if(mapa[heroi->y][heroi->x] == '%'){
        mapa[heroi->y][heroi->x] = ' ';
        heroi->dardos+=2;
    }
}

void moveTiro(TIRO* tiro, char mapa[HEIGHT][WIDTH]){

    if(tiro->t_restante != 12){
        putchxy(tiro->x, tiro->y, CHAR_ESPACO); //Apaga a posicao atual do tiro, apenas se não é a primeira vez que ele é desenhado
    }
    tiro->t_restante--; //Move o tiro uma posicao pra frente


    switch(tiro->direcao)
    {
    case PARADO:
        break;
    case CIMA:
        if (mapa[tiro->y-1][tiro->x] != '#' && mapa[tiro->y-1][tiro->x] != '0')
            tiro->y--;
        else
            tiro->t_restante = 0; //Se acertou a parede ou refem, zera a distancia do tiro
        break;
    case BAIXO:
        if (mapa[tiro->y+1][tiro->x] != '#' && mapa[tiro->y+1][tiro->x] != '0')
            tiro->y++;
        else
            tiro->t_restante = 0; //Se acertou a parede ou refem, zera a distancia do tiro
        break;
    case ESQUERDA:
        if (mapa[tiro->y][tiro->x-1] != '#' && mapa[tiro->y][tiro->x-1] != '0')
            tiro->x--;
        else
            tiro->t_restante = 0; //Se acertou a parede ou refem, zera a distancia do tiro
        break;
    case DIREITA:
        if (mapa[tiro->y][tiro->x+1] != '#' && mapa[tiro->y][tiro->x+1] != '0')
            tiro->x++;
        else
            tiro->t_restante = 0; //Se acertou a parede ou refem, zera a distancia do tiro
        break;
    }

    //Printa a posicao atual do tiro
    if(tiro->t_restante){
        if(tiro->direcao == CIMA || tiro->direcao == BAIXO)
            putchxy(tiro->x, tiro->y, CHAR_TIRO_V);
        else
            putchxy(tiro->x, tiro->y, CHAR_TIRO_H);
    }


    return;
}
