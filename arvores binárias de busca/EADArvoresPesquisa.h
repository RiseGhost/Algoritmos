#include"operacao.h"
#include"aleatorio.h"
#include"EADArvores.h"
#ifndef EADARVORESPESQUISA_H
#define EADARVORESPESQUISA_H

// Operações sobre ABP cuja chave é o campo "NFatura"
int pesquisarABP (INFOAB X, PNodoAB T);

PNodoAB inserirABP (INFOAB X, PNodoAB T);

PNodoAB substituirNodoDireita (PNodoAB T, INFOAB *X);

PNodoAB substituirNodoEsquerda (PNodoAB T, INFOAB *X);

PNodoAB removerNodoABP (PNodoAB T);

PNodoAB removerABP (INFOAB X, PNodoAB T)

#endif