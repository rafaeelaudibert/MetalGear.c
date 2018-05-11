#include "main.h"

int moveHero(HEROI* heroi, char mapa[HEIGHT][WIDTH], CHAVE chave, SAIDA* saida)
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

    colisaoPontos(heroi, mapa, chave, saida);
    heroi->direcao = PARADO; //Reseta a direcao do heroi, já que já usamos a anterior
    heroi->ciclos = CICLOS_HEROI; //Coloca seus ciclos de volta no maximo, para dar o tempo certo da sua movimentação

    putchxy(heroi->x, heroi->y, CHAR_HEROI); //Printa o heroi na sua nova posição
    return checaVitoria(heroi, saida); //Retorna se ganhou ou não
}

void moveTiro(TIRO* tiro, INIMIGOS* inimigos, char mapa[HEIGHT][WIDTH])
{

    int i; // Variavel contadora

    if(tiro->t_restante != 12)
    {
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

    for(i=0; i<inimigos->qtde; i++)  //Verifica se bala acertou inimigo
    {
        if(tiro->x == inimigos->listaInimigos[i].x && tiro->y == inimigos->listaInimigos[i].y)
        {
            inimigos->listaInimigos[i].t_sono = CICLOS_SONO;
            tiro->t_restante = 0; // Se acertou o inimigo, zera a distancia do tiro
            break; //Não precisa verificar os outros inimigos, apenas um deles
        }
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
    visaoInimigo(APAGA, inimigo->x, inimigo->y, inimigo->direcao == PARADO ? inimigo->u_direcao : inimigo->direcao, mapa); //Apaga a visão anterior

    if(!inimigo->t_sono) //Se o inimigo não está dormindo
    {
        putchxy(inimigo->x, inimigo->y, CHAR_ESPACO); //Apaga a posição atual

        if(!inimigo->passos_restantes) //Se o inimigo não tem mais passos para andar, gera uma nova direção
        {
            if(inimigo->direcao != PARADO) // Se não estava parado, "lembra" da ultima direção andada
                inimigo->u_direcao = inimigo->direcao;
            inimigo->direcao = rand() % 5;                  // Escolhe uma das 5 possiveis direções
            inimigo->passos_restantes = 2 + (rand() % 3);   // Anda entre 2 e 4 passos
        }

        switch(inimigo->direcao) // Verifica para qual lado inimigo precisa se movimentar
        {
        case PARADO: // Caso esteja parado, vai printar pra ultima direção que estava virado
            switch(inimigo->u_direcao)
            {
            case CIMA:
                putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_C); //Printa o heroi na sua nova posição
                break;
            case BAIXO:
                putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_B); //Printa o heroi na sua nova posição
                break;
            case ESQUERDA:
                putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_E); //Printa o heroi na sua nova posição
                break;
            case DIREITA:
                putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_D); //Printa o heroi na sua nova posição
                break;
            }
            break;
        case CIMA:
            if (mapa[inimigo->y-1][inimigo->x] != '#' && mapa[inimigo->y-1][inimigo->x] != '0'&& mapa[inimigo->y-1][inimigo->x] != 'K') //Checa colisão
                inimigo->y--;
            else
                inimigo->passos_restantes = 1; //Seto para 1, pois irei reduzir ao final do loop em 1, fazendo com que nao avance novamente
            putchxy(inimigo->x, inimigo->y, CHAR_INIMIGO_C); //Printa o heroi na sua nova posição
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

        visaoInimigo(MOSTRA, inimigo->x, inimigo->y, inimigo->direcao == PARADO ? inimigo->u_direcao : inimigo->direcao, mapa); //Reconstroi a visao do inimigo
        inimigo->passos_restantes--;
    }
    else     // Se inimigo estiver dormindo
    {
        putchxy(inimigo->x, inimigo->y, 'Z'); //Printa o caracter de sono
        inimigo->t_sono-=4;
    }

        inimigo->ciclos = CICLOS_INIMIGO;

    return;
}

int visaoInimigo(int status, int x, int y, int direcao, char mapa[HEIGHT][WIDTH])
{

    int avistado = 0; //Flag que retorna se viu o herói
    int i, j; //Contadores

    switch(direcao)
    {
    case CIMA:
        for(i=-1; i<=1; i++)
        {
            for(j=0; j<=3; j++)
            {
                if (x-i >= 0 && y-j >= 0) //Garante que esteja dentro dos limites da matriz
                    if ( !(i == 0 && j == 0) && mapa[y-j][x-i] != '#')
                        if(mapa[y-j][x-i] != 'K' && mapa[y-j][x-i] != '0')
                            putchxy(x-i, y-j, (status == MOSTRA ? CHAR_VISAO : CHAR_ESPACO)); //Operador ternario decide se apaga ou mostra o campo de visão
            }
        }
        break;
    case BAIXO:
        for(i=-1; i<=1; i++)
        {
            for(j=0; j<=3; j++)
            {
                if (x+i < WIDTH && y+j < HEIGHT) //Garante que esteja dentro dos limites da matriz
                    if ( !(i == 0 && j == 0) && mapa[y+j][x+i] != '#')
                        if(mapa[y+j][x+i] != 'K' && mapa[y+j][x+i] != '0')
                            putchxy(x+i, y+j, (status == MOSTRA ? CHAR_VISAO : CHAR_ESPACO)); //Operador ternario decide se apaga ou mostra o campo de visão
            }
        }
        break;
    case ESQUERDA:
        for(i=0; i<=3; i++)
        {
            for(j=-1; j<=1; j++)
            {
                if (x-i >= 0 && y-j >= 0) //Garante que esteja dentro dos limites da matriz
                    if ( !(i == 0 && j == 0) && mapa[y-j][x-i] != '#')
                        if(mapa[y-j][x-i] != 'K' && mapa[y-j][x-i] != '0')
                            putchxy(x-i, y-j, (status == MOSTRA ? CHAR_VISAO : CHAR_ESPACO)); //Operador ternario decide se apaga ou mostra o campo de visão
            }
        }
        break;
    case DIREITA:
        for(i=0; i<=3; i++)
        {
            for(j=-1; j<=1; j++)
            {
                if (x+i < WIDTH && y+j < HEIGHT) //Garante que esteja dentro dos limites da matriz
                    if ( !(i == 0 && j == 0) && mapa[y+j][x+i] != '#')
                        if(mapa[y+j][x+i] != 'K' && mapa[y+j][x+i] != '0')
                            putchxy(x+i, y+j, (status == MOSTRA ? CHAR_VISAO : CHAR_ESPACO)); //Operador ternario decide se apaga ou mostra o campo de visão
            }
        }
        break;

    }

    return avistado;
}
