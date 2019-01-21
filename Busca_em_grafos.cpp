//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//N�mero m�ximo de v�rtices
#define MAXV 20

//Estrutura de um n� (v�rtice da lista de adjac�ncias).
typedef struct str_no {
	int id;
	str_no *proximo;
} str_no;

//Grafo
str_no grafo[MAXV];

//====================Prot�tipos de fun��o===========================
// Fun��o para impress�o de um vetor.
// int v[] � o vetor a imprimir;
// tam � o numero de elementos do vetor.
void imprimeVetor(int v[], int tam);

// Fun��o de impress�o do grafo, no formato de conjuntos G = {V, E}
void imprimeGrafoConjuntos(str_no g[]);

// Fun��o que imprime o grafo no formato da lista de adjac�ncias
void imprimeGrafoListas(str_no g[]);

// Fun��o para inicializar o grafo.
// � preciso inicializar: 
//		- ponteiros com NULL;
//		- r�tulos dos v�rtices com �ndices de 0 a MAXV-1.
// str_no g[] � o grafo a imprimir.
void inicializaGrafo(str_no g[]);

// Fun��o para inserir arestas (vertices ajacentes).
// str_no g[] � o grafo;
// int v1 � o vertice de onde sai a aresta;
// int v2 � o v�rtice em que a aresta incide.
void insereAresta(str_no g[], int v1, int v2);

// Fun��o que cria um exemplo de grafo.
// Popula as listas de adjac�ncias com insereAresta()
void criaGrafoExemplo();

// Veja a Quest�o 1 do MAPA
void Busca1(str_no g[], int inicio, int alvo);

// Veja a Quest�o 2 do MAPA
void Busca2(str_no g[], int inicio, int alvo);




//====================Implementa��o das fun��es======================
void imprimeVetor(int v[], int tam){
	printf("\nVetor:\n[ ");
	for(int i=0;i<tam;i++){
		printf("%d ", v[i]);
	}
	printf("]\n");
}

void imprimeGrafoConjuntos(str_no g[])
{	
	str_no *ptr;
	
	printf("================\n Vertices = { ");
	for(int i = 0; i<MAXV; i++){
		printf("%d, ", g[i].id);
	}
	printf("}\n");
	printf("================\n Arestas = { ");
	for(int i = 0; i<MAXV; i++){
		for(ptr = g[i].proximo; ptr != NULL; ptr = ptr->proximo){
			printf("<%d, %d>; ", g[i].id, ptr->id);
		}
	}
	printf("}\n================\n");
}

void imprimeGrafoListas(str_no g[])
{	
	str_no *ptr;
	

	printf("================\nLista de Adjacencias:\n");
	for(int i = 0; i<MAXV; i++){
		printf(" [%d]", g[i].id);
		for(ptr = g[i].proximo; ptr != NULL; ptr = ptr->proximo){
			printf("-(%d)", ptr->id);
		}
		printf(".\n");
	}
	printf("\n================\n");
}

void inicializaGrafo(str_no g[])
{	
	for(int i=0; i<MAXV; i++)
	{
		g[i].id = i;
		g[i].proximo = NULL;
	}
}

void insereAresta(str_no g[], int v1, int v2)
{
	//V�rtice a ser inserido na lista de adjac�ncia de v2
	str_no *vertice1 = (str_no *) malloc(sizeof(str_no));
	//V�rtice a ser inserido na lista de adjac�ncia de v1
	str_no *vertice2 = (str_no *) malloc(sizeof(str_no));
	//N�o foi poss�vel alocar mem�ria, desistindo da inser��o.
	if (vertice1 == NULL) {
		printf("*** Falha ao alocar o vertice 1. \n");
		return;
	}
	//N�o foi poss�vel alocar mem�ria, desistindo da inser��o.
	if (vertice2 == NULL) {
		printf("*** Falha ao alocar o vertice 2. \n");
		return;
	}
	
	//Inicializando o v�rtice.
	vertice2->id = v2;
	vertice2->proximo = NULL;
 /* Posicionando o ponteiro para inser��o 
    do v�rtice v2 na lista de adjac�ncia de v1. */
	str_no *ptr ;
	for(ptr = &g[v1]; ptr->proximo != NULL; ptr = ptr->proximo)
	{
		
	}
	//Inserindo v�rtice v2 na lista de adjac�ncia v1.
	ptr->proximo = vertice2;

	//Inicializando o v�rtice.
	vertice1->id = v1;
	vertice1->proximo = NULL;
 /* Posicionando o ponteiro para inser��o 
    do v�rtice v1 na lista de adjac�ncia de v2. */
	for(ptr = &g[v2]; ptr->proximo != NULL; ptr = ptr->proximo);
	//Inserindo v�rtice v2 na lista de adjac�ncia v1.
	ptr->proximo = vertice1;
	
}

