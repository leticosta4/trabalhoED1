//#include "arvore.h"
#include "clientes.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

void lerArquivoArvore(FILE *arquivo, int qtd, Arvore **viagem);
void lerArquivoLista(FILE *arquivo, Pais **pais);
void pausar();
int main() {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  Pais *pais = NULL;
  Sitio *sitio = NULL;
  int qtd = 0;
  char opcao;
  

  lerArquivoArvore(arquivo, qtd, &viagem);
  lerArquivoLista(arquivo, &pais);
  // listarArvore(viagem);
  // listarLista(pais);

  printf("Bem vindo à Viagens ED1!\n\n");
  //aviao();
 // pausar();

  do {
    // printf("Bem vindo à Viagens ED1!\n\n");
    // aviao();
    system("clear");
    menu();
    printf("Digite a opção desejada: ");
    scanf(" %c", &opcao);
    system("clear");
  
    switch (opcao) {
    case '1':
      clienteTipo1(pais," ",1);
      pausar();
      break;
    case '2':
      clienteTipo1(pais,arvoreRespostas(viagem),2);
      pausar();
      break;
    case '3':
      listarLista(pais);
      pausar();
      break;
    case '4':
    case '5':
    case '6':
    case '7':
      listasEspecificas(pais, opcao);
      pausar();
      break;
    case '8':
      exit(1);

    default:
      printf("Opção Inválida!!\n");
      sleep(2);
      break;
    }
  } while (opcao != 8);
  return 0;
}

void lerArquivoArvore(FILE *arquivo, int qtd, Arvore **viagem) {
  char local[50];
  int prioridade = 0;

  arquivo = fopen("LetTexto.txt", "r+");
  if (arquivo == NULL) {
    printf("Erro, arquivo não aberto");
    return;
  }

  for (int i = 0; i < 33; i++) {

    fscanf(arquivo, "%d,%[^\n]", &prioridade, local);
    (*viagem) = inserir(*viagem, prioridade, local);
  }

  fclose(arquivo);
}

void lerArquivoLista(FILE *arquivo, Pais **pais) {
  char nome[50];
  int indice = 0;

  arquivo = fopen("LetDestinos.txt", "r+");
  if (arquivo == NULL) {
    printf("Erro, arquivo não aberto");
    return;
  }
  for (int i = 0; i < 26; i++) {
    fscanf(arquivo, "%d, %[^\n]", &indice, nome);
    if (indice == 0) {
      (*pais) = inserirPaises(*pais, nome);
    } else {
      (*pais)->local = inserirCidade((*pais)->local, nome);
    }
  }
  fclose(arquivo);
}

void pausar() {
  printf("Pressione Enter para continuar...\n");
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  getchar();
}