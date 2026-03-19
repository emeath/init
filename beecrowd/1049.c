/*
https://judge.beecrowd.com/pt/problems/view/1049

beecrowd | 1049
Animal
Por Neilor Tonin, URI  Brasil

Timelimit: 1

Neste problema, você deverá ler 3 palavras que definem o tipo de animal possível segundo o esquema abaixo, da esquerda para a direita.  Em seguida conclua qual dos animais seguintes foi escolhido, através das três palavras fornecidas.


 +===========================================================================+
 |                     ÁRVORE DE CLASSIFICAÇÃO ANIMAL                        |
 +===========================================================================+
 |  NÍVEL 0 (Filo)  |  NÍVEL 1 (Classe)  |  NÍVEL 2 (Dieta)  |    ESPÉCIE    |
 +------------------+--------------------+-------------------+---------------+
 |                  |                    | /[ carnivoro ] ----> "aguia"      |
 |                  | /--- [ ave ] ------+                                   |
 |                  |/                   | \[ onivoro   ] ----> "pomba"      |
 | [ vertebrado ] --+                                                        |
 |                  |\                   | /[ onivoro   ] ----> "homem"      |
 |                  | \--- [ mamifero ] -+                                   |
 |                  |                    | \[ herbivoro ] ----> "vaca"       |
 +------------------+--------------------+-------------------+---------------+
 |                  |                    | /[ hematofago] ----> "pulga"      |
 |                  | /--- [ inseto ] ---+                                   |
 |                  |/                   | \[ herbivoro ] ----> "lagarta"    |
 | [ invertebrado ] +                                                        | 
 |                  |\                   | /[ hematofago] ----> "sanguessuga"|
 |                  | \--- [ anelideo ] -+                                   |
 |                  |                    | \[ onivoro   ] ----> "minhoca"    |
 +===========================================================================+


## Entrada
A entrada contém 3 palavras, uma em cada linha, necessárias para identificar o animal segundo a figura acima, com todas as letras minúsculas.

## Saída
Imprima o nome do animal correspondente à entrada fornecida.


+-------------------------------------------------+-----------------+
|               EXEMPLOS DE ENTRADA               | EXEMPLO DE SAÍDA|
+-------------------------------------------------+-----------------+
| vertebrado                                      |                 |
| mamifero                                        |      homem      |
| onivoro                                         |                 |
+-------------------------------------------------+-----------------+
| vertebrado                                      |                 |
| ave                                             |      aguia      |
| carnivoro                                       |                 |
+-------------------------------------------------+-----------------+
| invertebrado                                    |                 |
| anelideo                                        |     minhoca     |
| onivoro                                         |                 |
+-------------------------------------------------+-----------------+


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum class0 { vertebrado, invertebrado };
enum class1 { ave, mamifero, inseto, anelideo };
enum class2 { carnivoro, onivoro, herbivoro, hematofago };

struct tipo2{
    enum class2 c;
};

struct tipo1{
    enum class1 c;
    struct tipo2 t2;
};

struct animal{
    enum class0 c;
    struct tipo1 t1;
    char *especie;
};

char* readStringDynamically();

int main() {

char *p1 = readStringDynamically();
char *p2 = readStringDynamically();
char *p3 = readStringDynamically();

struct animal a;

if ( strcmp ("vertebrado", p1) == 0 ) a.c = vertebrado;
else a.c = invertebrado;

switch (a.c) {
    case vertebrado: {
        if (strcmp ("ave", p2)==0) a.t1.c = ave;
        else a.t1.c = mamifero;
        break;
    }
    case invertebrado: {
        if(strcmp("inseto", p2)==0) a.t1.c = inseto;
        else a.t1.c = anelideo;
        break;
    }
}

switch (a.t1.c) {
    case ave: {
        if(strcmp("carnivoro", p3) == 0) {
            a.t1.t2.c = carnivoro;
            a.especie = "aguia";
        } 
        else {
            a.t1.t2.c = onivoro;
            a.especie = "pomba";
        }
        break;
    }
    case mamifero: {
        if(strcmp("onivoro", p3)==0) {
            a.t1.t2.c = onivoro;
            a.especie = "homem";
        }
        else {
            a.t1.t2.c = herbivoro;
            a.especie = "vaca";
        }
        break;
    }
    case inseto: {
        if(strcmp("hematofago", p3)==0) {
            a.t1.t2.c = onivoro;
            a.especie = "pulga";
        }
        else {
            a.t1.t2.c = herbivoro;
            a.especie = "lagarta";
        }
        break;
    }
    case anelideo: {
        if(strcmp("hematofago", p3)==0) {
            a.t1.t2.c = onivoro;
            a.especie = "sanguessuga";
        }
        else {
            a.t1.t2.c = onivoro;
            a.especie = "minhoca";
        }
        break;
    }
}

// printf("%s\n%s\n%s\n", p1,p2,p3);

printf("%s\n", a.especie);

free(p1);
free(p2);
free(p3);




return 0;
}


char* readStringDynamically()
{
    // initial length for allocation
    size_t len = 8; // size 8 for string
    char *string = NULL;
    char c;
    size_t aux = 0;
    
    string = (char *) malloc( len * sizeof(char) );
    if (string == NULL) {
        printf("Error allocating memory for string!\n");
        return 1;
    }

    do {
        c = getchar(); // read item by item in buffer
        if (c == '\n') break;
        *(string + aux) = c;
        ++aux;
        if(aux > len) // there's more itens on buffer so we need to allocate more memory
        {
            // the best practice is to put the new address in another pointer,
            // because if there's not memory enough for realocation NULL
            // will be returned so we will lost the previous address of string
            // then we wont be able to dealocate it so we wil have memory leak
            len = len + aux + 21;
            string = (char *) realloc (string, len * sizeof(char));
            if (string == NULL) {
                printf("Error when realocating memory!\n");
                return 1;
            }
        }
    } while(c != '\n');
    // printf("---%d\n", aux);
    *(string + aux) = '\0';

    return string;
}

