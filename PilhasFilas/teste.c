#include"operacaoFila.h"
#include"operacaoPilha.h"
#include"EADFila.h"
#include"EADPilha.h"
#include<stdio.h>

PNodoPilha AddElementP(int N){
    PNodoPilha P = criarPilha();
    for (int i = 0; i < N; i++){
        INFOP X = criarElementoP();
        P = push(X, P);
    }
    return P;
}

PNodoFila AddElementF(int N){
    PNodoFila F = criarFila();
    for (int i = 0; i < N; i++){
        INFOF X = criarElementoF();
        F = juntar(X, F);
    }
    return F;
}

void MostrarPilha(PNodoPilha P){
    if (P != NULL){
        mostrarElementoP(P->Elemento);
        MostrarPilha(P->Ant);
    }
}

int Plength(PNodoPilha P){
    if (P != NULL){
        return 1 + Plength(P->Ant);
    }   else{
        return 0;
    }
}

void MostrarFilha(PNodoFila F){
    if (F != NULL){
        mostrarElementoF(F->Elemento);
        MostrarFilha(F->Prox);
    }
}

int Flength(PNodoFila F){
    if (F != NULL){
        return 1 + Flength(F->Prox);
    }   else{
        return 0;
    }
}

INFOF convertINFOF(INFOP X){
    INFOF F;
    F.Data[0] = X.Data[0];
    F.Data[1] = X.Data[2];
    F.Data[2] = X.Data[1];
    F.NFatura = X.NFatura;
    F.NIF = X.NIF;
    F.Pagamento = X.Pagamento;
    return F;
}

INFOP convertINFOP(INFOF X){
    INFOP P;
    P.Data[0] = X.Data[0];
    P.Data[1] = X.Data[2];
    P.Data[2] = X.Data[1];
    P.NFatura = X.NFatura;
    P.NIF = X.NIF;
    P.Pagamento = X.Pagamento;
    return P;
}

//Retorna uma Fila contendo todos os elementos de um Pilha pela ordem contrária:
//Não altera a Pilha P.
PNodoFila PilhaToFila(PNodoPilha P){
    int tamanho = Plength(P);
    INFOP array[tamanho];
    for (int i = 0; i < tamanho; i++){
        array[i] = P->Elemento;
        P = P->Ant;
    }
    PNodoFila F = criarFila();
    for (int i = 1; i <= tamanho; i++){
        if (array[tamanho-i].NFatura % 2 != 0){
            F = juntar(convertINFOF(array[tamanho - i]), F);
        }
    }
    return F;
}

//Retorna uma Pilha com todos os elementos impares de um Fila mas mantendo a ordem da fila:
//Não alterar a Fila F.
PNodoPilha FilatoPilha(PNodoFila F){
    int tamanho = Flength(F);
    
    INFOF array[tamanho];
    for (int i = 0; i < tamanho; i++){
        array[i] = F->Elemento;
        F = F->Prox;
    }

    PNodoPilha P = criarPilha();
    for (int i = 1; i <= tamanho; i++){
        if (array[tamanho-i].NIF % 2 != 0){
            P = push(convertINFOP(array[tamanho - i]), P);
        }
    }
    
    return P;
}

PNodoPilha FilatoPilha1(PNodoFila F){
    int tamanho = Flength(F);
    PNodoPilha P = criarPilha();
    INFOF array[tamanho];
    for (int i = 0; i < tamanho; i++){
        array[i] = F->Elemento;
        F = F->Prox;
    }

    for (int i = 0; i < tamanho; i++){
        P = push(convertINFOP(array[i]), P);
    }
    
    return P;
}

int main(void){
    PNodoPilha P = AddElementP(10);
    PNodoFila F = AddElementF(10);
    MostrarFilha(F);
    printf("Tamanho da filha é: %i\n", Flength(F)); 
    MostrarPilha(FilatoPilha1(F));
    printf("Tamanho da pilha é: %i\n", Plength(FilatoPilha(F)));
    return 0;
}