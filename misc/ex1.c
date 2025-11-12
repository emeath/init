/*
 * Exercício 

Escreva um programa em C que:

  1. Leia um valor inteiro N (tamanho).

  2. Aloque dinamicamente um array de N inteiros usando malloc.

  3. Preencha o array com os valores N, N-1, ..., 1 (em ordem decrescente) usando apenas aritmética de ponteiros (sem usar []).

  4. Crie uma função chamada

    void increment_all(int *p, int n);

    que receba o ponteiro e incremente todos os elementos do array em +1, também usando apenas ponteiros.

  5. Imprima o array resultante.

  6. Libere a memória.

✅ Exemplo de uso

Entrada:

5

Array antes do incremento:

5 4 3 2 1

Array depois do incremento:

6 5 4 3 2

⚠️  Regras

    Não usar notação arr[i]

    Use apenas ponteiros e *p / p++

    O programa deve funcionar para qualquer N > 0

🔹 Dicas opcionais

    Para preencher:

*(p + i) = ...

Para iterar dentro da função:

    for(int i = 0; i < n; i++) *(p + i) += 1;

💡 Desafio extra (se sobrar tempo)

Crie outra função que receba o ponteiro e retorne o maior valor do array.

 * */

#include <stdio.h>
#include <stdlib.h>

void set_all(int *p, int n) {
	printf("primeiro address %p\n", p);
	for(;n>=1;--n){
		printf("%d\n", n);
		*p = n;
		p++;
		printf("proximo address  %p\n", p);
	}
}

void increment_all(int *p, int n) {
	printf("primeiro address %p\n", p);
	for(int i=0;i<n;++i){
		*p = *p + 1;
		p++;
		printf("proximo address  %p\n", p);
	}
}

void print_array(int *p, int n){
	for(int i=0;i<n;++i){
		printf("[%i] %i\n", i, *p);
		p++;
	}
}

int get_max(int *p, int n) {
	int max = *p;
	for(int i=0; i<n; ++i) {
		max = *p > max ? *p : max;
		p++;
	}
	return max;
}
		


int main(){
int n;
scanf("%d", &n);

int *ptrArray = malloc( n * sizeof(int) );
if (ptrArray == NULL) {
	fprintf(stderr, "erro ao alocar\n");
	return 1;
}

set_all(ptrArray, n);
print_array(ptrArray, n);
increment_all(ptrArray, n);
print_array(ptrArray, n);

printf("max value = %d\n", get_max(ptrArray, n));

int v[10] = {2,4,21,44,99,2,40,213,2,10};

printf("max value = %d\n", get_max(v, 10));

free(ptrArray);

return 0;
}
