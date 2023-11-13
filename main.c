#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>

void lerArquivoArvore(FILE *arquivo, int qtd, Arvore **viagem);
void lerArquivoLista(FILE *arquivo, Pais **paises, Sitio **sitio);

int main() {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  Pais *paises = NULL;
  Sitio *sitio = NULL; //nao tirar por causa da chamada da função lerArquivoLista
  int qtd = 0;

  lerArquivoArvore(arquivo, qtd, &viagem);
  lerArquivoLista(arquivo, &paises, &sitio);
  listarArvore(viagem);
  listarLista(paises);


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

void lerArquivoLista(FILE *arquivo, Pais **paises, Sitio **sitio) {
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
      (*paises) = inserirPaises(*paises, nome);
    } else {
      (*paises)->local = inserirCidade((*paises)->local, nome);
    }
  }
  fclose(arquivo);
}
