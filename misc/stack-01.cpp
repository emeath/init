#include <sys/resource.h>
#include <iostream>
#include <malloc.h>

//
// g++ stack-01.cpp -o stack-01 && ./stack-01
// g++ stack-01.cpp -o stack-01 -DESTOURAR_STACK && ./stack-01
//

// linux
// rode comando ulimit -s -> provavelmente 8192 -> 8MB
// windows
// ~ 1MB

int get_stack_size(void); 
int convert_kb_to_mb(int);
int convert_kb_to_b(int);
void print_stack_size(void);
void print_integer_size(void);
void print_qtd_integers_em_stack(void);
size_t get_int_size(void);
void alocar_inteiros_no_limite(void);
void alocar_inteiros_estourando_limite(void);

// HEAP
// sys 32 bits -> 4gb teorico mas na pratica linux/windows limita para 2gb por processo
// sys 64 bits -> virtualmente infinito, praticamente toda a memoria ram disponivel

int main() {
    print_stack_size();
    print_integer_size();
    print_qtd_integers_em_stack();
    #ifndef ESTOURAR_STACK
    alocar_inteiros_no_limite();
    #endif
    #ifdef ESTOURAR_STACK
    alocar_inteiros_estourando_limite();
    #endif
    return 0;
}

int get_stack_size(void) {
    struct rlimit limit;
    if(getrlimit(RLIMIT_STACK, &limit) == 0) {
        return limit.rlim_cur / 1024;
    }
    return -1;
}

void print_stack_size(void) {
    std::cout << "Tamanho da stack: " 
              << get_stack_size() 
              << " KB (ou KibiByte) | " 
              << convert_kb_to_b(get_stack_size()) 
              << " Bytes." 
              << std::endl;
    std::cout << "Tamanho da stack: " 
              << convert_kb_to_mb(get_stack_size()) 
              << " MB (ou MebiByte)" 
              << std::endl;
}

int convert_kb_to_b(int kb)
{
    return kb * 1024;
}

int convert_kb_to_mb(int kb) {
    return kb / 1024;
}

void print_integer_size(void) {
    std::cout << "Tamanho de um int: " << get_int_size() << " Bytes" << std::endl;
}

void print_qtd_integers_em_stack(void) {
    std::cout << "Cabem " << (get_stack_size() * 1024) / get_int_size() << " inteiros nessa stack." << std::endl;
}

size_t get_int_size(void) {
    return sizeof(int);
}

void alocar_inteiros_no_limite(void)
{
    // diretivas de pre-processamento (#define) nao seguem regra de escopo
    constexpr int tamanho =
    #if __cplusplus >= 201402L
        2'000'000;
    #else
        2000000;
    #endif
    int array[tamanho];
}

void alocar_inteiros_estourando_limite(void) // segmentation fault (core dumped)
{
    // diretivas de pre-processamento (#define) nao seguem regra de escopo
    constexpr int tamanho =
    #if __cplusplus >= 201402L
        2'097'153;
    #else
        2097153;
    #endif
    int array[tamanho];
}

