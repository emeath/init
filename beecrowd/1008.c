#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	int errorFlag = 0;
	int *pId = NULL;
	int *pHoras = NULL;
	double *pSalarioHoras = NULL;	
	
	pId = malloc(1*sizeof(int));
	if(pId==NULL){
		fprintf(stderr,"error allocating memory...\n");
		goto cleanup;
	}
	pHoras=malloc(1*sizeof(int));
	if(!pHoras){
		fprintf(stderr,"error allocating memory\n");
		goto cleanup;
	}

	pSalarioHoras=calloc(1, sizeof(double));
	if(pSalarioHoras){
		scanf("%d %d %lf", pId, pHoras, pSalarioHoras);
		double salarioReceber = *pSalarioHoras * *pHoras;
		printf("NUMBER = %d\n", *pId);
		printf("SALARY = U$ %.2lf\n", salarioReceber);
	}
	else {
		fprintf(stderr, "Error allocating memory for salario HORAS this, somehow is very important for this program...\n");
		goto cleanup;
	}

	free(pHoras);
	free(pSalarioHoras);
	free(pId);
	return 0;

cleanup:
	free(pHoras);
	free(pSalarioHoras);
	free(pId);
	fprintf(stderr, "freeing all memory allocated...\n");
	return 1;
}
