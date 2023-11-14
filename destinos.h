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
  int prioridade;
} Pais;

void listarLista(Pais *pais);
Pais *inserirPaises(Pais *pais, char *local);
Sitio *inserirCidade(Sitio *cidade, char *nome);
//void listasEspecificas(Pais *pais, int op); //so dps de turistas

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

/*void listasEspecificas(Pais *pais, int op) {
  Sitio *aux = pais->local;
  while (aux != NULL) {
    switch (op) {
    case 4: // sem auxilio
      if ((aux->turista1) > 0) {
        printf("%s\n", pais->nomePais);
      }
      break;
    case 5: // com auxilio
      if ((aux->turista2) > 0) {
        printf("%s\n", pais->nomePais);
      }
      break;
    case 6: // nao visitado
      if ((aux->turista1 == 0) && (aux->turista2 == 0)) {
        printf("%s\n", pais->nomePais);
      }
      break;
    }
    aux = aux->prox;
  }
}*/