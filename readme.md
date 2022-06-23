# Instruções
 - Todos os arquivos .h estão dentro do diretório "include".
 - Todos os arquivos .c estão dentro do diretório "src".
 - O diretório "objets" será criado temporariamente toda vez que compilarmos o programa.
 - O arquivo executável estará no diretório raíz e terá nome "edcare.out".

## Comandos
 - "make" -> compilar os arquivos
 - "make clean" -> remover os arquivos temporários.
 - "make run r=<qtd>" -> exeutar o programa (No lugar de "<qtd>", passar a quantidade de leituras do sensor).
 - "make again" -> limpar, compilar e exeutar o programa novamente.
 - "make valgrind r=<qtd>" -> passar o valgrind sobre o executável que está no diretório raíz (substituir "<qtd>" pela quantidade de leituras do sensor).

### Observação
 - O programa também pode ser exeutado sem o makefile, basta digitar ./edcare.out <qtd> (substituir o "<qtd>"
 pela quantidade de leituras do sensor).
 - Para executar o programa, as entradas dos testes deverão estar no diretório raíz.
 - As saídas geradas pelo programa serão encaminhadas também para o diretório raíz.