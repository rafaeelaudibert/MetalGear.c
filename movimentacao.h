#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H
int moveHero(HEROI* heroi, char mapa[HEIGHT][WIDTH], CHAVE chave, SAIDA* saida);
void moveTiro(TIRO* tiro, INIMIGOS* inimigos, char mapa[HEIGHT][WIDTH]);
void moveInimigos(INIMIGO* inimigo, char mapa[HEIGHT][WIDTH]);
#endif // MOVIMENTACAO_H
