#include <stdio.h>
#include "disciplina.h"
#include "../aluno/aluno.h"
#include <string.h>
#include "../utils/utils.h"

void cadastrar_disciplina(Disciplina disciplina[], int *qtd) {
    int codigo_temp, semestre_temp, vagas_temp, matricula_professor_temp;
    char nome_temp[100];

    if (*qtd >= MAX_DISCIPLINAS) {
        printf("Limite de disciplinas atingido.\n");
        return;
    }

    // Validação do nome da disciplina
    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", nome_temp);
    if(procurar_disciplina_por_nome(disciplina, qtd) != -1){
        printf("Disciplina já existe. Tente novamente.\n");
        return;
    }
    strcpy(disciplina[*qtd].nome, nome_temp);

    //validação do código da disciplina
    printf("Digite o código da disciplina: ");
    scanf("%d", &disciplina[*qtd].codigo);


    //validação do semestre da disciplina
    printf("Digite o semestre da disciplina: ");
    scanf("%d", &semestre_temp);
    if(semestre_temp <= 0 || semestre_temp > 10){ // considerando um curso de até 10 semestres  
        printf("Semestre inválido. Tente novamente.\n");
        return;
    }
    disciplina[*qtd].semestre = semestre_temp;

    //validação do número de vagas
    printf("Digite o número de vagas da disciplina: ");
    scanf("%d", &vagas_temp);
    if (!validar_vagas(vagas_temp)) {
        printf("Número de vagas inválido.\n");
        return;
    }
    disciplina[*qtd].vagas = vagas_temp;


    printf("Digite a matrícula do professor responsável: ");
    scanf("%d", &disciplina[*qtd].professor.matricula);
    
    printf("Matricula realizada com sucesso!\n");

    (*qtd)++;
    salvar_disciplinas(disciplina[*qtd - 1]);
}

void excluir_disciplina(Disciplina disciplina[], int *qtd) {
    char nome[100];
    printf("Digite o nome da disciplina a ser excluída: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < *qtd; i++) {
        if (strcmp(disciplina[i].nome, nome) == 0) {
            // "Exclui" a disciplina movendo as seguintes para trás
            for (int j = i; j < *qtd - 1; j++) {
                disciplina[j] = disciplina[j + 1];
            }
            (*qtd)--;
            printf("Disciplina excluída com sucesso!\n");
            return;
        }
    }
    printf("Disciplina com nome %s não encontrada.\n", nome);
}



int procurar_disciplina_por_nome(Disciplina disciplinas[], int *qtd) {
    char nome_procurado[100];

    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", nome_procurado);

    for(int i = 0; i < *qtd; i++){
        if(strcmp(disciplinas[i].nome, nome_procurado) == 0){
            return i; // retorna a posição
        }
    }
    return -1; // não achou
}

void matricular_aluno(Disciplina disciplina[], int qtd_disciplinas, Aluno aluno[], int qtd_alunos) {
/*
    char nome_disciplina[100];
    char nome_aluno[100];

    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", nome_disciplina);

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome_aluno);
*/
    int posD = procurar_disciplina_por_nome(disciplina, &qtd_disciplinas);
    int posA = procurar_aluno_por_nome(aluno, &qtd_alunos);
    int j=0;

    if(posD == -1){
        printf("\n----------------------------------------\n");
        printf("Disciplina nao encontrada.\n");
        printf("----------------------------------------\n");
        return;
    }
    if(posA == -1){
        printf("\n----------------------------------------\n");
        printf("Aluno nao encontrado.\n");
        printf("----------------------------------------\n");
        return;
    }
    
    if(disciplina[posD].vagas <= 0){
        printf("\n----------------------------------------\n");
        printf("Não há vagas disponíveis nessa disciplina.\n");
        printf("----------------------------------------\n");
        return;
    }


    if(posD != -1 && posA != -1){
        for(j = 0; j < MAX_ALUNOS_POR_DISCIPLINA; j++){
            if(aluno[posA].disciplinas[j] == 0){ // posição vazia
                break;
            }
            if(aluno[posA].disciplinas[j] == disciplina[posD].codigo){ // aluno já matriculado nessa disciplina
                printf("Aluno já matriculado nessa disciplina.\n");
                return;
            }
            if(j == MAX_DISCIPLINAS - 1){ // chegou no limite de disciplinas do aluno
                printf("Limite de disciplinas para o aluno atingido.\n");
                return;
            }
        }
    }
    

    if(posD != -1 && posA != -1){
        // aqui você matricula ele na disciplina
        for(int i = 0; i < MAX_ALUNOS_POR_DISCIPLINA; i++){
            if(disciplina[posD].aluno[i].matricula == 0){ // posição vazia
                disciplina[posD].aluno[i] = aluno[posA]; // matricula o aluno
                aluno[posA].disciplinas[j] = disciplina[posD].codigo; // adiciona a disciplina na lista do aluno
                disciplina[posD].vagas--; // decrementa a vaga
                printf("Aluno matriculado com sucesso!\n");
                return;
            }
        }
        printf("Limite de alunos na disciplina atingido.\n");
    } else {
        printf("Aluno ou disciplina nao encontrados\n");
    }
}

