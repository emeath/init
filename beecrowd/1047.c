/*
https://judge.beecrowd.com/pt/problems/view/1047

beecrowd | 1047
Tempo de Jogo com Minutos
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .

Exemplo de Entrada	Exemplo de Saída
7 8 9 10		O JOGO DUROU 2 HORA(S) E 2 MINUTO(S)

7 7 7 7			O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)

7 10 8 9		O JOGO DUROU 0 HORA(S) E 59 MINUTO(S)
*/

#include <stdio.h>

typedef struct {
    int qtdHora;
    int qtdMinuto;
} duracao;

int converterHoraParaMinutos(int horas, int minutos);
int calcularDuracaoEmMinutos(int timestampInicial, int timestampFinal);
duracao packDuracao(int duracaoEmMinutos);
void adicionarMais24Horas(int *timestamp);
int converterHorasParaMinutos(int horas);

int main() {
    int horaInicial, minutoInicial;
    int horaFinal, minutoFinal;
    scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);
    char buffer[256];
    int duracaoEmMinutosEmMinutos = calcularDuracaoEmMinutos(
        converterHoraParaMinutos(horaInicial, minutoInicial),
        converterHoraParaMinutos(horaFinal, minutoFinal)
    );
    duracao duracaoJogo = packDuracao(duracaoEmMinutosEmMinutos);
    sprintf(buffer, "O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", 
        duracaoJogo.qtdHora, duracaoJogo.qtdMinuto);
    printf("%s", buffer);
    return 0;
}

int converterHoraParaMinutos(int horas, int minutos) {
    return converterHorasParaMinutos(horas) + minutos;
}

int calcularDuracaoEmMinutos(int timestampInicial, int timestampFinal) {
    if ( timestampFinal <= timestampInicial) {
        adicionarMais24Horas(&timestampFinal);
    }
    return timestampFinal - timestampInicial;
}

duracao packDuracao(int duracaoEmMinutos) {
    duracao tempo = {0, 0};
    if(duracaoEmMinutos < 60) {
        tempo.qtdMinuto = duracaoEmMinutos;
    }
    else
    {
        tempo.qtdHora = (int) (duracaoEmMinutos / 60);
        tempo.qtdMinuto = duracaoEmMinutos % 60;
    }

    return tempo;

}

void adicionarMais24Horas(int *timestamp) {
    *timestamp += converterHorasParaMinutos(24);
}

int converterHorasParaMinutos(int horas) {
    return horas * 60;
}