void criaGrafoExemplo()
{
	insereAresta(grafo, 0, 1);
	insereAresta(grafo, 0, 2);
	insereAresta(grafo, 1, 3);
	insereAresta(grafo, 1, 4);
	insereAresta(grafo, 2, 5);
	insereAresta(grafo, 2, 6);
	insereAresta(grafo, 6, 7);
}

//==================Qust�o 1 - MAPA==================================
void Busca1(str_no g[], int inicio, int alvo){
	
	int pilha[MAXV]; //pilha
	bool visitado[MAXV]; //n�s visitados
	int indice = 0; //�ndice do topo da pilha
	bool achou = false; //flag de controle d
	int corrente = inicio;
	str_no *ptr;
	
	printf("=-=-=-= Algoritmo 1 =-=-=-=\n");
	
	//Marcando os n�s como 'n�o visitados'.
	for(int i=0; i < MAXV; i++){
		visitado[i] = false;
	}
	
	while(true){
		//Se o n� corrente n�o foi visitado, marque-o como visitado.
		//Empilhe o n� corrente.
		if(!visitado[corrente]){
			printf("VISITANDO: %d. \n", corrente);
			if(corrente == alvo)
			{
				printf("Vertice alvo encontrado!\n\n\n");
				return;
			}
			visitado[corrente] = true;
			pilha[indice] = corrente;
			indice++;
		}
		
		//Buscando por n�s adjacentes, n�o visitados.
		achou = false;
		for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
			if(!visitado[ptr->id]){
				achou = true;
				break;
			}
		}
		
		if(achou){
			//Atalizando o n� corrente, com o v�rtice adjacente n�o visitado.
			corrente = ptr->id;
		}
		else{
			//N�o h� v�rtices adjacentes n�o visitados.
			//Tentando desempilhar o v�rtice do topo.
			indice--;
			if(indice==-1){
				//N�o h� mais v�rtices n�o visitados, encerrando a busca.
				printf("Encerrando a busca. \n");
				break;
			}	
			corrente = pilha[indice-1];
			
		}
		
	}
		
	return;
}

//==================Qust�o 2 - MAPA==================================
void Busca2(str_no g[], int inicio, int alvo){
	
	int fila[MAXV];
	bool visitado[MAXV];
	int indice = 0;
	bool achou = false;
	int corrente = inicio;
	str_no *ptr;
	
	printf("=-=-=-= Algoritmo 2 =-=-=-= \n");
	
	//Marcando os n�s como 'n�o visitados'.
	for(int i=0; i < MAXV; i++)
		visitado[i] = false;
	
	//Partindo do primeiro v�rtice.
	printf("VISITANDO: %d. \n", corrente);
	visitado[corrente] = true;
	fila[indice] = corrente;
	indice++;
	
	while(true){
		//Visitar todos os n�s adjacentes ao v�rtice corrente
		for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
			//Caso o v�rtice ainda n�o tenha sido visitado:
			corrente = ptr->id;
			if(!visitado[corrente]){
				//Enfileirando e marcando o v�rtice como visitado.
				printf("VISITANDO: %d. \n", corrente);
				visitado[corrente] = true;
				fila[indice] = corrente;
				indice++;
				if(corrente == alvo)
				{
					printf("Vertice alvo encontrado!\n");
					return;
				}
			}
		}
		
		//Caso a fila n�o esteja vazia:
		if(indice!=0)
		{
			//Atualizando v�rtice corrente.
			corrente = fila[0];
			//Desenfileirando o primeiro v�rtice.
			for(int i=1;i<indice+1;i++)
				fila[i-1]=fila[i];
			indice--;
		}
		else
		{
			//N�o h� mais v�rtices para visitar.
			printf("Encerrando busca.\n");
			break;
		}
	}
		
	return;
}

////==================Corpo Principal do Programa====================
int main()
{
	//� sempre precizo iniciazlizar o grafo.
	//Cada n� recebe seu r�tulo, e os ponteiros s�o "zerados"
	inicializaGrafo(grafo);
	
	//Criando um grafo de exemplo (Apenas para fins did�ticos).
	criaGrafoExemplo();
	
	//Imprimindo o conjunto V de v�rtices e o conjunto E de arestas 
	imprimeGrafoConjuntos(grafo);
		
	return 0;
}































