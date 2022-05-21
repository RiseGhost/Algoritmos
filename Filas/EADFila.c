#include"EADFila.h"
#include<stdio.h>
#include<stdlib.h>
// Operações sobre o NodoFila

PNodoFila criarNodoFila (INFOF X){
  PNodoFila P;
  P = (PNodoFila) malloc(sizeof(struct NodoFila));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodoFila libertarNodoFila (PNodoFila P){
  P->Prox = NULL;
  free(P);
  P = NULL;
  return P;
}


// Operações sobre a Fila

PNodoFila criarFila (){
  PNodoFila P;
  P = NULL;
  return P;
}

int filaVazia (PNodoFila Fila){
  if (Fila == NULL)
    return 1;
  else
    return 0;
}

PNodoFila juntar (INFOF X, PNodoFila Fila){
  PNodoFila Novo, PAnt;
  Novo = criarNodoFila(X);
  if (Novo == NULL)
    return Fila;
  if (filaVazia(Fila)){
    Fila = Novo;
    return Fila;
  }
  PAnt = Fila;
  while(PAnt->Prox != NULL)
    PAnt = PAnt->Prox;
  PAnt->Prox = Novo;
  return Fila;
}


PNodoFila remover (PNodoFila Fila){
  PNodoFila P;
  P = Fila;
  Fila = Fila->Prox;
  P = libertarNodoFila(P);
  return Fila;
}


INFOF frente (PNodoFila Fila){
  return Fila->Elemento;
}


