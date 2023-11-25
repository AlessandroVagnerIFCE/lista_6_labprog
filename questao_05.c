#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IDADE_MAX 65
#define IDADE_MIN 20
#define SALARIO_MAX 25000
#define SALARIO_MIN 1320
#define CAD_MAX 100

#define MAX_ALUNOS 40
#define MIN_ALUNOS 10
#define CARGA_HORARIA 80

struct Professor  {
    char *nome;
    unsigned int idade;
    float salario;
    int num_cadastro;
};

struct Disciplina {
    char *nome_disciplina;
    struct Professor *prof;
    unsigned int qtd_alunos;
    unsigned int carga_horaria;
    char *horario; //O horário é uma string para dar mais flexibilidade
    char *sala;
};

int main(int argc, char *argv[])
{
    if (argc != 5) {
        printf("Síntaxe para uso: \n %s [nome da disciplina] [nome do professor] [horário] [sala]\n", *argv);
        exit(1);
    }

    srand(time(NULL));

    //Dados do professor
    struct Professor prof_disciplina;
    prof_disciplina.nome = argv[2];
    prof_disciplina.idade = (rand()%IDADE_MAX) + IDADE_MIN;
    prof_disciplina.salario = (((float)rand()/RAND_MAX) + rand()%SALARIO_MAX) + SALARIO_MIN;
    prof_disciplina.num_cadastro = rand()%CAD_MAX;

    //Dados da disciplina
    struct Disciplina x;
    x.nome_disciplina = argv[1];
    x.prof = &prof_disciplina;
    x.qtd_alunos = (rand()%MAX_ALUNOS) + MIN_ALUNOS;
    x.carga_horaria = CARGA_HORARIA;
    x.horario = argv[3];
    x.sala = argv[4];

    //Imprimir dados do professor
    puts("Dados do professor");
    printf("Nome: %s\n", x.prof->nome);
    printf("Idade: %u\n", x.prof->idade);
    printf("Salário: %.2f\n", x.prof->salario);
    printf("Cadastro: %d\n", x.prof->num_cadastro);
    puts("\n");

    //Imprimir dados da disciplina
    puts("Dados da disciplina");
    printf("Disciplina: %s\n", x.nome_disciplina);
    printf("Professor: %s\n", x.prof->nome);
    printf("Sala: %s\n", x.sala);
    printf("Horário: %s\n", x.horario);
    printf("Tamanho da turma: %u alunos\n", x.qtd_alunos);
    printf("Carga horária: %u\n", x.carga_horaria);

    return 0;
}