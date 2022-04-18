#include"EADPilha.h"
#include"operacaoPilha.h"
#include<stdio.h>
#include<stdlib.h>

PNodoPilha criarNodoPilha (INFOP X){
  PNodoPilha P;
  P = (PNodoPilha) malloc(sizeof(struct NodoPilha));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Ant = NULL;
  return P;
}

PNodoPilha libertarNodoPilha (PNodoPilha P){
  P->Ant = NULL;
  free(P);
  P = NULL;
  return P;
}

// Operações sobre a Pilha

PNodoPilha criarPilha (){
  PNodoPilha P;
  P = NULL;
  return P;
}

int pilhaVazia (PNodoPilha Pilha){
  if (Pilha == NULL)
    return 1;
  else
    return 0;
}

PNodoPilha push (INFOP X, PNodoPilha Pilha){
  PNodoPilha Novo;
  Novo = criarNodoPilha(X);
  if (Novo == NULL)
    return  Pilha;
  Novo->Ant = Pilha;
  Pilha = Novo;
  return Pilha;
}

PNodoPilha pop (PNodoPilha Pilha){
  PNodoPilha PAux;
  PAux = Pilha;
  Pilha = Pilha->Ant;
  PAux = libertarNodoPilha(PAux);
  return Pilha;
}

INFOP topo (PNodoPilha Pilha){
  return Pilha->Elemento;
}

