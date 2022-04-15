#include"aleatorio.h"
#include"EADArvores.h"
#include"operacaoArvores.h"
#include<stdio.h>

/*
Código para compilar:
gcc aleatorio.o operacaoArvores.o EADArvores.o arvores.c -o arvores
*/

//Dado um inteiro N devolve uma arvore com N elemento gerados aleatóriamente:
PNodoAB gerarElemento(int N){
    PNodoAB T = criarAB();
    for (int i = 0; i < N; i++)
    {
        INFOAB X = criarElementoAB();
        T = inserirPorAlturaAB(X, T);
    }
    return T;
}

//Gravar os elemento da árvore nem um ficheiro
void GravarArvore(PNodoAB Acacia, char *ficheiro){
    FILE *F = fopen(ficheiro, "a");
    if (Acacia != NULL)
    {
        fprintf(F, "%d \n", Acacia->Elemento.NIF);
        GravarArvore(Acacia->Esquerda, ficheiro);
        GravarArvore(Acacia->Direita, ficheiro);
    }
}

int ElementosImpares(PNodoAB A){
    int numEsq, numDir;
    if (A == NULL)
        return 0;
    if (A->Elemento.NIF % 2 == 0)
    {
        numEsq = numeroNodosAB(A->Esquerda) - 1;
    }   else{
        numEsq = numeroNodosAB(A->Esquerda);
    }
    if (A->Elemento.NIF % 2 == 0)
    {
        numDir = numeroNodosAB(A->Direita) - 1;
    }   else{
        numDir = numeroNodosAB(A->Direita);
    }
    return 1 + numEsq + numDir;
}

int main(void){
    PNodoAB T = gerarElemento(20);
    mostrarEmOrdemAB(T);
    printf("\n número de nodos = %i\n", numeroNodosAB(T));
    printf("Número de NIF impares = %i\n", ElementosImpares(T));
    GravarArvore(T, "teste.txt");
    return 0;
}