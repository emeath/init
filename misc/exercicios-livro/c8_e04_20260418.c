#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Ponto {
    float x;
    float y;
};

struct Retangulo {
    //ponto superior esquedo
    struct Ponto pse;
    //ponto inferior direito
    struct Ponto pid;
   
    /*        
        X--------------
        |             |
        |_____________X
    */
    
};

void limpaBufferEntrada();
float calculaArea(const struct Retangulo *);
float calculaBase(const struct Retangulo *);
float calculaAltura(const struct Retangulo *);
float calcularDiagonal(const struct Retangulo *);
int handleInvalidInput(void *);

void limpaBufferEntrada() {
    char c;
    while( (c = getchar()) != '\n' );
}

float calculaArea(const struct Retangulo *ret) {
    handleInvalidInput( (void *) ret);    
    return calculaBase(ret) * calculaAltura (ret);
}

float calculaBase(const struct Retangulo *ret) {
    handleInvalidInput( (void *) ret);
    float x1 = ret->pse.x;
    float x2 = ret->pid.x;
    if (x2 > x1) return x2 - x1;
    else         return x1 - x2;
}

float calculaAltura(const struct Retangulo *ret) {
    handleInvalidInput( (void *) ret);
    float y2 = ret->pse.y;
    float y1 = ret->pid.y;
    if (y2 > y1) return y2 - y1;
    else         return y1 - y2;
}

float calcularDiagonal(const struct Retangulo *ret) {
    handleInvalidInput( (void *) ret);
    float base = calculaBase(ret);
    float altura = calculaAltura(ret);
    float diagonal = sqrt( base * base + altura * altura );
    return diagonal;
}

int handleInvalidInput(void *pointer) {
    if (pointer == NULL) {
        printf("Invalid pointer...\n");
        exit(1);
    }
    return 1;
}

int main() {
    struct Retangulo retangulo;
    printf("Ponto superior esquerdo (x, y): ");
    scanf("%f%f", &retangulo.pse.x, &retangulo.pse.y);
    limpaBufferEntrada();
    printf("Ponto inferior direito (x, y): ");
    scanf("%f%f", &retangulo.pid.x, &retangulo.pid.y);
    limpaBufferEntrada();
 
    printf("Area = %.2f\n", calculaArea(&retangulo));
    printf("Diagonal principal = %.2f\n", calcularDiagonal(&retangulo)); 
    
    return 0;
}
