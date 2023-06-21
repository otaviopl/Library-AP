
#include <stdio.h>
#include <string.h>


int existe_user_empre(Emprestimo *vetEmpre, int totEmpre, char cpf[] )
{
    int i;
    
    for(i=0; i<totEmpre; i++)
    {
        if ( strcmp(vetEmpre[i].CPF, cpf) == 0 )
            return 1;
    }
    return 0;
}
//----------------------------------------------------------------------


int existe_livro_empre( Emprestimo *vetEmpre, int totEmpre, char isbn[] )
{
    int i;
    
    for(i=0; i<totEmpre; i++)
    {
        if ( strcmp(vetEmpre[i].ISBN, isbn) == 0 )
            return 1;
    }
	return 0;
}
//----------------------------------------------------------------------

int existe_empre( Emprestimo *vetEmpre, int totEmpre, char cpf[], char isbn[])
{
    int i;
    
    for(i=0; i<totEmpre; i++)
    {
      
        if ( (strcmp(vetEmpre[i].CPF, cpf) == 0) && (strcmp(vetEmpre[i].ISBN, isbn) == 0) )
            return i;
    }
            
    return -1;
}


void incluir_empre( Usuario *vetUser, int totUser, 
                      Livro *vetLivro, int totLivro, 
                      Emprestimo  *vetEmpre, int* totEmpre)
{
    char cpf[12];
    char isbn[12];
   	char dataRetirada[11];
   	char dataDevolucao[11];
    char LIXO[2];
    
    
    printf("\nIncluir Emprestimo:\n");
    
    // Se o vetor chegou no seu limite, indicar erro:
    if ( *totEmpre == TOTAL )
    {
        printf("\n*ERRO* Nao ha espaco para incluir seu emprestimo!\n");
    }
    else
    {
        printf("Digite o CPF do usuario: ");
        gets(cpf);
    
        // Verificar se este CPF existe:
        if ( existe_usuario(vetUser, totUser, cpf) == -1 )
        {
            printf("\n* Este CPF nao existe no nosso banco de dados!*\n");
        }
        else
        {
            printf("Digite o isbn do livro: ");
            gets(isbn);
            
            // Verificar se esta SIGLA existe:
            if ( existe_livro(vetLivro, totLivro, isbn) == -1 )
            {
                printf("\n* Este ISBN nao existe no nosso banco de dados!*\n");
            }
            else
            {
                if ( existe_empre(vetEmpre, *totEmpre, cpf, isbn) != -1 )
                {
                    printf("\n* Este emprestimo ja existe!*\n");
                }
                else
                {
                    printf("Digite a data de retirada (dd/mm/aaaa):\n");
                    scanf("%s%*c", &dataRetirada);
                    
                    printf("Digite a data de devolucao (dd/mm/aaaa):\n");
                    scanf("%s%*c", &dataDevolucao);
                    
        
                    strcpy( vetEmpre[*totEmpre].CPF, cpf );
                    strcpy( vetEmpre[*totEmpre].ISBN, isbn);
                    strcpy( vetEmpre[*totEmpre].dataDevolucao, dataDevolucao );
                    strcpy( vetEmpre[*totEmpre].dataRetirada, dataRetirada );
                  
                    (*totEmpre)++;
            
                    printf("\n* Emprestimo inserido com sucesso!\n");
                     FILE *arquivo;
			            arquivo = fopen("emprestimos.dat", "wb");
						if (arquivo != NULL) {
					    // Escrever a quantidade total de usu·rios no arquivo
					    fwrite(totEmpre, sizeof(int), 1, arquivo);
					    // Escrever o vetor de usu·rios completo no arquivo
					    fwrite(vetEmpre, sizeof(Emprestimo), *totEmpre, arquivo);
					    fclose(arquivo);
					    printf("*** Arquivo alterado com sucesso ***");
					} else {
					    printf("Erro ao abrir o arquivo para escrita!\n");
					}
                }
            }
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}


void alterar_empre(Emprestimo *vetEmpre, int *totEmpre) {
    char cpf[12];
    char isbn[12];
    int indice;

    printf("\nAlterar Emprestimo:\n");

    printf("Digite o CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o ISBN: ");
    fgets(isbn, sizeof(isbn), stdin);

    indice = existe_empre(vetEmpre, *totEmpre, cpf, isbn);

    if (indice == -1) {
        printf("\n* Este emprestimo nao existe! *\n");
    } else {
        int opcao;
        printf("\nEscolha o que deseja alterar:\n");
        printf("1. Data de Retirada\n");
        printf("2. Data de Devolucao\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Digite a nova data de retirada (DD/MM/AAAA): ");
                fgets(vetEmpre[indice].dataRetirada, sizeof(vetEmpre[indice].dataRetirada), stdin);
                printf("\n* Data de Retirada alterada com sucesso! *\n");
                break;
            case 2:
                printf("Digite a nova data de devolucao (DD/MM/AAAA): ");
                fgets(vetEmpre[indice].dataDevolucao, sizeof(vetEmpre[indice].dataDevolucao), stdin);
                printf("\n* Data de Devolucao alterada com sucesso! *\n");
                break;
            default:
                printf("\n* Opcao invalida! *\n");
                break;
        }
        printf("\n* Emprestimo alterado com sucesso!\n");
        FILE *arquivo;
			            arquivo = fopen("emprestimos.dat", "wb");
						if (arquivo != NULL) {
					    fwrite(totEmpre, sizeof(int), 1, arquivo);
					    // Escrever o vetor de usu·rios completo no arquivo
					    fwrite(vetEmpre, sizeof(Emprestimo), *totEmpre, arquivo);
					    fclose(arquivo);
					    printf("*** Arquivo alterado com sucesso ***");
					} else {
					    printf("Erro ao abrir o arquivo para escrita!\n");
					}
                    
    }

    printf("\nDigite <ENTER> para continuar....");
    getchar(); // Limpar o buffer do teclado
}



void apagar_empre(Emprestimo *vetEmpre, int *totEmpre )
{
    char cpf[12];
    char isbn[12];
    char LIXO[2];
    int indice, i;
    
    printf("\nApagando Emprestimo:\n");
    
    printf("Digite o CPF do usuario no Emprestimo: ");
    gets(cpf);
    printf("Digite o ISBN do livro no Emprestimo: ");
    gets(isbn);
            
    indice = existe_empre(vetEmpre, *totEmpre, cpf, isbn);
    
    if ( indice == -1 )
    {
        printf("\n* Esta Emprestimo nao existe!*\n");
    }
    else
    {
       
            
        for( i=indice; i<(*totEmpre)-1; i++)
        {
            strcpy( vetEmpre[i].CPF, vetEmpre[i+1].CPF );
            strcpy( vetEmpre[i].ISBN, vetEmpre[i+1].ISBN );
            strcpy( vetEmpre[i].dataRetirada, vetEmpre[i+1].dataRetirada);
            strcpy( vetEmpre[i].dataDevolucao, vetEmpre[i+1].dataDevolucao );

        }
        
        (*totEmpre)--;
            
        printf("\n* Emprestimo apagada com sucesso!\n");
                     FILE *arquivo;
			            arquivo = fopen("emprestimos.dat", "wb");
						if (arquivo != NULL) {
					    // Escrever a quantidade total de usu·rios no arquivo
					    fwrite(totEmpre, sizeof(int), 1, arquivo);
					    // Escrever o vetor de usu·rios completo no arquivo
					    fwrite(vetEmpre, sizeof(Emprestimo), *totEmpre, arquivo);
					    fclose(arquivo);
					    printf("*** Arquivo alterado com sucesso ***");
					} else {
					    printf("Erro ao abrir o arquivo para escrita!\n");
					}
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultar_empre( Emprestimo *vetEmpre, int *totEmpre)
{
    char cpf[12];
    char isbn[12];
    char LIXO[2];
    int indice;
    
    printf("\nConsultar Emprestimo:\n");
    
    printf("Digite o CPF do Emprestimo: ");
    gets(cpf);
    printf("Digite o SIGLA do Emprestimo: ");
    gets(isbn);
            
    // Verificar se essa lota√ß√£o j√° existe:
    indice = existe_empre(vetEmpre, *totEmpre, cpf, isbn);
    
    // Se a lota√ß√£o n√£o existir...
    if ( indice == -1 )
    {
        printf("\n* Este emprestimo nao existe!*\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
            
        printf("\nCPF: %s\n",  vetEmpre[indice].CPF);
        printf("ISBN: %s\n", vetEmpre[indice].ISBN);
        printf("Data Retirada: %s\n", vetEmpre[indice].dataRetirada);
        printf("Data Devolucao: %s\n", vetEmpre[indice].dataDevolucao);
        
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}  


void consultarTodas_empre( Emprestimo *vetEmpre, int *totEmpre )
{
    char LIXO[2];
    int i;
    
    if( (*totEmpre) == 0 )
    {
        printf("\nNao ha emprestimos registradosr!\n");
    }
    else
    {
        printf("\nExibindo todas as emprestimoss:\n");
    
        for( i=0; i<(*totEmpre); i++ )
        {            
            printf("\nCPF: %s\n",  vetEmpre[i].CPF);
            printf("ISBN: %s\n", vetEmpre[i].ISBN);
            printf("Data Retirada: %s\n", vetEmpre[i].dataRetirada);
            printf("Data Devolucao: %s\n", vetEmpre[i].dataDevolucao);
		}
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}
    

void emprestimo_por_cpf( Usuario *vetUser, int totUser, 
                         Livro *vetLivro, int totLivro, 
                         Emprestimo *vetEmpre, int totEmpre )
{
    char LIXO[2];
    int i;
    char CPF[12];
    int indUser, indLivro;
    int achou = 0;
    
    if( totEmpre == 0 )
    {
        printf("\nNao ha emprestimos cadastrados!\n");
    }
    else
    {
        printf("Digite o CPF do usuario: ");
        gets(CPF);
        
        
        for( i=0; i<totEmpre; i++ )
        {
            if( strcmp( CPF, vetEmpre[i].CPF ) == 0 )
            {
                achou = 1;
                indUser =  existe_usuario( vetUser, totUser, vetEmpre[i].CPF );
                indLivro = existe_livro( vetLivro, totLivro, vetEmpre[i].ISBN );
                printf("\nLivro %s - %s\n", vetLivro[indLivro].ISBN);
                printf("CPF: %s - %s\n", vetUser[indUser].CPF, vetUser[indUser].nome);
                printf("Data de Retirada: %s - Data de Devolucao: %s\n\n", vetEmpre[i].dataRetirada, vetEmpre[i].dataDevolucao);
            }
        }
        
        if (!achou)
            printf("Nao ha emprestimos para o CPF informado!");
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}


void emprestimo_entre_datas(Usuario *vetUser, int totUser, Livro *vetLivro, int totLivro, Emprestimo *vetEmpre,int totEmpre ) {
	char dataInicio[11];
	char dataFim[11];
	int i=0;
	
	printf("Digite a data Inicio:");
	gets(dataInicio);

	printf("Digite a data Fim:");
	gets(dataFim);
	
    printf("\nEmprÈstimos com data de devoluÁ„o entre %s e %s:\n", dataInicio, dataFim);

    for (i = 0; i < totEmpre; i++) {
        if (strcmp(vetEmpre[i].dataDevolucao, dataInicio) >= 0 && strcmp(vetEmpre[i].dataDevolucao, dataFim) <= 0) {
            printf("Emprestimo %d:\n", i + 1);
            printf("Data de Retirada: %s\n", vetEmpre[i].dataRetirada);
            printf("Data de Devolucao: %s\n", vetEmpre[i].dataDevolucao);
            printf("-----------------------------\n");
        }
    }
}
    
    
    
    
    
    
