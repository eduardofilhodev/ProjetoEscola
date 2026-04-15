#ifndef UTILS_H
#define UTILS_H


#include "../aluno/aluno.h"
#include "../professor/professor.h"


int validar_cpf(const char *cpf);
int validar_data(const char *data);
int validar_sexo(char sexo);
int validar_matricula_aluno(Aluno *aluno, int *qtd, int matricula);
int validar_matricula_professor(Professor *professor, int *qtd, int matricula);
int validar_vagas(int vagas);
void lista_aniversariantes(Aluno *aluno, Professor *professor, int qtd);
void buscar_pessoas_por_nome(Aluno *aluno, Professor *professor, int qtd);
int validar_professor_matricula(Professor *professor, int matricula);
// int validar_codigo_disciplina(Disciplina *disciplina, int *qtd, int codigo);
#endif