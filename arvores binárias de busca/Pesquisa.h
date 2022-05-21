#include"EADArvores.h"
#ifndef PESQUISA_H
#define PESQUISA_H
// Operações sobre ABP cuja chave é o campo "NFatura"

int pesquisarABP (INFOAB X, PNodoAB T);
PNodoAB inserirABP (INFOAB X, PNodoAB T);
PNodoAB substituirNodoDireita (PNodoAB T, INFOAB *X);
PNodoAB substituirNodoEsquerda (PNodoAB T, INFOAB *X);
PNodoAB removerNodoABP (PNodoAB T);
PNodoAB removerABP (INFOAB X, PNodoAB T);

#endif