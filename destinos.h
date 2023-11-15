#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sitioturistico {
  struct sitioturistico *prox;
  char nomeSitio[50];
  int turista1, turista2;
} Sitio;

typedef struct pais {
  struct pais *prox;
  Sitio *local;
  char nomePais[50];
  int prioridade, quantTuristas;
} Pais;

void listarSemAuxilio(Pais *pais);
void listarComAuxilio(Pais *pais);
void listarNaoVisitados(Pais *pais);
void listarLista(Pais *pais);
Pais *inserirPaises(Pais *pais, char *local);
Sitio *inserirCidade(Sitio *cidade, char *nome);
void listasEspecificas(Pais *pais, char op); // so dps de turistas

/////////////////////////////////////////////////////////////////////////////////////////////

Pais *inserirPaises(Pais *pais, char *local) {

  Pais *novo;

  novo = (Pais *)malloc(sizeof(Pais));

  if (novo == NULL) {
    exit(1);
  }

  strcpy(novo->nomePais, local);

  if (pais == NULL) {
    novo->prox = NULL;
  } else {
    novo->prox = pais;
  }
  pais = novo;

  return (pais);
}

/////////////////////////////////////////////////////////////////////////////////////////////

Sitio *inserirCidade(Sitio *cidade, char *nome) {

  Sitio *novo;

  novo = (Sitio *)malloc(sizeof(Sitio));

  if (novo == NULL) {
    exit(1);
  }

  strcpy(novo->nomeSitio, nome);

  if (cidade == NULL) {
    novo->prox = NULL;
  } else {
    novo->prox = cidade;
  }
  cidade = novo;

  return (cidade);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void listarLista(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;

  aux = pais;

  while (aux != NULL) {
    printf("País: %s\n", aux->nomePais);
    city = aux->local;
    while (city != NULL) {
      printf("\t  %s\n", city->nomeSitio);
      city = city->prox;
    }
    printf("\n");
    aux = aux->prox;
  }
}

void listasEspecificas(Pais *pais, char op) {
  

  switch (op) {
  case '4':
      listarSemAuxilio(pais);
      break;
  case '5':
      listarComAuxilio(pais);
    break;
  case '6':
    listarNaoVisitados(pais);
    break;
    }
  }


void listarSemAuxilio(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont;
  aux = pais;

  while (aux != NULL) {
    cont = 0;
    city = aux->local;
    
    while (city != NULL) {
      if (city->turista1 > 0){
        if(cont == 0){ printf("País: %s\n", aux->nomePais); cont++;}
        printf("\t  %s\n", city->nomeSitio);
        if(city->prox == NULL) printf("\n");
      }
     
      city = city->prox;
      
    }

    aux = aux->prox;
    
  }
}

void listarComAuxilio(Pais *pais){
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont;
  aux = pais;
  
  while (aux != NULL) {
    cont = 0;
    city = aux->local;
    while (city != NULL) {
      if (city->turista2 > 0){
        if(cont == 0){ printf("País: %s\n", aux->nomePais); cont++;}
        printf("\t  %s\n", city->nomeSitio);
        if(city->prox == NULL) printf("\n");
      }
      city = city->prox;
     
    }
    aux = aux->prox;
    
  }
}

void listarNaoVisitados(Pais *pais){
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont = 0;
  aux = pais;

  while (aux != NULL) {
    printf("País: %s\n", aux->nomePais);
    city = aux->local;
    while (city != NULL) {
      if (city->turista1 == 0 && city->turista2 == 0){
        printf("\t  %s\n", city->nomeSitio);
       if(city->prox == NULL) printf("\n");
      }
      city = city->prox;
    }
    printf("\n");
    aux = aux->prox;
  }
}