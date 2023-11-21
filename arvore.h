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

char* arvoreRespostas(Arvore *);
Arvore *inserir(Arvore *, int, char *);
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

void listarArvore(Arvore *raiz) { // esse que tem que usar
  if (raiz == NULL)
    return;
  printf("Prioridade: %d - Pergunta: %s\n", raiz->prioridade, raiz->pergunta);
  listarArvore(raiz->sim);
  listarArvore(raiz->nao);
}

char* arvoreRespostas(Arvore *viagens) {
  char resp;


  if (viagens->sim == NULL && viagens->nao == NULL ){
    system("clear");
    printf("O país selecionado após intensa pesquisa foi: %s\n", viagens->pergunta);
    return (viagens->pergunta);
  }

  do {
    sleep(1);
    system("clear");
    printf("Responda!\n");
    printf("%s\n", viagens->pergunta);
    scanf(" %c", &resp);
  } while (!erroResposta(resp));



  if (resp == 's' || resp == 'S' )
    return arvoreRespostas(viagens->sim);
   else 
    return arvoreRespostas(viagens->nao);

}
