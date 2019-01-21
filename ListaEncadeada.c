  //  2018 Copyright Fernando Costa Leite.
  // compiler gcc (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct nodeStack {  // structure of node of stack
	int data;
	struct nodeStack *previous;
	struct nodeStack *next;
};

struct DynamicStack { // structure that points to the top of the stack
	struct nodeStack *top;
};

typedef struct nodeStack nodeStack;
typedef struct DynamicStack DynamicStack;
struct DynamicStack *stack;


bool stackEmpty () {  // method that verify if the stack is empty
	if (stack->top == NULL) {
		return true;
	} else return false;
}

void push (int number) {  //  method that stacks elements
	if(stackEmpty()) {	
		struct nodeStack *pointer = (struct nodeStack *) malloc(sizeof(struct nodeStack));	
		pointer->data = number;
		pointer->previous = stack->top;
		pointer->next = NULL;
		stack->top = pointer;
	} else {
		nodeStack *pointer = (nodeStack *) malloc(sizeof(nodeStack));
		nodeStack *pointerAux = stack->top;	
		pointer->data = number;
		pointer->previous = stack->top;
		pointer->next = NULL;
		pointerAux->next = pointer;
		stack->top = pointer;
		}
	
}

int pop () {  //  method that removes an element from the stack
	if (!stackEmpty()) {
	nodeStack *pointer = stack->top;
	int temp;
	temp = pointer->data;
	stack->top = pointer->previous;
	pointer->previous = NULL;
	free(pointer);
	return temp;
	} else {
		printf("Stack empty!");
		system("pause");
	}
}
	
void showData () {  //  shows all stack elements in the order of inclusion
	if(!stackEmpty()) {
		nodeStack *pointer = stack->top;
		while(pointer->previous != NULL) { // walks to the begin of the stack
			pointer = pointer->previous;			
		}
		while(pointer->next != NULL) { // prints the stack in the order of inclusion
			printf("%d ", pointer->data);
			pointer = pointer->next;
		}
	printf("%d ", pointer->data);  // necessary because the while does not execute when the pointer to the next one is equal to null, but in that pointer there is still the top data, which must also be printed(necessário por que o while não executa quando o ponteiro para o próximo é igual a nulo, mas nesse ponteiro ainda consta o dado do topo, que também deve ser impresso).
	}
	printf("\n");
}

void drainOut () {  //  removes all elements of the stack following the LIFO principle. Automates the process of removing elements from the stack
	
	while(!stackEmpty()) {
		printf("%d ", pop ());
	}
	printf("\n");
}

int main () {
	
	stack = (DynamicStack *) malloc(sizeof(DynamicStack));
	stack->top = NULL;
	push(1);
	push(7);
	push(5);
	push(7);
	push(3);
	push(9);
	push(9);
	push(5);
	showData();
	drainOut();
}  //
/* I needed to put two pointers, one pointing to the next element and another pointing to the previous element, so that I could implement the showData () method so that it printed the data in the order they were inserted into the stack (Precisei colocar dois ponteiros, um para apontando para o próximo elemento e outro apontando para o elemento anterior para poder implementar o método showData() de modo que o mesmo imprimisse os dados na ordem em que foram inseridos na pilha). 
I also implemented a static stack using vectors. However, I preferred to present in MAPA using the dynamic stack implementation, but I present static stack code in these comments to enrich the work (também implementei uma pilha estática, utilizando vetores. entretanto, preferi apresentar no MAPA utilizando a implementação de pilha dinâmica, mas apresento o código referente a pilha estática nestes comentários para enriquecer o trabalho).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 8

struct mystack {  // struct of stack
	int data[size];
	int index;
};

struct mystack stack;

bool stackFull () {  
	if (stack.index < size) {
		return false;
	} else return true;
}

bool stackEmpty () {
	if (stack.index == -1) {
		return true;
	} else return false;
}

void push (int number) {  //  method that stacks elements
	if (!stackFull()) {
		stack.index++;
		stack.data[stack.index] = number;
	} else {
		printf("Stack full!");
		system("pause");
	}
}

int pop () {  //  method that removes an element from the stack
	if (!stackEmpty()) {
	int giveBack = 	stack.data[stack.index];
	stack.index--;
	return giveBack;
	} else {
		printf("Stack empty!");
		system("pause");
	}
}
	
void showData () {  //  shows all stack elements
	for (int i = 0; i <= stack.index; i++) {
		printf("%d ", stack.data[i]);
	}
	printf("\n");
}

void drainOut () {  //  removes all elements of the pile following the LIFO principle. Automates the process of removing elements from the stack
	int temp = stack.index;
	for (int i = 0; i <= temp; i++) {
		printf("%d ", pop ());
	}
	printf("\n");
}

int main () {
	stack.index = -1;
	push(1);
	push(7);
	push(5);
	push(7);
	push(3);
	push(9);
	push(9);
	push(5);
	showData();
	drainOut();
}  //
*/

