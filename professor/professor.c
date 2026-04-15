#include <stdio.h>
#include "professor.h"
#include <string.h>
#include "../utils/utils.h"

void cadastrar_professor(Professor professor[], int *qtd) {
    if (*qtd >= MAX_PROFESSORES) {
        printf("Limite de professores atingido.\n");
        return;
    }

    int matricula_temp;
    char cpf_temp[12];
    char data_temp[11];
    char sexo_temp;

    printf("Digite a matrícula: ");
    scanf("%d", &matricula_temp);
    if(validar_professor_matricula(professor, matricula_temp)==0){
        printf("Matrícula já existe. Tente novamente.\n");
        return;
    }
    professor[*qtd].matricula = matricula_temp;

    printf("Digite o nome: ");
    scanf(" %[^\n]", professor[*qtd].nome);

    // Validação do sexo
    printf("Sexo (M/F): ");
    scanf(" %c", &sexo_temp);
    if (!validar_sexo(sexo_temp)) {
        printf("Sexo inválido. Use 'M' para masculino ou 'F' para feminino.\n");
        return;
    }
    professor[*qtd].sexo = sexo_temp;
  
    // Validação da data de nascimento
    printf("Data de nascimento: ");
    scanf(" %[^\n]", data_temp);
    if (!validar_data(data_temp)) {
        printf("Data de nascimento inválida.\n");
        return;
    }
    strcpy(professor[*qtd].data_nascimento, data_temp);

    // Validação do CPF
    printf("CPF: ");
    scanf(" %[^\n]", cpf_temp);
    if (!validar_cpf(cpf_temp)) {
        printf("CPF inválido.\n");
        return;
    }
    strcpy(professor[*qtd].cpf, cpf_temp);

    (*qtd)++;
    salvar_professores(professor[*qtd - 1]);
}

void excluir_professor(Professor professor[], int *qtd) {
    int matricula;
    printf("Digite a matrícula do professor a ser excluído: ");
    scanf("%d", &matricula);

    for (int i = 0; i < *qtd; i++) {
        if (professor[i].matricula == matricula) {
            // "Exclui" o professor movendo os seguintes para trás
            for (int j = i; j < *qtd - 1; j++) {
                professor[j] = professor[j + 1];
            }
            (*qtd)--;
            printf("Professor excluído com sucesso!\n");
            return;
        }
    }
    printf("Professor com matrícula %d não encontrado.\n", matricula);
}

void listar_professores(Professor professor[], int qtd) {
    printf("Lista de Professores:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Matrícula: %d\n", professor[i].matricula);
        printf("Nome: %s\n", professor[i].nome);
        printf("Sexo: %c\n", professor[i].sexo);
        printf("Data de Nascimento: %s\n", professor[i].data_nascimento);
        printf("CPF: %s\n", professor[i].cpf);
        printf("-------------------------\n");
    }
}

void listar_professores_por_sexo(Professor professor[], int qtd) {
    char sexo;
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);
    printf("Lista de Professores do sexo %c:\n", sexo);
    printf("--------------------------\n");
    for (int i = 0; i < qtd; i++) {
        if (professor[i].sexo == sexo) {
            printf("Matrícula: %d\n", professor[i].matricula);
            printf("Nome: %s\n", professor[i].nome);
            printf("Data de Nascimento: %s\n", professor[i].data_nascimento);
            printf("CPF: %s\n", professor[i].cpf);
            printf("-------------------------\n");
        }
    }
}

void listar_professores_ordem_alfabetica(Professor professor[], int qtd) {
    // Implementação de ordenação por nome (exemplo: bubble sort)
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (strcasecmp(professor[j].nome, professor[j + 1].nome) > 0) { // comparação case-insensitive 
                Professor temp = professor[j];
                professor[j] = professor[j + 1];
                professor[j + 1] = temp;
            }
        }
    }
    printf("Lista de Professores em Ordem Alfabética:\n");
        printf("--------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("Matrícula: %d\n", professor[i].matricula);
        printf("Nome: %s\n", professor[i].nome);
        printf("Sexo: %c\n", professor[i].sexo);
        printf("Data de Nascimento: %s\n", professor[i].data_nascimento);
        printf("CPF: %s\n", professor[i].cpf);
        printf("-------------------------\n");
    }
}

void listar_professores_por_idade(Professor professor[], int *qtd) {
    // Implementação de ordenação por idade (exemplo: bubble sort)
    for (int i = 0; i < *qtd - 1; i++) {
        for (int j = 0; j < *qtd - i - 1; j++) {
            if (strcmp(professor[j].data_nascimento, professor[j + 1].data_nascimento) > 0) { // comparação de datas
                Professor temp = professor[j];
                professor[j] = professor[j + 1];
                professor[j + 1] = temp;
            }
        }
    }
    printf("Lista de Professores por Idade:\n");
        printf("--------------------------\n");
    for (int i = 0; i < *qtd; i++) {
        printf("Matrícula: %d\n", professor[i].matricula);
        printf("Nome: %s\n", professor[i].nome);
        printf("Sexo: %c\n", professor[i].sexo);
        printf("Data de Nascimento: %s\n", professor[i].data_nascimento);
        printf("CPF: %s\n", professor[i].cpf);
         printf("-------------------------\n");
    }
}

void editar_professor(Professor professor[], int *qtd) {
    int matricula;
    printf("Digite a matrícula do professor a ser editado: ");
    scanf("%d", &matricula);

    int sexo_temp;
    char data_temp[11];
    char cpf_temp[15];


    for (int i = 0; i < *qtd; i++) {
        if (professor[i].matricula == matricula) {
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", professor[i].nome);

            printf("Digite o novo sexo (M/F): ");
            scanf(" %c", &sexo_temp);
            if (!validar_sexo(sexo_temp)) {
                printf("Sexo inválido. Use 'M' para masculino ou 'F' para feminino.\n");
                return;
            }
            professor[i].sexo = sexo_temp;
            printf("Digite a nova data de nascimento (DD/MM/AAAA): ");
            scanf(" %[^\n]", data_temp);
            if (!validar_data(data_temp)) {
                printf("Data de nascimento inválida.\n");
                return;
            }
            strcpy(professor[i].data_nascimento, data_temp);

            printf("Digite o novo CPF: ");
            scanf(" %[^\n]", cpf_temp);
            if (!validar_cpf(cpf_temp)) {
                printf("CPF inválido.\n");
                return;
            }
            strcpy(professor[i].cpf, cpf_temp);
            printf("Professor editado com sucesso!\n");
            return;
        }
    }
    printf("Professor com matrícula %d não encontrado.\n", matricula);
}


int carregar_professores(Professor professores[]) {
    FILE *f = fopen("bd/professores.txt", "r");

    if (f == NULL) {
        return 0;
    }

    int i = 0;

    while (fscanf(f, "%d;%99[^;];%c;%10[^;];%11[^\n]\n",
        &professores[i].matricula,
        professores[i].nome,
        &professores[i].sexo,
        professores[i].data_nascimento,
        professores[i].cpf) == 5) {

        i++;
    }

    fclose(f);
    return i;
}


void salvar_professores(Professor professor) {
    FILE *f = fopen("bd/professores.txt", "a");

    if (f == NULL) return;

    fprintf(f, "%d;%s;%c;%s;%s\n",
        professor.matricula,
        professor.nome,
        professor.sexo,
        professor.data_nascimento,
        professor.cpf
    );

    fclose(f);
}