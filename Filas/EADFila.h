#include"operacaoFila.h"
#ifndef EADFILA_H
#define EADFILA_H

struct NodoFila {
  INFOF Elemento;
  struct NodoFila *Prox;
};

typedef struct NodoFila *PNodoFila;

// Operações sobre o NodoFila

PNodoFila criarNodoFila (INFOF X);

PNodoFila libertarNodoFila (PNodoFila P);

// Operações sobre a Fila

PNodoFila criarFila ();

int filaVazia (PNodoFila Fila);

PNodoFila juntar (INFOF X, PNodoFila Fila);

PNodoFila remover (PNodoFila Fila);


INFOF frente (PNodoFila Fila);

#endif