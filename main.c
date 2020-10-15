/*==============================================
Problema do Caixeiro Viajante resolvido com Algoritmo genetico
e crossover do tipo: 
Autor: 
 * Raquel lopes
versao 0.2
data: 04/02/09
LNCC Laboratorio Nacional de Computacao Cientifica 
==============================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h> 
#include <time.h>

#include "caixeiroViajante_TAD.h"
#define MAXBREED 1001 /*numero maximo de geracoes*/

/*--------------------------------------------*/
int main(int argc, char** argv){
   
    int *vet; /*vetor*/  
    float **dist;  /* matriz de distancias entre as cidades*/
    int j, nBreed=1;
    FILE* fp = fopen("data.txt","wt");
    if(!fp){
	printf("Erro ao abrir arquivo de saida\n");
    	exit(1);
    }
    vet = vetorCreate (NUMPOP); /*retorna o vetor alocado dinamicamente de acordo com o numero de cidades*/
    dist = matrixDist(NUMCITY, NUMCITY); /*retorna uma matriz alocada para calculo das distancias entre as cidades*/
    matrixArq("city50.txt", dist); /*le o arquivo com as cidades e cordenada (xy), calcula pares de distancias entre as cidades*/
    printMatrizDist(dist); /*imprime valores da matriz de distancia calculados*/
    
    /*AGs*/
    CaixeiroViajante populacao[NUMPOP]; /*cria a populacao inicial (vazia) com um conjunto de solucoes candidatas*/
    birthPop(populacao); /*nasce a populacao inicial com individuos*/
    fitnessPop(populacao, dist); /*avalia a aptidao de todos os individuos na populacao*/
    CaixeiroViajante *filho, *ptPop = populacao; /*ponteiro para vetor populacao*/
    ptPop = popSort(ptPop); /*ordena populacao por aptidao (ordem decrescente)*/
    /*testes com fitness pop*/
    printPop(populacao); /*imprime a populacao gerada com aptidao*/
    
    while (nBreed < MAXBREED){
    	filho = selecao(ptPop);
	filho = mutacao(filho,rand()%(NUMPOP/2));
	fitnessPop(filho, dist); /*avalia a aptidao de todos os individuos na populacao*/
	fp= printFile(fp,nBreed, filho);//saida em arquivo
	if(nBreed%250 == 0)
		melhor(fp, nBreed, filho);
     	ptPop = popSort(filho); /*ordena populacao por aptidao (ordem decrescente)*/
    	printf("Geração: %d\n",nBreed);
     	nBreed++;
    }
    
    printf("\nFIM DA SIMULACAO\nMelhor solucao encontrada...");
    printf("\nAptidao do percurso: %f \n", populacao[0].aptidao);
    printf("Percurso: ");
       for (j=0; j<NUMCITY; j++){
         printf("%d ", populacao[0].percurso[j]); 
        }
    printf("\n\n");

return (EXIT_SUCCESS);
}
/*==============================================*/
