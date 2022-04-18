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

//Retorna o número de elemento com NIF impares:
int ElementosImpares(PNodoAB A){
    if (A != NULL){
        if (A->Elemento.NIF % 2 != 0){
            return 1 + ElementosImpares(A->Direita) + ElementosImpares(A->Esquerda);
        }   else{
            return ElementosImpares(A->Direita) + ElementosImpares(A->Esquerda);
        }
    }
    return 0;
}

//Retorna o Número de filhos de um árvore:
int Filhos(PNodoAB Acacia){
    if (Acacia != NULL){
       if (Acacia->Esquerda == NULL & Acacia->Esquerda == NULL){
            return 1;
       }
            return Filhos(Acacia->Direita) + Filhos(Acacia->Esquerda);
    }
    return 0;
}

int main(void){
    PNodoAB T = gerarElemento(10);
    mostrarEmOrdemAB(T);
    printf("\n número de nodos = %i\n", numeroNodosAB(T));
    printf("Número de NIF impares = %i\n", ElementosImpares(T));
    printf("\nFilhos = %i\n", Filhos(T));
    return 0;
}