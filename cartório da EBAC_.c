#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//In�cio da cria��o de vari�veis/string
    char arquivo[60];
    char cpf[60];
    char nome[60];
    char sobrenome[60];
    char cargo[60];
    //Final da cira��o de vari�veis
    
    printf("Digite o CPF a ser cadastrado:  "); //Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
    
    
    FILE *file; // Acessa o FILE e cria um file. cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); //abre o arquivo com o nome que estiver dentro da vari�vel. Cria o arquivo do tipo "w" write - escrever
    fprintf(file,cpf);  //ao inv�s dele passar pro usu�rio, est� salvando no arquivo - no caso, o valor da vari�vel
    fclose(file);  // fecha o arquivo 
    
    file = fopen(arquivo,"a"); //cria o arquivo do tipo "a" - atualiza
	fprintf(file,","); //insere a v�rgula entre um e outro
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o Nome a ser cadastrado:  "); // Coletando informa��o do usu�rio
	scanf("%s",nome); //Salvando da string NOME
	
	file = fopen(arquivo, "a"); //Cria o arquivo do tipo "a" - atualizando
	fprintf(file,nome);  // salva no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - atualizando
	fprintf(file,","); //insere a v�rgula entre um e outro
	fclose(file); //Fecha o arquivo
	
	printf("Digite o Sobrenome:  "); //Coleta mais este dado do usu�rio
	scanf("%s",sobrenome);  // Salvando da string SOBRENOME
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - atualiza
	fprintf(file,sobrenome); //salva no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - arquivo
	fprintf(file,","); //insere a v�rgula entre um e outro
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo:  "); //Coleta mais este dado do usu�rio
	scanf("%s",cargo); //Salvando na string CARGO
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - atualiza
	fprintf(file,cargo); //salva o arquivo
	fclose(file); //fecha o arquivo

    system("pause"); //faz o sistema pausar
}

int consulta() //Fun��o respons�vel por Consultar os usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem 
	
	//In�cio da cria��o de vari�veis/string
    char cpf[40];
    char conteudo [200];
    //Final da cira��o de vari�veis
    
    printf("Digite o CPF a ser consultado: "); // Mensagem que aparecer� ao usu�rio para que ele possa digitar o CPF desejado para busca.
    scanf("%s",cpf); //Refere-se � string
    
    FILE *file; //consulteo arquivo
    file = fopen(cpf,"r"); //abrir o arquivo e l�-lo.
    
    if(file == NULL) //Caso o dado inserido seja nulo(n�o existente) ao que h� salvo nos dados
    {
    printf("Usu�rio n�o localizado no sistema.\n"); //Caso o dado inserido seja divergente do que h� salvo nos dados surgir� esta mensagem
   	}
   	
   	while(fgets(conteudo, 200, file) != NULL) //Enquanto o CPF digitado esteja de acordo com o que j� tivermos armazenado em nossos dados
   	{
   		printf("\nEssas s�o as informa��es do usu�rio:  "); //Aparecer�o as informa��es desejadas
   		printf("%s", conteudo);
   		printf("\n\n");
    }
    fclose(file);
	system("pause"); //Pausa
    
}

int deletar() //Fun��o respons�vel por Consultar os usu�rios no sistema
{
    //In�cio da cria��o de vari�veis/string - o caso, basta inserirmos o numero do CPF que desejamos deletar
	char cpf[40];
	//Final da cira��o de vari�veis
    
    printf("Digite o CPF do usu�rio a ser Deletado: "); //Mensagem que aparecer� ao usu�rio apra que ele possa inserir os CPF que deseja deletar
    scanf("%s",cpf); //Se refere a string
    
    remove(cpf); //Remover� o CPF digitado
    
    FILE *file;
    file = fopen(cpf,"r"); //Busca o dado e o l�
    
    if(file == NULL) //Caso a usca seja igual ao NULO
    {
    	printf("O usu�rio n�o se encontra no sistema.\n");
    	fclose(file);
		system("pause");
    }
    
}


int main () 
{
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
		system("cls");
			
    	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem 
	
	    printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1- Registrar Nomes\n");
	    printf("\t2- Consultar Nomes\n");
	    printf("\t3- Deletar Nomes\n\n"); 
	    printf ("\t4- Sair do Sistema\n\n");
    	printf("Op��o:"); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a esolha do usu�rio.	
	    
		system("cls");//Respons�vel por limpar a tela
	    
	    switch(opcao) //In�cio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //Chamada da fun��o "registro"
     	    break;
     	    
     	    case 2:
     	    consulta(); //Chamada da fun��o "consulta"
            break;
            
            case 3:
            deletar(); //Chamada da fun��o "delete"
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel.\n"); //Caso o que for digitado n�o seja nenhuma das 3 op��es acima
	    	system("pause");
	    	break;
		} //Fim da sele��o.
		
	}
}

	
	    
    

