#include <stdio.h>											// Declaração de bibliotecas
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int main() {												// Declaração do metodo principal	
	setlocale(LC_ALL, "");									// Funçao que aceita acentos no prompt
	int
		i = 0,
		RU = 0,
		x = 0,
		y = 0,
		a[5][5],
		b[5][5],
		aux[5][5];											// Declaração das variaveis

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			b[i][j] = 0;
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			aux[i][j] = 0;
		}
	}

	printf_s("Digite os dois ultimos digitos do seu RU: "); // Solicitação do final do RU
	scanf_s("%d", &RU);										// Recolhendo valor digitado

	if (RU < 10 || RU > 99) {								// Verificação se pode ser o final do RU

		printf_s("\nValor indisponivel\n");					// Informa que não é um RU disponivel
		Sleep(3000);										// Trava o prompt por 3 seg
		system("cls");										// Limpa o prompt
		main();												// Executa o metodo main
		return 0;											// Finaliza o metodo

	}

	printf_s("Digite o primeiro tamanho para matriz: ");	// Solicitação primeiro tamanho da matriz
	scanf_s("%d", &x);										// Recolhendo valor digitado
	printf_s("Digite o segundo tamanho para matriz: ");		// Solicitação segundo tamanho da matriz
	scanf_s("%d", &y);										// Recolhendo valor digitado

	if (x > 5 || x < 1 || y > 5 || y < 1) {
		
		printf_s("\nValor indisponivel\n");					// Informa que não é um tamanho disponivel
		Sleep(3000);										// Trava o prompt por 3 seg
		system("cls");										// Limpa o prompt
		main();												// Executa o metodo main
		return 0;											// Finaliza o metodo
	}

	for (i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("Digite o %dº valor da %dº matriz: ", j + 1, i+1);// Solicita os valores para preenchimento
			scanf_s("%d", &a[i][j]);						// Recolher valor digitado
		}
	}

	for (i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("Digite o %dº valor da %dº matriz: ", j + 1, i+1);// Solicita os valores para preenchimento
			scanf_s("%d", &b[i][j]);						// Recolher valor digitado
		}
	}

	for (i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			aux[i][j] = (a[i][j] + b[i][j]) * RU;
		}
	}

	for (i = 0; i < x; i++) {									// Loop para impressão
		for (int j = 0; j < y; j++) {			
			if (j == 0) {										// Verifica se é o primeiro numero
				printf_s(" __ \n|%d|", a[i][j]);				// Caso seja o primeiro ele imprime dois caracteres para fechar em cima a caixa
			} else if (j == (y - 1)) {							// Verifica se é o ultimo numero
				printf_s("\n|%d|\n --\n", a[i][j]);				// Caso seja o ultimo nume ele imprime dois caracteres para fechar em baixo
			} else {
				printf_s("\n|%d|", a[i][j]);					// Imprime o numero com barras laterais
			}
		}
	}

	for (i = 0; i < x; i++) {									// Loop para impressão
		for (int j = 0; j < y; j++) {
			if (j == 0) {										// Verifica se é o primeiro numero
				printf_s(" __ \n|%d|", b[i][j]);				// Caso seja o primeiro ele imprime dois caracteres para fechar em cima a caixa
			} else if (j == (y - 1)) {							// Verifica se é o ultimo numero
				printf_s("\n|%d|\n --\n", b[i][j]);				// Caso seja o ultimo nume ele imprime dois caracteres para fechar em baixo
			} else {
				printf_s("\n|%d|", b[i][j]);					// Imprime o numero com barras laterais
			}
		}
	}

	for (i = 0; i < x; i++) {									// Loop para impressão
		for (int j = 0; j < y; j++) {
			if (j == 0) {										// Verifica se é o primeiro numero
				printf_s(" __ \n|%d|", aux[i][j]);				// Caso seja o primeiro ele imprime dois caracteres para fechar em cima a caixa
			} else if (j == (y - 1)) {							// Verifica se é o ultimo numero
				printf_s("\n|%d|\n --\n", aux[i][j]);			// Caso seja o ultimo nume ele imprime dois caracteres para fechar em baixo
			} else {
				printf_s("\n|%d|", aux[i][j]);					// Imprime o numero com barras laterais
			}
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			aux[i][j] = 0;
		}
	}

	for (i = 0; i < x && i < y; i++) {
		aux[i][i] = (a[i][i] + b[i][i]) * RU;
	}

	for (i = 0; i < x; i++) {									// Loop para impressão
		for (int j = 0; j < y; j++) {
			if (j == 0) {										// Verifica se é o primeiro numero
				printf_s(" __ \n|%d|", aux[i][j]);				// Caso seja o primeiro ele imprime dois caracteres para fechar em cima a caixa
			} else if (j == (y - 1)) {							// Verifica se é o ultimo numero
				printf_s("\n|%d|\n --\n", aux[i][j]);			// Caso seja o ultimo nume ele imprime dois caracteres para fechar em baixo
			} else {
				printf_s("\n|%d|", aux[i][j]);					// Imprime o numero com barras laterais
			}
		}
	}

	system("pause");
	return 0;													// Finaliza metodo
}

