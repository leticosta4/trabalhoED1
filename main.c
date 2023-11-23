#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>

void lerArquivoArvore(FILE *, int, Arvore **);
void lerArquivoLista(FILE *, Pais **);

int main() {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  Pais *pais = NULL;
  Sitio *sitio = NULL;
  int qtd = 0;
  char opcao;

  lerArquivoArvore(arquivo, qtd, &viagem);
  lerArquivoLista(arquivo, &pais);

  printf("Bem vindo à Viagens ED1!\n\n");
  aviao();
  pausar();

  do {
    system("clear");
    menu();
    printf("Digite a opção desejada: ");
    scanf(" %c", &opcao);
    system("clear");

    switch (opcao) {
    case '1':
      addCliente(pais, "", 1);
      pausar();
      break;
    case '2':
      addCliente(pais, arvoreRespostas(viagem), 2);
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
      if(paisMaisVisitado(pais) != 0){ //so chama a função de cidade mais visitada se tiver algum pais
        cidadeMaisVisitada(pais);
      }
      pausar();
      break;
    case '9':
      theEnd();
      pause();
      exit(1);
    default:
      printf("Opção Inválida!!\n");
      sleep(2);
      break;
    }
  } while (opcao != 9);
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
  for (int i = 0; i < 27; i++) {
    fscanf(arquivo, "%d, %[^\n]", &indice, nome);
    if (indice == 0) {
      (*pais) = inserirPaises(*pais, nome);
    } else {
      (*pais)->local = inserirCidade((*pais)->local, nome);
    }
  }
  fclose(arquivo);
}
