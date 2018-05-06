#ifndef STRUCTS_H
#define STRUCTS_H


//Heroi principal
typedef struct {
    int x;      // Posição x do heroi
    int y;      // Posição y do heroi
    int direcao; //Direcao para qual ele esta correndo
    int u_direcao; //Direcao anterior
    int dardos; // Quantidade de dardos disponiveis para o heroi
    int pontos; // Pontos do heroi
    int vidas;  // Vida restante pro heroi
    int ciclos; // Ciclos até se movimentar novamente
} HEROI;

typedef struct{
    int x;
    int y;
    int direcao;
    int t_restante;
}TIRO;

// Inimigo
typedef struct {
    int x;
    int y;
    int direcao;
    int passos_restantes;
    int ciclos; // Ciclos até se movimentar novamente
    int estado; // 0 - Dormindo; 1 - Patrulhando;
    int t_sono; // Tempo que falta para dormir
} INIMIGO;

//Todos os inimigos
typedef struct {
    int qtde;
    INIMIGO listaInimigos[MAX_INIMIGOS];
} INIMIGOS;

// Informação sobre a saída do mapa
typedef struct {
    int x;
    int y;
} SAIDA;

typedef struct {
    int x;
    int y;
} CHAVE;

#endif // STRUCTS_H
