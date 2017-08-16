# Linhas de contorno

Projeto acadêmico que implementa a ideia de linhas de contorno aleatórias baseadas em um fator de deslocamento, a intensidade das curvas são diretamente proporcionais a esse fator. 
Essas linhas são trazidas na ideia de montanhas em três cenários possíveis (manhã, tarde e noite) que podem ser definidos pelo usuário via linha de comando ou de forma aleatória (caso não seja informado). 

### Compilando

$ gcc main.c rotinas.c


### Parâmetros de configuração em linha de código

`-d <num>` (fator deslocamento)

`-o <file>` (nome do arquivo que será gerado)

`-l <num>` (tamanho da matriz)

`-m <num>` (momento do dia que a imagem é gerada)


### Exemplos de uso

`$ ./a.out`

`$ ./a.out -d 50`

`$ ./a.out -o image.ppm`

`$ ./a.out -l 513 -m 1`

`$ ./a.out -o image.ppm -l 513`


### Valores Default

* `-d`: 100
* `-o`: image.ppm
* `-l`: 513
* `-m`: (random 1~3)


Caso queira que o programa gere um valor default para algum parâmetro, 
não o acrescente na linha de comando, exemplo:

`$ ./a.out -d 100 -o image.ppm -l 513`
_(nesse caso, o programa que decide se a imagem será de manhã, tarde ou noite)_

Caso seja inserido apenas o tamanho da imagem, o programa encontrará um valor favorável para o fator deslocamento, e visse versa.


### Valores ideais 

* `-d`:
   para valores onde **(65 <= l <= 129) usar 25**
   para valores onde **(129 < l <= 257) usar 50**
   para valores onde **(257 < l <= 513) usar 100**

   _(quanto maior for o fator deslocamento, mais acentuada será a curva da montanha)_
   _(tente usar um valor rozoável para o fator deslocamento em relação ao tamanho da matriz)_

* `-l`:
   o ideal é usar valores que sejam iguais a `2^n + 1` valores maiores que 65 para que a curva da montanha seja perceptível

* `-m`:
   use 1 pra gerar uma imagem de manhã
   use 2 pra gerar uma imagem de tarde
   use 3 pra gerar uma imagem de noite
   _(caso outros valores inteiros sejam inseridos, ou nenhum valor, o programa gera um aleatório)_


### Relatório do projeto 

Requisitos implementados: 
    
   * Realiza geração de arquivos;
   * Modularização;
   * Uso de enum, registro e tipo de dado através de typedef;
   * Uso de parâmetros por linha de código;
   * Implementação de duas linhas de contorno (manhã) , degradê (tarde) e estrelas (noite);
   * Realização da documentação do projeto.
---
_Foi pensado em implementar o projeto usando a raylib, onde a intenção era gerar uma transição das horas do dia, da manhã à noite. Estamos enviando uma versão inicial usando o raylib para gerar monstanhas aleatórias._



### Autores
        Franklin Matheus;
        Leonardo Santos;
        Univerdade Federal do Rio Grande do Norte (UFRN), Natal - RN. 

