#include <stdio.h>
#include <stdlib.h>
int line = 0;//Variável golbal utilizada para guarda o número de linhas do ficheiro

//Retorna um array com a notas do aluno n na coordenada n - 1 do array:
int *ReadArray(int *array)
{
    FILE *f = fopen("dados3.txt", "r");
    int index = 0, aux = 0;
    while (fscanf(f, "%i %i", &aux, &array[index]) != EOF)
    {
        index++;
        array = (int *)realloc(array, sizeof(int) * (index + 1));
    }
    fclose(f);
    line = index;
    return array;
}

//Retorna a soma de todas as notas de um array de tamanho size:
int SomaNotas(int array[], int size){
    if(size == -1){
        return 0;
    }  else{
        return array[size] + SomaNotas(array, size - 1);
    }
}

//Retorna a soma de todas as notas positivas de um array de tamanho size:
int SomaNotasAprovadas(int array[], int size){
    if(size == -1){
        return 0;
    }  else{
        if (array[size] > 9){
            return array[size] + SomaNotasAprovadas(array, size - 1);
        }  else{
            return SomaNotasAprovadas(array, size - 1);
        }
    }
}

//Retorna a media de todos os alunos
double Average(int array[], double size){
    return SomaNotas(array, size)/(size + 1);
}

//Retorna a media de todos os alunos aprovados
double AverageAprovados(int array[], double size){
    return SomaNotasAprovadas(array, size)/(size + 1);
}

int main(void)
{
    int *n = (int *)calloc(1, sizeof(int));
    n = ReadArray(n);
    printf("%i\n", line);
    printf("A nota média obetida na disciplina é de: %.2f\n", Average(n, line - 1));
    printf("A nota média obetida na disciplina pelos estudantes aprovados é de: %.2f\n", AverageAprovados(n, line - 1));
    free(n);
    n = NULL;

    return 0;
}