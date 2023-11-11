#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sitioturistico {
  struct sitioturistico *next;
  char nomeSitio[50];
  int turista1, turista2;
} Sitio;

typedef struct pais {
  struct pais *prox;
  Sitio *local;
  char nomePais[50];
  int prioridade, quantTuristas = 0;
} Pais;

Pais *inserirLista(Pais *paises, char *local);
void listasEspecificas(Pais *paises, int op);

/*void listarPorAuxilio(Pais *paises);
void listarSemAuxilio(Pais *paises);*/

Pais *inserirLista(Pais *paises, char *local) {
  Pais *novo;
  novo = (Pais *)malloc(sizeof(Pais));
  if (novo == NULL) {
    exit(1);
  }
  strcpy(novo->nomePais, local);

  // inseririndo em logica de pilha
  if (paises == NULL) {
    novo->prox = NULL;
  } else {
    novo->prox = paises;
  }
  paises = novo;

  return (paises);
}

void listasEspecificas(Pais *paises, int op) {
  Sitio *aux = paises->local;
  while (aux != NULL) {
    switch (op) {
    case 5: // sem auxilio
      if ((aux->turista1) > 0) {
        printf("%s", paises->nomePais);
      }
      break;
    case 6: // com auxilio
      if ((aux->turista2) > 0) {
        printf("%s", paises->nomePais);
      }
      break;
    case 7: // nao visitado
      if ((aux->turista1 == 0) && (aux->turista2 == 0)) {
        printf("%s", paises->nomePais);
      }
      break;
    }
    aux = aux->next;
  }
}

/*void listarPorAuxilio(Pais *paises){
  Sitio *ajudado = paises -> local;
  while((ajudado) != NULL){
    if((ajudado -> turista2) > 0){
      printf("%s", paises -> nomePais);
    }
    ajudado = ajudado -> next;
  }
}

void listarSemAuxilio(Pais *paises){
  Sitio *escolhido = paises -> local;
    while((escolhido) != NULL){
      if((escolhido -> turista1) > 0){
        printf("%s", paises -> nomePais);
      }
      escolhido = escolhido -> next;
    }
}*/