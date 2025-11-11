#include <stdio.h>
#include <string.h>

struct jogador {
	int score;
	char nick[32];
	int cheater;
};

void printStruct(struct jogador *ptrJogador) {

	printf("[[[STRUCT]]]\n");
	printf("------------\n");
	printf("Score:   %d\n", (*ptrJogador).score);
	printf("Nick:    %s\n", (*ptrJogador).nick);
	char cheaterBuffer;
	cheaterBuffer = (*ptrJogador).cheater ? 'y' : 'n';
	printf("Cheater: %c\n\n", cheaterBuffer);
	
}

int main(int argc, char *argv[]) {

	struct jogador j1;
	j1.score = 10;
	strncpy(j1.nick, "0xXXX", sizeof("0xXXX"));
	j1.nick[sizeof("0xXXX") + 1] = '\0';
	j1.cheater = 0;

	printStruct(&j1);

	struct jogador *ptrJ;
	ptrJ = &j1;
	(*ptrJ).score = 999;
	(*ptrJ).cheater = 1;


	printStruct(&j1);

	return 0;
}
