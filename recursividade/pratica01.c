#include<stdio.h>
#include"Aleatorio.h"

//Função recursiva capaz de calcular base^expoente
double expo(int base, int expoente){
    if (expoente == 0){
        return 1;
    } else{
        return base * expo(base, expoente - 1);
    }
}

//Função recursiva capaz de calcular o número de caracteres de uma frase
//string -> variável que contem a frazer
//count -> variável auxiliar responsável por contar os caracteres. Sempre inicializada a zero.
int NumberCar(char string[], int count){
    if(string[count] == '\0'){
        return count;
    } else{
        return NumberCar(string, count + 1);
    }
}

//Função recursiva capaz de calcular o número de digitos de um número inteiro positivo
int NumberDigitos(float number){
    if(1 > number/10){
        return 1;
    } else{
        return 1 + NumberDigitos(number/10);
    }
}

//Função recursiva capaz de calcular o néssimo elemento da sequência de Fibonacci
double fib(int number){
    if(number == 0){
        return 0;
    } if(number == 1){
        return 1;
    } else{
        return fib(number - 1) + fib(number - 2);
    }
}

//Não esta a funcionar muito bem
int MDC(int a, int b){
    if(b == 0){
        return a;
    } else{
        return(b, a%b);
    }
}

//Retorna para o utilizador o maior elemento de um array de tamanho size.
//A variável index é utilizada para identificar o indice onde está o maior elemento, é sempre inicializada a zero.
int MaiorElemento(int array[], int size, int index){
    if(size == -1){
        return array[index];
    } else{
        if(array[size] > array[index]){
            return MaiorElemento(array, size - 1, size);
        } else{
            return MaiorElemento(array, size - 1, index);
        }
    }
}

//Retorna para o utilizador o indice do maior elemento de uma array de tamanho size
//A variável index é utilizada para identidicar o indice do maior elemento, é sempre incializada a zero.
int MaiorIndice(int array[], int size, int index){
    if(size == -1){
        return index;
    } else{
        if(array[size] > array[index]){
            return MaiorIndice(array, size - 1, size);
        } else{
            return MaiorIndice(array, size - 1, index);
        }
    }
}

//Retorna a soma de todos os elementos de array de reais de tamanho size
double AddArray(double array[], int size){
    if(size == -1){
        return 0;
    }  else{
        return  array[size] + AddArray(array, size - 1);
    }
}

//Retorna a soma de todos os elementos pares de uma array de tamanho size
int SomaPar(int array[], int size){
    if(size == -1){
        return 0;
    } else{
        if(array[size] % 2 == 0){
            return array[size] + SomaPar(array, size - 1);
        }  else{
            return SomaPar(array, size - 1);
        }
    }
}

//Retorna a média de um array de tamanho size. 
//count -> utilizada para fazer a soma de todos os valores do array, tem de ser sempre incializada a zero
//n -> variável auxiliar, tem de ser incializada a zero
double AverageArray(int array[], int size, int count, int n){
    if(n == size){
        return count/size;
    }  else{
        return AverageArray(array, size, count + array[n], n + 1);
    }
}

//Retorna o número de elementos pares de um array de tamanho size
int NumberPar(int array[], int size){
    if(size == -1){
        return 0;
    }  else{
        if(array[size] % 2 == 0){
            return 1 + NumberPar(array, size - 1);
        }  else{
            return NumberPar(array, size - 1);
        }
    }
}

//Retorna o número de elementos positivos de um array de tamanho size
int NumberPositive(int array[], int size){
    if(size <= -1){
        return 0;
    } if(array[size] > 0){
        return 1 + NumberPositive(array, size - 1);
    }  else{
        return NumberPositive(array, size - 1);
    }
}

//Retorna 1 se o número for primo e retorna 0 se o número não for primo
//aux -> variável auxiliar tem de ser sempre inicializada a zero
//Só funciona com number > 1
int primo(int number, int aux){
    if(aux == 2){
        return 1;
    }  else{
        if(number % (aux - 1) == 0){
            return 0;
        }  else{
            return primo(number, aux - 1);
        }
    }
}

//Retorna o maior elemento par de um array de tamanho size
//par -> variável auxiliar, tem de ser sempre inicializada a zero
//Só funciona com array de inteiros maior de zero
int MaiorPar(int array[], int size, int par){
    if(size == -1){
        return par;
    }  else{
        if(array[size] % 2 == 0){
            if(array[size] > par){
                return MaiorPar(array, size - 1, array[size]);
            }  else{
                return MaiorPar(array, size - 1, par);
            }
        }  else{
            return MaiorPar(array, size - 1, par);
        }
    }
}

/*

*/

int main(void){
    int vetor[50];
    for (int i = 0; i < 49; i++)
    {
        vetor[i] = gerarNumeroInteiro(15,30);
    }
    
    printf("Média do vetor é = %f\n", AverageArray(vetor, 49, 0, 0));

    for (int i = 0; i < 49; i++)
    {
        vetor[i] = gerarNumeroInteiro(-80,35);
    }

    printf("Números de elementos positivos é = %i\n", NumberPositive(vetor, 50 - 1));

    /*
    int vetor[5];
    for(int k = 0; k < 5; i++){
        v[i] = gerarumvalor(0,10);
    }
    */

    return 0;
}