#include <stdio.h>
#include "aluno.h"
#include "../utils/utils.h"
#include <string.h>


int ja_existe_matricula_aluno(Aluno aluno[], int *qtd, int matricula) {
    for (int i = 0; i < *qtd; i++) {
        if (aluno[i].matricula == matricula) {
            return 1; // Matrícula já existe
        }
    }
    return 0; // Matrícula não existe
}

void cadastrar_aluno(Aluno aluno[], int *qtd) {
    if (*qtd >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }
    int matricula_temp=0;
    char cpf_temp[12];
    char data_temp[11];
    char sexo_temp;

     // Validação da matrícula

    printf("Digite a matrícula: ");
    scanf("%d", &matricula_temp);
    if(ja_existe_matricula_aluno(aluno, qtd, matricula_temp)){
        printf("Matrícula já existe. Tente novamente.\n");
        return;
    }

    aluno[*qtd].matricula = matricula_temp;

    printf("Digite o nome: ");
    scanf(" %[^\n]", aluno[*qtd].nome);

    // Validação do sexo
    printf("Sexo (M/F): ");
    scanf(" %c", &sexo_temp);
    if (!validar_sexo(sexo_temp)) {
        printf("Sexo inválido. Use 'M' para masculino ou 'F' para feminino.\n");
        return;
    }
    aluno[*qtd].sexo = sexo_temp;

    // Validação da data de nascimento
    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf(" %[^\n]", data_temp);
    if (!validar_data(data_temp)) {
        printf("Data de nascimento inválida.\n");
        return;
    }
    strcpy(aluno[*qtd].data_nascimento, data_temp);

    //validação do CPF
    printf("CPF: ");
    scanf(" %[^\n]", cpf_temp);
    if (!validar_cpf(cpf_temp)) {
        printf("CPF inválido.\n");
        return;
    }
    strcpy(aluno[*qtd].cpf, cpf_temp);


    (*qtd)++;

    salvar_aluno(aluno[*qtd - 1]);
}


void excluir_aluno(Aluno aluno[], int *qtd) {
    int matricula;
    printf("Digite a matrícula do aluno a ser excluído: ");
    scanf("%d", &matricula);

    for (int i = 0; i < *qtd; i++) {
        if (aluno[i].matricula == matricula) {
            // "Exclui" o aluno movendo os seguintes para trás
            for (int j = i; j < *qtd - 1; j++) {
                aluno[j] = aluno[j + 1];
            }
            (*qtd)--;
            printf("Aluno excluído com sucesso!\n");
            return;
        }
    }
    printf("Aluno com matrícula %d não encontrado.\n", matricula);
}

int procurar_aluno_por_nome(Aluno alunos[], int *qtd) {
    char nome_procurado[100];

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome_procurado);

    for(int i = 0; i < *qtd; i++){
        if(strcmp(alunos[i].nome, nome_procurado) == 0){
            return i; // retorna a posição
        }
    }

    return -1; // não achou
}

void listar_alunos(Aluno aluno[], int qtd) {
    printf("--------------------------\n");
    printf("Lista de Alunos:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Matrícula: %d\n", aluno[i].matricula);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Sexo: %c\n", aluno[i].sexo);
        printf("Data de Nascimento: %s\n", aluno[i].data_nascimento);
        printf("CPF: %s\n", aluno[i].cpf);
        printf("-------------------------\n");
    }
}

void listar_alunos_por_sexo(Aluno aluno[], int qtd) {
    char sexo;
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);
    printf("Lista de Alunos do sexo %c:\n", sexo);
    printf("--------------------------\n");
    for (int i = 0; i < qtd; i++) {
        if (aluno[i].sexo == sexo) {
            printf("Matrícula: %d\n", aluno[i].matricula);
            printf("Nome: %s\n", aluno[i].nome);
            printf("Data de Nascimento: %s\n", aluno[i].data_nascimento);
            printf("CPF: %s\n", aluno[i].cpf);
            printf("-------------------------\n");
        }
    }
}

