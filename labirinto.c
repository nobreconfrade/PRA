#include "labirinto.h"
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define col 100
#define lin 100
char labirinto[lin][col];
FILE* in

int inicializar_labirinto (){
    char ch;
    int numero_de_linhas=0, numero_de_colunas=0;

    fseek(in, 0, SEEK_SET); 
    if(in==NULL){
	return 0;
    }else{
	while( (ch=fgetc(in))!= EOF ){
	    if(ch == '\n'){
		numero_de_linhas++;
		numero_de_colunas=0;
		
	    }
	    else{
		numero_de_colunas++;
		labirinto[numero_de_linhas][numero_de_colunas] = ch;
	    }
	}
    }

   return OK;
}

void mostrar_labirinto() 
{


}

int main(){
    
    in = fopen("asd.txt","rt");
    FILE* out;
    out = fopen("teste.txt","wt");
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

    int aux = inicializar_labirinto(in);
    
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
