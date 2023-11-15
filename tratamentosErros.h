#include <stdio.h>

int erroResposta(char resp) {
  // Verifica se a resposta foi N ou S
  if ((resp == 's' || resp == 'S') || (resp == 'n' || resp == 'N')) {

    return 1;
  }
  printf("Erro Inválido\n");
  return 0;
}