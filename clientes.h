#include "arvore.h"
#include "destinos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void paginaInicial();
void clienteTipo1();

void paginaInicial(){
  int opcao = 0;
  printf("Bem vindo à Viagens ED1!\n\n");
  printf("Digite a opção desejada\n1 - Já sei para onde quero viajar\n2 - Não sei para onde quero viajar (SUGESTÕES)\n3 - Exibir lista geral de países e sítios turísticos\n4 - Ver meu cadastro\n5 - Listar países e sítios turísticos escolhidos sem  auxílio\n6 - Listar países e sítios turísticos escolhidos por  auxílio\n7 - Listar países e sítios turísticos não visitados\n 8 - Sair\n");
  scanf("%d", &opcao);
  getchar();
  system("clear");
  switch(opcao){
    case 1:
      clienteTipo1();
      break;
    case 2:
      //função cliente tipo 2 que chama arvore
      break;
    case 3:
      //chamar uma função que printa a lista principal 
      break;
    case 4:
      //chamr alguma função com o cadastro
      break;
    case 5:

      break;
    case 6:

      break;
    case 7:

      break;
    case 8:
      exit(1);
  }
}

void clienteTipo1(){
  char destino[50], country[30], sitioTuristico[30];
  int i, j, k, l;
  printf("\nDigite o local de destino desejado\n");
  printf("Modelo: pais, sitio turistico\n");
  scanf(" %[^\n]", destino);
  getchar();

  for(int j = 0; j < strlen(destino); j++){
    destino[j] = toupper(destino[j]);
  } 

  for(i = 0; i < strlen(destino); i++){
    if(destino[i] != ','){
      country[i] = destino[i];
    } else{ break; }
  }

  for(k = i + 1, l = 0; k < strlen(destino); k++, l++){
    sitioTuristico[l] = destino[k];
  }

  //teste
  printf("\ndestino: %s\n", destino);
  printf("pais: %s\n", country);
  printf("cidade: %s\n", sitioTuristico);

  //fazer a comparação 
}