#include <stdio.h>
#include <string.h>

#include "../disciplina/disciplina.h"   
#include "../aluno/aluno.h"
#include "../professor/professor.h"
#include "utils.h"

int validar_cpf(const char *cpf) {
    int i, j, sum = 0, rest;
    int cpf_digits[11];

    // Verificar se o CPF tem 11 dígitos
    for (i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return 0; // CPF inválido
        }
        cpf_digits[i] = cpf[i] - '0'; // Converter char para int
    }

    // Verificar se todos os dígitos são iguais (CPF inválido)
    for (i = 1; i < 11; i++) {
        if (cpf_digits[i] != cpf_digits[0]) {
            break;
        }   
    }
    if (i == 11) {
        return 0; // CPF inválido
    }

    // Calcular o primeiro dígito verificador
    for (i = 0, j = 10; i < 9; i++, j--) {
        sum += cpf_digits[i] * j;
    }
    rest = sum % 11;
    if (rest < 2) {
        rest = 0;
    } else {
        rest = 11 - rest;
    }
    if (cpf_digits[9] != rest) {
        return 0; // CPF inválido
    }

    // Calcular o segundo dígito verificador
    sum = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        sum += cpf_digits[i] * j;
    }
    rest = sum % 11;
    if (rest < 2) {
        rest = 0;
    } else {
        rest = 11 - rest;
    }
    if (cpf_digits[10] != rest) {
        return 0; // CPF inválido
    }

    return 1; // CPF válido
}


int validar_data(const char *data) {
    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        return 0; // Formato inválido
    }
    if (ano < 1900 || ano > 2100) {
        return 0; // Ano inválido
    }
    if (mes < 1 || mes > 12) {
        return 0; // Mês inválido
    }
    if (dia < 1 || dia > 31) {
        return 0; // Dia inválido
    }
    // Verificar dias em meses específicos
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0; // Mês com apenas 30 dias
    }
    if (mes == 2) {
        int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (dia > (bissexto ? 29 : 28)) {
            return 0; // Fevereiro com dias inválidos
        }
    }
    return 1; // Data válida
}

int validar_sexo(char sexo) {
    if (sexo == 'M' || sexo == 'F' || sexo == 'O') {
        return 1; // Sexo válido
    }
    return 0; // Sexo inválido
}

int validar_matricula_aluno(Aluno *aluno, int *qtd, int matricula) {
    if (matricula > 0) {
        for(int i = 0; i < *qtd; i++) {
            if (aluno[i].matricula != matricula) {
                return 1; // Matrícula válida
            }
        }
    }
    return 0; // Matrícula inválida
}

int validar_matricula_professor(Professor *professor, int *qtd, int matricula) {
    if (matricula > 0) {
        for(int i = 0; i < *qtd; i++) {
            if (professor[i].matricula != matricula) {
                return 1; // Matrícula válida
            }
        }
    }
    return 0; // Matrícula inválida
}

int validar_vagas(int vagas) {
    if (vagas > 0 && vagas <= 60 /*MAX_ALUNOS_POR_DISCIPLINA*/) {
        return 1; // Vagas válidas
    }
    return 0; // Vagas inválidas
}

/*int validar_codigo_disciplina(Disciplina *disciplina, int *qtd, int codigo) {
    if (codigo > 0) {
        for(int i = 0; i < *qtd; i++) {
            if (disciplina[i].codigo == codigo) {
                return 0; // Código já existe
            }
        }
    }
    return 1; // Código válido
}*/

int validar_professor_matricula(Professor *professor, int matricula) {
    if (matricula > 0) {
        for(int i = 0; i < 50; i++) {
            if (professor[i].matricula == matricula) {
                return 1; // Professor encontrado
            }
        }
    }
    return 0; // Professor não encontrado
}

void lista_aniversariantes(Aluno *aluno, Professor *professor, int qtd) {
    char mes[3];
    printf("Digite o mês (MM) para listar os aniversariantes: ");
    scanf("%2s", mes);

    printf("Aniversariantes do mês %s:\n", mes);
    for (int i = 0; i < qtd; i++) {
        if (aluno[i].data_nascimento[3] == mes[0] && aluno[i].data_nascimento[4] == mes[1]) {
            printf("Aluno: %s\n", aluno[i].nome);
        }
        if (professor[i].data_nascimento[3] == mes[0] && professor[i].data_nascimento[4] == mes[1]) {
            printf("Professor: %s\n", professor[i].nome);
        }
    }
}



/*

◦Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no
mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no
nome.

*/
void buscar_pessoas_por_nome(Aluno *aluno, Professor *professor, int qtd) {
    char nome_procurado[100];
    printf("Digite o nome a ser procurado: ");
    scanf(" %[^\n]", nome_procurado);
    if(nome_procurado[0] == '\0' || strlen(nome_procurado) < 3){
        printf("Por favor, digite pelo menos 3 letras para a busca.\n");
        return;
    }

    printf("Resultados da busca por nome '%s':\n", nome_procurado);
    for (int i = 0; i < qtd; i++) {
        if (strcmp(aluno[i].nome, nome_procurado) == 0) {
            printf("Aluno encontrado: %s - Matrícula: %d\n", aluno[i].nome, aluno[i].matricula);
        }
        if (strcmp(professor[i].nome, nome_procurado) == 0) {
            printf("Professor encontrado: %s - Matrícula: %d\n", professor[i].nome, professor[i].matricula);
        }
    }

    for (int i = 0; i < qtd; i++) {
        if (strstr(aluno[i].nome, nome_procurado) != NULL) {
            printf("Aluno encontrado: %s - Matrícula: %d\n", aluno[i].nome, aluno[i].matricula);
        }
        if (strstr(professor[i].nome, nome_procurado) != NULL) {
            printf("Professor encontrado: %s - Matrícula: %d\n", professor[i].nome, professor[i].matricula);
        }
    }


}

