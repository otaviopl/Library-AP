
#include <stdio.h>
#include <string.h>

// Criando constante que representa a capacidade máxima dos vetores:
#define TOTAL 2


// Definindo a estrutura usuario:

typedef struct {
    
    char CPF[12];
    char NOME[31];
    char EMAIL[20];
	char CATEGORIA[15];
	
} usuario;


//----------------------------------------------------------------------


//
// Função existe_usuario
//
//
// Parâmetros:
//     - vetuser : ponteiro para o vetor de userionários.
//     - totuser : inteiro que registra quantos usuarios
//                 estão cadastrados no vetor.
//     - CPF     : string que representa o CPF a procurar.
//
// Retorno:
//     - inteiro : -1 se não achou.
//                 o índice onde está, se achou.
//

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


//----------------------------------------------------------------------


//
// Função incluir_usuario
//
// Parâmetros:
//     - vetuser : ponteiro para o vetor de userionários.
//     - totuser : ponteiro para o inteiro que registra 
//                 quantos usuarios estão cadastrados no vetor.

void incluir_usuario( usuario *vetuser, int *totuser )
{
    char CPF[12];
    char NOME[31];
    char EMAIL[20];
    char CATEGORIA[15];
    char LIXO[2];
    
    
    printf("\nIncluir usuario:\n");
    
    // ATENÇÃO! 	
    // Recebemos aqui o endereço de memória onde está a variável totuser.
    // Então, para acessar o seu conteúdo, 
    // precisamos usar o "operador de desreferência" (*) para acessar seu conteúdo.
    
    // Se o vetor chegou no seu limite, indicar erro:
    if ( *totuser == TOTAL )
    {
        printf("\n*ERRO* nao ha espaco para incluir mais um usuario!\n");
    }
    else
    {
        printf("Digite o CPF do usuario: ");
        gets(CPF);
    
        // Verificar se este CPF já existe no vetor:
        if ( existe_usuario(vetuser, *totuser, CPF) != -1 )
        {
            printf("\n* Este CPF ja existe!*\n");
        }
        else
        {
            // Tudo ok, receber o NOME e inserir os dados no vetor:
            
            strcpy(vetuser[*totuser].CPF,CPF);
            printf("Digite o nome do usuario: ");
            gets(NOME);
           	printf("Digite a categoria do usuario:--PROFESSOR OU ALUNO--");
           	gets(CATEGORIA);
            strcpy( vetuser[*totuser].CATEGORIA,CATEGORIA);
            printf("Digite o email do usuario:");
            gets(EMAIL);
            strcpy( vetuser[*totuser].EMAIL, EMAIL);
            
            // Como inserimos um userionário, incrementar a variável
            // que registra essa quantidade. Lembrando,
            // só temos o endereço, então precisamos usar o operador
            // de desreferência (*).
            // Outra coisa, cuidado!!!!
            // *totuser++ soma 1 no endereço em totuser!!!!!
            // Queremos somar 1 no CONTEÚDO apontado por totuser!!!
            // (já tivemos uma aula lá no início onde falamos dessa posição
            //  do operador).
            // Então:
            // (*totuser) acessa o conteúdo apontado por totuser.
            // (*totuser)++ soma 1 nesse conteúdo.
        
            (*totuser)++;
            
            printf("\n* usuario inserido com sucesso!\n");
        }
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
}


//----------------------------------------------------------------------


//
// Função alterar_usuario
//
// Parâmetros:
//     - vetuser : ponteiro para o vetor de userionários.
//     - totuser : ponteiro para o inteiro que registra 
//                 quantos usuarios estão cadastrados no vetor.

void alterar_usuario( usuario *vetuser, int *totuser )
{
    char CPF[12];
    char NOME[31];
    char LIXO[2];
    char EMAIL[20];
    char CATEGORIA[15];
    int indice;
    int opcao;
    
    
    printf("\nAlteracao de usuario:\n");
    
    printf("Digite o CPF do usuario:\n");
    gets(CPF);
    
    // Verificar se este CPF existe no vetor:
    indice = existe_usuario(vetuser, *totuser, CPF);
    
    if ( indice == -1 )
    {
        printf("\n* Este CPF nao existe!*\n");
    }
    else
    {
        // Tudo ok, receber o NOME e alterar os dados no vetor:
        printf("Digite o que quer mudar:\n");
		printf("1->Nome\n2->Email\n3->Categoria\n");
		scanf("%d%*c",&opcao);
		switch(opcao){
			case 1:
				do{
				printf("Digite o novo Nome do usuario:");
				gets(NOME);
				strcpy(vetuser[indice].NOME,NOME);
				printf("Nome alterado com sucesso!");
				}break;
			case 2:
				do{
				printf("Digite o novo Email do usuario:");
				gets(EMAIL);
				strcpy(vetuser[indice].EMAIL,EMAIL);
				printf("Email alterado com sucesso!");}
				break;
			case 3:
				do{
				
				printf("Digite o novo a nova Categoria:");
				gets(CATEGORIA);
				strcpy(vetuser[indice].CATEGORIA,CATEGORIA);
				printf("Categoria alterada com sucesso!!");
			}
			break;
			default:
				printf("opcao invalida!");
}
		

         
        strcpy( vetuser[indice].CPF, CPF );
            
        printf("\n* NOME do userionário alterado com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}  
//----------------------------------------------------------------------


//
// Função apagar_usuario
//
// Parâmetros:
//     - vetuser : ponteiro para o vetor de userionários.
//     - totuser : ponteiro para o inteiro que registra 
//                 quantos usuarios estão cadastrados no vetor.


// ATENÇÃO
// TÁ FALTANDO AQUI VERIFICAR SE EXISTEM ALGUMA LOTAÇÃO DESTE userIONÁRIO!
// SE TIVER, ERRO, NÃO PODE APAGAR!!!


void apagar_usuario( usuario *vetuser, int *totuser )
{
    char CPF[12];
    char LIXO[2];
    int indice, i;
    
    
    printf("\nApagando usuario:\n");
    
    printf("Digite o CPF do usuario: ");
    gets(CPF);
    
    // Verificar se este CPF existe no vetor:
    indice = existe_usuario(vetuser, *totuser, CPF);
    
    if ( indice == -1 )
    {
        printf("\n* Este CPF nao existe!*\n");
    }
    else
    {
        // Tudo ok, apagar o registro.
        // Lembrando que para apagar um elemento do vetor,
        // você precisa "deslocar para a esquerda"
        // todos os elementos seguintes armazenados no vetor,
        // isto é, deslocar "pra esquerda" desde o elemento 'indice'+1
        // até o elemento (*totuser)-1.
        // Ao final, decrementar *totuser.
            
        for( i=indice; i<(*totuser)-1; i++)
        {
            strcpy( vetuser[indice].CPF, vetuser[indice+1].CPF );
            strcpy( vetuser[indice].NOME, vetuser[indice+1].NOME );
        }
        
        // Decrementa *totuser:
        (*totuser)--;
            
        printf("\n* usuario apagado com sucesso!\n");
    }
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
    
    
//----------------------------------------------------------------------


//
// Função consultar_usuario
//
// Parâmetros:
//     - vetuser : ponteiro para o vetor de userionários.
//     - totuser : ponteiro para o inteiro que registra 
//                 quantos usuarios estão cadastrados no vetor.

void consultar_usuario( usuario *vetuser, int *totuser )
{
    char CPF[12];
    char LIXO[2];
    int indice;
    
    
    printf("\nConsultar usuario:\n");
    
    printf("Digite o CPF do usuario: ");
    gets(CPF);
    
    // Verificar se este CPF existe no vetor:
    indice = existe_usuario(vetuser, *totuser, CPF);
    
    if ( indice == -1 )
    {
        printf("\n* Este CPF nao existe!*\n");
    }
    else
    {            
        printf("CPF: %s\n",  vetuser[indice].CPF);
        printf("NOME: %s\n", vetuser[indice].NOME);
        printf("E-mail: %s\n", vetuser[indice].EMAIL);
        printf("Categoria: %s\n", vetuser[indice].CATEGORIA);
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}
//----------------------------------------------------------------------


//
// Função consultarTodos_usuario
//
// Parâmetros:
//     - vetuser : ponteiro para o vetor de userionários.
//     - totuser : ponteiro para o inteiro que registra 
//                 quantos usuarios estão cadastrados no vetor.

void consultarTodos_usuario( usuario *vetuser, int *totuser )
{
    char LIXO[2];
    int i;
    
    if( (*totuser) == 0 )
    {
        printf("\nao ha usuarios ha exibir!\n");
    }
    else
    {
        printf("\nExibindo todos os usuarios:\n");
    
        for( i=0; i<(*totuser); i++ )
        {            
            printf("\nCPF: %s\n",  vetuser[i].CPF);
            printf("NOME: %s\n",   vetuser[i].NOME);
            printf("E-mail: %s\n", vetuser[i].EMAIL);
            printf("Categoria (--aluno ou professor--): %s\n", vetuser[i].CATEGORIA);
        }
    }
    
    printf("\nDigite <ENTER> para continuar....");
    gets(LIXO);
    
}    
    
    
    
    
    
    
    
    
    
