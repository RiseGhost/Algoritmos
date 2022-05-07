#ifndef OPERACAO_H
#define OPERACAO_H

typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOAB;


void mostrarElementoAB (INFOAB X);

INFOAB criarElementoAB ();

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB (INFOAB X, INFOAB Y);

#endif