# Como está organizado esta diretoria❓:
Existem 3 ficheiros header (cabeçalho):

    aleatorio.h
    operacaoFila.h
    EADFila.h

Este 3 ficheiros contém a declaração de funções que vão auxiliar na manipulação de Filas. O desenvolvimento das funções destes ficheiros encontram-se nos ficheiros:

    aleatorio.c
    operacaoFila.c
    EADFila.c

Caso haja necessidade de alterar os ficheiros headers ou os ficheiros que contém o desenvolvimento das respetivas funções será necessário usar o comando:

    gcc -c nome_do_ficheiro.c

O ficheiro principal é o __fila.c__. Para fazer a compilação deste ficheiro será necessário utilizar o seguinte código:

    gcc aleatorio.o operacaoFila.o EADFila.o fila.c -o fila

Infelizmente não fiz um ficheiro __MakeFile__, porque esta com preguiça. 😪😓

<p>
De qualquer maneira espero que gostem. 😀😀

<p>
Qualquer dúvida enviem pelo Twitter.