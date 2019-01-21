  //  2018 Copyright Fernando Costa Leite.
  //  compiler gcc (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>


  // constants

#define max 5

  //  prototyping

void menuInitial();
void menu();
void readOp();
bool validOp();
void directMenu();
void errorMsg();
void checkStack();
void collectData();
void scheduleInclude(char firstName [], char lastName [], char street [], int number, char complement  [], int ddd, int prefix, int suffix);
int generateKey();
void scheduleEnd();
void scheduleShowData();
void pause();

  // creating structure schedule


typedef struct {
	char firstName [30];
	char lastName [50];
} name;

typedef struct {
	char street [50];
	int number;
	char complement [30];
} adress;

typedef struct {
	int ddd;
	int prefix;
	int suffix;
} phone;

typedef struct {
	int primaryKey;
	name name;
	phone phone;
	adress adress;
} schedule1;

  //  global variables

schedule1 schedule[max];
int op;
int count = 0;

int main() {

	setlocale(LC_ALL,"portuguese");

	menuInitial();

	return 0;
}  // end of main method

void menu() {

	system("clear");
	printf("Por favor, escolha uma das opções abaixo\n\n");
	printf("1 - Inserir um novo cadastro\n");
	printf("2 - Mostrar todos os cadastros\n");
	printf("0 - Encerrar\n");
	printf("Opção: ");
	readOp();
}

void menuInitial() {
	system("clear");
	printf("\n\n*** Bem-vindo a versão Beta do assistente pessoal My Schedule ***\n\n\n");
	pause();
	menu();
}

void readOp() {
	scanf("%d", &op);
	if (validOp()) {
		directMenu();
	} else {
		errorMsg();
	}
}

bool validOp() {
	if (op == 1 || op == 2 || op == 0) {
		return true;
	} else {
		return false;
	}
}

void directMenu() {
	switch (op) {
		case 1: checkStack();
			break;
		case 2: scheduleShowData();
			break;
		default: scheduleEnd();
	}
}

void errorMsg() {
	printf("Por favor, digite uma opção válida\n");
	getchar();
	pause();
	menu();
}

void checkStack() {
	if (count == max) {
		printf("\n\nAgenda lotada!\n\n");
		getchar();
		pause();
		menu();
	} else {
		collectData();
	}
}

void collectData() {
	char firstName [30];
	char lastName [50];
	char street  [50];
	int number;
	char complement [30];
	int ddd;
	int prefix;
	int suffix;
	getchar();
	printf("\ninforme o primeiro nome: ");
	gets(firstName);
	printf("\ninforme o sobrenome: ");
	gets(lastName);
	printf("\ninforme o nome da rua: ");
	gets(street);
	printf("\ninforme o número da casa: ");
	scanf("%d", &number);
	printf("\ninforme o complemento: ");
	getchar();
	gets(complement);
	printf("\ninforme o DDD: ");
	scanf("%d", &ddd);
	printf("\ninforme os primeiros números do telefone: ");
	scanf("%d", &prefix);
	printf("\ninforme os números finais do telefone: ");
	scanf("%d", &suffix);

	scheduleInclude(firstName, lastName, street, number, complement, ddd, prefix, suffix);
}

void scheduleInclude(char firstName [], char lastName [], char street [], int number, char complement  [], int ddd, int prefix, int suffix) {
	schedule[count].primaryKey = generateKey();
	strcpy(schedule[count].name.firstName, firstName);
	strcpy(schedule[count].name.lastName, lastName);
	strcpy(schedule[count].adress.street, street);
	schedule[count].adress.number = number;
	strcpy(schedule[count].adress.complement, complement);
	schedule[count].phone.ddd = ddd;
	schedule[count].phone.prefix = prefix;
	schedule[count].phone.suffix = suffix;
	count++;
	menu();
}

int generateKey() {
	srand((unsigned)time(NULL));
	int number = rand()%100;
	if(count == 0) {
		return number;
	} else {
		for (int i=0; i <= count; i++) {
			if (number == schedule[count].primaryKey) {
				srand((unsigned)time(NULL));
				number = rand()%100;
				i=0;
			}
		}
	}
	return number;
}

void scheduleEnd() {
	int foo;
	printf("\nTem certeza que deseja encerrar o programa (digite 0 para confirmar)? ");
	scanf("%d", &foo);
	if (foo != 0) {
		menu();
	}
}

void scheduleShowData() {
	if (count == 0) {
		printf("\n\nAgenda vazia!\n");

	} else {
		for(int i=0; i <= count-1; i++) {
			printf("\nCódigo: %d", schedule[i].primaryKey);
			printf(" Nome: %s, %s", schedule[i].name.firstName, schedule[i].name.lastName);
			printf("\nEndereço: Rua %s, número, %d, %s", schedule[i].adress.street, schedule[i].adress.number, schedule[i].adress.complement);
			printf("\nTelefone: (%d) %d-%d\n", schedule[i].phone.ddd, schedule[i].phone.prefix, schedule[i].phone.suffix);
		}
	}
	getchar();
	pause();
	menu();
}

void pause() {
	printf("pressione enter para continuar...");
	getchar();
}

/* ALgumas observações sobre o programa:
1º utilizei o system("clear") pois meu sistema operacional é o Linux e o clear funciona como o cls no windows;
2º o fflush(stdin) também não funcionou corretamente, então criei utilizei o getchar() para substituir o fflush(stdin);
3º assim como nos comandos anteriores o system("pause") também não funcionou corretamente no Linux, então criei minha própria função para pausar o programa (pause());
4º utilizei o nome das funções, variáveis, etc em inglês para padrozinação do código;
5º fiz todos os testes de mesa e o programa passou em todos os testes.
*/

