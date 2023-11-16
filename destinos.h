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

void listarSemAuxilio(Pais *);
void listarComAuxilio(Pais *);
void listarNaoVisitados(Pais *);
void listarSoVisitados(Pais *);
void listarLista(Pais *);
Pais *inserirPaises(Pais *, char *);
Sitio *inserirCidade(Sitio *, char *);
void listasEspecificas(Pais *, char ); 
void paisMaisVisitado(Pais *pais);

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
  case '7':
    listarSoVisitados(pais);
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
      if (city->turista1 > 0) {
        if (cont == 0) {
          printf("País: %s\n", aux->nomePais);
          cont++;
        }
        printf("\t  %s\n", city->nomeSitio);
        if (city->prox == NULL)
          printf("\n");
      }

      city = city->prox;
    }

    aux = aux->prox;
  }
}

void listarComAuxilio(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont;
  aux = pais;

  while (aux != NULL) {
    cont = 0;
    city = aux->local;
    while (city != NULL) {
      if (city->turista2 > 0) {
        if (cont == 0) {
          printf("País: %s\n", aux->nomePais);
          cont++;
        }
        printf("\t  %s\n", city->nomeSitio);
        if (city->prox == NULL)
          printf("\n");
      }
      city = city->prox;
    }
    aux = aux->prox;
  }
}

void listarNaoVisitados(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont;
  aux = pais;

  while (aux != NULL) {
    cont = 0;
    city = aux->local;
    while (city != NULL) {
      if (city->turista1 == 0 && city->turista2 == 0) {
        if (cont == 0) {
          printf("País: %s\n", aux->nomePais);
          cont++;
        }
        printf("\t  %s\n", city->nomeSitio);
        if (city->prox == NULL)
          printf("\n");
      }
      city = city->prox;
    }
    printf("\n");
    aux = aux->prox;
  }
}

void listarSoVisitados(Pais *pais){
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont;
  aux = pais;
  while (aux != NULL) {
    cont = 0;
    city = aux->local;
    while (city != NULL) {
      if (city->turista1 > 0 || city->turista2 > 0) {
        if (cont == 0) {
          printf("País: %s\n", aux->nomePais);
          cont++;
        }
        printf("\t  %s\n", city->nomeSitio);
        if (city->prox == NULL)
          printf("\n");
      }
      city = city->prox;
    }
    printf("\n");
    aux = aux->prox;
  }
}

void paisMaisVisitado(Pais *pais){
  Pais *aux = pais;
  Pais *maior = pais;
  char nomesPaises[10][50] = {""};
  int cont = 0;

  while(aux != NULL){
    if(aux->quantTuristas > maior->quantTuristas){
      memset(nomesPaises, '\0', sizeof(nomesPaises));
      cont = 0;
      strcpy(nomesPaises[cont],aux->nomePais);
      maior = aux;
      cont++;
    }
    else if ((aux->quantTuristas > 0) && (aux->quantTuristas == maior->quantTuristas)){
      if(cont != 0){
        strcpy(nomesPaises[cont],aux->nomePais);
      }
      else{
        strcpy(nomesPaises[cont],aux->nomePais);
        maior = aux;
      }
      cont++;
    }
    aux = aux->prox;
  }

  printf("País(es) mais visitado(s):\n");
  for(int i = 0; i < 10; i++){
    if(strcmp(nomesPaises[i], "") != 0)
        printf("%s\n", nomesPaises[i]);
  }
}
