#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 100
#define MAX_DISCIPLINAS 20

typedef struct {
    int matricula;
    char nome[100];
    char sexo;
    char data_nascimento[11];
    char cpf[12];
    int disciplinas[MAX_DISCIPLINAS]; // Adiciona um array de disciplinas para cada aluno
} Aluno;


void cadastrar_aluno(Aluno aluno[], int *qtd);
void excluir_aluno(Aluno aluno[], int *qtd);
int procurar_aluno_por_nome(Aluno alunos[], int *qtd);
void listar_alunos(Aluno aluno[], int qtd);
void listar_alunos_por_sexo(Aluno aluno[], int qtd);
void listar_alunos_ordem_alfabetica(Aluno aluno[], int qtd);
int carregar_alunos(Aluno alunos[]);
void salvar_aluno(Aluno aluno);
void listar_alunos_por_idade(Aluno aluno[], int *qtd);
void editar_aluno(Aluno aluno[], int *qtd);
#endif