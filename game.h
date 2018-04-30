#ifndef GAME_H
#define GAME_H

void gameLoop(char mapa[HEIGHT][WIDTH], HEROI* heroi, SAIDA* saida, INIMIGOS* inimigos, CHAVE chave);
char detectKey();
void decodeKey(char key, HEROI* heroi, TIRO* tiro);

#endif // GAME_H


