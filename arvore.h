#include "tratamentosErros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct arvore {
  struct arvore *sim, *nao;
  char pergunta[50];
  int prioridade;
} Arvore;

void arvoreRespostas(Arvore *viagens);
Arvore *inserir(Arvore *, int, char *);
// int busca(Arvore*, int);
void listarArvore(Arvore *);

Arvore *inserir(Arvore *raiz, int n, char *l) {
  if (raiz == NULL) {
    raiz = (Arvore *)malloc(sizeof(Arvore));

    if (raiz == NULL)
      exit(1);
    raiz->prioridade = n;
    strcpy(raiz->pergunta, l);
    raiz->nao = NULL;
    raiz->sim = NULL;
    return raiz;
  }
  if (n > raiz->prioridade) {
    raiz->nao = inserir(raiz->nao, n, l);
  } else if (n < raiz->prioridade)
    raiz->sim = inserir(raiz->sim, n, l);
  else {
    printf("Número inválido");
  }
  return raiz;
}

/*
int busca(Arvore *raiz, int n){
  if(raiz == NULL) return 0;

  if(raiz->prioridade  == n) return 1;
  else if(raiz->prioridade < n) busca(raiz->nao, n);
  else busca(raiz->sim,n);
}
*/

void listarArvore(Arvore *raiz) { // esse que tem que usar
  if (raiz == NULL)
    return;
  printf("Prioridade: %d - Pergunta: %s\n", raiz->prioridade, raiz->pergunta);
  listarArvore(raiz->sim);
  listarArvore(raiz->nao);
}

void arvoreRespostas(Arvore *viagens) {
  char resp;
   do {
    sleep(1);
    system("clear");
    printf("Responda!\n");
    printf("%s\n", viagens->pergunta);
    scanf(" %c", &resp);
  } while (!erroResposta(resp));
  if (resp == 85 || resp == 115)
    arvoreRespostas(viagens->sim);
  else
    arvoreRespostas(viagens->nao);
}