#ifndef PROFESSOR_H
#define PROFESSOR_H

#define MAX_PROFESSORES 50

typedef struct {
    int matricula;
    char nome[100];
    char sexo;
    char data_nascimento[11]; // formato: DD/MM/AAAA
    char cpf[12]; // formato: XXX.XXX.XXX-XX
} Professor;

void cadastrar_professor(Professor professor[], int *qtd);
void excluir_professor(Professor professor[], int *qtd);
void listar_professores(Professor professor[], int qtd);
void salvar_professores(Professor professor);
int carregar_professores(Professor professores[]);
void listar_professores_por_sexo(Professor professor[], int qtd);
void listar_professores_ordem_alfabetica(Professor professor[], int qtd);
void listar_professores_por_idade(Professor professor[], int *qtd);
void editar_professor(Professor professor[], int *qtd);

#endif