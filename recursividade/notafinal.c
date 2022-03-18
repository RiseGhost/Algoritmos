#include<stdio.h>
#include<stdlib.h>
int line = 0;//variável auxiliar utilizada para guarda o número de linhas do ficheiro

//Retorna um array contendo as notas finais do alunos. A nota do aluno n está na linha n - 1 do array:
int *ReadArray(int *array){
    FILE *f = fopen("dados4.txt", "r");
    int StudentNumber, Work, Teste, index = 0;
    while (fscanf(f, "%i %i %i", &StudentNumber, &Work, &Teste) != EOF){
        array[index] = Work + Teste;
        array = (int*) realloc(array, sizeof(int) * (index + 2));
        index++;
    }
    line = index;
    return array;
}

//Retorna o número de alunos que passaram a disciplina:
int CalcularAprovados(int array[], int size){
    if(size == -1){
        return 0;
    }  else{
        if(array[size] > 10){
            return 1 + CalcularAprovados(array, size - 1);
        }  else{
            return CalcularAprovados(array, size - 1);
        }
    }
}

int main(void){
    int *array = (int *) calloc(1, sizeof(int));
    array = ReadArray(array);    
    printf("O número de alunos aprovados é = %i\n", CalcularAprovados(array, line - 1));
    free(array);
    array = NULL;
    return 0;
}