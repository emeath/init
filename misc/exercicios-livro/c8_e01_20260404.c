#include <stdio.h>
#include <string.h>
#include "c8_e01_20260404_lib.h"

int main()
{
    Pessoa pessoa; 
    printf("name? ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[ strlen(pessoa.nome) - 1] = '\0';
    
    printf("age? ");        
    scanf("%u", &pessoa.idade);
    
    // scanf will leave \n in buffer. We need to clean it
//    while(getchar() != '\n');

    printf("address? ");
    fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);
    *(pessoa.endereco + strlen(pessoa.endereco) - 1) = '\0';

    printf("--- INPUT ---\n");
    printf("Name: %s\n", pessoa.nome);
    printf("Age:  %u\n", pessoa.idade);
    printf("Address: %s\n", pessoa.endereco);
    
    return 0;
}
