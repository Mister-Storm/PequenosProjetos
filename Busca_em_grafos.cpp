//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Número máximo de vértices
#define MAXV 20

//Estrutura de um nó (vértice da lista de adjacências).
typedef struct str_no {
	int id;
	str_no *proximo;
} str_no;

//Grafo
str_no grafo[MAXV];

//====================Protótipos de função===========================
// Função para impressão de um vetor.
// int v[] é o vetor a imprimir;
// tam é o numero de elementos do vetor.
void imprimeVetor(int v[], int tam);

// Função de impressão do grafo, no formato de conjuntos G = {V, E}
void imprimeGrafoConjuntos(str_no g[]);

// Função que imprime o grafo no formato da lista de adjacências
void imprimeGrafoListas(str_no g[]);

// Função para inicializar o grafo.
// É preciso inicializar: 
//		- ponteiros com NULL;
//		- rótulos dos vértices com índices de 0 a MAXV-1.
// str_no g[] é o grafo a imprimir.
void inicializaGrafo(str_no g[]);

// Função para inserir arestas (vertices ajacentes).
// str_no g[] é o grafo;
// int v1 é o vertice de onde sai a aresta;
// int v2 é o vértice em que a aresta incide.
void insereAresta(str_no g[], int v1, int v2);

// Função que cria um exemplo de grafo.
// Popula as listas de adjacências com insereAresta()
void criaGrafoExemplo();

// Veja a Questão 1 do MAPA
void Busca1(str_no g[], int inicio, int alvo);

// Veja a Questão 2 do MAPA
void Busca2(str_no g[], int inicio, int alvo);




//====================Implementação das funções======================
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
	//Vértice a ser inserido na lista de adjacência de v2
	str_no *vertice1 = (str_no *) malloc(sizeof(str_no));
	//Vértice a ser inserido na lista de adjacência de v1
	str_no *vertice2 = (str_no *) malloc(sizeof(str_no));
	//Não foi possível alocar memória, desistindo da inserção.
	if (vertice1 == NULL) {
		printf("*** Falha ao alocar o vertice 1. \n");
		return;
	}
	//Não foi possível alocar memória, desistindo da inserção.
	if (vertice2 == NULL) {
		printf("*** Falha ao alocar o vertice 2. \n");
		return;
	}
	
	//Inicializando o vértice.
	vertice2->id = v2;
	vertice2->proximo = NULL;
 /* Posicionando o ponteiro para inserção 
    do vértice v2 na lista de adjacência de v1. */
	str_no *ptr ;
	for(ptr = &g[v1]; ptr->proximo != NULL; ptr = ptr->proximo)
	{
		
	}
	//Inserindo vértice v2 na lista de adjacência v1.
	ptr->proximo = vertice2;

	//Inicializando o vértice.
	vertice1->id = v1;
	vertice1->proximo = NULL;
 /* Posicionando o ponteiro para inserção 
    do vértice v1 na lista de adjacência de v2. */
	for(ptr = &g[v2]; ptr->proximo != NULL; ptr = ptr->proximo);
	//Inserindo vértice v2 na lista de adjacência v1.
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

//==================Qustão 1 - MAPA==================================
void Busca1(str_no g[], int inicio, int alvo){
	
	int pilha[MAXV]; //pilha
	bool visitado[MAXV]; //nós visitados
	int indice = 0; //índice do topo da pilha
	bool achou = false; //flag de controle d
	int corrente = inicio;
	str_no *ptr;
	
	printf("=-=-=-= Algoritmo 1 =-=-=-=\n");
	
	//Marcando os nós como 'não visitados'.
	for(int i=0; i < MAXV; i++){
		visitado[i] = false;
	}
	
	while(true){
		//Se o nó corrente não foi visitado, marque-o como visitado.
		//Empilhe o nó corrente.
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
		
		//Buscando por nós adjacentes, não visitados.
		achou = false;
		for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
			if(!visitado[ptr->id]){
				achou = true;
				break;
			}
		}
		
		if(achou){
			//Atalizando o nó corrente, com o vértice adjacente não visitado.
			corrente = ptr->id;
		}
		else{
			//Não há vértices adjacentes não visitados.
			//Tentando desempilhar o vértice do topo.
			indice--;
			if(indice==-1){
				//Não há mais vértices não visitados, encerrando a busca.
				printf("Encerrando a busca. \n");
				break;
			}	
			corrente = pilha[indice-1];
			
		}
		
	}
		
	return;
}

//==================Qustão 2 - MAPA==================================
void Busca2(str_no g[], int inicio, int alvo){
	
	int fila[MAXV];
	bool visitado[MAXV];
	int indice = 0;
	bool achou = false;
	int corrente = inicio;
	str_no *ptr;
	
	printf("=-=-=-= Algoritmo 2 =-=-=-= \n");
	
	//Marcando os nós como 'não visitados'.
	for(int i=0; i < MAXV; i++)
		visitado[i] = false;
	
	//Partindo do primeiro vértice.
	printf("VISITANDO: %d. \n", corrente);
	visitado[corrente] = true;
	fila[indice] = corrente;
	indice++;
	
	while(true){
		//Visitar todos os nós adjacentes ao vértice corrente
		for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
			//Caso o vértice ainda não tenha sido visitado:
			corrente = ptr->id;
			if(!visitado[corrente]){
				//Enfileirando e marcando o vértice como visitado.
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
		
		//Caso a fila não esteja vazia:
		if(indice!=0)
		{
			//Atualizando vértice corrente.
			corrente = fila[0];
			//Desenfileirando o primeiro vértice.
			for(int i=1;i<indice+1;i++)
				fila[i-1]=fila[i];
			indice--;
		}
		else
		{
			//Não há mais vértices para visitar.
			printf("Encerrando busca.\n");
			break;
		}
	}
		
	return;
}

////==================Corpo Principal do Programa====================
int main()
{
	//É sempre precizo iniciazlizar o grafo.
	//Cada nó recebe seu rótulo, e os ponteiros são "zerados"
	inicializaGrafo(grafo);
	
	//Criando um grafo de exemplo (Apenas para fins didáticos).
	criaGrafoExemplo();
	
	//Imprimindo o conjunto V de vértices e o conjunto E de arestas 
	imprimeGrafoConjuntos(grafo);
		
	return 0;
}































