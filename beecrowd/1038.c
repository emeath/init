/*
https://judge.beecrowd.com/pt/problems/view/1038

beecrowd | 1038
Lanche
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1

Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. A seguir, calcule e mostre o valor da conta a pagar.

Entrada
O arquivo de entrada contém dois valores inteiros correspondentes ao código e à quantidade de um item conforme tabela acima.

Saída
O arquivo de saída deve conter a mensagem "Total: R$ " seguido pelo valor a ser pago, com 2 casas após o ponto decimal.

Exemplo de Entrada              Exemplo de Saída
3 2                             Total: R$ 10.00
4 3                             Total: R$ 6.00
2 3                             Total: R$ 13.50
*/

#include <stdio.h>

struct lanche {
    int codigo;
    char nome[32];
    float preco;
};


int main() {

    struct lanche lan[5] = {
        {1, "Cachorro Quente", 4},
        {2, "X-Salada", 4.5},
        {3, "X-Bacon", 5},
        {4, "Torrada simples", 2},
        {5, "Refrigerante", 1.5}
    };
    
    /*
    printf("%d %s %f\n", lan[0].codigo, lan[0].nome, lan[0].preco);

    for(int i = 0; i < 5; ++i) {
        printf("%d %s %.2f\n\n", lan[i].codigo, lan[i].nome, lan[i].preco);
    }
    */
    
    int codigo, qtd;
    scanf("%d %d", &codigo, &qtd);
    printf("Total: R$ %.2f\n", lan[codigo - 1].preco * qtd);

    return 0;
}  
