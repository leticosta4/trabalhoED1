#include "arvore.h" 
#include "destinos.h"
//tirar dps pq ja estao em clientes.h
#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerArquivo(FILE *arquivo, int qtd, Arvore **viagem);
void lerArquivoLista(FILE *arquivo, Pais **pais, Sitio **sitio);

int main(void) {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  int qtd = 0;

  lerArquivo(arquivo, qtd, &viagem);
  
  //chamar função da pagina inicial
  listarArvore(viagem);
  return 0;
}

void lerArquivo(FILE *arquivo, int qtd, Arvore **viagem) {
  char local[50];
  int prioridade = 0;

  arquivo = fopen("TextoDeLet.txt", "r+");
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

void lerArquivoLista(FILE *arquivo, Pais **pais, Sitio **sitio) {
  char nome[50];
  int indice = 0;

  arquivo = fopen("Destinos.txt", "r+");
  if (arquivo == NULL) {
    printf("Erro, arquivo não aberto");
    return;
  }
  for (int i = 0; i < 14; i++) {
    fscanf(arquivo, "%d, %[^\n]", &indice, nome);
    if (indice == 1) {
      (*pais) = inserirPaises(*pais, nome);
    } else {
      (*pais)->local = inserirCidade((*pais)->local, nome);
    }
  }
  fclose(arquivo);
}
