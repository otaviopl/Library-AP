#include <stdio.h>
#include <string.h>
#include <time.h>
#define TOTAL 50
typedef struct{
	int dia;
	int mes;
	int ano;
}data;
typedef struct{
	char CPF;
	char ISBN;
	data dataRetirada;
	
}emprestimos;
typedef struct {
    
    char CPF[12];
    char NOME[31];
    char EMAIL[20];
	char CATEGORIA[15];
	
} usuario;
typedef struct {
    
    char ISBN[12];
    char TITULO[31];
	char GENERO[20];
	char AUTOR[20];
    
} livro;
int existe_livro( livro *vetlivro, int totlivro, char ISBN[])
{
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 até totDepto).
    for(i=0; i<totlivro; i++)
    {
        // Compara a ISBN neste elemento do vetor, com a ISBN informado.
        // Se achou, retorna o índice.
        if ( strcmp(vetlivro[i].ISBN, ISBN) == 0 )
            return i;
    }
            
    // Se chegou aqui, não achou. Retorna -1.
    return -1;
}
int existe_usuario( usuario *vetuser, int totuser, char CPF[])
{
    int i;
    
    // Percorre os elementos existentes no vetor (de 0 até totuser).
    for(i=0; i<totuser; i++)
    {
        // Compara o CPF neste elemento do vetor, com o CPF informado.
        // Se achou, retorna o índice.
        if ( strcmp(vetuser[i].CPF, CPF) == 0 )
            return i;
    }
            
    // Se chegou aqui, não achou. Retorna -1.
    return -1;
}

void incluir_emprestimo( livro *vetlivro, int *totlivro )
{
    char ISBN[12];
    char TITULO[31];
    char AUTOR[20];
    char GENERO[20];
    char LIXO[2];
    
    
    printf("\nInclusao de livro:\n");
    
    if ( *totlivro == TOTAL )
    {
        printf("\n*ERRO* Nao ha espaco para incluir mais um livro!\n");
    }
    else
    {
        printf("Digite o ISBN do livro: ");
        gets(ISBN);
    
        // Verificar se esta ISBN já existe no vetor:
        if ( existe_livro(vetlivro, *totlivro, ISBN) != -1 )
        {
            printf("\n* Esta ISBN ja existe!*\n");
        }
        else
        {
            // Tudo ok, receber o NOME e inserir os dados no vetor:
			strcpy(vetlivro[*totlivro].ISBN,ISBN);            
            printf("Digite o tiulo do livro: ");
            gets(TITULO);
        
            strcpy( vetlivro[*totlivro].TITULO, TITULO );
            printf("Digite o genero do livro: ");
            gets(GENERO);
            strcpy( vetlivro[*totlivro].GENERO, GENERO);
            printf("Digite o autor do livro");
            gets(AUTOR);
            strcpy(vetlivro[*totlivro].AUTOR, AUTOR);
       
            (*totlivro)++;
            
            printf("\n* livro inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}


void alterar_livro( livro *vetlivro, int *totlivro )
{
    char ISBN[12];
    char TITULO[31];
    char LIXO[2];
    char AUTOR[20];
    char GENERO[20];
    int indice;
    
    
    printf("\nAlteracao de livro:\n");
    
    printf("Digite o ISBN do livro: ");
    gets(ISBN);
    
    // Verificar se esta ISBN existe no vetor:
    indice = existe_livro(vetlivro, *totlivro, ISBN);
    
    if ( indice == -1 )
    {
        printf("\n* Esta ISBN naoo existe!*\n");
    }
    else
    {
        // Tudo ok, receber o ISBN e alterar os dados no vetor:
            
        printf("Digite o ISBN do livro: ");
        gets(ISBN);
        
        strcpy( vetlivro[indice].ISBN, AUTOR );
        strcpy( vetlivro[indice].TITULO, TITULO );
                strcpy( vetlivro[indice].GENERO, GENERO );

        
        printf("\n* tudo do livro alterado com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}


void apagar_livro( livro *vetlivro, int *totlivro )
{
    char ISBN[12];
    char LIXO[2];
    char AUTOR[20];
    char GENERO[20];
    char TITULO[20];
    int indice, i;	    
    printf("\nApagando livro:\n");
    
    printf("Digite o ISBN do livro: ");
    gets(ISBN);
    
    // Verificar se esta ISBN existe no vetor:
    indice = existe_livro(vetlivro, *totlivro, ISBN);
    
    if ( indice == -1 )
    {
        printf("\n* Este ISBN  nao existe!*\n");
    }
    else
    {         
        for( i=indice; i<(*totlivro)-1; i++)
        {
            strcpy( vetlivro[indice].ISBN, vetlivro[indice+1].ISBN );
            strcpy( vetlivro[indice].TITULO, vetlivro[indice+1].TITULO );
            strcpy( vetlivro[indice].AUTOR, vetlivro[indice+1].TITULO);
            strcpy( vetlivro[indice].GENERO, vetlivro[indice+1].TITULO);
        }
        
        // Decrementa *totDepto:
        (*totlivro)--;
            
        printf("\n* livro apagado com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultar_livro( livro *vetlivro, int *totlivro )
{
    char ISBN[12];
    char LIXO[2];
    char TITULO[20];
    char GENERO[20];
    char AUTOR[20];
    int indice;
    
    
    
    printf("\nConsultar livro:\n");
    
    printf("Digite a ISBN do livro: ");
    gets(ISBN);
    
    // Verificar se esta ISBN existe no vetor:
    indice = existe_livro(vetlivro, *totlivro, ISBN);
    
    if ( indice == -1 )
    {
        printf("\n* Este ISBN nao existe!*\n");
    }
    else
    {
        // Tudo ok, exibir os dados:
            
        printf("ISBN: %s\n",  vetlivro[indice].ISBN);
        printf("TITULO: %s\n", vetlivro[indice].TITULO);
        printf("Genero: %s\n", vetlivro[indice].GENERO);
        printf("Autor: %s\n", vetlivro[indice].AUTOR);
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    


void consultarTodos_livro( livro *vetlivro, int *totlivro )
{
    char LIXO[2];
    int i;
    
    if( (*totlivro) == 0 )
    {
        printf("\n nao ha livros a exibir!\n");
    }
    else
    {
        printf("\nExibindo todos os livros:\n");
    
        for( i=0; i<(*totlivro); i++ )
        {            
            printf("\nISBN: %s\n",  vetlivro[i].ISBN);
            printf("TITULO: %s\n",   vetlivro[i].TITULO);
            printf("Autor: %s\n", vetlivro[i].AUTOR);
            printf("Genero: %s\n", vetlivro[i].GENERO);
            
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
