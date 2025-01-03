#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema 
{
	//Início da criação de variáveis/string
    char arquivo[60];
    char cpf[60];
    char nome[60];
    char sobrenome[60];
    char cargo[60];
    //Final da ciração de variáveis
    
    printf("Digite o CPF a ser cadastrado:  "); //Coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
    
    
    FILE *file; // Acessa o FILE e cria um file. cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); //abre o arquivo com o nome que estiver dentro da variável. Cria o arquivo do tipo "w" write - escrever
    fprintf(file,cpf);  //ao invés dele passar pro usuário, está salvando no arquivo - no caso, o valor da variável
    fclose(file);  // fecha o arquivo 
    
    file = fopen(arquivo,"a"); //cria o arquivo do tipo "a" - atualiza
	fprintf(file,","); //insere a vírgula entre um e outro
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o Nome a ser cadastrado:  "); // Coletando informação do usuário
	scanf("%s",nome); //Salvando da string NOME
	
	file = fopen(arquivo, "a"); //Cria o arquivo do tipo "a" - atualizando
	fprintf(file,nome);  // salva no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - atualizando
	fprintf(file,","); //insere a vírgula entre um e outro
	fclose(file); //Fecha o arquivo
	
	printf("Digite o Sobrenome:  "); //Coleta mais este dado do usuário
	scanf("%s",sobrenome);  // Salvando da string SOBRENOME
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - atualiza
	fprintf(file,sobrenome); //salva no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - arquivo
	fprintf(file,","); //insere a vírgula entre um e outro
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo:  "); //Coleta mais este dado do usuário
	scanf("%s",cargo); //Salvando na string CARGO
	
	file = fopen(arquivo, "a"); //cria o arquivo do tipo "a" - atualiza
	fprintf(file,cargo); //salva o arquivo
	fclose(file); //fecha o arquivo

    system("pause"); //faz o sistema pausar
}

int consulta() //Função responsável por Consultar os usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem 
	
	//Início da criação de variáveis/string
    char cpf[40];
    char conteudo [200];
    //Final da ciração de variáveis
    
    printf("Digite o CPF a ser consultado: "); // Mensagem que aparecerá ao usuário para que ele possa digitar o CPF desejado para busca.
    scanf("%s",cpf); //Refere-se à string
    
    FILE *file; //consulteo arquivo
    file = fopen(cpf,"r"); //abrir o arquivo e lê-lo.
    
    if(file == NULL) //Caso o dado inserido seja nulo(não existente) ao que há salvo nos dados
    {
    printf("Usuário não localizado no sistema.\n"); //Caso o dado inserido seja divergente do que há salvo nos dados surgirá esta mensagem
   	}
   	
   	while(fgets(conteudo, 200, file) != NULL) //Enquanto o CPF digitado esteja de acordo com o que já tivermos armazenado em nossos dados
   	{
   		printf("\nEssas são as informações do usuário:  "); //Aparecerão as informações desejadas
   		printf("%s", conteudo);
   		printf("\n\n");
    }
    fclose(file);
	system("pause"); //Pausa
    
}

int deletar() //Função responsável por Consultar os usuários no sistema
{
    //Início da criação de variáveis/string - o caso, basta inserirmos o numero do CPF que desejamos deletar
	char cpf[40];
	//Final da ciração de variáveis
    
    printf("Digite o CPF do usuário a ser Deletado: "); //Mensagem que aparecerá ao usuário apra que ele possa inserir os CPF que deseja deletar
    scanf("%s",cpf); //Se refere a string
    
    remove(cpf); //Removerá o CPF digitado
    
    FILE *file;
    file = fopen(cpf,"r"); //Busca o dado e o lê
    
    if(file == NULL) //Caso a usca seja igual ao NULO
    {
    	printf("O usuário não se encontra no sistema.\n");
    	fclose(file);
		system("pause");
    }
    
}


int main () 
{
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
		system("cls");
			
    	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem 
	
	    printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1- Registrar Nomes\n");
	    printf("\t2- Consultar Nomes\n");
	    printf("\t3- Deletar Nomes\n\n"); 
	    printf ("\t4- Sair do Sistema\n\n");
    	printf("Opção:"); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a esolha do usuário.	
	    
		system("cls");//Responsável por limpar a tela
	    
	    switch(opcao) //Início da seleção do menu
	    {
	    	case 1:
	    	registro(); //Chamada da função "registro"
     	    break;
     	    
     	    case 2:
     	    consulta(); //Chamada da função "consulta"
            break;
            
            case 3:
            deletar(); //Chamada da função "delete"
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível.\n"); //Caso o que for digitado não seja nenhuma das 3 opções acima
	    	system("pause");
	    	break;
		} //Fim da seleção.
		
	}
}

	
	    
    

