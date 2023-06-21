
#include <stdio.h>

#include "Zestruturas.c"
#include "Zprototipos.c"
#include "Zemprestimos.c"
#include "Zusuarios.c"
#include "Zlivros.c"


int main()
{
    // Criando os armazenamentos:
    
    Usuario BDusuarios[TOTAL];
        // Variável que vai indicar quantos funcionários estão cadastrados no vetor:
        int totUser = 0;
        
    Livro BDlivros[TOTAL];
        // Variável que vai indicar quantos departamentos estão cadastrados no vetor:
        int totLivros = 0;
        
    Emprestimo BDemprestimos[TOTAL];
        // Variável que vai indicar quantas lotações estão cadastradas no vetor:
        int totEmpre = 0;
        
        
        
        
    // Lendo dados dos arquivos:
    FILE *arquivo;
    
    // Dados de funcionarios:
    arquivo = fopen("usuarios.dat", "rb");
    if(arquivo != NULL)
    {
        // A PRIMEIRA INFORMACAO EH A QUANTIDADE DE DADOS ARMAZENADOS!!!
        fread(&totUser, sizeof(int), 1, arquivo);
        // AGORA VAMOS LER O VETOR INTEIRO!!!
        fread(BDusuarios, sizeof(Usuario), TOTAL, arquivo);
        fclose(arquivo);        
    }

    // Dados de departamentos:
    arquivo = fopen("livros.dat", "rb");
    if(arquivo != NULL)
    {
        // A PRIMEIRA INFORMACAO EH A QUANTIDADE DE DADOS ARMAZENADOS!!!
        fread(&totLivros, sizeof(int), 1, arquivo);
        // AGORA VAMOS LER O VETOR INTEIRO!!!
        fread(BDlivros, sizeof(Livro), TOTAL, arquivo);
        fclose(arquivo);        
    }        
        
   
    arquivo = fopen("emprestimos.dat", "rb");
    if(arquivo != NULL)
    {
        // A PRIMEIRA INFORMACAO EH A QUANTIDADE DE DADOS ARMAZENADOS!!!
        fread(&totEmpre, sizeof(int), 1, arquivo);
        // AGORA VAMOS LER O VETOR INTEIRO!!!
        fread(BDemprestimos, sizeof(Emprestimo), TOTAL, arquivo);
        fclose(arquivo);        
    }        

   
    
    int opcao_principal, opcao_submenu;

    do {
        printf("=== Menu ===\n");
        printf("1. Usuarios\n");
        printf("2. Livros\n");
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
                            incluir_usuario(BDusuarios, &totUser);
                            break;
                        case 2:
                            alterar_usuario(BDusuarios, &totUser);
                            break;
                        case 3:
                            apagar_usuario(BDusuarios, &totUser, BDemprestimos, totEmpre);
                            break;
                        case 4:
                            consultar_usuario(BDusuarios, &totUser);
                            break;
                        case 5:
                            consultarTodos_usuario(BDusuarios, &totUser);
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
                    printf("\n=== Submenu Livros ===\n");
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
                            incluir_livro(BDlivros, &totLivros);
                            break;
                        case 2:
                            alterar_livro(BDlivros, &totLivros);
                            break;
                        case 3:
                            apagar_livro(BDlivros, &totLivros, BDemprestimos, totEmpre);
                            break;
                        case 4:
                            consultar_livro(BDlivros, &totLivros);
                            break;
                        case 5:
                            consultarTodos_livro(BDlivros, &totLivros);
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
               do {
                    printf("\n=== Submenu Emprestimo ===\n");
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
                            incluir_empre( BDusuarios, totUser, BDlivros, totLivros, BDemprestimos, &totEmpre); 
                            break;
                        case 2:
                            alterar_empre( BDemprestimos, &totEmpre);
                            break;
                        case 3:
                            apagar_empre( BDemprestimos, &totEmpre);
                            break;
                        case 4:
                            consultar_empre( BDemprestimos, &totEmpre);
                            break;
                        case 5:
                            consultarTodas_empre( BDemprestimos, &totEmpre);
                            break;
                        case 6:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 6);
                break;
            case 4:
                do {
                    printf("\n=== Submenu Relatorios ===\n");
                    printf("1. Mostrar emprestimos de um CPF especifico.\n");
                    printf("2. Mostrar emprestimos entre datas.\n");
                    printf("3. Voltar ao menu anterior\n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d%*c", &opcao_submenu);

                    switch (opcao_submenu) {
                        case 1:
                            emprestimo_por_cpf( BDusuarios, totUser, BDlivros, totLivros, BDemprestimos, totEmpre ); 
                            break;
                        case 2:
                            emprestimo_entre_datas( BDusuarios, totUser, BDlivros, totLivros, BDemprestimos, totEmpre );
                            break;
                        case 3:
                            printf("Voltando ao menu anterior...\n");
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while (opcao_submenu != 3);
                break;
            case 5:
                printf("Opcao escolhida: Sair\n");
                
                if (totUser != 0) 
                {
                    arquivo = fopen("usuarios.dat", "wb");
                    // PRECISA GRAVAR A QUANTIDADE DE DADOS ARMAZENADOS!!!!
                    fwrite(&totUser, sizeof(int), 1, arquivo);
                    // AGORA GRAVAR O VETOR INTEIRO!!!!
                    fwrite(BDusuarios, sizeof(Usuario), TOTAL, arquivo);
                    fclose(arquivo);
                }
                
                if (totLivros != 0) 
                {
                    arquivo = fopen("livros.dat", "wb");
                    // PRECISA GRAVAR A QUANTIDADE DE DADOS ARMAZENADOS!!!!
                    fwrite(&totLivros, sizeof(int), 1, arquivo);
                    // AGORA GRAVAR O VETOR INTEIRO!!!!
                    fwrite(BDlivros, sizeof(Livro), TOTAL, arquivo);
                    fclose(arquivo);
                }
                
                if (totEmpre != 0) 
                {
                    arquivo = fopen("emprestimos.dat", "wb");
                    // PRECISA GRAVAR A QUANTIDADE DE DADOS ARMAZENADOS!!!!
                    fwrite(&totEmpre, sizeof(int), 1, arquivo);
                    // AGORA GRAVAR O VETOR INTEIRO!!!!
                    fwrite(BDemprestimos, sizeof(Emprestimo), TOTAL, arquivo);
                    fclose(arquivo);
                }
                break;
                
            default:
                printf("Opcao invalida.\n");
        }
        
    } while (opcao_principal != 5);


}

                   







