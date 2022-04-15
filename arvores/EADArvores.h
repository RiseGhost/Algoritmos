#include"operacaoArvores.h"
#ifndef EADARVORES_H
#define EADARVORES_H

struct NodoAB {
  INFOAB  Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

// Operações sobre o Nodo

PNodoAB criarNodoAB(INFOAB X);
PNodoAB libertarNodoAB(PNodoAB P);

// Operações sobre a EAD Árvore Binária

PNodoAB criarAB();
PNodoAB destruirAB(PNodoAB T);
int ABVazia(PNodoAB T);
int numeroNodosAB (PNodoAB T);
int alturaAB (PNodoAB T);
void mostrarEmOrdemAB (PNodoAB T);
void mostrarPreOrdemAB (PNodoAB T);
void mostrarPosOrdemAB (PNodoAB T);
PNodoAB pesquisarAB (INFOAB X, PNodoAB T);

// inserir de forma que fique o mais possível equilibrada
PNodoAB inserirPorAlturaAB (INFOAB X, PNodoAB T);
PNodoAB procurarFolhaAB (PNodoAB T, INFOAB *X);
PNodoAB removerNodoAB (PNodoAB T);

//  X está na árvore binária T
PNodoAB removerAB (INFOAB X, PNodoAB T);

#endif