#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"labirinto.h"
/*
##################-ORIENTAÇÕES-#####################
#                                                  #
#            1-) ^ (cima)                          #
#            2-) > (direita)                       #
#            3-) v (baixo)                         #
#            4-) < (esquerda)                      #
#                                                  #
####################################################
*/

//CONTA O NUMERO DE LINHAS NO LABIRINTO
int conta_num_de_linhas(){
	char c;
	int numero_de_linhas =0;
	FILE* in;
	in = fopen("labirinto.txt","rt");
	
	if (in == NULL)
		return -1;
	while((c = fgetc(in)) != EOF ){
		if(c == '\n'){
			numero_de_linhas++;
		}
	}
	return numero_de_linhas;
	fclose(in);
}
//CONTA O NUMERO DE COLUNAS NO LABIRINTO
int conta_num_de_colunas(){
	char c;
	int numero_de_colunas =0;
	FILE* in;
	in = fopen("labirinto.txt","rt");
	
	if (in == NULL)
		return -1;
	while((c = fgetc(in)) != EOF ){
		numero_de_colunas++;
		if(c == '\n'){
			return numero_de_colunas-1;
		}
	}
	return numero_de_colunas;
	fclose(in);
}
//VERIFICA A EXISTENCIA DO CARACTER EXPECIFICO
int verifica_a_existencia(char caractere){
	char c;
	int numero_de_repeticoes =0;
	FILE* in;
	in = fopen("labirinto.txt","rt");
	
	if (in == NULL)
		return -1;//SE NÃO CONSEGUIR ABRIR O ARQUIVO
	while((c = fgetc(in)) != EOF ){
		if(c == caractere){
			numero_de_repeticoes++;//TODA VEZ QUE ENCONTRA O CARACTER ELE ACRESENTA 1 AO numero de repetições
		}
	}
	return numero_de_repeticoes;
	fclose(in);
}
//aloca uma matri dinamicamente
char **Alocar_matriz (int linha, int coluna){
	char **v;
	int i;
	if (linha < 1 || coluna < 1) { /* verifica parametros recebidos */
		printf ("** Erro: Parametro invalido **\n");
		return (NULL);
	}
	/* aloca as linhas da matriz */
	v = (char **) calloc (linha, sizeof(char *));
	if (v == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
		return (NULL);
	}
	/* aloca as colunas da matriz */
	for ( i = 0; i < linha; i++ ) {
		v[i] = (char*) calloc (coluna, sizeof(char));
		if (v[i] == NULL) {
			printf ("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}
	return (v); /* retorna o ponteiro para a matriz */
}
//libera uma matri dinamicamente
char **Liberar_matriz (int linha, int coluna, char **v){
	int  i;  /* variavel auxiliar */
	if (v == NULL) return (NULL);
	if (linha < 1 || coluna < 1) {  /* verifica parametros recebidos */
		printf ("** Erro: Parametro invalido **\n");
		return (v);
	}
	for (i=0; i<linha; i++) free (v[i]); /* libera as linhas da matriz */
		free (v);      /* libera a matriz */
	return (NULL); /* retorna um ponteiro nulo */
}
//CARREGA O LABIRINTO PARA DENTRO DA MATRIZ
char** carrega_labirinto(){
	
	char c;
	int numero_de_linhas = conta_num_de_linhas();//CHAMA O NUMERO DE LINHA QUE TEM NO LABIRINTO
	int numero_de_colunas = conta_num_de_colunas();//CHAMA O NUMERO DE COLUNAS QUE TEM NO LABRINTO
	int i=0,j=0;
	char** labirinto;//CRIA UM PONTEIRO PARA PONTEIRO REPRESENTANDO O LABRINTO
	labirinto = Alocar_matriz(numero_de_linhas,numero_de_colunas); //ALOCA DINAMICAMENTE O LABIRINTO DO TAMANHO DO LABIRINTO
	FILE* in;//CRIA UM PONTEIRO PARA ARQUIVO "NULL"
	in = fopen("labirinto.txt","rt");//FAZ in APONTAR PARA O ARQUIVO labirinto.txt EM MODO LEITURA
	
	if (in == NULL)//SE O ARQUIVO NÃO EXISTIR OU NÃO CONSEGUIR SER LIDO
		return NULL;//RETORNA NULL E O PROGRAMA É IMPOSSIBILITADO DE CONTINUAR
	while((c = fgetc(in)) != EOF ){//EOF É O FINAL DO PROGRAMA
		
		if(c == '\n'){//TODA VEZ QUE ENCONTRA UM \n PULA UMA LINHA DO LABIRINTO E VOLTA PARA A PRIMEIRA COLUNA
			i++;
			j=0;
			continue;
		}else{
			labirinto[i][j] = c;//COLOCA O CARACTER LIDO PARA A MATRIZ(labirinto)
			j++;
		}
		
	}
	return labirinto;
	fclose(in);
}
//IMPRIME O LABIRINTO	
void imprime_labirinto(char** labirinto,int linhas, int colunas,double gold, int flechas,int mensagem){
	int i,j;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nLabirinto de ratos......Gold: %4g ....Flechas:%i..\n",gold,flechas);
	if(mensagem==1){
		printf("Wunpus: OH, NoOoOoOoOoOoOoOoOoOoOoOoOoOoO....\n");
		
	}else if(mensagem==2){
		printf("Heroi: ToOoOoO RICAAAAAAAAAAAAAAAAAA\n");
			
	}else if(mensagem==3){
		printf("Heroi: Ops, Esqueci do Wunpus\n");
			
	}else if(mensagem==4){
		printf("Heroi: Esse Fedor, o Wunpus deve estar por perto!\n");
			
	}else if(mensagem==5){
		printf("Heroi: Há um poço por perto, devo tomar cuidado!\n");
			
	}else{
		printf("\n");
	}
	printf(".......................................\n");
	for(i=0;i<linhas;i++){
		printf(".    ");
		for(j=0;j<colunas;j++){
			printf("%c",labirinto[i][j]);
		}
		printf("    .\n");
	}
	printf(".......................................\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

//RETORNA POR REFERENCIA A POSIÇÃO DE UM CARACTER EXPECIFICO
void retorna_posicao(int *linha,int *coluna,char** labirinto, char c){
	int i,j;
	for(i=0;i<conta_num_de_linhas();i++){
		for(j=0;j<conta_num_de_colunas();j++){
			if(labirinto[i][j]==c){
				*linha = i;//PASSA PARA A VARIAVEL linha A POSIÇÃO(linha) QUE ENCONTROU O CARACTER 'c'
				*coluna = j;//PASSA PARA A VARIAVEL coluna A POSIÇÃO(coluna) QUE ENCONTROU O CARACTER 'c'
			}
		}
	}
}

//VERIFICA SE TEM A POSSIBILIDADE DE MOVER PARA FRENTE
int mover_para_frente(char** labirinto,int linha,int coluna,int orientacao){
	
	switch(orientacao){
		case 1:
			linha--;
			break;
		case 2:
			coluna++;
			break;
		case 3:
			linha++;
			break;
		case 4:
			coluna--;
			break;
	}
	if(labirinto[linha][coluna] == '.' || labirinto[linha][coluna] == 'F'||labirinto[linha][coluna] == 'G'||labirinto[linha][coluna] == 'W'){
		return 1;//RETORNA 1 SE ELE PODE SE MOVER PARA FRENTE
	}
	return 0;//RETORNA 1 SE ELE PODE SE MOVER PARA FRENTE
}
//VERIFICA SE TEM A POSSIBILIDADE DE MOVER PARA DIREITA
int mover_para_direita(char** labirinto,int linha,int coluna,int orientacao){
	
	switch(orientacao){
		case 1:
			coluna++;
			break;
		case 2:
			linha++;
			break;
		case 3:
			coluna--;
			break;
		case 4:
			linha--;
			break;
	}
	if(labirinto[linha][coluna] == '.' || labirinto[linha][coluna] == 'F'||labirinto[linha][coluna] == 'G'||labirinto[linha][coluna] == 'W'){
		return 1;//RETORNA 1 SE ELE PODE SE MOVER PARA DIREITA
	}
	return 0;//RETORNA 1 SE ELE PODE SE MOVER PARA DIREITA
}
//VERIFICA SE TEM A POSSIBILIDADE DE MOVER PARA ESQUERDA
int mover_para_esquerda(char** labirinto,int linha,int coluna,int orientacao){
	
	switch(orientacao){
		case 1:
			coluna--;
			break;
		case 2:
			linha--;
			break;
		case 3:
			coluna++;
			break;
		case 4:
			linha++;
			break;
	}
	if(labirinto[linha][coluna] == '.' || labirinto[linha][coluna] == 'F'||labirinto[linha][coluna] == 'G'||labirinto[linha][coluna] == 'W'){
		return 1;//RETORNA 1 SE ELE PODE SE MOVER PARA ESQUERDA
	}
	return 0;//RETORNA 0 SE ELE ESTA IMPOSSIBILITADO DE SE MOVER PARA ESQUERDA
}

// VERIFICA A PROXIMIDADE DE UM CARACTER
int verifica_prossimidade(int linha, int coluna,char** labirinto, char c){
	if(labirinto[linha-1][coluna]==c || labirinto[linha+1][coluna]==c || labirinto[linha][coluna-1]==c || labirinto[linha][coluna+1]==c){
		return 1;//RETORNA 1 SE ESTA PROXIMO DO 
	}
	return 0;
}
//VERIFICA SE O WUMPUS AINDA ESTA VIVO
int verifica_wumpus(char **labirinto,int numero_de_linhas,int numero_de_colunas){
	int i,j;
	for (i=0;i<numero_de_linhas;i++){
		for (j=0;j<numero_de_colunas;j++){
			if(labirinto[i][j]=='W'){
				return 1;//SE ENCONTROT RETORNA 1
			}
		}
	}
	return 0;//SE NÃO ENCONTROU RETORNA ZERO
}

//PRINCIPAL FUNÇÃO DO SISTEMA
int mover(char** labirinto,int linha,int coluna,int numero_de_linhas,int numero_de_colunas,int orientacao, double gold,int flechas){
	int mensagem;//dis a msg que tem que falar
	
	int linha_anterior = linha;//GUARDA A POSIÇÃO NA linha ANTES DE ALTERAR
	int coluna_anterior = coluna;//GUARDA A POSIÇÃO NA coluna ANTES DE ALTERAR
	int l,c;
	retorna_posicao(&l,&c,labirinto,'S');//CHAMA A FUNÇÃO QUE DIZ QUAL É A POSIÇÃO (linha e coluna) DO 'S'(inicio)
	//VERIFICA SE ESTA NA POSIÇÃO INICIAL E DAI IMPRIME O LABIRINTO COMO ELE FOI CARREGADO
	if(l==linha && c==coluna){
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,0);//IMPRIME O LABIRINTO
		gold--;//TIRA UM DE gold POR ANDAR
		inicio_de_jogo();
	}
	//VERIFICA SE O FIM ESTA PROXIMO E SE MATOU O WUMPUS(pois sem matar não é possivel passar a fase)
	if(verifica_prossimidade(linha,coluna,labirinto,'E')==1 && verifica_wumpus(labirinto,numero_de_linhas,numero_de_colunas)==0){
		if(verifica_prossimidade(linha,coluna,labirinto,'E')==1){
			printf("oi\n");
		}
		retorna_posicao(&l,&c,labirinto,'E');/*################################################################################*/
		labirinto[linha_anterior][coluna_anterior]='.';//COLOCA UM . NA POSIÇÃO QUE O HEROI ESTAVA
		labirinto[l][c]='H';//COLOCA O HEROI NO FIM DO LABIRINTO
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,0);//IMPRIME O LABIRINTO
		fim_de_jogo();
		return 1;
	}else if(verifica_prossimidade(linha,coluna,labirinto,'E')==1){
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,3);//IMPRIME O LABIRINTO
		batida();
	}
	if(verifica_prossimidade(linha,coluna,labirinto,'P')==1){
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,5);//IMPRIME O LABIRINTO
		perigo();
	}
	//VERIFICA OS CAMINHOS POSSIVEIS MAS ESCOLHA NA SEQUINTE ORDEM DIREITA,FRENTE,ESQUERDA,MEIA VOLTA
	if(mover_para_direita(labirinto,linha,coluna,orientacao)==1){
		segue_direita(&linha,&coluna,&orientacao);//FAZ ELE VIRAR PARA DIREITA
	}else if(mover_para_frente(labirinto,linha,coluna,orientacao)==1){
		segue_frente(&linha,&coluna,&orientacao);//FAZ ELE IR PARA FRENTE
	}else if(mover_para_esquerda(labirinto,linha,coluna,orientacao)==1){
		segue_esquerda(&linha,&coluna,&orientacao);//FAZ ELE VIRAR PARA ESQUERDA
	}else{
		volta(&linha,&coluna,&orientacao);//FAZ ELE DAR MEIA VOLTRA
		batida();
	}
	//SE ELE ENCONTRE W(wumpus) IMPRIME O TEXTO CORRESPONDENTE
	if(labirinto[linha][coluna]=='W'){
		flechas--;//TIRA A FLECHA POIS ELE A USOU PARA MATAR O WUMPUS
		gold-=10;//TIRA 10 DE gold POIS É O PREÇO PRA ATRAR A FLECHA
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,1);//IMPRIME O LABIRINTO
		grito();
	}
	//SE ELE ENCONTRE G(gold) IMPRIME O TEXTO CORRESPONDENTE
	if(labirinto[linha][coluna]=='G'){
		gold+=1000;//ACRECENTA 1000 DE gold POIS ELE ACABOU DE PECAR DO CHÃO
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,2);//IMPRIME O LABIRINTO
		money();
	}
	//SE ELE ENCONTRE F(fedor) IMPRIME O TEXTO CORRESPONDENTE
	if(labirinto[linha][coluna]=='F'&& verifica_wumpus(labirinto,numero_de_linhas,numero_de_colunas)==1){
		imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,4);//IMPRIME O LABIRINTO
		perigo();
	}
	labirinto[linha_anterior][coluna_anterior]='.';//COLOCA UM . NA POSIÇÃO QUE O HEROI ESTAVA
	labirinto[linha][coluna]='H';//COLOCA O HEROI NA NOVA POSIÇÃO
	imprime_labirinto(labirinto,numero_de_linhas,numero_de_colunas,gold,flechas,0);//IMPRIME O LABIRINTO
	gold--;//TIRA UM DE gold POR ANDAR
	passo();
	return mover(labirinto,linha,coluna,numero_de_linhas,numero_de_colunas,orientacao,gold,flechas);//RECURSIVIDADE
}
/*AS 4 FUNÇÕES A SEGUIR AOTERAM DINAMICAMENTE O VALOR DOS INDICADORES 
DA MATRIZ DE ACORD COM A ORIENTAÇÃO E POSIÇÃO QUE VAI SEGUIR*/
//SEGUINDO PARA DIREITA
void segue_direita(int* linha,int* coluna,int* orientacao){
	int i = *orientacao;
	
	switch(i){
		case 1:
			*coluna+=1;
			*orientacao+=1;
			break;
		case 2:
			*linha+=1;
			*orientacao+=1;
			break;
		case 3:
			*coluna-=1;
			*orientacao+=1;
			break;
		case 4:
			*linha-=1;
			*orientacao=1;
			break;
	}
}
//SEGUINDO PARA ESQUERDA
void segue_esquerda(int* linha,int* coluna,int* orientacao){
	
	int i = *orientacao;
	
	switch(i){
		case 1:
			*coluna-=1;
			*orientacao=4;
			break;
		case 2:
			*linha-=1;
			*orientacao-=1;
			break;
		case 3:
			*coluna+=1;
			*orientacao-=1;
			break;
		case 4:
			*linha+=1;
			*orientacao-=1;
			break;
	}
}
//SEGUINDO PARA FRENTE
void segue_frente(int* linha,int* coluna,int* orientacao){
	
	int i = *orientacao;
	
	switch(i){
		case 1:
			*linha-=1;
			break;
		case 2:
			*coluna+=1;
			break;
		case 3:
			*linha+=1;
			break;
		case 4:
			*coluna-=1;
			break;
	}
}
//DANDO MEIA VOLTA
void volta(int* linha,int* coluna,int* orientacao){
	
	int i = *orientacao;
	
	switch(i){
		case 1:
			*linha+=1;
			*orientacao+=2;
			break;
		case 2:
			*coluna-=1;
			*orientacao+=2;
			break;
		case 3:
			*linha-=1;
			*orientacao-=2;
			break;
		case 4:
			*coluna+=1;
			*orientacao-=2;
			break;
	}	
}
/*FUNÇÕES QUE VÃO REPRODUZIR SOM ESPECIFICOS E DAR UM CERTO DELAY*/
//SOM DE INICIO
void inicio_de_jogo(){
	passo();
}
//SOM DE FIM DE JOGO "COMGRATULATIONS"
void fim_de_jogo(){
	passo();
}
//GRITO APAVORANTE
void grito(){
	passo();
	sleep(1.5);
}
//SOM DE MOEDAS CAINDO
void money(){
	grito();
}
//SOM DE UMA BATIDO OU PEQUENA EXPLOSÃO
void batida(){
	grito();
}
//SOM DE PERIGO OU SUSPENCE TIPO "THAM THAM THAM THAAAAAAMMMMM"
void perigo(){
	grito();
}
//SOM DE SAPATOS AO CAMINHAR EM CAUSADA
void passo(){
	//printf("\a\a\a\a\a\a\a\a\a\a\a");
	//printf("\7\7\7\7\7\7\7\7\7\7\7");
	usleep(200000);
}
//SOM DO BEEP PARA O "TOCK DE 5 SEGUNDOS"
void beep(){
	//printf("\a\a\a\a\a\a\a\a\a\a\a");
	//printf("\7\7\7\7\7\7\7\7\7\7\7");
	usleep(1000000);
}
//TOCK DE 5 SEGUNDOS KKKKKKK
void start(){
	printf("##############################\n");
	printf("############......############\n");
	printf("############..################\n");
	printf("############......############\n");
	printf("################..############\n");
	printf("############......############\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
	printf("##############################\n");
	printf("############..##..############\n");
	printf("############..##..############\n");
	printf("############......############\n");
	printf("################..############\n");
	printf("################..############\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
	printf("##############################\n");
	printf("############......############\n");
	printf("################..############\n");
	printf("############......############\n");
	printf("################..############\n");
	printf("############......############\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
	printf("##############################\n");
	printf("############......############\n");
	printf("################..############\n");
	printf("############......############\n");
	printf("############..################\n");
	printf("############......############\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
	printf("##############################\n");
	printf("##############..##############\n");
	printf("#############...##############\n");
	printf("##############..##############\n");
	printf("##############..##############\n");
	printf("############......############\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
	printf("##############################\n");
	printf("############......############\n");
	printf("############..##..############\n");
	printf("############..##..############\n");
	printf("############..##..############\n");
	printf("############......############\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
	printf("##############################\n");
	printf("#######......####......#######\n");
	printf("#######..########..##..#######\n");
	printf("#######..#...####..##..#######\n");
	printf("#######..##..####..##..#######\n");
	printf("#######......####......#######\n");
	printf("##############################\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	beep();
}




