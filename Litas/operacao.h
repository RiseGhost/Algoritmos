#include"aleatorio.h"
#ifndef OPERACAO_H
#define OPERACAO_H

typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFO;

void mostrarElemento (INFO X);
INFO criarElemento ();
int compararElementos (INFO X, INFO Y);
#endif