#include <stdio.h>
#include <string.h>

int existe_usuario( Usuario *vetUser, int totUser, char cpf[])
{
    int i;
    
    for(i=0; i<totUser; i++)
    {
      
        if ( strcmp(vetUser[i].CPF, cpf) == 0 )
            return i;
    }
            
    return -1;
}



void incluir_usuario( Usuario *vetUser, int *totUser )
{
    char cpf[12];
    char nome[31];
    char email[20];
    char categoria[15];
    char LIXO[2];
    int i=0;
    
    
    printf("\nInclusao de usuarios:\n");
    
  
    if ( *totUser == TOTAL )
    {
        printf("\n*ERRO* Nao ha espaco para adicionar mais usuarios!\n");
    }
    else
    {
        printf("Digite o CPF do usuario: ");
        gets(cpf);
    
        if ( existe_usuario(vetUser, *totUser, cpf) != -1 )
        {
            printf("\n* Este CPF ja existe!*\n");
        }
        else
        {
            
            printf("Digite o nome do usuario:\n");
            gets(nome);
            printf("Digite o email:");
            gets(email);
            printf("Digite a categoria do usuario:");
            gets(categoria);
        
            strcpy( vetUser[*totUser].CPF, cpf );
            strcpy( vetUser[*totUser].nome, nome );
            strcpy( vetUser[*totUser].email, email );
            strcpy( vetUser[*totUser].categoria, categoria );        
            (*totUser)++;
            
            printf("\n* Usuario inserido com sucesso!\n");
        }
        FILE *arquivo;
		
		// Dados de usuários:
		arquivo = fopen("usuarios.dat", "wb");
		if (arquivo != NULL) {
		    // Escrever a quantidade total de usuários no arquivo
		    fwrite(totUser, sizeof(int), 1, arquivo);
		    // Escrever o vetor de usuários completo no arquivo
		    fwrite(vetUser, sizeof(Usuario), *totUser, arquivo);
		    fclose(arquivo);
		    printf("*** Arquivo alterado com sucesso ***");
		} else {
		    printf("Erro ao abrir o arquivo para escrita!\n");
		}
      
	
		    }
		    printf("\nDigite <ENTER> para continuar....");
		    gets(LIXO);
}


void alterar_usuario(Usuario *vetUser, int *totUser)
{
    char cpf[12];
    char nome[31];
    char categoria[20];
    char email[31];
    char LIXO[2];
    int indice;
    int opcao;

    printf("\nAlteracao de Usuario:\n");
    printf("Digite o CPF do Usuario: ");
    gets(cpf);

    // Verificar se este CPF existe no vetor:
    indice = existe_usuario(vetUser, *totUser, cpf);

    if (indice == -1)
    {
        printf("\n* Este CPF nao existe!*\n");
    }
    else
    {
        printf("\nSelecione o campo que deseja alterar:\n");
        printf("1. Nome\n");
        printf("2. Categoria\n");
        printf("3. Email\n");

        printf("Opcao: ");
        scanf("%d%*c", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o novo nome do usuario: ");
            gets(nome);
            strcpy(vetUser[indice].nome, nome);
            printf("\n* Nome do usuario alterado com sucesso!\n");
            break;
        case 2:
            printf("Digite a nova categoria do usuario: ");
            gets(categoria);
            strcpy(vetUser[indice].categoria, categoria);
            printf("\n* Categoria do usuario alterada com sucesso!\n");
            break;
        case 3:
            printf("Digite o novo email do usuario: ");
            gets(email);
            strcpy(vetUser[indice].email, email);
            printf("\n* Email do usuario alterado com sucesso!\n");
            break;
        default:
            printf("\n* Opcao invalida!*\n");
            break;
        }
        FILE *arquivo;
		
		// Dados de usuários:
		arquivo = fopen("usuarios.dat", "wb");
		if (arquivo != NULL) {
		    // Escrever a quantidade total de usuários no arquivo
		    fwrite(totUser, sizeof(int), 1, arquivo);
		    // Escrever o vetor de usuários completo no arquivo
		    fwrite(vetUser, sizeof(Usuario), *totUser, arquivo);
		    printf("*** Arquivo atualizado com sucesso ***");
		    fclose(arquivo);
		} else {
		    printf("Erro ao abrir o arquivo para escrita!\n");
		}
    }

    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}





