#ifndef STRUCTS_H
#define STRUCTS_H

//Heroi principal
typedef struct {
    int x;      // Posi��o x do heroi
    int y;      // Posi��o y do heroi
    int dardos; // Quantidade de dardos disponiveis para o heroi
    int pontos; // Pontos do heroi
    int vidas;  // Vida restante pro heroi
    int ciclos; // Ciclos at� se movimentar novamente
} HEROI;

typedef struct{
    int x;
    int y;
    int t_restante;
}TIRO;

// Inimigo
typedef struct {
    int x;
    int y;
    int ciclos; // Ciclos at� se movimentar novamente
    int estado; // 0 - Dormindo; 1 - Patrulhando;
    int t_sono; // Tempo que falta para dormir
} INIMIGO;

//Todos os inimigos
typedef struct {
    int qtde;
    INIMIGO listaInimigos[MAX_INIMIGOS];
} INIMIGOS;

// Informa��o sobre a sa�da do mapa
typedef struct {
    int x;
    int y;
    int ativo; // S� pode sair se a porta estiver ativada, ou seja, quando pegar a chave
} SAIDA;

typedef struct {
    int x;
    int y;
} CHAVE;

#endif // STRUCTS_H