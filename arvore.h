#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore{
  struct arvore *sim, *nao;
  char pergunta[50];
  int prioridade;
}Arvore;


Arvore* inserir(Arvore *, int, char *);
void emOrdem(Arvore *);
void preOrdem(Arvore *);
void posOrdem(Arvore *);
//Arvore* retirar(Arvore *, int);
//Arvore* substitui(Arvore *, Arvore *);
//int busca(Arvore*, int);

Arvore* inserir(Arvore *raiz, int n, char *l){
  if(raiz == NULL){
    raiz = (Arvore*) malloc(sizeof(Arvore));

  if(raiz == NULL) exit(1);
    raiz->prioridade = n;
    strcpy(raiz->pergunta, l);
    raiz->nao = NULL;
    raiz->sim = NULL;
    return raiz;
  }
  if(n>raiz->prioridade){
    raiz->nao = inserir(raiz->nao, n, l);
  }
  else if (n<raiz->prioridade)
    raiz->sim = inserir(raiz->sim, n, l);
  else{
    printf("Número inválido");
  }
  return raiz;
  }

void emOrdem(Arvore *raiz){
  if(raiz == NULL) return;
  emOrdem(raiz->sim);
  printf("Prioridade: %d - Pergunta: %s\n", raiz->prioridade, raiz->pergunta);
  emOrdem(raiz->nao);
}

void posOrdem(Arvore *raiz){
  emOrdem(raiz->sim);
  emOrdem(raiz->nao);
  printf("%d", raiz->prioridade);
}

void preOrdem(Arvore *raiz){
  printf("%d", raiz->prioridade);
  emOrdem(raiz->sim);
  emOrdem(raiz->nao);

}
/*
Arvore* retirar(Arvore *raiz, int n){
  Arvore* aux;

  if(raiz->prioridade < n) raiz->nao = retirar(raiz->nao,n);
   else
    if(raiz->prioridade > n) raiz->sim = retirar(raiz->sim,n);
      else
        if(raiz->nao == NULL){
          aux = raiz;
          raiz = raiz->sim;
          free(aux);
        }
        else
          if(raiz->sim == NULL){
            aux = raiz;
            raiz = raiz->nao;
            free(aux);
          }

          else raiz->sim = substitui(raiz, raiz->sim);

  return raiz;
}


Arvore* substitui(Arvore* raiz, Arvore* antecessor){
  Arvore* aux;

  if(antecessor->nao == NULL){
    aux = antecessor;
    raiz->prioridade = antecessor->num;
    antecessor = antecessor->sim;
    free(aux);
  }
  else antecessor->nao = substitui(raiz, antecessor->nao);

  return antecessor;
}

int busca(Arvore *raiz, int n){
  if(raiz == NULL) return 0;

  if(raiz->prioridade  == n) return 1;
  else if(raiz->prioridade < n) busca(raiz->nao, n);
  else busca(raiz->sim,n);
}
*/