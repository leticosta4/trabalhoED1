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
void listasEspecificas(Pais *, char);
int paisMaisVisitado(Pais *);
void cidadeMaisVisitada(Pais *);


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
  int cont, fim = 0;
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
        fim++;
        if (city->prox == NULL)
          printf("\n");
      }

      city = city->prox;
    }

    aux = aux->prox;
  }
  if (fim == 0) {
    printf("┌─────────────────────────────────┐\n");
    printf("│Nenhum pais acessado SEM auxilio!│\n");
    printf("└─────────────────────────────────┘\n");
    printf("\n");
  }
}

void listarComAuxilio(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont, fim = 0;
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
        fim++;
        if (city->prox == NULL)
          printf("\n");
      }
      city = city->prox;
    }
    aux = aux->prox;
  }
  if (fim == 0) {
    printf("┌─────────────────────────────────┐\n");
    printf("│Nenhum pais acessado COM auxilio!│\n");
    printf("└─────────────────────────────────┘\n");
    printf("\n");
  }
}

void listarNaoVisitados(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont, fim = 0;
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
        fim++;
        if (city->prox == NULL)
          printf("\n");
      }
      city = city->prox;
    }
    // printf("\n");
    aux = aux->prox;
  }
  if (fim == 0) {
    printf("┌────────────────────────────────┐\n");
    printf("│Todos os paises foram visitados!│\n");
    printf("└────────────────────────────────┘\n");
    printf("\n");
  }
}

void listarSoVisitados(Pais *pais) {
  Pais *aux = NULL;
  Sitio *city = NULL;
  int cont, fim = 0;
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
        fim++;
        if (city->prox == NULL)
          printf("\n");
      }
      city = city->prox;
    }
    // printf("\n");
    aux = aux->prox;
  }
  if (fim == 0) {
    printf("┌─────────────────────┐\n");
    printf("│Sem paises visitados!│\n");
    printf("└─────────────────────┘\n");
    printf("\n");
  }
}

void cidadeMaisVisitada(Pais *pais) {
  Pais *country = pais;
  Sitio *city = NULL, *maiorCidade = NULL;
  char nomesCidades[17][50] = {""};
  int cont = 0;
  while(country != NULL){
    city = country->local;
    if (maiorCidade == NULL) {
      maiorCidade = city; // p n sobrescrever
    }
     while (city != NULL) {
       if((city->turista1 + city->turista2) >
           (maiorCidade->turista1 + maiorCidade->turista2)) {
         memset(nomesCidades, '\0', sizeof(char));
         printf("%c\n", nomesCidades[0][2]);
         cont = 0;
         strcpy(nomesCidades[cont], city->nomeSitio);
         maiorCidade = city;
         cont++;
       } else if (((city->turista1 + city->turista2) > 0) &&
                  (city->turista1 + city->turista2) ==
                      (maiorCidade->turista1 +
                       maiorCidade->turista2)) { // caso seja igual
         if (cont != 0) {
           strcpy(nomesCidades[cont], city->nomeSitio);
         } else {
           strcpy(nomesCidades[cont], city->nomeSitio);
           maiorCidade = city;
         }
         cont++;
       }
       city = city->prox;
     }
    country = country -> prox;
  }
  //não tem o if generico da condicional pq ela depende do pais p ser chamada
  printf("\nEstado(s)/Cidade(s) mais visitado/a(s):\n"); // ainda tem que tirar os  espaços vazios que ficam dos outros países
  for (int i = 0; i < 17; i++) {
    if (strcmp(nomesCidades[i], "") != 0)
      printf("%s\n", nomesCidades[i]);
    }
    printf("\n"); 
}

int paisMaisVisitado(Pais *pais) {
  Pais *aux = pais, *maiorPais = pais;
  Sitio *city = NULL;//, *maiorCidade = NULL;
  char nomesPaises[10][50] = {""};//, *nomesCidades[17][50];= {""}; // caso tenha mais de um
  int cont = 0;//, cont2 = 0;

  while (aux != NULL) {
    if (aux->quantTuristas > maiorPais->quantTuristas) {
      memset(nomesPaises, '\0', sizeof(nomesPaises));
      cont = 0;
      strcpy(nomesPaises[cont], aux->nomePais);
      maiorPais = aux;
      cont++;
    } else if ((aux->quantTuristas > 0) &&
               (aux->quantTuristas == maiorPais->quantTuristas)) {
      if (cont != 0) {
        strcpy(nomesPaises[cont], aux->nomePais);
      } else {
        strcpy(nomesPaises[cont], aux->nomePais);
        maiorPais = aux;
      }
      cont++;
    }
    aux = aux->prox;
  }
  if (strcmp(nomesPaises[0], "") != 0) {
    printf(
        "País(es) mais visitado(s):\n"); // ainda tem que tirar os espaços vazios que ficam dos outros países
    for (int i = 0; i < 10; i++) {
      if (strcmp(nomesPaises[i], "") != 0)
        printf("%s\n", nomesPaises[i]);
    }
    return 1;
  } else {
    printf("┌───────────────────────┐\n");
    printf("│Nenhum país cadastrado!│\n");
    printf("└───────────────────────┘\n");
    printf("\n");
    return 0;
  }
}
