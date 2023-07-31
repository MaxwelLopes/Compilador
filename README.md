<h1 align="center">Compilador</h1>

<p align="center">
  <em>Um compilador desenvolvido durante o 5º período da disciplina de Compiladores do curso de Ciência da Computação.</em>
</p>

## Sobre o Projeto

Este é o repositório do compilador que implementei durante o 5º período da disciplina de Compiladores do meu curso de Ciência da Computação. O objetivo do compilador é transformar uma linguagem de programação simples em uma representação intermediária em três endereços.

## Funcionalidades

- Conversão de código-fonte da linguagem para uma representação intermediária em três endereços.
- Utilização de Bison (Yacc) e Flex (Lex) para análise sintática e léxica, respectivamente.
- Implementado em C++.

## Como Testar

Para começar, clone este repositório em seu computador:

git clone https://github.com/MaxwelLopes/Compiladores.git


Navegue até o diretório do projeto, abra o arquivo "exemplo.foca" em um editor de texto de sua preferência e digite o código que deseja compilar.
Por exemplo:
            int a;
            a = 1 + 1;

No terminal, digite o comando `make all` e pressione Enter. O compilador processará o arquivo "exemplo.foca" e exibirá o código intermediário resultante diretamente no terminal:

            int t1;
            int t2;
            int t3;
            t2 = 1;
            t3 = 1;
            t1 = t2 + t3;
            a = t1;

