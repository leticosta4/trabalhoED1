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
  int prioridade, quantTuristas = 0;
} Pais;

Pais *inserirPaises(Pais *pais, char *local);
Sitio *inserirCidade(Sitio *cidade, char *nome);
void listasEspecificas(Pais *pais, int op);

Pais *inserirPaises(Pais *pais, char *local) { 
  Pais *novo;
  novo = (Pais*)malloc(sizeof(Pais));
  if (novo == NULL) { exit(1); }
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
  novo = (Sitio*)malloc(sizeof(Sitio));
  if (novo == NULL) { exit(1); }
  strcpy(novo->nomeSitio, nome);

  if (cidade == NULL) {
    novo->prox = NULL;
  } else {
    novo->prox = cidade;
  }
  cidade = novo;

  return (cidade);
}

void listasEspecificas(Pais *pais, int op) {
  Sitio *aux = pais->local;
  while (aux != NULL) {
    switch (op) {
    case 5: // sem auxilio
      if ((aux->turista1) > 0) {
        printf("%s\n", pais->nomePais);
      }
      break;
    case 6: // com auxilio
      if ((aux->turista2) > 0) {
        printf("%s\n", pais->nomePais);
      }
      break;
    case 7: // nao visitado
      if ((aux->turista1 == 0) && (aux->turista2 == 0)) {
        printf("%s\n", pais->nomePais);
      }
      break;
    }
    aux = aux->prox;
  }
}
