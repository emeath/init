#include <stdio.h>
#include <string.h>

int main() {
	char lista[100][32] = {
    		"banana", "manga", "uva", "pera", "banana",
    		"laranja", "uva", "manga", "tomate", "pera",
    		"abacate", "abacaxi", "banana", "melao", "maca",
    		"pera", "uva", "manga", "morango", "kiwi",
    		"banana", "maca", "abacaxi", "tomate", "manga",
    		"uva", "pera", "banana", "goiaba", "nectarina",
    		"manga", "pera", "banana", "uva", "caju",
    		"cereja", "figo", "banana", "manga", "carambola",
    		"acerola", "melao", "maca", "pitaia", "manga",
    		"uva", "pera", "banana", "ameixa", "jabuticaba",
    		"banana", "uva", "manga", "pera", "abacaxi",
    		"maca", "banana", "manga", "uva", "pera",
    		"lichia", "banana", "manga", "amora", "pera",
    		"uva", "damasco", "banana", "manga", "melao",
    		"pera", "banana", "uva", "manga", "maca",
    		"cupuacu", "pera", "banana", "acerola", "uva",
    		"manga", "framboesa", "pera", "banana", "graviola",
    		"uva", "manga", "pera", "banana", "mamao",
			"uva", "manga", "pera", "banana", "caqui",
			"uva", "manga", "pera", "banana", "mamao"
	};

	char set[100][32];
	int flagIsPresent = 0;
	int setIndex = 0;

	for(int i = 0; i < 100; ++i) {
		flagIsPresent = 0;
		for(int j = 0; j < 100; ++j) {
			if (strcmp(lista[i],set[j]) == 0) {
				// printf("0\n");
				flagIsPresent = 1;
				break;
			}
		}
		if(0 == flagIsPresent) {
			strcpy(set[setIndex],lista[i]);
			// printf("%s add em set\n", lista[i]);
			setIndex++;
		}
	}

	// indica fim de set
	strcpy(set[setIndex], "EOS");



	//dump strings
	for(int i = 0; i<100;++i){
		printf("%s\n", lista[i]);
	}
	printf("-------\n");

	int auxSetIndex = 0;
	while ( 0 != strcmp(set[auxSetIndex], "EOS") ) {
		printf("%s\n", set[auxSetIndex]);
		auxSetIndex++;
	}

	
	// printf("%ld\n", sizeof(lista));

	return 0;

}

