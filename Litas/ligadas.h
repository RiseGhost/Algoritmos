#include"operacao.h"
#ifndef LIGADAS_H
#define LIGADAS_H

struct Nodo {
  INFO   Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

PNodo criarLista ();
PNodo criarNodo (INFO X);
void libertarNodo (PNodo P);
int listaVazia (PNodo L);
void mostrarListaInicio (PNodo L);
void mostrarListaInicioRec (PNodo L);
void mostrarListaFimRec (PNodo L);
int tamanhoLista (PNodo L);
int tamanhoListaRec (PNodo L);
int pesquisarLista (INFO X, PNodo L);
int pesquisarListaRec (INFO X, PNodo L);
PNodo procurarAntecessor (INFO X, PNodo L);
PNodo procurarAntecessorRec (INFO X, PNodo L);
PNodo inserirListaInicio (INFO X, PNodo L);
PNodo inserirListaFim (INFO X, PNodo L);
PNodo inserirListaFimRec (INFO X, PNodo L);
PNodo procurarAntecessorOrdem (INFO X, PNodo L);
PNodo inserirListaOrdem (INFO X, PNodo L);
PNodo removerLista (INFO X, PNodo L);
PNodo removerListaRec (INFO X, PNodo L, PNodo LAux);

#endif