#include <stdio.h>													// Declaração de bibliotecas
#include <stdlib.h>
#include <locale.h>

float calc(float salario, float *Imposto);

int main(){															// Metodo Principal
	setlocale(LC_ALL, "");
	float salario = 0,
		NovoSalario = 0,
		Imposto = 0;												// Declaração das variaveis

	printf_s("Digite o salário: ");									// Solicitando salario
	scanf_s("%f", &salario);										// Recolhendo valor digitado
	NovoSalario = calc(salario, &Imposto);							// Chama o metodo calc aplicando o valor digitado, aplicando seu retorno em NovoSalario
	printf_s("Seu salário antigo é de: R$%.2f \n", salario);		// Monstra seu antigo salario
	printf_s("Seu salário atual é de: R$%.2f \n", NovoSalario);		// Mostra seu salario atual
	printf_s("O Imposto devido é de: R$%.2f \n", Imposto);			// Mostra imposto devido

	return 0;														// Retorno no metodo principal
}

float calc(float salario, float *Imposto) {							// Metodo para o calculo
	float 
			taxa = 869.36,
			NovoSalario = salario,
			Aux = 0;												// Declaração das variaveis

	if (NovoSalario <= 1903.98) {}									// Verificação do salario
	  else if (NovoSalario > 1903.98 && NovoSalario <= 2826.65) {	// Verifica se esta entre 1903.98 e 2826.65

		Aux = (NovoSalario * 7.5) / 100;							// Salva o valor na variavel auxiliar
		*Imposto = Aux - 142.80;									// Salvando valor do imposto
		NovoSalario = NovoSalario - Aux;							// Guarda do novo salario

	} else if (NovoSalario > 2826.65 && NovoSalario <= 3751.05) {	// Verifica se esta entre 2826.65 e 3751.05
		
		Aux = (NovoSalario * 15) / 100;								// Salva o valor na variavel auxiliar
		*Imposto = Aux - 354.80;									// Salvando valor do imposto
		NovoSalario = NovoSalario - Aux;							// Guarda do novo salario

	} else if (NovoSalario > 3751.05 && NovoSalario <= 4664.68) {	// Verifica se esta entre 3751.05 e 4664.68

		Aux = (NovoSalario * 22.5) / 100;							// Salva o valor na variavel auxiliar
		*Imposto = Aux - 636.13;									// Salvando valor do imposto
		NovoSalario = NovoSalario - Aux;							// Guarda do novo salario

	} else {

		Aux = (NovoSalario * 27.5) / 100;							// Salva o valor na variavel auxiliar
		*Imposto = Aux - 869.36;									// Salvando valor do imposto
		NovoSalario = NovoSalario - Aux;							// Guarda do novo salario

	}

	return (NovoSalario);											// Retorno e finalização do metodo
}