#include <stdio.h>
#include <string.h>


int existe_livro( Livro *vetLivro, int totLivro, char ISBN[])
{
    int i;
    
    for(i=0; i<totLivro; i++)
    {
        if ( strcmp(vetLivro[i].ISBN, ISBN) == 0 )
            return i;
    }            
    return -1;
}


void incluir_livro( Livro *vetLivro, int *totLivro )
{
    char ISBN[12];
    char TITULO[31];
    char GENERO[20];
    char AUTOR[31];
    char LIXO[2];
    
    
    printf("\nIncluir Livro:\n");
    
    if ( *totLivro == TOTAL )
    {
        printf("\n*ERRO* Nao ha espacos para incluir mais um livro aqui!\n");
    }
    else
    {
        printf("Digite o isbn do livro: ");
        gets(ISBN);
    
        if ( existe_livro(vetLivro, *totLivro, ISBN) != -1 )
        {
            printf("\n* Este ISBN ja existe!*\n");
        }
        else
        {
            
            printf("Digite o titulo do livro: ");
            gets(TITULO);
            printf("Digite o nome do autor do livro:");
            gets(AUTOR);
            printf("Digite o Genero:");
            gets(GENERO);
          
        
            strcpy( vetLivro[*totLivro].ISBN, ISBN );
            strcpy( vetLivro[*totLivro].TITULO, TITULO );
            strcpy( vetLivro[*totLivro].GENERO, GENERO );
            strcpy( vetLivro[*totLivro].AUTOR, AUTOR );

       
            (*totLivro)++;
            FILE *arquivo;
            arquivo = fopen("livros.dat", "wb");
			if (arquivo != NULL) {
		    // Escrever a quantidade total de usuários no arquivo
		    fwrite(totLivro, sizeof(int), 1, arquivo);
		    // Escrever o vetor de usuários completo no arquivo
		    fwrite(vetLivro, sizeof(Livro), *totLivro, arquivo);
		    fclose(arquivo);
		    printf("*** Arquivo alterado com sucesso ***");
		} else {
		    printf("Erro ao abrir o arquivo para escrita!\n");
		}
            
            printf("\n* Livro inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}


void alterar_livro(Livro *vetLivro, int *totLivro)
{
    char ISBN[12];
    char AUTOR[31];
    char GENERO[20];
    char TITULO[31];
    char LIXO[2];
    int indice;
    int opcao;

    printf("\nAlterar Livro:\n");

    printf("Digite o ISBN do Livro que deseja alterar: ");
    gets(ISBN);

    indice = existe_livro(vetLivro, *totLivro, ISBN);

    if (indice == -1)
    {
        printf("\n* Este ISBN nao existe!*\n");
    }
    else
    {

        printf("\nO que deseja alterar?\n");
        printf("1. TITULO\n");
        printf("2. AUTOR\n");
        printf("3. GENERO\n");
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &opcao);

        // Limpar o buffer do teclado
        getchar();

        switch (opcao)
        {
            case 1:
                printf("Digite o novo titulo do livro: ");
                gets(TITULO);
                strcpy(vetLivro[indice].TITULO, TITULO);
                printf("\n* TITULO do livro alterado com sucesso!\n");
                break;
            case 2:
                printf("Digite o novo autor do livro: ");
                gets(AUTOR);
                strcpy(vetLivro[indice].AUTOR, AUTOR);
                printf("\n* AUTOR do livro alterado com sucesso!\n");
                break;
            case 3:
                printf("Digite o novo genero do livro: ");
                gets(GENERO);
                strcpy(vetLivro[indice].GENERO, GENERO);
                printf("\n* GENERO do livro alterado com sucesso!\n");
                break;
            default:
                printf("\n* Opcao invalida!*\n");
                break;
        }
         FILE *arquivo;
            arquivo = fopen("livros.dat", "wb");
			if (arquivo != NULL) {
		    // Escrever a quantidade total de usuários no arquivo
		    fwrite(totLivro, sizeof(int), 1, arquivo);
		    // Escrever o vetor de usuários completo no arquivo
		    fwrite(vetLivro, sizeof(Livro), *totLivro, arquivo);
		    fclose(arquivo);
		    printf("*** Arquivo alterado com sucesso ***");
		} else {
		    printf("Erro ao abrir o arquivo para escrita!\n");
		}
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}



void apagar_livro( Livro *vetLivro, int *totLivro, Emprestimo *vetEmpre, int totEmpre )
{
    char ISBN[12];
    char LIXO[2];
    int indice, i;
   
    printf("\nApagando livro:\n");
    
    printf("Digite a ISBn do departamento: ");
    gets(ISBN);
    
    if ( existe_livro_empre( vetEmpre, totEmpre, ISBN ) )
    {
        printf("\n* Este livro esta em um emprestimo, nao posso apagar!*\n");
    }
    else
    {    
        indice = existe_livro(vetLivro, *totLivro, ISBN);
    
        if ( indice == -1 )
        {
            printf("\n* Este ISBN nao existe!*\n");
        }
        else
        {         
            for( i=indice; i<(*totLivro)-1; i++)
            {
                strcpy( vetLivro[i].ISBN, vetLivro[i+1].ISBN );
                strcpy( vetLivro[i].TITULO, vetLivro[i+1].TITULO );
                strcpy( vetLivro[i].GENERO, vetLivro[i+1].GENERO);
                strcpy( vetLivro[i].AUTOR, vetLivro[i+1].AUTOR );
            }
        
            (*totLivro)--;
            
            printf("\n* Livro apagado com sucesso!\n");
        }
         FILE *arquivo;
            arquivo = fopen("livros.dat", "wb");
			if (arquivo != NULL) {
		    // Escrever a quantidade total de usuários no arquivo
		    fwrite(totLivro, sizeof(int), 1, arquivo);
		    // Escrever o vetor de usuários completo no arquivo
		    fwrite(vetLivro, sizeof(Livro), *totLivro, arquivo);
		    fclose(arquivo);
		    printf("*** Arquivo alterado com sucesso ***");
		} else {
		    printf("Erro ao abrir o arquivo para escrita!\n");
		}
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultar_livro( Livro *vetLivro, int *totLivro )
{
    char ISBN[12];
    char AUTOR[31];
    char GENERO[20];
    char TITULO[31];
    char LIXO[2];
    int indice;
    
    
    printf("\nConsultar Livro:\n");
    
    printf("Digite o ISBN do Livro: ");
    gets(ISBN);
    
    indice = existe_livro(vetLivro, *totLivro, ISBN);
    
    if ( indice == -1 )
    {
        printf("\n* Este ISBN nao existe!*\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
            
        printf("SIGLA: %s\n",  vetLivro[indice].ISBN);
        printf("Titulo: %s\n", vetLivro[indice].TITULO);
        printf("Genero: %s\n", vetLivro[indice].GENERO);
        printf("Autor: %s\n", vetLivro[indice].AUTOR);

    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultarTodos_livro( Livro *vetLivro, int *totLivro )
{
    char LIXO[2];
    int i;
    
    if( (*totLivro) == 0 )
    {
        printf("\nNao ha livros para exibir!\n");
    }
    else
    {
        printf("\nExibindo todos os livros:\n");
    
        for( i=0; i<(*totLivro); i++ )
        {            
            printf("\nSIGLA: %s\n",  vetLivro[i].ISBN);
            printf("Titulo: %s\n",   vetLivro[i].TITULO);
            printf("Autor: %s\n",   vetLivro[i].AUTOR);
            printf("Genero: %s\n",   vetLivro[i].GENERO);

        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
