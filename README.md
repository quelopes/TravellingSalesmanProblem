---
output:
  pdf_document: default
  html_document: default
---

# Travelling Salesman Problem  

Trabalho final do curso de Computação Evolutiva

Laboratório Nacional de Computação Científica.

Professor: Hélio Barbosa

Data: Fevereiro de 2009


## Description

Metaheurística é um procedimento destinados a encontrar uma boa solução, consistindo na aplicação em cada passo, de uma heurística subordinada, a qual deve ser modelada para cada problema específico. Metaheurísticas possuem um  caratergeral e comcondições de escapar de ótimos locais. Dentre as técnicas utilizadas, encontram-se a Computação Evolutiva (CE) que incorpora princípios de evolução biológica dentro de algoritmos usados para solucionar problemas grandes e com complicadas otimizações (Foster, 2001). As linhas de pesquisa que constituem a CE são os Algoritmos Genéticos, Programação Evolutiva, Estrategia Evolutiva, Sistemas Classificadores e Programação Genética.


## Genetic Algorithms
Na busca de soluções em espaços complexos e numerosos, inspirados nos conceitos de seleção natural, reprodução diferencial, fitness, crossover mutação, surgiu o algoritmo genético proposto inicialmente por Holland e colaboradores por volta de 1976. Os algoritmos genéticos empregam uma terminologia originada da teoria da evolução natural e da genética. Um indivíduo da população é representado por um único cromossomo, o qual contém a codificação (genótipo) de uma possível solução do problema (fenótipo). Cromossomos são usualmente implementados na forma de listas de atributos ou vetores, onde cada atributo é conhecido como gene. Os possíveis valores que um determinado gene pode assumir são denominados de alelos. O processo de evolução executado por um algoritmo genético corresponde a um procedimento de busca em um espac ̧o de soluções potenciais para o problema. Dentre as vantagens no uso de AGs podemos citar: seu paralelismo inerente, simplicidade de implementação e a possibilidade de utilização para qualquer estrutura.


## Salesman Problem

Um determinado vendedor precisa encontrar o caminho mais curto dentre uma lista de cidades a serem  visitadas, devendo passar  por todas apenas uma única vez e retornar a cidade de origem. Cada cidade está ligada a uma outra por meio de uma estrada.

O problema do caixeiro viajante é considerado um problema do tipo NP-difícil, pois não tem solução deteminística polinomial. Para um número pequeno de cidades, pode-se fazer uma busca exaustiva, entretanto a medida que aumenta o número de cidades esta solução torna-se computacionalmente impraticável.


### Representation

* Cromossomo e população Inicial
* Função objetivo
* Função aptidão
* Operadores genéticos
* Critério de parada

## Program structure



## How to execute -- Executar o código



