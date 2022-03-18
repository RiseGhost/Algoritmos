#include <stdio.h>
#include "ligadas.h"
#include "operacao.h"
#include "aleatorio.h"

// gcc aleatorio.o operacao.o ligadas.o listas.c -o listas

// Função que recebe um inteiro N e gera N info diferentes
// e guarda-os numa Lista L:
PNodo AddNElementos(int N)
{
    PNodo L;
    L = criarLista();
    INFO f;
    for (int i = 0; i < N; i++){
        f = criarElemento();
        L = inserirListaFim(f, L);
    }
    return L;
}

void MostrarLista(PNodo L)
{
    printf("Do inicio para o fim:\n");
    mostrarListaInicio(L);
    // printf("Do fim para o inicio:\n");
    // mostrarListaFimRec(L);
}

// DEvolve a soma dos Pagamentos com NIF igual a x
int SomaPagamento(PNodo L, int x)
{
    int soma = 0;
    PNodo P = L;
    while (P != NULL){
        if (P->Elemento.NIF == x){
            soma = soma + soma;
            P = P->Prox;
        }
        else{
            P = P->Prox;
        }
    }
    return soma;
}

// Devolve o número de pagamentos superiores a um n
int TotalPagamento(PNodo L, int n)
{
    int pagamento = 0;
    PNodo P = L;
    while (P != NULL){
        if (P->Elemento.Pagamento > n){
            pagamento = pagamento + 1;
            P = P->Prox;
        }
        else{
            P = P->Prox;
        }
    }
    return pagamento;
}

// Devolve o maior valor do Pagamento
float MaiorPagamento(PNodo L)
{
    float maior = -999999;
    PNodo P = L;
    while (P != NULL){
        if (P->Elemento.Pagamento > maior){
            maior = P->Elemento.Pagamento;
            P = P->Prox;
        }
        else{
            P = P->Prox;
        }
    }
    return maior;
}

// Devolve o menor Pagamento mairo que um K:
float MenorPagamento(PNodo L, int K)
{
    float menor = 999999;
    PNodo P = L;
    while (P != NULL){
        if (P->Elemento.Pagamento<menor & P->Elemento.Pagamento> K){
            menor = P->Elemento.Pagamento;
            P = P->Prox;
        }
        else{
            P = P->Prox;
        }
    }
    return menor;
}

// Devolve uma lista sem a fatura com o número fatura
PNodo RemoverFatura(PNodo L, int fatura)
{
    PNodo P = L;
    while (P != NULL){
        if (fatura == P->Elemento.NFatura){
            L = removerLista(P->Elemento, L);
        }
        else{
            P = P->Prox;
        }
    }
    return L;
}

// Retorna uma lista sem os elementos com o NIF nif:
PNodo RemoverNIF(PNodo L, int nif)
{
    PNodo P = L;
    while (P != NULL){
        if (P->Elemento.NIF == nif){
            L = removerLista(P->Elemento, L);
        }
        else{
            P = P->Prox;
        }
    }
    return L;
}

//Retorna a lista ordenada pelo NIF para o utilizador:
PNodo OrdenarNIF(PNodo L)
{
    PNodo F = L;
    PNodo P = criarLista();
    int aux = -999999999, menor = 999999999;
    for (int i = 0; i < tamanhoLista(L); i++){
        while (F != NULL){
            if (F->Elemento.NIF < menor && F->Elemento.NIF > aux)
                menor = F->Elemento.NIF;
            F = F->Prox;
        }
        F = L;
        while (F != NULL){
            if (F->Elemento.NIF == menor)
                P = inserirListaFim(F->Elemento, P);
            F = F->Prox;
        }
        aux = menor;
        F = L;
        menor = 999999999;
    }
    return P;
}

int main(void)
{
    int aux = 0;
    PNodo L = AddNElementos(100);
    //MostrarLista(L);
    printf("Tamanho da lista = %i\n", tamanhoLista(L));
    /* while (SomaPagamento(L, aux) == 0)
     {
         aux = gerarNumeroInteiro(100000, 110000);
     }
     printf("\naux = %i\n", aux);*/
    // printf("%i\n", SomaPagamento(L, aux));
    // printf("%i\n", TotalPagamento(L, 100));
    // printf("O maior pagamento é: %f\n", MaiorPagamento(L));
    // printf("%d\n",L->Elemento.NIF);
    // L = RemoverNIF(L, L->Elemento.NIF);
    // L = RemoverFatura(L, L->Elemento.NFatura);
    // L = RemoverFatura(L, L->Prox->Elemento.NFatura);
    // L = RemoverNIF(L, L->Elemento.NIF);
    // L = RemoverNIF(L, L->Prox->Elemento.NIF);
    L = OrdenarNIF(L);
    MostrarLista(L);
    printf("\n\n");
    // MostrarLista(L);
    printf("Tamanho da lista = %i\n", tamanhoLista(L));
    return 0;
}