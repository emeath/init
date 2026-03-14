/*
https://judge.beecrowd.com/pt/problems/view/1048

beecrowd | 1048
Aumento de Salário
Por Neilor Tonin, URI BR Brasil

Timelimit: 1

A empresa ABC resolveu conceder um aumento de salários a seus funcionários de acordo com a tabela abaixo:

Salário	            Percentual de Reajuste
-------------------------------------------
0 - 400.00              15%
400.01 - 800.00         12%
800.01 - 1200.00        10%
1200.01 - 2000.00       7%
Acima de 2000.00        4%

Leia o salário do funcionário e calcule e mostre o novo salário, bem como o valor de reajuste ganho e o índice reajustado, em percentual.

Entrada
A entrada contém apenas um valor de ponto flutuante, com duas casas decimais.

Saída
Imprima 3 linhas na saída: o novo salário, o valor ganho de reajuste (ambos devem ser apresentados com 2 casas decimais) e o percentual de reajuste ganho, conforme exemplo abaixo.

Exemplo de Entrada	            Exemplo de Saída
400.00                          Novo salario: 460.00
                                Reajuste ganho: 60.00
                                Em percentual: 15 %

800.01                          Novo salario: 880.01
                                Reajuste ganho: 80.00
                                Em percentual: 10 %

2000.00                         Novo salario: 2140.00
                                Reajuste ganho: 140.00
                                Em percentual: 7 %

*/

#include <stdio.h>

typedef struct {
    float salario;
} funcionario;

typedef struct {
    float limiteMinimo;
    float limiteMaximo;
    int reajuste;
} faixaDeReajuste;

typedef struct {
    char novoSalario[100];
    char reajusteGanho[100];
    char percentual[100];
} impressao;

void initFaixas(faixaDeReajuste *);
void printFaixas(faixaDeReajuste *);
impressao computarAumento(float , faixaDeReajuste *, size_t);

int main(){

funcionario f = {0};
scanf("%f", &f.salario);

faixaDeReajuste faixas[5];
initFaixas(faixas);
#ifdef DEBUG
printFaixas(faixas);
#endif
impressao iResp = computarAumento(f.salario, faixas, 5);
printf("%s\n%s\n%s\n", iResp.novoSalario, iResp.reajusteGanho, iResp.percentual);



}

void initFaixas(faixaDeReajuste *faixa)
{
    faixa[0].limiteMinimo = 0;
    faixa[0].limiteMaximo = 400;
    faixa[0].reajuste = 15;

    faixa[1] = (faixaDeReajuste){ 400.01 , 800 , 12 };
    faixa[2] = (faixaDeReajuste){ 800.01 , 1200, 10 };
    faixa[3] = (faixaDeReajuste){ 1200.01, 2000,  7 };
    faixa[4] = (faixaDeReajuste){ 2000.01, -1  ,  4 };
}

void printFaixas(faixaDeReajuste *faixa)
{
    printf("                Salario                Percentual de Reajuste\n");
    for(size_t i; i<5; ++i) {
        printf("%20.2f - %10.2f       %2.0d\n",    faixa[i].limiteMinimo,
                                                    faixa[i].limiteMaximo,
                                                    faixa[i].reajuste);
    }
}

impressao computarAumento(float salario, faixaDeReajuste *faixa, size_t qtdFaixas)
{
    impressao i;
    faixaDeReajuste *cursor = faixa;
    size_t j;
    
    for(j=0; j<qtdFaixas; ++j) {

        if ( salario >= cursor->limiteMinimo
             && ( salario <= cursor->limiteMaximo 
                  || cursor->limiteMaximo == -1) 
           )
        {
            snprintf(   i.novoSalario, 
                        sizeof(i.novoSalario), 
                        "Novo salario: %.2f", 
                        salario * (100 + cursor->reajuste)/100.0
            );
            
            snprintf(   i.reajusteGanho, 
                        sizeof(i.reajusteGanho), 
                        "Reajuste ganho: %.2f", 
                        salario * (cursor->reajuste)/100.0
            );
            
            snprintf(   i.percentual, 
                        sizeof(i.percentual), 
                        "Em percentual: %d%%", 
                        cursor->reajuste
            );
            
            break;
        }
        
        ++cursor;
    }
    
    return i;
}

