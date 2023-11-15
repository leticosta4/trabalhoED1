#include "arvore.h"
#include "destinos.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clienteTipo1(Pais *pais, char*, int);
//void clienteTipo2(Pais *, char *);
void compIncrementa(char *country, char *city, Pais *pais, int);

void clienteTipo1(Pais *pais, char *localDestino, int tipoCLiente) {
  char destino[50] = "", country[30] = "", sitioTuristico[30] = "";
  int i, j, k, l = 0;

  if(tipoCLiente == 1){
  printf("\nDigite o local de destino desejado\n");
  printf("Modelo: pais, sitio turistico\n");
  scanf(" %[^\n]", destino);
  getchar();
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
     // printf("Cheguei aqui\n %c", destino[k]);
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

    while ((auxCidade->prox != NULL) &&
           (strcmp(city, auxCidade->nomeSitio) != 0)) {
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

/*void clienteTipo2(char *localEscolhido, Pais *listaPais) {
  Pais *aux = NULL;
  Sitio *city = NULL;

  aux = listaPais;

  while (aux != NULL) {
    if ( aux->nomePais)
    city = aux->local;
    while (city != NULL) {
      printf("\t  %s\n", city->nomeSitio);
      city = city->prox;
    }
    printf("\n");
    aux = aux->prox;
}*/

/*void ClienteTipo2(Pais *pais, char *destino) {
  char country[30] = "", sitioTuristico[30] = "";
  int i, j, k, l = 0, tipoCliente = 2;


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
      printf("Cheguei aqui: %c\n", destino[k]);
      sitioTuristico[l] = destino[k];
      l++;
    }
  }

   //compIncrementa(country, sitioTuristico, pais);
} */