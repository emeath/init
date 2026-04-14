#include <dirent.h>
#include <stdio.h>
#include <regex.h>
#include <time.h>
#include <string.h>


// fluxo
// 1- abrir diretorio: ponteiro para o dir atual
// 2- ler conteudo: loop no diretorio. Cada arquivo eh representado por um registro/struct
// 3- fechar diretorio: fechar/liberar recurso

#define DIR_TARGET "."

void getDataAtual(char *bufferDataAtual, size_t stringSize)
{
    if(stringSize < 9) {
        fprintf(stderr, "buffer not big enough to store current date");
        return;
    }
    time_t dataAtual = time(NULL);
    struct tm *dataDecomposta = localtime(&dataAtual);
    strftime(bufferDataAtual, 9, "%Y%m%d", dataDecomposta);
}


int main()
{
    DIR *ponteiroDiretorio;
    ponteiroDiretorio = opendir(DIR_TARGET);

    //struct dirent *ponteiroParaItem = readdir(ponteiroDiretorio);
    //printf("file: %s\n", ponteiroParaItem->d_name);

    struct dirent *arquivo_info = NULL;

    /*
    fluxo regex:
    1. compilar expressao -> regcomp()
    2. exercuar a comparacao -> regexec()
    3. transformar msg de erro pra facil leitura -> regerror()
    4. liberar recurso -> regfree()
    */

    char dataAtual[9];
    char newFilename[100];
    *dataAtual = '\0';
    *newFilename = '\0';

    regex_t regex;
    int ret = regcomp(&regex, "^c[0-9][0-9]_e[0-9][0-9].*", REG_EXTENDED);

    char *lista[] = {"abc", "def", "c00_e00.c", "0c00_e00.g"};

    char b[11] = "_";
    for(int i = 0; i < 4; ++i)
    {
        printf("testando: %s\n", lista[i]);
        ret = regexec(&regex, lista[i], 0, NULL, 0);
        if (ret == REG_NOMATCH) printf("nao encaixa no padrao...\n");
        else {
            printf ("validado!\n");
            getDataAtual(dataAtual, 9);
            snprintf(newFilename, 100, "%s_%s\n", lista[i], dataAtual);
            printf("novo = %s\n", newFilename);
        }
    }

    regfree(&regex);
    
    return 0;

    do {
        arquivo_info = readdir(ponteiroDiretorio);
        if ( NULL == arquivo_info ) {
            break;
        }
        printf("address = %p\n", arquivo_info);
        printf("nome arquivo = %s\n", arquivo_info->d_name);
    } while ( NULL != arquivo_info );
    
    closedir(ponteiroDiretorio);
    return 0;
}
