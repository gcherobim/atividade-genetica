#define repeticoes 10
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

  clock_t tempo_inicial, tempo_final = 0;

  for (int i = 0; i < repeticoes; i++) {
    FILE *arquivo_genoma, *arquivo_pos_genes, *arquivo_fragmentos;
    FILE *arquivo_pos_fragmentos = NULL;
    FILE *arquivo_saida = NULL;

    arquivo_genoma = fopen("Arquivos/genoma_grande.txt", "r");
    arquivo_pos_genes = fopen("Arquivos/pos_genes_grande.csv", "r");
    arquivo_fragmentos = fopen("Arquivos/fragmentos_grande.txt", "r");

    arquivo_pos_fragmentos = fopen("Arquivos/pos_fragmentos.txt", "w");
    arquivo_saida = fopen("Arquivos/atividade_genetica.txt", "w");

    tempo_inicial = clock();
    ContagemLeituras(arquivo_genoma, arquivo_pos_genes, arquivo_fragmentos, arquivo_pos_fragmentos, 10000, 30000, arquivo_saida);
    tempo_final += clock() - tempo_inicial;

    fclose(arquivo_pos_fragmentos);
    fclose(arquivo_saida);
  }

  printf("Tempo médio decorrido: %.4f\n", (double) tempo_final / repeticoes / CLOCKS_PER_SEC);

  return 0;
}
