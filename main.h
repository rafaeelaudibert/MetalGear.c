#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include <locale.h>
#include "constantes.h"
#include "structs.h"
#include "conio.h"
#include "mapa.h"
#include "game.h"
#include "movimentacao.h"
#include "auxiliars.h"

#ifndef ENUMS_H
#define ENUMS_H

typedef enum {
    PARADO = 0,
    CIMA,
    ESQUERDA,
    BAIXO,
    DIREITA
} DIRECOES;

#endif // ENUMS_H



