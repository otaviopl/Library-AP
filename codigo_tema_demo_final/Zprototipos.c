

int existe_usuario( Usuario *vetUser, int totUser, char cpf[]);

void incluir_usuario( Usuario *vetUser, int *totUser );

void alterar_usuario( Usuario *vetUser, int *totUser );

void apagar_usuario( Usuario *vetUser, int *totUser, Emprestimo *vetEmpre, int totEmpre );

void consultar_usuario( Usuario *vetUser, int *totUser );

void consultarTodos_usuario( Usuario *vetUser, int *totUser );


int existe_livro( Livro *vetLivro, int totLivro, char isbn[]);

void incluir_livro( Livro *vetLivro, int *totLivro );

void alterar_livro( Livro *vetLivro, int *totLivro );

void apagar_livro( Livro *vetLivro, int *totLivro, Emprestimo *vetEmpre, int totEmpre );

void consultar_livro( Livro *vetLivro, int *totLivro );

void consultarTodos_livro( Livro *vetLivro, int *totLivro );



int existe_user_empre( Emprestimo *vetEmpre, int totEmpre, char cpf[] );

int existe_livro_empre( Emprestimo *vetEmpre, int totEmpre, char isbn[] );

int existe_empre( Emprestimo *vetEmpre, int totEmpre, char cpf[], char isbn[]);

void incluir_empre( Usuario *vetUser, int totUser, 
                      Livro *vetLivro, int totLivro, 
                      Emprestimo *vetEmpre, int* totEmpre );

void alterar_empre( Emprestimo *vetUser, int *totUser );

void apagar_usuario( Usuario *vetUser, int *totUser,Emprestimo *vetEmpre, int totEmpre );

void consultar_empre( Emprestimo *vetEmpre, int *totEmpre );

void consultarTodas_empre( Emprestimo *vetEmpre, int *totEmpre );

void emprestimo_por_cpf( Usuario *vetUser, int totUser, 
                         Livro *vetLivro, int totLivro, 
                         Emprestimo *vetEmpre, int totEmpre );
                         
void emprestimo_entre_datas( Usuario *vetUser, int totUser, 
                          	Livro *vetLivro, int totLivro, 
                          	Emprestimo *vetEmpre, int totEmpre );
                          



