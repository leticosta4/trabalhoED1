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

void listarLista(Pais *paises);
Pais *inserirPaises(Pais *paises, char *local);
Sitio *inserirCidade(Sitio *cidade, char *nome);
//void listasEspecificas(Pais *pais, int op); //so dps de turistas

/////////////////////////////////////////////////////////////////////////////////////////////

Pais *inserirPaises(Pais *paises, char *local) {

  Pais *novo;

  novo = (Pais *)malloc(sizeof(Pais));

  if (novo == NULL) {
    exit(1);
  }

  strcpy(novo->nomePais, local);

  if (paises == NULL) {
    novo->prox = NULL;
  } else {
    novo->prox = paises;
  }
  paises = novo;

  return (paises);
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

void listarLista(Pais *paises) { //só p teste de debug
  Pais *aux = NULL;
  Sitio *city = NULL;

  aux = paises;

  while (aux != NULL) {
    printf("%s\n", aux->nomePais);
    city = aux->local;
    while (city != NULL) {
      printf("%s\n", city->nomeSitio);
      city = city->prox;
    }
    aux = aux->prox;
  }
}

/*void listasEspecificas(Pais *paises, int op) {
  Sitio *aux = paises->local;
  while (aux != NULL) {
    switch (op) {
    case 5: // sem auxilio
      if ((aux->turista1) > 0) {
        printf("%s\n", paises->nomePais);
      }
      break;
    case 6: // com auxilio
      if ((aux->turista2) > 0) {
        printf("%s\n", paises->nomePais);
      }
      break;
    case 7: // nao visitado
      if ((aux->turista1 == 0) && (aux->turista2 == 0)) {
        printf("%s\n", paises->nomePais);
      }
      break;
    }
    aux = aux->prox;
  }
}*/
