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
    for (int i = 0; i < N; i++)
    {
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

// Devolve a soma dos Pagamentos com NIF igual a x
int SomaPagamento(PNodo L, int x)
{
    int soma = 0;
    PNodo P = L;
    while (P != NULL)
    {
        if (P->Elemento.NIF == x)
        {
            soma = soma + soma;
            P = P->Prox;
        }
        else
        {
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
    while (P != NULL)
    {
        if (P->Elemento.Pagamento > n)
        {
            pagamento = pagamento + 1;
            P = P->Prox;
        }
        else
        {
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
    while (P != NULL)
    {
        if (P->Elemento.Pagamento > maior)
        {
            maior = P->Elemento.Pagamento;
            P = P->Prox;
        }
        else
        {
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
    while (P != NULL)
    {
        if (P->Elemento.Pagamento<menor & P->Elemento.Pagamento> K)
        {
            menor = P->Elemento.Pagamento;
            P = P->Prox;
        }
        else
        {
            P = P->Prox;
        }
    }
    return menor;
}

// Devolve uma lista sem a fatura com o número fatura
PNodo RemoverFatura(PNodo L, int fatura)
{
    PNodo P = L;
    while (P != NULL)
    {
        if (fatura == P->Elemento.NFatura)
        {
            L = removerLista(P->Elemento, L);
        }
        else
        {
            P = P->Prox;
        }
    }
    return L;
}

// Retorna uma lista sem os elementos com o NIF nif:
PNodo RemoverNIF(PNodo L, int nif)
{
    PNodo P = L;
    while (P != NULL)
    {
        if (P->Elemento.NIF == nif)
        {
            L = removerLista(P->Elemento, L);
        }
        else
        {
            P = P->Prox;
        }
    }
    return L;
}

// Retorna a lista ordenada pelo NIF para o utilizador:
PNodo OrdenarNIF(PNodo L)
{
    PNodo F = L;
    PNodo P = criarLista();
    int aux = -999999999, menor = 999999999;
    for (int i = 0; i < tamanhoLista(L); i++)
    {
        while (F != NULL)
        {
            if (F->Elemento.NIF < menor && F->Elemento.NIF > aux)
                menor = F->Elemento.NIF;
            F = F->Prox;
        }
        F = L;
        while (F != NULL)
        {
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

// Retorna uma lista sem os NIF maiores ou iguais ao nif
// Recebe como argumento uma lista ordenada pelos NIF e
// um int NIF, que é o valor a partir do qual é para eleminar
PNodo RemoverNIFMaiores(PNodo L, int nif)
{
    PNodo P = L;
    while (P != NULL){
        if (P->Elemento.NIF >= nif){
            L = removerLista(P->Elemento, L);
            P = P->Prox;
        }   else{
            P = P->Prox;
        }
    }
    return L;
}

// Retorna o número de pagamentos maiores que o k1 e menores que o k2
int IntrevaloDePagamentos(PNodo L, float k1, float k2)
{
    PNodo P = L;
    int incr = 0;
    while (P != NULL){
        if (P->Elemento.Pagamento > k1 & P->Elemento.Pagamento < k2)
            incr++;
        P = P->Prox;
    }
    return incr;
}

// Retorna uma Lista com um acrescimo de k1 no pagamento da 1º metade da lista e com um acrescimo de k2 na 2º metade da lista
PNodo AcrescentaPagamento(PNodo L, float k1, float k2)
{
    PNodo P = L, F = criarLista();
    int aux = 1;
    while (P != NULL){
        if (aux < tamanhoLista(L) / 2){
            P->Elemento.Pagamento = P->Elemento.Pagamento + k1;
            F = inserirListaFim(P->Elemento, F);
        }   else{
            P->Elemento.Pagamento = P->Elemento.Pagamento + k2;
            F = inserirListaFim(P->Elemento, F);
        }
        P = P->Prox;
        aux++;
    }
    return F;
}

// Retorna uma Lista em que os primeiros e ultimos K elementos têm um acrescimo de y1 e os restantes um acrescimo y2
PNodo AcrescentaPagamentoInicioFim(PNodo L, float y1, float y2, int k)
{
    PNodo P = L, F = criarLista();
    int aux = 1;
    while (P != NULL){
        if (aux <= k | aux > k + (tamanhoLista(L) - 2 * k)){
            P->Elemento.Pagamento = P->Elemento.Pagamento + y1;
            F = inserirListaFim(P->Elemento, F);
        }   else{
            P->Elemento.Pagamento = P->Elemento.Pagamento + y2;
            F = inserirListaFim(P->Elemento, F);
        }
        P = P->Prox;
        aux++;
    }
    return F;
}

// Retorna o maior pagamento menor que um valor y
float MaiorPagamentoMenor(PNodo L, float y)
{
    PNodo P = L;
    float maior = -9999999;
    while (P != NULL){
        if (P->Elemento.Pagamento > maior & P->Elemento.Pagamento < y)
            maior = P->Elemento.Pagamento;
        P = P->Prox;
    }
    return maior;
}

// Retorna uma lista sem o primeiro e ultimo elemento.
PNodo RemoverPrimeiroUltimo(PNodo L)
{
    PNodo P = L;
    L = removerLista(P->Elemento, L);
    while (P->Prox != NULL){
        P = P->Prox;
    }
    L = removerLista(P->Elemento, L);
    P = L;
    return P;
}

// Retorna a Listade Trás para a Frente
PNodo TrasParaFrente(PNodo L)
{
    PNodo P = L, F = criarLista();
    while (P != NULL){
        F = inserirListaInicio(P->Elemento, F);
        P = P->Prox;
    }
    return F;
}

// Retorna a Lista na coordernadea index:
PNodo x(PNodo L, int index)
{
    if (index == 1)
        return L;
    else
        return x(L->Prox, index - 1);
    
}

//Retorna uma lista com e elemeto X adiciona no posição index:
PNodo InserirElemtoLista(PNodo L, INFO X, int index)
{
    PNodo P;
    if (index == 2){
        P = criarNodo(X);
        P->Prox = L->Prox;
        L->Prox = P;
    }   else
        InserirElemtoLista(L->Prox ,X ,index - 1);
    return L;
}

//Retorna a Lista com o elemento X adicionar no Penultimo lugar da lista:
PNodo Penultimo(PNodo L, INFO X)
{
    if (L->Prox->Prox == NULL){
        PNodo element = criarNodo(X);
        element->Prox = L->Prox;
        L->Prox = element;
    }   else{
        Penultimo(L->Prox, X);
    }
    return L;
}

float SomaPositiva(PNodo L){
    if (L != NULL){
        return L->Elemento.Pagamento + SomaPositiva(L->Prox);
    }   else{
        return 0;
    }
}

PNodo RemoveN(PNodo L){
    if (L != NULL)
    {
        if (L->Elemento.NIF > 1000){
            L = L->Prox->Prox;
            libertarNodo(L->Prox);
            return L;
        }   else{
            RemoveN(L->Prox);
        }
    }   else{
        return L;
    }
}

int main(void)
{
    int aux = 0;
    PNodo L = AddNElementos(25);
    // MostrarLista(L);
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
    // L = OrdenarNIF(L);
    MostrarLista(L);
    // L = RemoverNIFMaiores(L, L->Prox->Prox->Elemento.NIF);
    printf("\n\n");
    // L = AcrescentaPagamento(L, 20, 95);
    // L = AcrescentaPagamentoInicioFim(L, 10, 0, 5);
    // printf("O números de pagamentos maiores que 10 e menores que 320 são = %i\n", IntrevaloDePagamentos(L, 10, 320));
    // printf("Maior pagamento menor que 350= %f\n", MaiorPagamentoMenor(L, 350));
    // InserirElemtoLista(L, X, 25);
    mostrarListaInicio(RemoveN(L));
    printf("%i\n", tamanhoLista(L));
    printf("\nSoma dos pagamentos = %f\n", SomaPositiva(L));
    return 0;
}