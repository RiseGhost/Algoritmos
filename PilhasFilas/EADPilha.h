#include"operacaoPilha.h"
#ifndef EADPILHA_H
#define EADPILHA_H

struct NodoPilha {
  INFOP   Elemento;
  struct NodoPilha *Ant;
};

typedef struct NodoPilha *PNodoPilha;

// Operações sobre o NodoPilha

PNodoPilha criarNodoPilha (INFOP X);

PNodoPilha libertarNodoPilha (PNodoPilha P);


// Operações sobre a Pilha

PNodoPilha criarPilha ();

int pilhaVazia (PNodoPilha Pilha);

PNodoPilha push (INFOP X, PNodoPilha Pilha);

PNodoPilha pop (PNodoPilha Pilha);

INFOP topo (PNodoPilha Pilha);

#endif
