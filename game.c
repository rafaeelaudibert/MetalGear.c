#include "main.h"

void gameLoop(char mapa[HEIGHT][WIDTH], HEROI* heroi, SAIDA* saida, INIMIGOS* inimigos, CHAVE chave)
{

    TIRO tiro = {NULL, NULL, PARADO, 0}; // Inicialização do tiro
    int gameOver = 0; //Flag do gameOver
    int i; //Contador dos laços

//LAÇO DO JOGO
    while(!gameOver)
    {

        if(kbhit())
        {
            decodeKey(detectKey(), heroi, &tiro); //Decodifica a tecla, e "traduz" o seu valor para informacoes relevantes
        }

        if(tiro.t_restante)  // Se tenho um tiro, movo ele
        {
            moveTiro(&tiro, inimigos, mapa);
        }

        for(i=0; i<inimigos->qtde; i++)
        {
            if(!inimigos->listaInimigos[i].ciclos) //Se o inimigo precisa se mover agora
            {
                moveInimigos(&inimigos->listaInimigos[i], mapa);
            }
            else
            {
                inimigos->listaInimigos[i].ciclos--;
            }
        }

        if(!heroi->ciclos)
        {
            gameOver = moveHero(heroi, mapa, chave, saida);
        }
        else
        {
            heroi->ciclos--;
        }


        //MoveEnemies
        //Detect key collision
        //DetectEnemyPlayerCollision
        //...


        Sleep(FPS); // Controla a velocidade do jogo
    }

    return;
}

char detectKey()
{
    char key='X';

    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57)) //Up key
    {
        key = 'W';
    }
    else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53)) //Down key
    {
        key = 'S';
    }
    else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) //Left key
    {
        key = 'A';
    }
    else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44)) //Right key
    {
        key = 'D';
    }
    else if (GetAsyncKeyState(0x50)) //'P' key - Pause
    {
        key = 'P';
    }
    else if (GetAsyncKeyState(0x4E)) //'N' key - New Game
    {
        key = 'N';
    }
    else if (GetAsyncKeyState(0x54)) //'T' key - Top10
    {
        key = 'T';
    }
    else if (GetAsyncKeyState(VK_SPACE)) //'Space' key
    {
        key = ' ';
    }
    else if (GetAsyncKeyState(VK_ESCAPE)) //'Esc' key
    {
        key = 'E';
    }

    return key;

}

void decodeKey(char key, HEROI* heroi, TIRO* tiro)
{

    switch(key)
    {
    case 'W':
        heroi->direcao = CIMA;
        heroi->u_direcao = CIMA;
        break;
    case 'A':
        heroi->direcao = ESQUERDA;
        heroi->u_direcao = ESQUERDA;
        break;
    case 'S':
        heroi->direcao = BAIXO;
        heroi->u_direcao = BAIXO;
        break;
    case 'D':
        heroi->direcao = DIREITA;
        heroi->u_direcao = DIREITA;
        break;
    case ' ':
        if(!tiro->t_restante && heroi->dardos)  //Para impedir de extender duracao do tiro ou de atirar quando nao tem mais dardos
        {
            tiro->direcao = heroi->u_direcao;
            tiro->x = heroi->x;
            tiro->y = heroi->y;
            tiro->t_restante = DURACAO_TIRO;
            heroi->dardos--;
        }
        break;
    case 'P':
        //pause();
        break;
    }
    return;
}
