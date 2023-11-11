#include "arvore.h"
#include "clientes.h"
//#include "destinos.h"
//tirando o #include "destinos.h" pq o clientes.h já traz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerArquivo(FILE *arquivo, int qtd, Arvore **viagem);
void lerArquivoLista(FILE *arquivo, int qtd, Pais **paises);

/*O sistema da agênciadeverá:•Apresentar os menus de atendimento adequados;•Listar todos os países que foram visitados por clientes decididos;•Listar todos os paísese sítiosturísticosque foram visitados para clientes que usaram o sistema de auxílio;•Lista de países visitados em geral;•Lista de países não visitados;•Informar o paíse o sítiomais visitado pelos dois tipos de clientes*/

int main(void) {
  FILE *arquivo = NULL;
  Arvore *viagem = NULL;
  int qtd = 0;

  lerArquivo(arquivo, qtd, &viagem);
  //chamar função da pagina inicial
  emOrdem(viagem);
  return 0;
}

void lerArquivo(FILE *arquivo, int qtd, Arvore **viagem) {
  char local[50];
  int prioridade = 0;

  arquivo = fopen("TextoDeLet.txt", "r+");
  if (arquivo == NULL) {
    printf("Erro, arquivo não aberto");
    return;
  }

  for (int i = 0; i < 16; i++) {

    fscanf(arquivo, "%d,%[^\n]", &prioridade, local);
    (*viagem) = inserir(*viagem, prioridade, local);
  }

  fclose(arquivo);
}

void lerArquivoLista(FILE *arquivo, int qtd, Pais **paises){
  char local[50];
  int prioridade = 0;

  arquivo = fopen("Paises.txt", "r+");
  if (arquivo == NULL) {
    printf("Erro, arquivo não aberto");
    return;
  }
  for (int i = 0; i < 10; i++) {
    fscanf(arquivo, " %[^\n]", local);
    (paises) = inserirLista(*paises, local);
  }
  fclose(arquivo);
}