void excluir_aluno_disciplina(Disciplina disciplina[], int qtd_disciplinas, Aluno aluno[], int qtd_alunos) {
    char nome_disciplina[100];
    char nome_aluno[100];

    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", nome_disciplina);

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome_aluno);

    int posD = procurar_disciplina_por_nome(disciplina, &qtd_disciplinas);
    int posA = procurar_aluno_por_nome(aluno, &qtd_alunos);

    if(posD != -1 && posA != -1){
        // aqui você exclui ele da disciplina
        for(int i = 0; i < MAX_ALUNOS_POR_DISCIPLINA; i++){
            if(disciplina[posD].aluno[i].matricula == aluno[posA].matricula){ // encontrou o aluno
                disciplina[posD].aluno[i].matricula = 0; // "exclui" o aluno
                printf("Aluno excluido com sucesso!\n");
                return;
            }
        }
        printf("Aluno nao matriculado nessa disciplina.\n");
    } else {
        printf("Aluno ou disciplina nao encontrados\n");
    }
}

void listar_disciplinas(Disciplina disciplina[], int qtd) {
    printf("Lista de Disciplinas:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Nome: %s\n", disciplina[i].nome);
        printf("Código: %d\n", disciplina[i].codigo);
        printf("Semestre: %d\n", disciplina[i].semestre);
        printf("Matricula do Professor Responsável: %d\n", disciplina[i].professor.matricula);
        printf("-------------------------\n");
    }
}

void listar_alunos_matriculados(Disciplina disciplina[], int qtd_disciplinas) {
    for (int i = 0; i < qtd_disciplinas; i++) {
        printf("Disciplina: %s\n", disciplina[i].nome);
        printf("Alunos Matriculados:\n");
        for (int j = 0; j < MAX_ALUNOS_POR_DISCIPLINA; j++) {
            if (disciplina[i].aluno[j].matricula != 0) { // Verifica se há um aluno matriculado
                printf("- %s\n", disciplina[i].aluno[j].nome);
            }
        }
        printf("-------------------------\n");
    }
}

void listar_alunos_em_menos_de_3_disciplinas(Disciplina disciplina[], int qtd_disciplinas) {
    printf("Alunos matriculados em menos de 3 disciplinas:\n");
    for (int i = 0; i < qtd_disciplinas; i++) {
        for (int j = 0; j < MAX_ALUNOS_POR_DISCIPLINA; j++) {
            if (disciplina[i].aluno[j].matricula != 0) { // Verifica se há um aluno matriculado
                int contador_disciplinas = 0;
                for (int k = 0; k < MAX_DISCIPLINAS; k++) {
                    if (disciplina[i].aluno[j].disciplinas[k] != 0) {
                        contador_disciplinas++;
                    }
                }
                if (contador_disciplinas < 3) {
                    printf("- %s\n", disciplina[i].aluno[j].nome);
                }
            }
        }
    }
}


//◦Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.[]

void disciplinas_extrapolam_vagas(Disciplina disciplina[], int qtd_disciplinas) {
    printf("Disciplinas que extrapolam 40 vagas:\n");
    for (int i = 0; i < qtd_disciplinas; i++) {
        if (disciplina[i].vagas > 40) {
            printf("- %s (Professor: %s)\n", disciplina[i].nome, disciplina[i].professor.nome);
        }
    }
}

void editar_disciplina(Disciplina disciplina[], int *qtd) {
    char nome[100];
    printf("Digite o nome da disciplina a ser editada: ");
    scanf(" %[^\n]", nome);

    int codigo_temp;
    int semestre_temp;
    int vagas_temp;
    int professor_matricula_temp;
    char nome_temp[100];



    for (int i = 0; i < *qtd; i++) {
        if (strcmp(disciplina[i].nome, nome) == 0) {
            //validação do nome da disciplina
            printf("Digite o novo nome da disciplina: ");
            scanf(" %[^\n]", nome_temp);
            if(procurar_disciplina_por_nome(disciplina, qtd) != -1){
                printf("Disciplina já existe. Tente novamente.\n");
                return;
            }
            strcpy(disciplina[i].nome, nome_temp);

            //validação do código da disciplina
            printf("Digite o novo código da disciplina: ");
            scanf("%d", &disciplina[i].codigo);

            printf("Digite o novo semestre da disciplina: ");
            scanf("%d", &semestre_temp);
            if(semestre_temp <= 0 || semestre_temp > 10){ // considerando um curso de até 10 semestres  
                printf("Semestre inválido. Tente novamente.\n");
                return;
            }
            disciplina[i].semestre = semestre_temp;

            printf("Digite o novo número de vagas da disciplina: ");
            scanf("%d", &vagas_temp);
            if (!validar_vagas(vagas_temp)) {
                printf("Número de vagas inválido.\n");
                return;
            }
            disciplina[i].vagas = vagas_temp;

            printf("Digite a nova matrícula do professor responsável: ");
            scanf("%d", &professor_matricula_temp);
            disciplina[i].professor.matricula = professor_matricula_temp;


            printf("Disciplina editada com sucesso!\n");
            return;
        }
    }
    printf("Disciplina com nome %s não encontrada.\n", nome);
}

int carregar_disciplinas(Disciplina disciplinas[]) {
    FILE *f = fopen("bd/disciplinas.txt", "r");

    if (f == NULL) return 0;

    int i = 0;

    while (fscanf(f, "%99[^;];%d;%d;%d;%d\n",
        disciplinas[i].nome,
        &disciplinas[i].codigo,
        &disciplinas[i].semestre,
        &disciplinas[i].vagas,
        &disciplinas[i].professor.matricula) == 5) {

        i++;
}

    fclose(f);
    return i;
}




void salvar_disciplinas(Disciplina disciplina) {
    FILE *f = fopen("bd/disciplinas.txt", "a");

    if (f == NULL) return;

   fprintf(f, "%s;%d;%d;%d;%d\n",
    disciplina.nome,
    disciplina.codigo,
    disciplina.semestre,
    disciplina.vagas,
    disciplina.professor.matricula);

    fclose(f);
}



