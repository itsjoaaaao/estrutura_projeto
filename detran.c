#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cad_carro{
	char nome[20];
	char modelo[20];
};

struct cliente{
	char nome[20];
	char sobrenome[20];
	char cpf[20];
	struct cad_carro carro;
};

int cadastrar_cliente(struct cliente *pessoa, FILE *parq);
void buscar_cliente(struct cliente *pessoa);
void excluir_cliente(struct cliente *pessoa);
void listar_cliente(struct cliente *pessoa);

int main(){
	
	FILE *parq;
	struct cliente *pessoa;
	int op;
  //int cod;

  //alocar memoria
  pessoa = (struct cliente*) malloc(2*(sizeof(struct cliente)));
  if(pessoa == NULL){
    printf("ERRO na memória!!\n");
    exit(1);
  }

  printf("\t\t...Arquivo sendo criado....\n");
	parq = fopen("arquivo_detran.txt","w");
	
	if(parq == NULL){
		printf("erro na abertura do arquivo!!");
		exit(1);
	}
	
	do{
    //system("cls");
		printf("DETRAN:\n");
		printf("Bem-vindo!!\n");
		printf("\t1 - cadastrar cliente\n");
		printf("\t2 - buscar cliente\n");
		printf("\t3 - excluir cliente\n");
    printf("\t4 - listar clientes\n");
		printf("\t5 - sair\n");
		scanf("%d", &op);
		
		
		switch(op){
			case 1:
				cadastrar_cliente(pessoa, parq);
			break;
			case 2:
				buscar_cliente(pessoa);
			break;
			case 3:
				excluir_cliente(pessoa);
      break;
      case 4:
        listar_cliente(pessoa);
      break;
			case 5:
				printf("Saindo...\n");
			break;
			default:
				printf("opcao invalida!\n");
		}
	}while(op<4);

  //fecha o arquivo
	fclose(parq);
  //libera a memoria alocada
  free(pessoa);
	
	return 0;
}

int cadastrar_cliente(struct cliente *pessoa, FILE *parq){

  //system("cls");
	for(int i=0; i<2; i++){
    printf("ID: %d\n", i);
		printf("digite o nome:\n");
		scanf(" %[^\n]", pessoa[i].nome);
		printf("digite o sobrenome:\n");
		scanf(" %[^\n]", pessoa[i].sobrenome);
		printf("digite o cpf:\n");
		scanf(" %[^\n]", pessoa[i].cpf);
		printf("digite o nome do carro:\n");
		scanf(" %[^\n]", pessoa[i].carro.nome);
    printf("digite o modelo do carro:\n");
    scanf(" %[^\n]", pessoa[i].carro.modelo);
	}

  for(int i=0; i<2; i++){
    fprintf(parq,"\t\t---DADOS---\n");
    fprintf(parq,"ID: %d\n", i);
    fprintf(parq,"Nome: %s\n", pessoa[i].nome);
	  fprintf(parq,"Sobrenome: %s\n", pessoa[i].sobrenome);
	  fprintf(parq,"CPF: %s\n", pessoa[i].cpf);
	  fprintf(parq,"Carro: %s\n", pessoa[i].carro.nome);
    fprintf(parq,"Modelo: %s\n", pessoa[i].carro.modelo);
  }
	
}

void buscar_cliente(struct cliente *pessoa){
  //system("cls");
  char bus;

  fflush(stdin);
  printf("Digite o cpf de quem deseja buscar:\n");
  scanf("%s", &bus);

	for(int i=0; i<2; i++){
    if(strcmp(&bus,pessoa[i].cpf)==0){
		  printf("Nome: %s\n", pessoa[i].nome);
		  printf("Sobrenome: %s\n", pessoa[i].sobrenome);
		  printf("CPF: %s\n", pessoa[i].cpf);
		  printf("Carro: %s\n", pessoa[i].carro.nome);
      printf("Modelo do carro: %s\n", pessoa[i].carro.modelo);
    }
	}
}

void excluir_cliente(struct cliente *pessoa){
  int cod;
  int exc;

	printf("Digite o ID do contato:\n");
  scanf("%d", &cod);

  for(int i=0; i<2; i++){
    if(cod==i){
      printf("Nome: %s\n", pessoa[i].nome);
		  printf("Sobrenome: %s\n", pessoa[i].sobrenome);
		  printf("CPF: %s\n", pessoa[i].cpf);
		  printf("Carro: %s\n", pessoa[i].carro.nome);
      printf("Modelo do carro: %s\n", pessoa[i].carro.modelo);
    }
  }

  printf("Deseja excluir este cliente? - [1]SIM ou [2]NÂO\n");
  scanf("%d", &exc);
  if(exc==1){
    for(int i=cod; i<cod; i++){
      strcpy(pessoa[i].nome,pessoa[i+1].nome);
      strcpy(pessoa[i].sobrenome,pessoa[i+1].sobrenome);
      strcpy(pessoa[i].cpf,pessoa[i+1].cpf);
      strcpy(pessoa[i].carro.nome,pessoa[i+1].carro.nome);
      strcpy(pessoa[i].carro.modelo,pessoa[i+1].carro.modelo);
    }
    cod--;
  }

void listar_cliente(struct cliente *pessoa){

  for(int i=0; i<2; i++){
      printf("ID: %d\n", i);
      printf("Nome: %s\n", pessoa[i].nome);
		  printf("Sobrenome: %s\n", pessoa[i].sobrenome);
		  printf("CPF: %s\n", pessoa[i].cpf);
		  printf("Carro: %s\n", pessoa[i].carro.nome);
      printf("Modelo do carro: %s\n\n", pessoa[i].carro.modelo);
  }
  
}



}
