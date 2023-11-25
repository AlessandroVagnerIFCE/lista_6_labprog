#include <stdio.h>

#define QTD_NOTAS 2

struct Aluno  {
    float n1;
    float n2;
    float media;
};

int main()
{
    struct Aluno al;

    puts("Insira a nota 1 do aluno:");
    scanf("%f", &(al.n1));
    puts("Insira a nota 2 do aluno:");
    scanf("%f", &(al.n2));

    al.media = (al.n1 + al.n2)/QTD_NOTAS;

    printf("Média: %.2f\n", al.media);

    return 0;
}