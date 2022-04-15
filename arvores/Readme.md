# Como está organizado esta diretoria❓:
Existem 3 ficheiros header (cabeçalho):

    aleatorio.h
    operacaoArvores.h
    EADArvores.h

Este dois ficheiros contém a declaração de funções que vão auxiliar na manipulação de arvores. O desenvolvimento das funções destes ficheiros encontram-se nos ficheiros:

    aleatorio.c
    operacaoArvores.c
    EADArvores.c

Caso haja necessidade de alterar os ficheiros headers ou os ficheiros que contém o desenvolvimento das respetivas funções será necessário usar o comando:

    gcc -c nome_do_ficheiro.c

O ficheiro principal é o __arvores.c__. Para fazer a compilação deste ficheiro será necessário utilizar o seguinte código:

    gcc aleatorio.o operacaoArvores.o EADArvores.o arvores.c -o arvores

Infelizmente não fiz um ficheiro __MakeFile__, porque esta com preguiça. 😪😓

<p>
De qualquer maneira espero que gostem. 😀😀

<p>
Qualquer dúvida enviem pelo Twitter.