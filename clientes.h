#include "arvore.h"
#include "destinos.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clienteTipo1();
Arvore *clienteTipo2(Arvore *raiz);

void clienteTipo1() {
  char destino[50], country[30], sitioTuristico[30];
  int i, j, k, l;
  printf("\nDigite o local de destino desejado\n");
  printf("Modelo: pais, sitio turistico\n");
  scanf(" %[^\n]", destino);
  getchar();

  for (int j = 0; j < strlen(destino); j++) {
    destino[j] = toupper(destino[j]);
  }

  for (i = 0; i < strlen(destino); i++) {
    if (destino[i] != ',') {
      country[i] = destino[i];
    } else {
      break;
    }
  }

  for (k = i + 1, l = 0; k < strlen(destino); k++, l++) {
    sitioTuristico[l] = destino[k];
  }

  // teste
  printf("\nDestino: %s\n", destino);
  printf("Pais: %s\n", country);
  printf("Xidade: %s\n", sitioTuristico);

  // fazer a comparação
}

Arvore *clienteTipo2(Arvore *raiz) {}
