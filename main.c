//#include "arvore.h"
#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


void lerArquivoArvore(FILE *arquivo, int qtd, Arvore **viagem);
void lerArquivoLista(FILE *arquivo, Pais **pais);

int main() {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  Pais *pais = NULL;
  Sitio *sitio = NULL;
  int qtd = 0,opcao = 0;

  lerArquivoArvore(arquivo, qtd, &viagem);
  lerArquivoLista(arquivo, &pais);
  //listarArvore(viagem);
  //listarLista(pais);
  printf("Bem vindo à Viagens ED1!\n\n");
  //aviao();
  menu();
  printf("Digite a opção desejada: \n");
  // scanf("%d", &opcao);
  opcao = 2;
  system("clear");
  switch (opcao) {
  case 1:
    clienteTipo1();
    break;
  case 2:
    arvoreRespostas(viagem);
    break;
  case 3:
    listarLista(pais);
    break;
  case 4:
  case 5:
  case 6:
    // listasEspecificas(paises, opcao);
    break;
  case 7:
    exit(1);

    default:
      printf("Opção Inválida!!\n");
      break;
  }

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

  for (int i = 0; i < 16; i++) {

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

