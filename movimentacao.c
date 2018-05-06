#include "main.h"

int moveHero(HEROI* heroi, char mapa[HEIGHT][WIDTH], CHAVE chave, SAIDA* saida)
{

    putchxy(heroi->x, heroi->y, CHAR_ESPACO); //Apaga a posi��o atual

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

    colisaoPontos(heroi, mapa, chave, saida);
    heroi->direcao = PARADO; //Reseta a direcao do heroi, j� que j� usamos a anterior
    heroi->ciclos = CICLOS_HEROI; //Coloca seus ciclos de volta no maximo, para dar o tempo certo da sua movimenta��o

    putchxy(heroi->x, heroi->y, CHAR_HEROI); //Printa o heroi na sua nova posi��o

    return checaVitoria(heroi, saida); //Retorna se ganhou ou n�o
}

void moveTiro(TIRO* tiro, char mapa[HEIGHT][WIDTH])
{


    if(tiro->t_restante != 12)
    {
        putchxy(tiro->x, tiro->y, CHAR_ESPACO); //Apaga a posicao atual do tiro, apenas se n�o � a primeira vez que ele � desenhado
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
    if(tiro->t_restante)
    {
        if(tiro->direcao == CIMA || tiro->direcao == BAIXO)
            putchxy(tiro->x, tiro->y, CHAR_TIRO_V);
        else
            putchxy(tiro->x, tiro->y, CHAR_TIRO_H);
    }


    return;
}

void moveInimigos(INIMIGO* inimigo, char mapa[HEIGHT][WIDTH])
{
    putchxy(inimigo->x, inimigo->y, CHAR_ESPACO); //Apaga a posi��o atual

    if(!inimigo->passos_restantes) //Se o inimigo n�o tem mais passos para andar, gera uma nova dire��o
    {
        if(inimigo->direcao != PARADO) // Se n�o estava parado, "lembra" da ultima dire��o andada
            inimigo->u_direcao = inimigo->direcao;
        inimigo->direcao = rand() % 5;                  // Escolhe uma das 5 possiveis dire��es
        inimigo->passos_restantes = 2 + (rand() % 3);   // Anda entre 2 e 4 passos
    }

    switch(inimigo->direcao) // Verifica para qual lado inimigo precisa se movimentar
    {
    case PARADO: // Caso esteja parado, vai printar pra ultima dire��o que estava virado
        switch(inimigo->u_direcao)
        {
        case CIMA:
            putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_C); //Printa o heroi na sua nova posi��o
            break;
        case BAIXO:
            putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_B); //Printa o heroi na sua nova posi��o
            break;
        case ESQUERDA:
            putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_E); //Printa o heroi na sua nova posi��o
            break;
        case DIREITA:
            putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_D); //Printa o heroi na sua nova posi��o
            break;
        }
        break;
    case CIMA:
        if (mapa[inimigo->y-1][inimigo->x] != '#' && mapa[inimigo->y-1][inimigo->x] != '0'&& mapa[inimigo->y-1][inimigo->x] != 'K') //Checa colis�o
            inimigo->y--;
        else
            inimigo->passos_restantes = 1; //Seto para 1, pois irei reduzir ao final do loop em 1, fazendo com que nao avance novamente
        putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_C); //Printa o heroi na sua nova posi��o
        break;
    case BAIXO:
        if (mapa[inimigo->y+1][inimigo->x] != '#' && mapa[inimigo->y+1][inimigo->x] != '0'&& mapa[inimigo->y+1][inimigo->x] != 'K')
            inimigo->y++;
        else
            inimigo->passos_restantes = 1;
        putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_B);
        break;
    case ESQUERDA:
        if (mapa[inimigo->y][inimigo->x-1] != '#' && mapa[inimigo->y][inimigo->x-1] != '0'&& mapa[inimigo->y][inimigo->x-1] != 'K')
            inimigo->x--;
        else
            inimigo->passos_restantes = 1;
        putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_E);
        break;
    case DIREITA:
        if (mapa[inimigo->y][inimigo->x+1] != '#' && mapa[inimigo->y][inimigo->x+1] != '0'&& mapa[inimigo->y][inimigo->x+1] != 'K')
            inimigo->x++;
        else
            inimigo->passos_restantes = 1;
        putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_D);
        break;
    }

    inimigo->passos_restantes--;
    inimigo->ciclos = CICLOS_INIMIGO;

    return;
}
