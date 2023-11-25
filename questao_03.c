#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_MAX 20
#define QTD_MIN 1
#define NUM_MAX 100

//Recebe um vetor de inteiros e a quantidade de elementos
//Preenche o vetor com valores pseudo-aleatórios
void preencher_vetor(int*, unsigned int);

//Recebe um vetor de inteiros e a quantidade de elementos
//Imprime o vetor
void imprimir_vetor(int *v, unsigned int);

//Recebe um vetor de inteiros e a quantidade de elementos
//Retorna a média aritmética dos valores
float media_artimetica(int*, unsigned int);

struct Vetor  {
    int *p_matriz;
    unsigned int qtd;
    float media;
};

int main()
{
    srand(time(NULL));

    int *v = NULL;
    unsigned int quant = (rand()%QTD_MAX) + QTD_MIN; //Evitar um vetor de 0 elementos

    v = (int*) malloc(quant*sizeof(int));

    if (!v) {
        puts("Não há memória disponível");
        exit(1);
    }

    preencher_vetor(v, quant);

    struct Vetor x;
    x.p_matriz = v;
    x.qtd = quant;
    x.media = media_artimetica(v, quant);

    puts("Vetor gerado:");
    imprimir_vetor(x.p_matriz, x.qtd);
    printf("Quantidade de elementos: %u\n", x.qtd);
    printf("Média dos valores: %.2f\n", x.media);

    free(v);

    return 0;
}

void preencher_vetor(int *v, unsigned int qtd)
{
    for (unsigned int i = 0; i < qtd; i++) {
        *(v + i) = rand()%NUM_MAX;
    }
}

void imprimir_vetor(int *v, unsigned int qtd)
{
    for (unsigned int i = 0; i < qtd; i++) {
        printf("%d\n", *(v + i));
    }
}

float media_artimetica(int *v, unsigned int qtd)
{
    int s = 0;
    for (unsigned int i = 0; i < qtd; i++) {
        s += *(v + i);
    }

    return (float)s/qtd;
}