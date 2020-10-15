#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h> 
#include <time.h>

#include "caixeiroViajante_TAD.h"

#define NUMCITY 50

/*==============================================*/
/*** Cria memoria para um vetor de acordo com o número de cidades */
int *vetorCreate(int tamVet){
   
    int *vetor;
    vetor = (int*)malloc(tamVet*sizeof(int));
    if (!vetor){
  	printf("Falta memória para alocar o vetor de ponteiros");
        exit(1);
    }
  return vetor;
}
/*==============================================*/
/*** Cria matriz de ponteiros para float de acordo com o num de linhas e colunas */
float **matrixDist(int nlinhas, int ncolunas){
    
    int i;
    float **matrix;
    matrix = (float**)malloc(nlinhas*sizeof(float*));
    if (!matrix) {
       printf("Falta memória para alocar a matriz de ponteiros\n");
       exit(1);
    }
    for (i=0; i< nlinhas; i++) {
       matrix[i] = (float*)malloc(ncolunas*sizeof(float));
       if (!matrix[i]){
       printf("Falta memória para alocar a matriz de ponteiros.\n");
       exit(1);
       }
    }
  return matrix;
}
/*==============================================*/
/*** Le arquivo e calcula os pares de distancias d_ij das cidades e insere na matriz*/
void matrixArq(char nomeArq[], float **distance){
    
  int *vetorX, *vetorY; 
  int x, y, i, j;
  float xi, yi;
  FILE *arq;

  vetorX = vetorCreate(NUMCITY);/*cria vetor para inserir coordenadas X*/
  vetorY = vetorCreate(NUMCITY);/*cria vetor para inserir coordenadas Y*/
  
  arq = fopen(nomeArq,"r");
  
  if (!arq) {
     printf("O Arquivo %s nao pode ser aberto.\n", nomeArq);
//      getchar();
     exit(1);
  }
  while (!feof(arq)){
     fscanf(arq, "%d %d %d", &i, &x, &y);
     vetorX[i] = x;
     vetorY[i] = y;
  }
  /*matriz de distancias calculado a partir das distancias euclidianas dos pontos xy*/
  for(i=0; i <NUMCITY-1; i++) {
     distance[i][i] = 0;
     for(j=i+1; j <NUMCITY; j++){
        xi= (float)pow((vetorX[i]- vetorX[j]),2);
        yi= (float)pow((vetorY[i]- vetorY[j]),2);
        distance[i][j]= sqrt(xi+ yi);
        distance[j][i] = distance[i][j]; /*pq a matriz é simetrica*/
      }
   }
  fclose(arq);
  
  free(vetorX); /*libera a memoria dos vetores */
  free(vetorY);
}
/*==============================================*/
void printMatrizDist(float **distancia){

int i, j;
float valor;
  for(i=0; i <NUMCITY- 1; i++) {
    for(j=i+1; j <NUMCITY; j++){
      valor= distancia[i][j]; //conteudo da matriz valor da distancia
      printf("\nvalor da coordenada x: %d Y: %d -> %f\n", i, j, valor);
    }
  }
}
/*==============================================*/
float getMatrix(float** distance, int i, int j){

  float valor;
  return (valor= distance[i][j]);
}




