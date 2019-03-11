#include <stdio.h>											// Declara��o de bibliotecas
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int main(){													// Declara��o do metodo principal

	setlocale(LC_ALL, "");									// Fun�ao que aceita acentos no prompt
	int 
		i = 0,
		N[100],
		Par[100],
		Impar[100],
		Aux = 0,
		RU = 0;												// Declara��o das variaveis

	printf_s("Digite os dois ultimos digitos do seu RU: "); // Solicita��o do final do RU
	scanf_s("%d", &RU);										// Recolhendo valor digitado

	if (RU < 10 || RU > 99) {								// Verifica��o se pode ser o final do RU

		printf_s("\nValor indisponivel\n");					// Informa que n�o � um RU disponivel
		Sleep(3000);										// Trava o prompt por 3 seg
		system("cls");										// Limpa o prompt
		main();												// Executa o metodo main
		return 0;											// Finaliza o metodo

	}
	else {

		printf_s("Digite o tamanho do vetor: ");			// Solicita o tamanho do vetor
		scanf_s("%d", &Aux);								// Recolhendo valor digitado
		if (Aux < 100 && Aux > 0) {							// Limita o vetor e n�o permite numeros negativos

			for (i = 0; i < Aux; i++) {						// Loop para preenchimento do vetor
				printf_s("Digite o %d� valor: ", i+1);		// Solicita os valores para preenchimento
				scanf_s("%d", &N[i]);						// Recolher valor digitado
			}

		} else {

			printf_s("\nValor indisponivel\n");				// Informa que n�o � um RU disponivel
			Sleep(3000);									// Trava o prompt por 3 seg
			system("cls");									// Limpa o prompt
			main();											// Executa o metodo main
			return 0;										// Finaliza o metodo

		}
		imPar(N, Aux, RU);									// Executa o metodo imPar enviando 3 parametros
	}
	return 0;												// Finaliza metodo
}

int imPar(int numero[], int aux, int RU) {					// Declara o metodo imPar

	int i = 0,
		ip = 0,
		p = 0,
		Impar[100],
		Par[100];											// Declara as variaveis do metodo inPar

	for (i = 0; i < aux; i++) {								// Loop para verificar se � impar ou par

		if ((numero[i] % 2) != 0) {							// Verifica se mod do numero em questao � 0 (Par) ou 1 (Impar)

			Impar[ip] = numero[i] * RU;					// Guarda o numero impar j� multiplicado pelo final do RU
			ip++;											// Incrementar mais um no contador
		} else {
			Par[p] = numero[i];								// Guarda o numero par
			p++;											// Incrementar mais um no contador
		}

	}

	printf_s("Numeros impares:\n");							// Informa que os numeros que serao imprimidos serao os impares
	for (i = 0; i < ip; i++) {								// Loop para impress�o dos numeros impares
		if (i == 0) {										// Verifica se � o primeiro numero
			printf_s(" __ \n|%d|", Impar[i]);				// Caso seja o primeiro ele imprime dois caracteres para fechar em cima a caixa
		} else if (i == (ip-1)) {							// Verifica se � o ultimo numero
			printf_s("\n|%d|\n --\n", Impar[i]);			// Caso seja o ultimo nume ele imprime dois caracteres para fechar em baixo
		} else {
			printf_s("\n|%d|", Impar[i]);					// Imprime o numero com barras laterais
		}
	}

	printf_s("Numeros pares:\n");							// Informa que os numeros que serao imprimidos serao os pares
	for (i = 0; i < p; i++) {								// Loop para impress�o dos numeros pares
		if (i == 0) {										// Verifica se � o primeiro numero
			printf_s(" __ \n|%d|", Par[i]);					// Caso seja o primeiro ele imprime dois caracteres para fechar em cima a caixa
		} else if (i == (p - 1)) {							// Verifica se � o ultimo numero
			printf_s("\n|%d|\n --\n", Par[i]);				// Caso seja o ultimo nume ele imprime dois caracteres para fechar em baixo
		} else {
			printf_s("\n|%d|", Par[i]);						// Imprime o numero com barras laterais
		}
	}

	return 0;												// Finaliza o metodo
}