#include <stdio.h>
#include <string.h>
#include <stdlib.h>





void opcoes_do_sistema();
void estoque_de_material();
void saida_de_material();
void salvar_em_arquivo();
void carregar_arquivo();
void adicionar_cliente();
void guardar_saida();
void abrir_movimentacao();



struct _cliente{
  char nome[128];
  char endereco[128];
  char telefone[50];
};
typedef struct _cliente cliente;

cliente cadastrar_cliente[1000];
int num_clientes = 0;

struct estoque{
  char produtos[128];
  float quantidade;
  char unidade_medida[50];
};
typedef struct estoque estoque;

estoque cadastro_material_de_construcao[1000];
int num_de_itens = 0;

int procurar_estoque(char produto[], int tamanho, struct estoque cadastro_material_de_construcao[]);

struct movimentacao {
  char produtos[128];
  float quantidade;
  char unidade_medida[50];
  char nome[128];
  char endereco[128];

};
typedef struct movimentacao movimentacao;

movimentacao movimentacao_de_materiais[1000];
int sai_ent_materiais = 0;



int main(void) {
  int indice;
  carregar_arquivo();
  abrir_movimentacao();
	 
  char produtos[128] = ("brita");
  indice = procurar_estoque(produtos, num_de_itens, cadastro_material_de_construcao);
  printf("valor %s no indice => %d\n",produtos, indice);

  char opcao = 0; 
  int i;
 
  opcoes_do_sistema();

  while(1){
   
    printf(" \ndigite a opcao desejada:");
    scanf(" %c", &opcao);

    if(opcao=='c') {
      adicionar_cliente();

    }else if(opcao=='e') {
      estoque_de_material();

    }else if(opcao=='s') {
      saida_de_material();
      guardar_saida();
      

    }else if(opcao=='i') {
      printf("ESTOQUE DE MATERIAIS");
	  for( i = 0; i < num_de_itens; i++){
        printf("\t Nome do produto - %s \n", cadastro_material_de_construcao[i].produtos);
        printf("\t Quantidade -  %f %s \n", cadastro_material_de_construcao[i].quantidade, cadastro_material_de_construcao[i].unidade_medida);
        }


    }else if (opcao =='l') {
      printf("LISTA DE CLIENTES\n");
      for( i=0; i<num_clientes; i++ ){
        printf("nome: %s\n", cadastrar_cliente[i].nome);
        printf("endereco: %s\n", cadastrar_cliente[i].endereco);
        }




    }else if(opcao=='m') {
      printf(" Movimentação\n");
      for( i = 0; i < sai_ent_materiais; i++){
      	printf("nome do produto: %s\n", movimentacao_de_materiais[i].produtos);
      	printf(" quantidade: %.1f %s\n",movimentacao_de_materiais[i].quantidade, movimentacao_de_materiais[i].unidade_medida);
      	printf(" nome do cliente: %s\n",movimentacao_de_materiais[i].nome);
      	printf(" endereco: %s\n",movimentacao_de_materiais[i].endereco);
      	
	  }
      
    }else if(opcao=='p') {
        printf(" SAIR\n");
        break;

    } 
  salvar_em_arquivo();


  return 0;
}
void opcoes_do_sistema(){
  printf("opções disponiveis:\n");
  printf("\t e - Entrada de material \n");
  printf("\t s - Saida de material \n");
  printf("\t i - inventario \n");
  printf("\t c - Cadastro de clientes \n");
  printf("\t l - lista de clientes \n");
  printf("\t m - movimentacao \n");
}
void adicionar_cliente(){
  cliente novo_cliente;

  printf("Adicionar clientes \n");
  printf(" Nome do cliente: ");
  scanf(" %[^\n]", novo_cliente.nome);
  printf(" Endereco: ");
  scanf(" %[^\n]", novo_cliente.endereco);
  printf(" telefone: ");
  scanf(" %[^\n]", novo_cliente.telefone);

  cadastrar_cliente[num_clientes] = novo_cliente;
  num_clientes += 1;

}
void  estoque_de_material(){
  estoque receb_material;

  printf(" CADASTRO DE MATERIAIS \n");
  printf(" Nome do produto: ");
  scanf(" %[^\n]", receb_material.produtos);
  printf(" Quantidade: ");
  scanf(" %f %s", &receb_material.quantidade, receb_material.unidade_medida);

  cadastro_material_de_construcao[num_de_itens] = receb_material;
  num_de_itens += 1;


}
void saida_de_material(){
  movimentacao vende_material; 
  
 	

  printf(" SAIDA DE MATERIAIS \n");
  printf("Nome do produto: ");
  scanf(" %[^\n]", vende_material.produtos);
  printf(" Quantidade: ");
  scanf(" %f %[^\n]", &vende_material.quantidade, vende_material.unidade_medida);
  printf("Nome do cliente:");
  scanf("  %[^\n]", vende_material.nome);
  printf("Endereco:");
  scanf("  %[^\n]", vende_material.endereco);


  movimentacao_de_materiais[sai_ent_materiais] = vende_material;
  sai_ent_materiais += 1;
  
}
void salvar_em_arquivo(){
  FILE* arq = fopen("armazem.dat","w");

  fprintf(arq," estoque: %d \n", num_de_itens);

  int i;
  for( i = 0; i < num_de_itens; i++){
    fprintf(arq," produto: %s\n", cadastro_material_de_construcao[i].produtos);
    fprintf(arq," quantidade: %.1f %s\n", cadastro_material_de_construcao[i].quantidade, cadastro_material_de_construcao[i].unidade_medida );
    }

  fprintf(arq," lista de clientes: %d \n", num_clientes);

  int c;
  for( c = 0; c < num_clientes; c++){
    fprintf(arq,"%s\n",cadastrar_cliente[c].nome);
    fprintf(arq,"%s\n",cadastrar_cliente[c].endereco);
    fprintf(arq,"%s\n",cadastrar_cliente[c].telefone);

  } fclose(arq);

  printf("ARQUIVO SALVO\n");
}
void carregar_arquivo(){
  FILE* arq = fopen("armazem.dat", "r");

  fscanf(arq," estoque: %d \n", &num_de_itens);

  int i;
  for( i = 0; i < num_de_itens; i++){
    fscanf(arq," produto: %s\n", cadastro_material_de_construcao[i].produtos);
    fscanf(arq," quantidade: %f %s\n", &cadastro_material_de_construcao[i].quantidade, cadastro_material_de_construcao[i].unidade_medida );
    }

  fscanf(arq," lista de clientes: %d \n", &num_clientes);

  int c;
  for( c = 0; c < num_clientes; c++){
    fscanf(arq," %[^\n]", cadastrar_cliente[c].nome);
    fscanf(arq," %[^\n]", cadastrar_cliente[c].endereco);
    fscanf(arq," %[^\n]", &cadastrar_cliente[c].telefone);



  } fclose(arq);
  printf("ARQUIVO GARREGADO!\n");

}
void guardar_saida(){

  FILE* arqv = fopen("movimetacao.dat", "w");

  fprintf(arqv,"numero de vendas: %d \n", sai_ent_materiais);

  int i;
  for( i = 0; i < sai_ent_materiais; i++){
    fprintf(arqv," produto: %s\n", movimentacao_de_materiais[i].produtos);
    fprintf(arqv," quantidade: %.1f %s\n", movimentacao_de_materiais[i].quantidade, movimentacao_de_materiais[i].unidade_medida );
    fprintf(arqv,"%s\n",movimentacao_de_materiais[i].nome);
    fprintf(arqv,"%s\n",movimentacao_de_materiais[i].endereco);

  }
}
void abrir_movimentacao(){
	
	FILE* arqv = fopen("movimentacao.dat", "r");
	
	fscanf(arqv,"numero de vendas: %d \n", &sai_ent_materiais);
	
	int i;
	for( i = 0; i < sai_ent_materiais; i++){
		fscanf(arqv," %[^\n]", movimentacao_de_materiais[i].produtos);
		fscanf(arqv," %f %[^\n]", &movimentacao_de_materiais[i].quantidade,  movimentacao_de_materiais[i].unidade_medida);
		fscanf(arqv," %[^\n]", movimentacao_de_materiais[i].nome);
		fscanf(arqv," %[^\n]", movimentacao_de_materiais[i].endereco);
	}
}
int procurar_estoque(char produto[], int tamanho, struct estoque cadastro_material_de_construcao[]){
	

	int i;
    for( i = 0; i < tamanho; i++){
        if( strcmp (produto,cadastro_material_de_construcao[i].produtos)== 0){
         return i;
        }
    }
         return -1;
}

	





