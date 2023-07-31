<h1 align="center">Compilador</h1>

<p align="center">
  <em>Um compilador desenvolvido durante o 5º período na disciplina de Compiladores do curso de Ciência da Computação (UFRRJ).</em>
</p>

## Sobre o Projeto

Este é o repositório do compilador que implementei durante o 5º período da disciplina de Compiladores do meu curso de Ciência da Computação. O objetivo do compilador é transformar uma linguagem de programação simples em uma representação intermediária em três endereços.

## Funcionalidades

- Conversão de código-fonte da linguagem para uma representação intermediária em três endereços.
- Utilização de Bison (Yacc) e Flex (Lex) para análise sintática e léxica, respectivamente.
- Implementado em C++.

## Como Testar

Para começar, clone este repositório em seu computador:

git clone https://github.com/MaxwelLopes/Compilador.git


Navegue até o diretório do projeto, abra o arquivo "exemplo.foca" em um editor de texto de sua preferência e digite o código que deseja compilar.
Por exemplo:
            
            int i;
            int a;
            a=0;
            for(i=0;i<10;i=i+1){
                a = a + 1;
            }

No terminal, digite o comando `make all` e pressione Enter. O compilador processará o arquivo "exemplo.foca" e exibirá o código intermediário resultante diretamente no terminal:

            int t1;
            int t2;
            int t3;
            int t4;
            int t5;
            int t6;
            int t7;
            int t8;
            int t9;
            int t10;
            int t11;
            t3 = 0;
            t2 = t3;
            t4 = 0;
            t1 = t4;
            label_2:
            t5 = 10;
            t6 = t1 < t5;
            t11 = !t6;
            if(t11) goto label_1;
            t9 = 1;
            t10 = t2 + t9;
            t2 = t10;
            t7 = 1;
            t8 = t1 + t7;
            t1 = t8;
            goto label_2;
            label_1:

