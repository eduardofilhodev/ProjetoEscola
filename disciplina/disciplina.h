#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#define MAX_DISCIPLINAS 20
#define MAX_ALUNOS_POR_DISCIPLINA 60

#include "../professor/professor.h"
#include "../aluno/aluno.h"


typedef struct {
    char nome[100];
    int codigo;
    int semestre;
    int vagas;
    Professor professor;
    Aluno aluno[MAX_ALUNOS_POR_DISCIPLINA];
} Disciplina;

void cadastrar_disciplina(Disciplina disciplina[], int *qtd);
void excluir_disciplina(Disciplina disciplina[], int *qtd);
void matricular_aluno(Disciplina disciplina[], int qtd_disciplinas, Aluno aluno[], int qtd_alunos);
void excluir_aluno_disciplina(Disciplina disciplina[], int qtd_disciplinas, Aluno aluno[], int qtd_alunos);
int procurar_disciplina_por_nome(Disciplina disciplina[], int *qtd);
void listar_disciplinas(Disciplina disciplina[], int qtd);
void listar_alunos_matriculados(Disciplina disciplina[], int qtd_disciplinas);
int carregar_disciplinas(Disciplina disciplinas[]);
void salvar_disciplinas(Disciplina disciplina);
void listar_alunos_em_menos_de_3_disciplinas(Disciplina disciplina[], int qtd_disciplinas);
void disciplinas_extrapolam_vagas(Disciplina disciplina[], int qtd_disciplinas);
void editar_disciplina(Disciplina disciplina[], int *qtd);

#endif // DISCIPLINA_H