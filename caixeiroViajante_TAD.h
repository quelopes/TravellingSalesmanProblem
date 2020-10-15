#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h> 
#include <time.h>

#ifndef _CAIXEIROVIAJANTE_TAD_H
#define	_CAIXEIROVIAJANTE_TAD_H

#define NUMCITY 50 /*numero de cidades para visitar*/   /*VERIFICAR NO ARQUIVO DE ENTRADA*/
#define NUMPOP 500 /*tamanho da populacao*/

struct caixeiroViajante{
   int   percurso[NUMCITY]; /*Uma rota possivel (solucao candidata)*/
   float   aptidao; /*Aptidao da solucao (Valor total do percusso somado)*/
   int   estado; /* verifica se ja foi modificado na geracao atual*/
};
typedef struct caixeiroViajante CaixeiroViajante;



/***FUNCOES RELACIONADAS A CONSTRUCAO DA MATRIZ***/
/* Cria memoria para um vetor de acordo com o número de cidades */
int *vetorCreate(int tamVet);
/* Cria matriz de ponteiros para float de acordo com o num de linhas e colunas */
float **matrixDist(int nlinhas, int ncolunas);
/*imprime matriz*/
void printMatrizDist(float **distancia);
/*fornece a */
float getMatrix(float** distance, int i, int j);
/*==============================================*/
/***FUNCOES RELACIONADAS COM LEITURA DE ARQUIVOS***/
/* Le arquivo e calcula os pares de distancias das cidades e insere na matriz*/
void matrixArq(char nomeArq[], float **distance);
/*==============================================*/
/***FUNCOES RELACIONADAS COM HEURISTICAS AGs***/
/* Gera a populacao inicial*/
void birthPop(CaixeiroViajante *populacao);
/*Imprime a populacao gerada*/
void printPop(CaixeiroViajante *populacao);
/*Avalia cada uma das rotas (individuos) na populacao*/
void fitnessPop(CaixeiroViajante *populacao, float **distance);
/*Organiza a populacao de acordo com o fitness*/
CaixeiroViajante* popSort(CaixeiroViajante* pPop);
/*funcao auxiliar da ordenacao. Compara o fitness de dois individuos*/
static int compFit(const void* a,const void* b);
CaixeiroViajante* selecao(CaixeiroViajante* pai);
CaixeiroViajante* mutacao(CaixeiroViajante* filho,int nmut);
FILE* printFile(FILE* f, int breed, CaixeiroViajante* p);
int getCity(FILE* fcity, int n, int* x, int* y);
void melhor(FILE* fcity, int breed, CaixeiroViajante* p);
#endif	/* _CAIXEIROVIAJANTE_TAD_H */