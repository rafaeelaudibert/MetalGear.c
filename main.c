#include "main.h"

int main()
{

    setlocale(LC_ALL, "portuguese"); //Coloca o local como portugues
    system("mode 100,50");

    char mapa[HEIGHT][WIDTH]; // Mapa

    /* INICIALIZA��O DOS VALORES PRINCIPAIS */

    //Inicializa��o do her�i
    HEROI heroi = {NULL, NULL, DARDOS_INICIAL, PONTOS_INICIAL, VIDAS_INICIAL, 0};

    // Inicializa��o do tiro
    TIRO tiro = {NULL, NULL, 0};

    //Inicializa��o dos inimigos
    INIMIGOS inimigos;
    inimigos.qtde = 0; //Inicializa com 0 inimigos

    //Inicializa��o da sa�da
    SAIDA saida = {NULL, NULL, SAIDA_OCULTA}; //Sem posi��o inicial, por�m n�o ativa ainda

    //Inicializa��o da chave
    CHAVE chave = {NULL, NULL};

    /* ############################# */


    if(leMapa(mapa, &heroi, &saida, &inimigos, &chave)){
        printaParedes(mapa);
        //DoStuff
    }
    else
        return 1; // Erro na leitura do mapa

    return 0;
}
