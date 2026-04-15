/*
CRUD:
aluno : matricula, nome, sexo, data de nascimento, cpf
professor: matricula, nome, sexo, data de nascimento, cpf
disciplina: nome, codigo, semestre, professor
*/

#include <stdio.h>

#include "aluno/aluno.h"
#include "professor/professor.h"
#include "disciplina/disciplina.h"
#include "utils/menu.h"
#include "utils/utils.h"


int main() {
    Aluno aluno[MAX_ALUNOS];
    Professor professor[MAX_PROFESSORES];
    Disciplina disciplina[MAX_DISCIPLINAS];
    int qtd_alunos = carregar_alunos(aluno);
    int qtd_professores = carregar_professores(professor);
    int qtd_disciplinas = carregar_disciplinas(disciplina);
    int opcao, opcaoL, opcaoE, opcaoEd;

    char *nomes[MAX_ALUNOS];

    printf("Bem-vindo ao sistema de cadastro da escola!\n");
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
               cadastrar_aluno(aluno, &qtd_alunos);
                for(int i = 0; i < qtd_alunos; i++){
                    nomes[i] = aluno[i].nome; //corrigir
                }
                break;
            case 2:
               cadastrar_professor(professor, &qtd_professores);
                break;
            case 3:
              cadastrar_disciplina(disciplina, &qtd_disciplinas);
                break;
            case 4:
                matricular_aluno(disciplina, qtd_disciplinas, aluno, qtd_alunos);
                break;
            case 5:

                do{
                    opcaoL=menu_listar();
                    switch (opcaoL) {
                        case 1:
                            listar_professores(professor, qtd_professores);
                            break;
                        case 2:
                            listar_disciplinas(disciplina, qtd_disciplinas);
                            break;
                        case 3:
                            listar_alunos(aluno, qtd_alunos);
                            break;
                        case 4:
                            listar_alunos_matriculados(disciplina, qtd_disciplinas);
                            break;
                        case 5:
                            listar_alunos_por_sexo(aluno, qtd_alunos);
                            break;
                        case 6:
                            listar_alunos_ordem_alfabetica(aluno, qtd_alunos);
                            break;
                        case 7:
                            listar_alunos_por_idade(aluno, &qtd_alunos);
                            break;
                        case 8:
                            listar_professores_por_sexo(professor, qtd_professores);
                            break;
                        case 9:
                            listar_professores_ordem_alfabetica(professor, qtd_professores);
                            break;
                        case 10:
                            listar_professores_por_idade(professor, &qtd_professores);
                            break;
                        case 11:
                            lista_aniversariantes(aluno, professor, qtd_alunos);
                            break;
                        case 12:
                            buscar_pessoas_por_nome(aluno, professor, qtd_alunos);
                            break;
                        case 13:
                            listar_alunos_em_menos_de_3_disciplinas(disciplina, qtd_disciplinas);
                            break;
                        case 14:
                            disciplinas_extrapolam_vagas(disciplina, qtd_disciplinas);
                            break;
                        case -1:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida. Tente novamente.\n");
                            break;
                    }//switch menu_listar

                }while(opcaoL != -1);

                break;//case 5
            
            case 6:
                //chamar menu excluir
                do{
                    opcaoE = menu_excluir();
                    switch (opcaoE) {
                        case 1:
                            excluir_aluno(aluno, &qtd_alunos);
                            break;
                        case 2:
                            excluir_professor(professor, &qtd_professores);
                            break;
                        case 3:
                            excluir_disciplina(disciplina, &qtd_disciplinas);
                            break;
                        case 4:
                            excluir_aluno_disciplina(disciplina, qtd_disciplinas, aluno, qtd_alunos);
                            break;
                        case -1:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida. Tente novamente.\n");
                            break;
                    }
                } while (opcaoE != -1);

                break;
            case 7:
                //chamar menu editar
                do{
                    opcaoEd = menu_editar();
                    switch (opcaoEd) {
                        case 1:
                            editar_aluno(aluno, &qtd_alunos);
                            break;
                        case 2:
                            editar_professor(professor, &qtd_professores);
                            break;
                        case 3:
                            editar_disciplina(disciplina, &qtd_disciplinas);
                            break;
                        case -1:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida. Tente novamente.\n");
                            break;
                    }
                } while (opcaoEd != -1);

                break;
            case -1:
                printf("Saindo do sistema. Até mais!\n");   
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != -1);
    return 0;

}//main
