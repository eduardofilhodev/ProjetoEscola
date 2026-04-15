#include <stdio.h>

int menu() {
    int opcao;
    printf("Menu:\n");
    printf("1. Cadastrar Aluno\n");
    printf("2. Cadastrar Professor\n");
    printf("3. Cadastrar Disciplina\n");
    printf("4. Matricular Aluno em Disciplina\n");
    printf("5. Menu de Listagem\n");
    printf("6. Menu de Exclusão\n");
    printf("7. Menu de Alteração\n");
    printf("-1. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int menu_listar() {
    int opcao;
    printf("\n");
    printf("**********************************\n");
    printf("Menu de Listagem:\n");
    printf("1. Listar Professores\n");
    printf("2. Listar Disciplinas\n");
    printf("3. Listar Alunos\n");
    printf("4. Listar Alunos Matriculados em uma Disciplina\n");
    printf("5. Listar Alunos por Sexo\n");
    printf("6. Listar Alunos em Ordem Alfabética\n");
    printf("7. Listar Alunos por Idade\n");
    printf("8. Listar Professores por Sexo\n");
    printf("9. Listar Professores em Ordem Alfabética\n");
    printf("10. Listar Professores por Idade\n");
    printf("11. Listar Aniversariantes do Mês\n");
    printf("12. Buscar Pessoas por Nome\n");
    printf("13. Listar Alunos em Menos de 3 Disciplinas\n");
    printf("14. Listar Disciplinas que Extrapolam 40 Vagas\n");
    printf("-1. Voltar ao Menu Principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int menu_excluir() {
    int opcao;
    printf("\n");
    printf("**********************************\n");
    printf("Menu de Exclusão:\n");
    printf("1. Excluir Aluno\n");
    printf("2. Excluir Professor\n");
    printf("3. Excluir Disciplina\n");
    printf("4. Excluir Aluno de uma Disciplina\n");
    printf("-1. Voltar ao Menu Principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int menu_editar() {
    int opcao;
    printf("\n");
    printf("**********************************\n");
    printf("Menu de Alteração:\n");
    printf("1. Alterar Dados do Aluno\n");
    printf("2. Alterar Dados do Professor\n");
    printf("3. Alterar Dados da Disciplina\n");
    printf("-1. Voltar ao Menu Principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}