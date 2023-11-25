#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MAX 50

struct Estoque  {
    char *nomePeca;
    int numPeca;
    float preco;
    int numPedido;
};

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Síntaxe para uso: \n %s [nome da peça] [preço]\n", *argv);
        exit(1);
    }

    srand(time(NULL));

    struct Estoque x;
    x.nomePeca = argv[1];
    x.numPeca = rand()%NUM_MAX;
    x.preco = atof(argv[2]);
    x.numPedido = rand()%NUM_MAX;

    puts("\n");
    printf("Nome: %s\n", x.nomePeca);
    printf("Número da peça: %d\n", x.numPeca);
    printf("Preço: %.2f\n", x.preco);
    printf("Número do pedido: %d\n", x.numPedido);

    return 0;
}