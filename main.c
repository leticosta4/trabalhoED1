#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void lerArquivo(FILE *arquivo, int qtd, Arvore **viagem);

int main() {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  int qtd = 0;

  lerArquivo(arquivo, qtd, &viagem);

  emOrdem(viagem);

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