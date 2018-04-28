#include "main.h"

int main()
{

    setlocale(LC_ALL, "portuguese"); //Coloca o local como portugues
    system("mode 100,50");

    char mapa[HEIGHT][WIDTH]; // Mapa

    /* INICIALIZAÇÃO DOS VALORES PRINCIPAIS */

    //Inicialização do herói
    HEROI heroi = {NULL, NULL, DARDOS_INICIAL, PONTOS_INICIAL, VIDAS_INICIAL, 0};

    // Inicialização do tiro
    TIRO tiro = {NULL, NULL, 0};

    //Inicialização dos inimigos
    INIMIGOS inimigos;
    inimigos.qtde = 0; //Inicializa com 0 inimigos

    //Inicialização da saída
    SAIDA saida = {NULL, NULL, SAIDA_OCULTA}; //Sem posição inicial, porém não ativa ainda

    //Inicialização da chave
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
