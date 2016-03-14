#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//FUNÇÕES AUXILIARES
int conta_num_de_linhas();
int conta_num_de_colunas();
void retorna_posicao(int *m,int *n,char** labirinto, char c);
void imprime_labirinto(char** labirinto,int linhas, int colunas,double gold, int flechas,int mensagem);


//FUNÇÕES PARA CARREGAR O LABIRINTO
char **Alocar_matriz(int linha,int coluna);
char **Liberar_matriz(int linha,int coluna, char** v);
char **carrega_labirinto();


//FUNÇÕES DE VERIFICAÇÃO
int verifica_a_existencia(char caractere);
int mover_para_frente(char** labirinto,int linha,int coluna,int orientacao);
int mover_para_direita(char** labirinto,int linha,int coluna,int orientacao);
int mover_para_esquerda(char** labirinto,int linha,int coluna,int orientacao);
int verfica_prossimidade(int linha, int coluna,char** labirinto,char c);
int verifica_wumpus(char **labirinto,int numero_de_linhas,int numero_de_colunas);


//FUNCÕES PRINCIPAIS DO PROGRAMA
int mover(char** labirinto,int linha,int coluna,int numero_de_linhas,int numero_de_colunas,int orientacao, double gold,int flechas);
void segue_direita(int* linha,int* coluna,int* orientacao);
void segue_esquerda(int* linha,int* coluna,int* orientacao);
void segue_frente(int* linha,int* coluna,int* orientacao);
void volta(int* linha,int* coluna,int* orientacao);


//FUNÇÕES DE SOM
void inicio_de_jogo();
void fim_de_jogo();
void grito();
void money();
void batida();
void perigo();
void passo();
void beep();


