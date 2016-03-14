#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"labirinto.h"
/*
####################################################
#                                                  #
#     PROGRMA QUE RESOLVE O LABIRINTO              #
#                                                  #
#                                                  #
#                                                  #
#                                                  #
####################################################
*/
int main(){

	char** labirinto = Alocar_matriz(conta_num_de_linhas(),conta_num_de_colunas());
	labirinto = carrega_labirinto();
	
	int linha,coluna;
	retorna_posicao(&linha,&coluna,labirinto,'S');
	
	start();
	int asd = mover(labirinto,linha,coluna,conta_num_de_linhas(),conta_num_de_colunas(),2,0,1);
	return 0;
}
