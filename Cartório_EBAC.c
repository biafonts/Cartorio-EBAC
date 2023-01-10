#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca��o de texto por regi�o
# include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // respons�vel por cadastrar usu�rios no sistema
{
	// in�cio cria��o de vari�veis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das vari�veis
	
	printf ("Digite o CPF a ser cadastrado:");// coletando informa��o do usu�rio
	scanf("%s",cpf);// %s refere-se a string
	
	strcpy(arquivo,cpf); // Respons�vel por copiar valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo eo 'w' significa escrever
	fprintf(file,cpf);// salvo o valor da vari�vel
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

// in�cio cria��o de vari�veis/string	
	char cpf[40];
	char conteudo[200];
// fim cria��o de vari�veis/string
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file== NULL)
	{
		printf("N�o foi poss�vel localizar o registro!\n");		
	}
	
	while (fgets(conteudo,200,file)!=NULL);
	
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];// cria��o de vari�veis/string
	
	printf("Digite o cpf a ser deletado:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen (cpf,"r");// 'r' l� o arquivo
		
	
	if(file == NULL)
	{
		printf ("O usu�rio n�o se encontra no sistema! .\n");
		system ("pause");	
	}
	
	else
	{
		fclose(file);
		remove(cpf);// remove o registro
		printf ("Usu�rio deletado com sucesso!\n");
		system ("pause");
	}
		
}

int main ()
{

	int opcao=0;//Vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system ("cls");
			
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cart�rio da EBAC ### \n\n");//In�cio do menu
		printf ("Escolha a op��o desejada do menu: \n\n");
		printf ("\t01 - Registrar nomes\n");
		printf ("\t02 - Consultar nomes\n");
		printf ("\t03 - Deletar nomes\n");
		printf ("\t04 - Sair do sistema\n");
		printf ("Op��o:");// Fim do menu
	
		scanf ("%d",&opcao);
	
		system ("cls");
		
		switch (opcao) // in�cio da sele��o
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
			printf ("Essa op��o n�o est� dispon�vel!\n");
			system ("pause");
			break; 
			
		} // fim da sele��o		

	}

}