void listar_alunos_ordem_alfabetica(Aluno aluno[], int qtd) {
    // Implementação de ordenação por nome (exemplo: bubble sort)
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (strcasecmp(aluno[j].nome, aluno[j + 1].nome) > 0) { // comparação case-insensitive 
                Aluno temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
    printf("Lista de Alunos em Ordem Alfabética:\n");
        printf("--------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("Matrícula: %d\n", aluno[i].matricula);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Sexo: %c\n", aluno[i].sexo);
        printf("Data de Nascimento: %s\n", aluno[i].data_nascimento);
        printf("CPF: %s\n", aluno[i].cpf);
        printf("-------------------------\n");
    }
}

void listar_alunos_por_idade(Aluno aluno[], int *qtd) {
    // Implementação de ordenação por idade (exemplo: bubble sort)
    for (int i = 0; i < *qtd - 1; i++) {
        for (int j = 0; j < *qtd - i - 1; j++) {
            if (strcmp(aluno[j].data_nascimento, aluno[j + 1].data_nascimento) > 0) { // comparação de datas
                Aluno temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
    printf("Lista de Alunos por Idade:\n");
        printf("--------------------------\n");
    for (int i = 0; i < *qtd; i++) {
        printf("Matrícula: %d\n", aluno[i].matricula);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Sexo: %c\n", aluno[i].sexo);
        printf("Data de Nascimento: %s\n", aluno[i].data_nascimento);
        printf("CPF: %s\n", aluno[i].cpf);
         printf("-------------------------\n");
    }
}

void editar_aluno(Aluno aluno[], int *qtd) {
    int matricula;
    printf("Digite a matrícula do aluno a ser editado: ");
    scanf("%d", &matricula);

    int sexo_temp;
    char data_temp[11];
    char cpf_temp[15];
    for (int i = 0; i < *qtd; i++) {
        if (aluno[i].matricula == matricula) {
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", aluno[i].nome);
            
            printf("Digite o novo sexo (M/F): ");
            scanf(" %c", &sexo_temp);
            if (!validar_sexo(sexo_temp)) {
                printf("Sexo inválido. Use 'M' para masculino ou 'F' para feminino.\n");
                return;
            }
            aluno[i].sexo = sexo_temp;

            printf("Digite a nova data de nascimento (DD/MM/AAAA): ");
            scanf(" %[^\n]", data_temp);
            if (!validar_data(data_temp)) {
                printf("Data de nascimento inválida.\n");
                return;
            }
            strcpy(aluno[i].data_nascimento, data_temp);

            printf("Digite o novo CPF: ");
            scanf(" %[^\n]", cpf_temp);
            if (!validar_cpf(cpf_temp)) {
                printf("CPF inválido.\n");
                return;
            }
            strcpy(aluno[i].cpf, cpf_temp);
            
            printf("Aluno editado com sucesso!\n");
            return;
        }
    }

    printf("Aluno com matrícula %d não encontrado.\n", matricula);
}


int carregar_alunos(Aluno alunos[]) {
    FILE *f = fopen("bd/alunos.txt", "r");

    if (f == NULL) {
        return 0;
    }

    int i = 0;

    while (fscanf(f, "%d;%99[^;];%c;%10[^;];%11[^\n]\n",
        &alunos[i].matricula,
        alunos[i].nome,
        &alunos[i].sexo,
        alunos[i].data_nascimento,
        alunos[i].cpf) == 5) {

        // inicializa disciplinas
        for (int j = 0; j < MAX_DISCIPLINAS; j++) {
            alunos[i].disciplinas[j] = 0;
        }

        i++;
    }

    fclose(f);
    return i;
}


void salvar_aluno(Aluno aluno) {
    FILE *f = fopen("bd/alunos.txt", "a");

    if (f == NULL) return;

    fprintf(f, "%d;%s;%c;%s;%s\n",
        aluno.matricula,
        aluno.nome,
        aluno.sexo,
        aluno.data_nascimento,
        aluno.cpf
    );

    fclose(f);
}

