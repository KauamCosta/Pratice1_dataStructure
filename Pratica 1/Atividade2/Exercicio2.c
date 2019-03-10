#include <stdio.h>	//Declaração de bibliotecas
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int inPar(int numero[], int aux, int *RU);

int main(){

	setlocale(LC_ALL, "");
	int 
		i = 0,
		N[100],
		Par[100],
		Impar[100],
		Aux = 0,
		RU = 0;

	printf_s("Digite os dois ultimos digitos do seu RU: ");
	scanf_s("%d", &RU);

	if (RU < 10 || RU > 99) {

		printf_s("\nValor indisponivel\n");
		Sleep(3000);
		system("cls");
		main();
		return 0;

	}
	else {

		printf_s("Digite o tamanho do vetor: ");
		scanf_s("%d", &Aux);
		if (Aux < 100 && Aux > 0) {

			for (i = 0; i < Aux; i++) {
				printf_s("Digite o %dº valor: ", i+1);
				scanf_s("%d", &N[i]);				
			}

		} else {

			printf_s("\nValor indisponivel\n");
			Sleep(3000);
			system("cls");
			main();
			return 0;

		}
		inPar(N, Aux, &RU);
	}
	return 0;
}

int inPar(int numero[], int aux, int *RU) {

	int i = 0,
		ip = 0,
		p = 0,
		Impar[100],
		Par[100];

	for (i = 0; i < aux; i++) {

		if ((numero[i] % 2) != 0) {

			Impar[ip] = numero[i] * *RU;
			ip++;
		} else {
			Par[p] = numero[i];
			p++;
		}

	}

	printf_s("Numeros impares:\n");
	for (i = 0; i < ip; i++) {		
		if (i == 0) {
			printf_s(" __ \n|.0%d|", Impar[i]);
		} else if (i == (ip-1)) {
			printf_s("\n|%d|\n --", Impar[i]);
		} else {
			printf_s("\n|%d|", Impar[i]);
		}
	}

	return 0;
}