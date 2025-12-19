#include <stdio.h>
#include <stdlib.h>
int main(){
	char nome[64];
	double salario, vendas;
	fgets(nome, 64, stdin);
	scanf("%lf %lf", &salario, &vendas);
	double bonus = vendas * 0.15;
	double salarioFinal = salario + bonus;
#ifdef DEBUG
	printf("%s\n", nome);
	printf("%.2lf %.2lf %.2lf %.2lf\n", salario, vendas, bonus, salarioFinal);
#endif
	printf("TOTAL = R$ %.2lf\n", salarioFinal);
	return 0;
}
