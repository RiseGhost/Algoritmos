#include"aleatorio.h"
#include"operacao.h"
#include"EADArvores.h"
#include"Pesquisa.h"
#include<stdio.h>

/*
    Comando para compilar:
    gcc aleatorio.o operacao.o EADArvores.o Pesquisa.o arvore.c -o arvore
*/

//Criar uma árvore com N elementos aleatórios:
PNodoAB Add(int N){
    PNodoAB T = criarAB();
    for (int i = 0; i < N; i++){
        INFOAB X = criarElementoAB();
        T = inserirABP(X, T);
    }
    return T;
}

//Mostrar todos os elementos de uma árvore binária:
void imprimir(PNodoAB T){
    if(T != NULL){
        mostrarElementoAB(T->Elemento);
        imprimir(T->Direita);
        imprimir(T->Esquerda);
    }
}

//Retorna o número de elementos da árvore:
int ElementNumber(PNodoAB T){
    if(T != NULL){
        return 1 + ElementNumber(T->Esquerda) + ElementNumber(T->Direita);
    }   else{
        return 0;
    }
}

//Retorna o Maior elemento da chave NFatura:
int MaiorNFatura(PNodoAB T){
    if(T->Direita != NULL){
        MaiorNFatura(T->Direita);
    }else{
        return T->Elemento.NFatura;
    }
}

//Retorna o Menor elemento da chave NFatura:
int MenorNFatura(PNodoAB T){
    if(T->Esquerda != NULL){
        MenorNFatura(T->Esquerda);
    }   else{
        return T->Elemento.NFatura;
    }
}

//Retorna o número de valores de NFatura maiores que um N:
int MaiorqueN(PNodoAB T, int N){
    if(T != NULL){
        if(T->Elemento.NFatura > N){
            return 1 + ElementNumber(T->Direita) + MaiorqueN(T->Esquerda, N);
        }   else{
            return MaiorqueN(T->Direita, N);
        }
    }   else{
        return 0;
    }
}

//Retorna o Nodo que contém a NFatura igual ao N, se esse nodo não existir ele retorna NULL:
PNodoAB PesquisaElemento(PNodoAB T, int N){
    if(T != NULL){
        if(T->Elemento.NFatura == N){
            return T;
        }   else if(N > T->Elemento.NFatura){
            PesquisaElemento(T->Direita, N);
        }   else{
            PesquisaElemento(T->Esquerda, N);
        }
    }   else{
        return NULL;
    }
}

int main(void){
    PNodoAB T = Add(10);
    imprimir(T);
    printf("O número de elementos da árvore é: %d\n", ElementNumber(T));
    printf("A maior NFatura é: %d\n", MaiorNFatura(T));
    printf("A menor NFatura é: %d\n", MenorNFatura(T));
    printf("Existe %d valores maiores que 1450\n", MaiorqueN(T, 1450));
    printf("%d\n", PesquisaElemento(T, T->Direita->Elemento.NFatura)->Elemento.NFatura);
    return 0;
}