void apagar_usuario( Usuario *vetUser, int *totUser, Emprestimo *vetEmpre, int totEmpre )
{
    char cpf[12];
    char LIXO[2];
    int indice, i;
    
    printf("\nApagando Usuario:\n");
    
    printf("Digite o CPF do Usuario: ");
    gets(cpf);
    
    if ( existe_user_empre( vetEmpre, totEmpre, cpf ) )
    {
        printf("\n* Este CPF tem emprestimo! nao posso apagar!*\n");
    }
    else
    {
        // Verificar se este CPF existe no vetor:
        indice = existe_usuario(vetUser, *totUser, cpf);
    
        if ( indice == -1 )
        {
            printf("\n* Este CPF nao existe!*\n");
        }
        else
        {
            // Tudo ok, apagar o registro.
            // Lembrando que para apagar um elemento do vetor,
            // vocÃª precisa "deslocar para a esquerda"
            // todos os elementos seguintes armazenados no vetor,
            // isto Ã©, deslocar "pra esquerda" desde o elemento 'indice'+1
            // atÃ© o elemento (*totFunc)-1.
            // Ao final, decrementar *totFunc.
            
            for( i=indice; i<(*totUser)-1; i++)
            {
                strcpy( vetUser[i].CPF, vetUser[i+1].CPF );
                strcpy( vetUser[i].nome, vetUser[i+1].nome );
                strcpy( vetUser[i].nome, vetUser[i+1].email );
                strcpy( vetUser[i].nome, vetUser[i+1].categoria ); }
            (*totUser)--;
            FILE *arquivo;
		
		// Dados de usuários:
		arquivo = fopen("usuarios.dat", "wb");
		if (arquivo != NULL) {
		    // Escrever a quantidade total de usuários no arquivo
		    fwrite(totUser, sizeof(int), 1, arquivo);
		    // Escrever o vetor de usuários completo no arquivo
		    fwrite(vetUser, sizeof(Usuario), *totUser, arquivo);
		    fclose(arquivo);
		    printf("*** Arquivo alterado com sucesso ***");
		} else {
		    printf("Erro ao abrir o arquivo para escrita!\n");
		}
            
            printf("\n* Usuario apagado com sucesso!\n");
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultar_usuario( Usuario *vetUser, int *totUser )
{
    char cpf[12];
    char LIXO[2];
    int indice;
    
    
    printf("\nConsultar Usuario:\n");
    
    printf("Digite o CPF do usuario: ");
    gets(cpf);
    
    // Verificar se este CPF existe no vetor:
    indice = existe_usuario(vetUser, *totUser, cpf);
    
    if ( indice == -1 )
    {
        printf("\n* Este CPF nao existe!*\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
            
        printf("CPF: %s\n",  vetUser[indice].CPF);
        printf("Nome: %s\n", vetUser[indice].nome);
        printf("Categoria: %s\n", vetUser[indice].categoria);
        printf("Email: %s\n", vetUser[indice].email);
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultarTodos_usuario( Usuario *vetUser, int *totUser )
{
    char LIXO[2];
    int i;
    
    if( (*totUser) == 0 )
    {
        printf("\nNao ha usuarios para exibir!\n");
    }
    else
    {
        printf("\nExibindo todos os usuarios:\n");
    
        for( i=0; i<(*totUser); i++ )
        {            
            printf("\nCPF: %s\n",  vetUser[i].CPF);
            printf("Nome: %s\n",   vetUser[i].nome);
            printf("Categoria: %s\n", vetUser[i].categoria);
            printf("Email: %s\n",vetUser[i].email);
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
    
