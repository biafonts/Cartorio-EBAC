#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocação de texto por região
# include <string.h> // biblioteca responsável por cuidar das strings

int registro() // responsável por cadastrar usuários no sistema
{
	// início criação de variáveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação das variáveis
	
	printf ("Digite o CPF a ser cadastrado:");// coletando informação do usuário
	scanf("%s",cpf);// %s refere-se a string
	
	strcpy(arquivo,cpf); // Responsável por copiar valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo eo 'w' significa escrever
	fprintf(file,cpf);// salvo o valor da variável
	fclose (file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf ("%s", cargo);
	
	file= fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");// Definido o idioma

// início criação de variáveis/string	
	char cpf[40];
	char conteudo[200];
// fim criação de variáveis/string
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file== NULL)
	{
		printf("Não foi possível localizar o registro!\n");		
	}
	
	while (fgets(conteudo,200,file)!=NULL);
	
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];// criação de variáveis/string
	
	printf("Digite o cpf a ser deletado:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen (cpf,"r");// 'r' lê o arquivo
		
	
	if(file == NULL)
	{
		printf ("O usuário não se encontra no sistema! .\n");
		system ("pause");	
	}
	
	else
	{
		fclose(file);
		remove(cpf);// remove o registro
		printf ("Usuário deletado com sucesso!\n");
		system ("pause");
	}
		
}

int main ()
{

	int opcao=0;//Variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system ("cls");
			
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cartório da EBAC ### \n\n");//Início do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t01 - Registrar nomes\n");
		printf ("\t02 - Consultar nomes\n");
		printf ("\t03 - Deletar nomes\n");
		printf ("\t04 - Sair do sistema\n");
		printf ("Opção:");// Fim do menu
	
		scanf ("%d",&opcao);
	
		system ("cls");
		
		switch (opcao) // início da seleção
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf ("Agradecemos por utilizar nosso sistema!\n");
			return 0;
			break;
						
			default:
			printf ("Essa opção não está disponível!\n");
			system ("pause");
			break; 
			
		} // fim da seleção		

	}

}
