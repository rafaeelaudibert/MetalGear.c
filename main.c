#include "main.h"

int main()
{

    setlocale(LC_ALL, "portuguese"); //Coloca o local como portugues
    _setcursortype(0); //Deixa o cursor invisivel
    system("mode 100,50"); //Seta o tamanho da tela

    char mapa[HEIGHT][WIDTH]; // Mapa

    /* INICIALIZAÇÃO DOS VALORES PRINCIPAIS */

    //Inicialização do herói
    HEROI heroi = {NULL, NULL, PARADO, DIREITA, DARDOS_INICIAL, PONTOS_INICIAL, VIDAS_INICIAL, 0}; //Atira para direita no inicio do jogo

    //Inicialização dos inimigos
    INIMIGOS inimigos;
    inimigos.qtde = 0; //Inicializa com 0 inimigos

    //Inicialização da saída
    SAIDA saida = {NULL, NULL}; //Sem posição inicial

    //Inicialização da chave
    CHAVE chave = {NULL, NULL};

    /* ############################# */

    //if(menuInicial && leMapa(mapa, &heroi, &saida, &inimigos, &chave)){
    if(leMapa(mapa, &heroi, &saida, &inimigos, &chave)){
        printaParedes(mapa);
        gameLoop(mapa, &heroi, &saida, &inimigos, chave);
    }else
        return 1; //Erro na leitura do mapa

    return 0;
}
