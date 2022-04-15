#ifndef OPERACAOARVORES_H
#define OPERACAOARVORES_H

typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOAB;

void mostrarElementoAB (INFOAB X);
INFOAB criarElementoAB ();
int compararElementosAB (INFOAB X, INFOAB Y);

#endif