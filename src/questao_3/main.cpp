#include <stdlib.h>

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <stack>
using std::stack;

void entradaInvalida() {
	cerr << "Entrada Inválida!" << endl;
	exit(1);
}

void operacaoInvalida() {
	cerr << "Operação Inválida!" << endl;
	exit(1);
}

int operar(stack<int> &pilha, char operacao) {
	int x, y;
	if (pilha.size() > 1) {
		y = pilha.top();
		pilha.pop();
		x = pilha.top();
		pilha.pop();
	} else {
		entradaInvalida();	
	} 

	switch(operacao) {
		case '+': return x + y;
			break;
		case '-': return x - y;
			break;
		case 'x': return x * y;
			break;
		case '/': return x / y;
			break;
		default: operacaoInvalida();
			break;
	}
	return 0;
}

bool isInt(char string) {
	if (string >= char(48) && string <= char(57)) return true;
	return false;
}

int getStringSize(char *string) {
	int i = 0;
	while(string[i] != '\0') {
		i++;
	}
	return i;
}

int empilhar(stack<int> &pilha, char **args, int n) {
	int valor, size;
	for (int i = 1; i < n; i++) {
		if (isInt(args[i][0])) {
			size = getStringSize(args[i]);
			for (int j = 0; j < size; j++) {
				if (!isInt(args[i][j])) entradaInvalida();
			}
		}
		if ((valor = atoi(args[i]))) {
			pilha.push(valor);
		} else {
			pilha.push(operar(pilha, args[i][0]));
		}
	}			
	
	return pilha.top();
}

int main(int argc, char **argv) {
	if (argc <= 3) entradaInvalida();
	int resultado = 0;
	stack<int> valores;
	resultado = empilhar(valores, argv, argc);

	cout << resultado << endl;
	return 0;

}