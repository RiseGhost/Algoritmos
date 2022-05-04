#include"operacaoFila.h"
#include"EADFila.h"
#include<stdio.h>

/*
Comando para compilar:
gcc aleatorio.o operacaoFila.o EADFila.o fila.c -o fila 
*/

//Retorna uma fila com N elementos do tipo INFOF gerados aleatóriamente:
PNodoFila AddElement (int N){
    PNodoFila F = criarFila();
    for (int i = 0; i < N; i++){
        INFOF X = criarElementoF();
        F = juntar(X, F);
    }
    return F;
}

//Mostrar todos os elementos de uma Fila:
void MostrarFila(PNodoFila F){
    if (F != NULL){
        mostrarElementoF(F->Elemento);
        MostrarFila(F->Prox);
    }
}

//Retorna o tamanho da lista
int length(PNodoFila F){
    int count = 0;
    while (F != NULL){
        F = F->Prox;
        count++;
    }
    return count;
}

//Devolve um Fila sem o segundo elemento
PNodoFila Remove2Element(PNodoFila F){
    PNodoFila R = criarFila();
    int tamanho = length(F);
    for (int i = 1; i <= tamanho; i++){
        if (i != 2)
            R = juntar(F->Elemento, R);
        F = F->Prox;
    }
    return R;
}

//Retorna uma Fila sem o elemento da posição N:
//Se o N > tamanho da lista ele devolve a lista F normal:
PNodoFila RemoveElement(PNodoFila F, int N){
    PNodoFila R = criarFila();
    int tamanho = length(F);
    if (N > tamanho){
        return F;
    }   else{
        for (int i = 1; i <= tamanho; i++){
            if (i != N)
                R = juntar(F->Elemento, R);
            F = F->Prox;   
        }
        return R;
    }
}

//Retorna uma Fila sem o ultima elemento:
//Atenção ele altera a Fila original.
PNodoFila RemoverUltimo(PNodoFila F){
    if (F->Prox->Prox == NULL){
        F->Prox = NULL;
    }   else{
        RemoverUltimo(F->Prox);
    }
    return F;
}

//Retorna a lista de trás para a frente:
PNodoFila Revese(PNodoFila F){
    PNodoFila R = criarFila();
    int tamanho = length(F);
    INFOF array[tamanho];
    for (int i = 0; i < tamanho; i++){
        array[i] = F->Elemento;
        F = F->Prox;
    }
    for (int i = 1; i <= tamanho; i++){
        R = juntar(array[tamanho - i],R);
    }
    return R;
}

//Retorna uma Fila com o Primeiro e ultimo elementos trocados:
PNodoFila PrimeiroUltimo(PNodoFila F){
    PNodoFila R = criarFila();
    int tamanho = length(F);
    INFOF array[tamanho];
    INFOF first = F->Elemento;
    for (int i = 1; i <= tamanho; i++){
        array[i-1] = F->Elemento;
        F = F->Prox;
    }
    INFOF last = array[tamanho - 1];
    for (int i = 0; i < tamanho; i++){
        if (i == 0)
            R = juntar(last, R);
        else if(i == tamanho - 1)
            R = juntar(first, R);
        else
            R = juntar(array[i], R);
    }
    return R;
}

int main(void){
    PNodoFila F = AddElement(10);
    MostrarFila(F);
    printf("\ntamanho -> %i\n\n", length(F));
    MostrarFila(Reverse(F));
    printf("\ntamanho -> %i\n\n", length(F));
    printf("\ntamanho -> %i\n\n", length(PrimeiroUltimo(F)));
    return 0;
}