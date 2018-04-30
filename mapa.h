#ifndef MAPA_H
#define MAPA_H

int leMapa(char[HEIGHT][WIDTH], HEROI*, SAIDA*, INIMIGOS*, CHAVE*);
void printaParedes(char[HEIGHT][WIDTH]);
void decodificaMapa(int, int, char*, HEROI*, SAIDA*, INIMIGOS*, CHAVE*);

#endif // MAPA_H

