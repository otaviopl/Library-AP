
#include <stdio.h>
#include "Zusuarios.c"
#include "Zlivros.c"

// Criando constante que representa a capacidade máxima dos vetores:
#define TOTAL 2

int main()
{
    // Criando os armazenamentos:
    
usuario BDusuarios[TOTAL];
        // Variável que vai indicar quantos userionários estão cadastrados no vetor:
        int totuser = 0;
        
    livro BDlivros[TOTAL];
        // Variável que vai indicar quantos livros estão cadastrados no vetor:
        int totlivro = 0;
    
    // Menus de opções:
    
    int opcao_principal, opcao_submenu;

    do {
        printf("=== Menu ===\n");
        printf("1. Usuario\n");-
        printf("2. Livro\n");
        printf("3. Emprestimos\n");
        printf("4. Relatorios\n");
        printf("5. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d%*c", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                do {
                    printf("\n=== Submenu Usuarios ===\n");
                    printf("1. Incluir\n");
                    printf("2. Alterar\n");
                    printf("3. Excluir\n");
                    printf("4. Consultar\n");
                    printf("5. Consultar todos\n");
                    printf("6. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            incluir_usuario(BDusuarios, &totuser);
                            break;
                        case 2:
                            alterar_usuario(BDusuarios, &totuser);
                            break;
                        case 3:
                            apagar_usuario(BDusuarios, &totuser);
                            break;
                        case 4:
                            consultar_usuario(BDusuarios, &totuser);
                            break;
                        case 5:
                            consultarTodos_usuario(BDusuarios, &totuser);
                            break;
                        case 6:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 6);
                break;
            case 2:
                do {
                    printf("\n=== Submenu livros ===\n");
                    printf("1. Incluir\n");
                    printf("2. Alterar\n");
                    printf("3. Excluir\n");
                    printf("4. Consultar\n");
                    printf("5. Consultar todos\n");
                    printf("6. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            incluir_livro(BDlivros, &totlivro);
                            break;
                        case 2:
                            alterar_livro(BDlivros, &totlivro);
                            break;
                        case 3:
                            apagar_livro(BDlivros, &totlivro);
                            break;
                        case 4:
                            consultar_livro(BDlivros, &totlivro);
                            break;
                        case 5:
                            consultarTodos_livro(BDlivros, &totlivro);
                            break;
                        case 6:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 6);
                break;
            case 3:
               /*do {
                    printf("\n=== Submenu emprestimos ===\n");
                    printf("1. Incluir\n");
                    printf("2. Alterar\n");
                    printf("3. Excluir\n");
                    printf("4. Consultar\n");
                    printf("5. Consultar todos\n");
                    printf("6. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            printf("Opcao escolhida: Incluir Lotacao\n");
                            break;
                        case 2:
                            printf("Opcao escolhida: Alterar Lotacao\n");
                            break;
                        case 3:
                            printf("Opcao escolhida: Excluir Lotacao\n");
                            break;
                        case 4:
                            printf("Opcao escolhida: Consultar Lotacao\n");
                            break;
                        case 5:
                            printf("Opcao escolhida: Consultar todos as emprestimos\n");
                            break;
                        case 6:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 6);
                break;*/
            case 4:
                printf("Opcao escolhida: Relatorios\n");
                break;
            case 5:
                printf("Opcao escolhida: Sair\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao_principal != 5);


}

                   







