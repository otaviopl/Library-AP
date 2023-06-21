
#define TOTAL 10



typedef struct {
    
    char CPF[12];
    char nome[31];
    char email[31];
    char categoria[20];
    
} Usuario;


typedef struct {
    
    char ISBN[12];
    char TITULO[31];
	char GENERO[20];
	char AUTOR[31];
} Livro;


typedef struct {
    
    char CPF[12];
    char ISBN[12];
    char dataRetirada[11];
    char dataDevolucao[11];
    
} Emprestimo;



