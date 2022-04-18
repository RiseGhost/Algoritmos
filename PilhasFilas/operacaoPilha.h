#ifndef OPERACAOPILHA_H
#define OPERACAOPILHA_H

typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOP;

void mostrarElementoP (INFOP X);
INFOP criarElementoP ();
int compararElementosP (INFOP X, INFOP Y);

#endif