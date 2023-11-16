#include "arvore.h"
#include "destinos.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
void cliente(Pais *, char*, int);

void compIncrementa(char *, char *, Pais *, int);

void addCliente(Pais *pais, char *localDestino, int tipoCLiente) {
  char destino[50] = "", country[30] = "", sitioTuristico[30] = "";
  int i, j, k, l = 0;

  if(tipoCLiente == 1){
  opcao1Menu();
  scanf(" %[^\n]", destino);
  //getchar();
  }
  else
    strcpy(destino, localDestino);
  
  for (int j = 0; j < strlen(destino); j++) {
    destino[j] = toupper(destino[j]);
  }

  for (i = 0; i < strlen(destino); i++) {
    if (destino[i] == ',') {
      break;
    }
    country[i] = destino[i];
  }

  for (k = i + 1; k < strlen(destino); k++) {
    if (destino[k] != ' ' || destino[k - 1] != ',') {
      sitioTuristico[l] = destino[k];
      l++;
    }
  }

  compIncrementa(country, sitioTuristico, pais, tipoCLiente); // ver o negocio aqui em pais
}

void compIncrementa(char *country, char *city, Pais *pais, int tipoCliente) {
  Pais *auxPais = pais;
  Sitio *auxCidade = NULL;
  while ((auxPais->prox != NULL) && (strcmp(country, auxPais->nomePais) != 0)) {
    auxPais = auxPais->prox;
  }

  if (strcmp(country, auxPais->nomePais) == 0) { // achou o pais igual
    
    (auxPais->quantTuristas)++;
    auxCidade = auxPais->local;

    
    while ((auxCidade->prox != NULL) && (strcmp(city, auxCidade->nomeSitio) != 0)) {
      auxCidade = auxCidade->prox;
    }

    if (strcmp(city, auxCidade->nomeSitio) == 0) {
      if(tipoCliente == 1)
        (auxCidade->turista1)++;
      else 
        (auxCidade->turista2)++;
    }
  }
}