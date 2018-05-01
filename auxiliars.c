#include "main.h"

int checaVitoria(HEROI* heroi, SAIDA* saida){
    return (heroi->x == saida->x && heroi->y == saida->y);
}

void colisaoPontos(HEROI* heroi, char mapa[HEIGHT][WIDTH], CHAVE chave, SAIDA* saida){

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

    //Colisão com a chave
    if(mapa[heroi->y][heroi->x] == 'K'){
        mapa[heroi->y][heroi->x] = ' ';
        mapa[saida->y][saida->x] = ' ';
        putchxy(saida->x, saida->y, ' ');
        if(mapa[heroi->y][heroi->x+1]!= '#')
            putchxy(heroi->x+1, heroi->y, ' '); //Apaga a ponta da chave
    }
}
