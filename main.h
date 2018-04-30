#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include <locale.h>
#include "constantes.h"
#include "structs.h"
#include "conio/conio.h"
#include "mapa.h"
#include "game.h"
#include "movimentacao.h"

typedef enum {
    PARADO = 0,
    CIMA,
    ESQUERDA,
    BAIXO,
    DIREITA
} DIRECOES;


