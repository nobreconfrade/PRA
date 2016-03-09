#include "labirinto.h"
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define col 100
#define lin 100
char labirinto[lin][col];

int inicializar_labirinto (){
    FILE* in;
    char ch;
    int numero_de_linhas=0, numero_de_colunas=0, aux;

    in = fopen("asd.txt","rt");

    if(in==NULL){
        fclose(in);
	return -1;
    }else{
	while( (ch=fgetc(in))!= EOF ){
	    if(ch == '\n'){
		numero_de_linhas++;
                aux = numero_de_colunas;
		numero_de_colunas=0;
		
	    }
	    else{
		numero_de_colunas++;
		labirinto[numero_de_linhas][numero_de_colunas] = ch;
	    }
	}
    }
    fclose(in);
    return numero_de_linhas*aux;
}

int checa_existencia(char c){
  int i,j, cont=0;
    for(i=0;i<col;i++){
	for(j=0;j<=lin;j++){
	   if(labirinto[i][j] == c){
             cont++;
	   }
    	}
    }
    return cont;
}



int main(){
    FILE* in;
    in = fopen("asd.txt","rt");
    //FILE* out;
    //out = fopen("teste.txt","wt");
    int numero_de_linhas=0, numero_de_colunas=0;
    char ch;
    if(in==NULL){
	return 0;
    }else{
	while( (ch=fgetc(in))!= EOF ){
	    if(ch == '\n')
		numero_de_linhas++;
	    else
		numero_de_colunas++;
	}
    }

    numero_de_colunas=numero_de_colunas/numero_de_linhas;

    int aux = inicializar_labirinto();
    
    int i,j;
    for(i=0;i<numero_de_linhas;i++){
	for(j=0;j<=numero_de_colunas;j++){
	   printf("%c",labirinto[i][j]);
    	}
	printf("\n");
    }

    


    fclose(in);
    return 0;
}
