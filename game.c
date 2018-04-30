#include "main.h"

void gameLoop(char mapa[HEIGHT][WIDTH], HEROI* heroi, SAIDA* saida, INIMIGOS* inimigos, CHAVE chave)
{

    TIRO tiro = {NULL, NULL, 0}; // Inicialização do tiro
    int gameOver = 0; //Flag do gameOver

//LAÇO DO JOGO
    while(!gameOver)
    {

        if(kbhit())
        {
            decodeKey(detectKey(), heroi, &tiro); //Decodifica a tecla, e "traduz" o seu valor para informacoes relevantes
        }

        if(!heroi->ciclos){
            moveHero(heroi, mapa);
        } else {
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
        break;
    case 'A':
        heroi->direcao = ESQUERDA;
        break;
    case 'S':
        heroi->direcao = BAIXO;
        break;
    case 'D':
        heroi->direcao = DIREITA;
        break;
    case ' ':
        if(!tiro->t_restante)  //Para impedir de perder o tiro anterior, ou extender sua duração
        {
            tiro->t_restante = DURACAO_TIRO;
        }
        break;
    case 'P':
        //pause();
        break;
    }
    return;
}
