#ifndef OPERACAOFILA_H
#define OPERACAOFILA_H

typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOF;

void mostrarElementoF (INFOF X);

INFOF criarElementoF ();

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosF (INFOF X, INFOF Y);

#endif