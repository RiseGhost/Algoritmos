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
        //Gravação no ficheiro teste.txt o elemento da árvore.
        //Não apaga o conteudo pé existente.
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

//Retorna o Número de folhas de um árvore:
int Folhas(PNodoAB Acacia){
    if (Acacia != NULL){
       if (Acacia->Esquerda == NULL && Acacia->Direita == NULL){
            return 1;
       }
            return Folhas(Acacia->Direita) + Folhas(Acacia->Esquerda);
    }
    return 0;
}

//Retorna o Número de filhos de uma árvore:
int filhos(PNodoAB Acacia){
    if(Acacia != NULL){
        if (Acacia->Direita != NULL)
        {
            return 1 + filhos(Acacia->Direita) + filhos(Acacia->Esquerda);
        }
        if(Acacia->Esquerda != NULL){
            return 1 + filhos(Acacia->Direita) + filhos(Acacia->Esquerda);
        }
    }
    return 0;
}

//Retorna o número de elemetos da árvore:
int length(PNodoAB Acacia){
    if(Acacia != NULL){
        return 1 + length(Acacia->Esquerda) + length(Acacia->Direita);
    }
    return 0;
}

int main(void){
    PNodoAB T = gerarElemento(10);
    mostrarEmOrdemAB(T);
    printf("Número de NIF impares = %i\n", ElementosImpares(T));
    printf("\nFolhas = %i\n", Folhas(T));
    printf("Filhos = %i\n", filhos(T));
    printf("Número de elementos é = %i\n", length(T));
    return 0;
}