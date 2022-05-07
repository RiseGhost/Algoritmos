#include"operacaoFila.h"
#include"EADFila.h"
#include<stdio.h>

/*
Comando para compilar:
gcc aleatorio.o operacaoFila.o EADFila.o fila.c -o fila
*/

/*
    Vou considerar que as filas começam da posição zero:
*/

//Retorna uma Fila com N elementos gerados aleatóriamente:
PNodoFila AddElemento(int N){
    PNodoFila F = criarFila();
    for(int i = 0; i < N; i++){
        INFOF X = criarElementoF();
        F = juntar(X, F);
    }
    return F;
}

//Mostra todos os elementos de uma Fila F:
void mostrar(PNodoFila F){
    if (F != NULL){
        mostrarElementoF(F->Elemento);
        mostrar(F->Prox);
    }
}

//Retorna o tamanho de uma Fila:
int length(PNodoFila F){
    int count = 0;
    while(F != NULL){
        F = F->Prox;
        count++;
    }
    return count;
}

//Remove o segundo elemento de uma Fila, mas altera a Fila original:
PNodoFila remover2(PNodoFila F){
    if(F->Prox->Prox != NULL && F->Prox->Prox->Prox != NULL){
        F->Prox->Prox = F->Prox->Prox->Prox;
    }
    return F;
}

//Remove o segundo elemento de uma Fila, mas não altera a Fila original:
PNodoFila Remover2(PNodoFila F){
    PNodoFila B = criarFila();
    int size = length(F);
    for(int i = 0; i < size; i++){
        if(i != 2){
            B = juntar(F->Elemento, B);
        }
        F = F->Prox;
    }
    return B;
}

//Remove o elemento que esta no posição N da Fila, mas altera a fila original:
//Se o utilizador colcoar um valor de Q > length(Fila) ela retorna a fila original
PNodoFila removeN(PNodoFila F, int Q){
    if (F != NULL){
        if (Q != 0){
            removeN(F->Prox, Q - 1);
        }else{
            F->Prox = F->Prox->Prox;
            removeN(F->Prox, Q - 1);
        }
    }
    return F;
}

//Remove o elemento que esta na posição N da Fila, mas não altera a fila original:
PNodoFila RemoveN(PNodoFila F, int Q){
    PNodoFila B = criarFila();
    int size = length(F);
    for (int i = 0; i < size; i++){
        if (i != Q){
            B = juntar(F->Elemento, B);
        }
        F = F->Prox;
    }
    return B;
}

//Remove o útlimo elemento da Fila, mas altera a fila original:
PNodoFila removeLast(PNodoFila F){
    while (F->Prox->Prox != NULL){
        F = F->Prox;
    }
    F->Prox = NULL;
    return F;
}

//Remove o último elemento da Fila, mas não altera a fila original:
PNodoFila RemoveLast(PNodoFila F){
    PNodoFila B = criarFila();
    while (F->Prox != NULL)
    {
        B = juntar(F->Elemento, B);
        F = F->Prox;
    }
    return B;
}

//Remove o antepenultimo elemento da Fila, mas altera a fila original:
PNodoFila removeAntePenultimo(PNodoFila F){
    int size = length(F);
    for (int i = 0; i < size - 1; i++){
        if (i == size - 3){
            F->Prox = F->Prox->Prox;
        }   else{
            F = F->Prox;
        }
    }
    return F;
}

PNodoFila RemoveAntePenultimo(PNodoFila F){
    PNodoFila B = criarFila();
    int size = length(F);
    for (int i = 0; i < size; i++){
        if(i != size - 3){
            B = juntar(F->Elemento, B);
        }
        F = F->Prox;
    }
    return B;
}

int main(void){
    PNodoFila Fila = AddElemento(15);
    mostrar(Fila);
    printf("size -> %i\n", length(Fila));
    PNodoFila B = RemoveAntePenultimo(Fila);
    printf("\n+++++++++++++\n\n");
    mostrar(B);
    printf("size -> %i\n", length(B));
    return 0;
}