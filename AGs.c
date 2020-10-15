#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h> 
#include <time.h>

#include "caixeiroViajante_TAD.h"

#define NUMCITY 50 /*numero de cidades para visitar*/   /*VERIFICAR NO ARQUIVO DE ENTRADA*/
#define NUMPOP 500 /*tamanho da populacao*/

/* Gera a populacao inicial*/
void birthPop(CaixeiroViajante *populacao){
   
  int i; //contador para a populacao;
  int j,k; 
  int sort, quantos;
  int check=1; //parametro para ajudar a verificar se determinada cid ja foi sorteada;
  srand((unsigned) time(NULL)/2); //sorteia um numero aleatorio
 
  for(i=0; i<NUMPOP; i++){
    j=0;
    quantos=0;
    while (j < NUMCITY){
      sort = rand()%NUMCITY;
      for (k=0; k<quantos; k++) //o K aqui nao tem que ter o sinal =???
        if (populacao[i].percurso[k] == sort){ /*cidade ja sorteada*/
          check = 0; //pq isto??
	}
        if(check){
          populacao[i].percurso[j] = sort;
          populacao[i].estado = 0;
          quantos++;
          j++;
        }
        check= 1;
     }
   // fitness (populacao, i, numPop);
   }
}
/*==============================================*/
/*Imprime a populacao gerada*/
void printPop(CaixeiroViajante *populacao){
    
    int i, j;
    for (i=0; i<NUMPOP; i++){
       j=0; //vou retirar
       printf("\n\nNumero do individuo da solucao candidata: %d\n", i);
       printf("Aptidao do percurso: %f \n", populacao[i].aptidao);
       printf("Percurso: ");
       for (j=0; j<NUMCITY; j++){
         printf("%d ", populacao[i].percurso[j]); 
        }
    }
    printf("\n");
}
/*==============================================*/
/*Avalia a aptidao de toda a populacao*/
void fitnessPop(CaixeiroViajante *populacao, float **distance){

    int i, j;
    float apt; /*valor da aptidao*/
    for (i=0; i<NUMPOP; i++){
       apt= 0;
       j=0;//vou retirar
      for (j=0; j<NUMCITY; j++){
          if(j==NUMCITY -1){ /*ultimo elemento no vetor*/
            apt= apt + getMatrix(distance, populacao[i].percurso[j], populacao[i].percurso[0]);/*retorno a cidade de origem*/ 
	    populacao[i].aptidao = apt;
	  }  
	  else
            apt = apt + getMatrix(distance, populacao[i].percurso[j], populacao[i].percurso[j+1]);
      }
    }
}
/*==============================================*/
/*Funcao para ordenar populacao*/
CaixeiroViajante* popSort(CaixeiroViajante* pPop){
  
  printf("Organizando o vetor em ordem decrescente de acordo com o fitness...");
  qsort(pPop,NUMPOP,sizeof(CaixeiroViajante),compFit);
  //printf("done\n");
  return pPop;
}
/*==============================================*/
/*funcao auxiliar da ordenacao. Compara o fitness de dois individuos*/
static int compFit(const void* a,const void* b){ 
  
  CaixeiroViajante *pt1= (CaixeiroViajante*)a;
  CaixeiroViajante *pt2= (CaixeiroViajante*)b;
  if(pt1->aptidao < pt2->aptidao) 
     return -1;
  else if(pt1->aptidao > pt2->aptidao) 
     return 1;
  else 
     return 0;
}
/*==============================================*/
CaixeiroViajante* selecao(CaixeiroViajante* pai){//recebe ponteiro para pai e retorna para filho
	CaixeiroViajante* filho = (CaixeiroViajante*) malloc(sizeof(CaixeiroViajante)*NUMPOP);
	printf("Aplicando selecao...");

	for(int i=0; i<NUMPOP/2; i++)
		filho[i] = pai[i];
	for(int i=0; i<NUMPOP/2; i++){
		for(int j=NUMPOP/2; j<NUMPOP; j++){
			filho[j] = pai[i];
			i++;
		}
	}
	printf("feito\n");
	return filho;
}
/*==============================================*/

CaixeiroViajante* mutacao(CaixeiroViajante* filho,int n){//novo operador de mutacao
	int temp;
	int a, b1,b2;
	printf("Aplicando mutacao...");
	for(int i=0; i<n; i++){
		a = rand()%(NUMPOP);//mutacao atinge somente a primeira metade do vetor 'filho'
		b1 = rand()%NUMCITY;
		b2 = rand()%NUMCITY;
		temp = filho[a].percurso[b2];
		filho[a].percurso[b2] = filho[a].percurso[b1];
		filho[a].percurso[b1] = temp;
	}
	printf("feito\n");
	return filho;
}
/*==============================================*/

FILE* printFile(FILE* f, int breed, CaixeiroViajante* p){
	for(int i=0; i<NUMPOP; i++)
		fprintf(f,"%d\t%f\n",breed,p[i].aptidao);
	return f;
}

/*==============================================*/

int getCity(FILE* fcity, int n, int* x, int* y){
	int n2;
	char line[10];
	while(fgets(line,10,fcity)){
		sscanf(line,"%d",&n2);//compara primeira coluna: n da cidade
		if(n==n2){//se for mesma cidade
			sscanf(line,"%*d %d %*d",&x);
			sscanf(line,"%*d %*d %d",&y);
			rewind(fcity);
			return 1;
		}
	}
}

/*==============================================*/
void melhor(FILE* fcity, int breed, CaixeiroViajante* p){//saida em arquivo do melhor da pop. fcity = txt de cidades
	int ok;
	char filename[20], str[20];
	sprintf(filename,"path%d.txt",breed);
	FILE* fout = fopen(filename,"wt");
	if(!fout)
		printf("Erro ao abrir arquivo %s\n",filename);
	
	int vx[NUMCITY], x;
	int vy[NUMCITY], y;
	for(int i=0; i<NUMCITY; i++){
		ok = getCity(fcity,p[0].percurso[i], &x, &y);
// 		vx[i] = x;
// 		vy[i] = y;
		if(ok){
			sprintf(str,"%d %d %d\n",i,x,y);
			fputs(str,fout);
		}
	}
	
	return; 
}

/*==============================================*/

// CaixeiroViajante* mut(CaixeiroViajante* c,int n){ //n = number of mutations (maybe 'rand()') -> BETA
// 	int temp;
// 	int a, b1,b2;
// 	printf("Applicando operador de mutacao...");
// 	for(int i=0; i<n; i++){
// 		a = rand()%(NUMPOP/3);
// 		b1 = rand()%NUMCITY;
// 		b2 = rand()%NUMCITY;
// 		temp = c[a].percurso[b2];
// 		c[a].percurso[b2] = c[a].percurso[b1];
// 		c[a].percurso[b1] = temp;
// 	}
// 	printf("fim\n");
// 	return c;
// }
// 

/*==============================================*/
