#include <stdio.h>													// Declaração de bibliotecas
#include <stdlib.h>
#include <locale.h>

int main() {														// Metodo Principal
	setlocale(LC_ALL, "");
	float 
		apols = 0,
		apol[3],
		atp = 0,
		obj = 0,
		disc = 0,
		media = 0,
		nxt = 0;													// Declaração das variaveis
	
	for (int i = 0; i < 3; i++) {
		apol[i] = 0;
	}

	for (int i = 0; i < 3; i++) {
		printf_s("Digite a nota da %dº apol: ", i+1);				// Solicitando salario
		scanf_s("%f", &apol[i]);									// Recolhendo valor digitado
		apols = apols + apol[i];
	}
	apols = apols / 3;
	printf_s("Digite a nota da atividade pratica: ");				// Solicitando salario
	scanf_s("%f", &atp);											// Recolhendo valor digitado
	printf_s("Digite a nota da prova objetiva: ");					// Solicitando salario
	scanf_s("%f", &obj);											// Recolhendo valor digitado
	printf_s("Digite a nota da prova discursiva: ");				// Solicitando salario
	scanf_s("%f", &disc);											// Recolhendo valor digitado

	nxt = calc(apols, atp, obj, disc, &media);

	if (nxt == 1) {
		printf_s("Aluno aprovado com %.2f de media", media);
	} else if(nxt == 2){
		printf_s("Aluno em exame com %.2f de media", media);
	} else {
		printf_s("Aluno reprovado com %.2f de media", media);
	}

	return 0;														// Retorno no metodo principal
}

int calc(float apols, float atp, float obj, float disc, float *media){
	*media = ((apols*0.2) * 100) + ((atp*0.2) * 100) + ((obj*0.3) * 100) + ((disc*0.3) * 100);
	if (*media >= 70) {
		return 1;
	} else if (*media < 70 || *media > 39){
		return 2;
	} else {
		return 0;
	}
}