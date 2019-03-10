#include <stdio.h>	//Declara��o de bibliotecas
#include <stdlib.h>
#include <locale.h>

float calc(float salario, float *Imposto);

int main(){ //Metodo Principal
	setlocale(LC_ALL, "");
	float salario = 0,
		NovoSalario = 0,
		Imposto = 0; //Declara��o das variaveis

	printf_s("Digite o sal�rio: "); //Solicitando salario
	scanf_s("%f", &salario);		//Recolhendo valor digitado
	NovoSalario = calc(salario, &Imposto);	//Chama o metodo calc aplicando o valor digitado, aplicando seu retorno em NovoSalario
	printf_s("Seu sal�rio antigo � de: R$%.2f \n", salario);	//Monstra seu antigo salario
	printf_s("Seu sal�rio atual � de: R$%.2f \n", NovoSalario);	//Mostra seu salario atual
	printf_s("O Imposto devido � de: R$%.2f \n", Imposto);		// Mostra imposto devido

	return 0;	//Retorno no metodo principal
}

float calc(float salario, float *Imposto) { //Metodo para o calculo
	float 
			taxa = 869.36,
			NovoSalario = salario,
			Aux = 0;			//Declara��o das variaveis

	if (NovoSalario <= 1903.98) {}				//Verifica��o do salario
	  else if (NovoSalario > 1903.98 && NovoSalario <= 2826.65) {

		Aux = (NovoSalario * 7.5) / 100;
		*Imposto = Aux - 142.80;
		NovoSalario = NovoSalario - Aux;

	} else if (NovoSalario > 2826.65 && NovoSalario <= 3751.05) {
		
		Aux = (NovoSalario * 15) / 100;
		*Imposto = Aux - 354.80;
		NovoSalario = NovoSalario - Aux;

	} else if (NovoSalario > 3751.05 && NovoSalario <= 4664.68) {

		Aux = (NovoSalario * 22.5) / 100;
		*Imposto = Aux - 636.13;
		NovoSalario = NovoSalario - Aux;

	} else {

		Aux = (NovoSalario * 27.5) / 100;
		*Imposto = Aux - 869.36;
		NovoSalario = NovoSalario - Aux;

	}

	return (NovoSalario);	//Retorno do metodo
}