#include <stdio.h>
#include <stdlib.h>
#include "aleatorio.h"
#include "operacaoPilha.h"
#include "EADPilha.h"

/*
Comando para compilar:
gcc operacaoPilha.o EADPilha.o aleatorio.o  pilhas.c -o pilhas
*/

//Retorna um elemento com todos os campos a zero:
INFOP zzero(){
    INFOP zero;
    zero.Data[0] = 0;
    zero.Data[1] = 0;
    zero.Data[2] = 0;
    zero.NFatura = 0;
    zero.NIF = 0;
    zero.Pagamento = 0;
    return zero; 
}

// Mostrar ao utilizador 
void mostrarPilha (PNodoPilha S){
  PNodoPilha P = S;
  while (P != NULL){
    mostrarElementoP(P->Elemento);
    P = P->Ant;
  }
}

//Criar uma pilha de tamanho N com elemtno aleatórios:
PNodoPilha criarPilhaAleatoria (int N){
    PNodoPilha P = criarPilha();
    INFOP F;
    for (int i = 0; i < N; i++)
    {
        F = criarElementoP();
        P = push(F, P);
    }
    return P;
}


//Retorna o segundo elementoo da pilha a contar do topo:
INFOP SegundoElementoTop(PNodoPilha S){
    return topo(S->Ant);
}

//Retorna o elemento N a contar o topo da pilha:
INFOP DeterminarElemento(PNodoPilha S, int N){
    PNodoPilha P = S;
    int aux = 1;
    while (P->Ant != NULL & aux < N){
        P = P->Ant;
        aux++;
    }
    return P->Elemento;
}

//Retorna o 3 elemento de uma pilha a contar do fim:
//Caso a Pilha tenha memos de 3 elementos ela devolve um elemento com NFatura igual a -1
INFOP TerceiroDoFim(PNodoPilha S){
    PNodoPilha P = S;
    INFOP x1,x2,x3;
    x1.NFatura = -1;
    x2.NFatura = -1;
    x3.NFatura = -1;
    while (pilhaVazia(P) == 0)
    {
        x3 = x2;
        x2 = x1;
        x1 = topo(P);
        P = pop(P);
    }
    return x3;
}

//Não está a funionar
PNodoPilha TrocarPrimeiroUltimo(PNodoPilha S){
    PNodoPilha P = criarPilha();
    INFOP A = topo(S), B;
    while (pilhaVazia(S) == 0)
    {
        P = push(topo(S), S);
        S = pop(S);
    }
    if(pilhaVazia(P) == 1){
        S = push(A, S);
        return S;
    }   else{
        B = topo(P);
        P = pop(P);
        while (pilhaVazia(P) == 0)
        {
            S = push(topo(P), S);
            P = pop(P);
        }
        S = push(B, S);
    }
    return S;
}

//Retorna a pilha invertida:
PNodoPilha reverse (PNodoPilha S){
    PNodoPilha Reverse = criarPilha();
    PNodoPilha aux = S;
    while (aux->Ant != NULL)
    {
        Reverse = push(topo(aux), Reverse);
        aux = aux->Ant;
    }
    Reverse = push(topo(aux), Reverse);
    return Reverse;
}

//Retorna o elemento do fundo de uma pilha, se a pilha estiver fazia retorna,
//Um elemento com todos os campos a zero
INFOP FundoPilha(PNodoPilha S){
    if (S != NULL)
    {
        PNodoPilha P = S;
        while (P->Ant != NULL){
            P = P->Ant;
        }
        return P->Elemento;
    }   else{
        return zzero();
    }    
}

int main(void){
    PNodoPilha Pilha = criarPilhaAleatoria(10);
    int N;
    mostrarPilha(Pilha);
    printf("\n");
    PNodoPilha G = criarPilha();
    //mostrarElementoP(SegundoElementoTop(Pilha));
    //mostrarElementoP(DeterminarElemento(Pilha, 5));
    //mostrarElementoP(TerceiroDoFim(Pilha));
    //mostrarPilha(TrocarPrimeiroUltimo(Pilha));
    //mostrarElementoP(FundoPilha(Pilha));

    mostrarPilha(reverse(Pilha));
    printf("\n");
    mostrarPilha(Pilha);

    return 0;
}
