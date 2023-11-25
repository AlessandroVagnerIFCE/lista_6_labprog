#include <stdio.h>

#define QTD_ALUNOS 3
#define QTD_NOTAS 2

struct Aluno  {
    float n1;
    float n2;
    float media;
};

//Recebe um vetor de alunos e a quantidade de alunos
//Calcula e atualiza a média de cada um dos alunos, e retorna uma média geral
float media_alunos(struct Aluno*, unsigned int);

int main()
{
    struct Aluno al1, al2, al3;
    struct Aluno alunos[] = {al1, al2, al3};

    //Obter as notas
    for (unsigned char i = 0; i < QTD_ALUNOS; i++) {
        printf("Insira a nota 1 do aluno %hhu:\n", i+1);
        scanf("%f", &((alunos+i)->n1));
        printf("Insira a nota 2 do aluno %hhu:\n", i+1);
        scanf("%f", &((alunos+i)->n2)); 
    }

    //Calcular as médias
    float media_geral = media_alunos(alunos, QTD_ALUNOS);

    //Imprimir as médias
    for (unsigned char j = 0; j < QTD_ALUNOS; j++) {
        printf("Média do aluno %u: %.2f\n", j+1, (alunos + j)->media);
    }
    printf("Média geral: %.2f\n", media_geral);

    /*
    puts("Insira a nota 1 do aluno 1:");
    scanf("%f", &(al1.n1));
    puts("Insira a nota 2 do aluno 1:");
    scanf("%f", &(al1.n2));
    */

    //al.media = (al.n1 + al.n2)/QTD_NOTAS;

    //printf("Média: %.2f\n", al.media);

    return 0;
}

float media_alunos(struct Aluno *v, unsigned int qtd_alunos)
{
    float s = 0;
    for (unsigned int i = 0; i < qtd_alunos; i++) {
        (v + i)->media = ((v + i)->n1 + (v + i)->n2)/QTD_NOTAS;
        s += (v + i)->media;
    }

    return s/(qtd_alunos); //Média geral
}