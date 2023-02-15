#include "funcoes.h"

// função auxiliar de OrdenaNumeros para encontrar o maior elemento em A[i][0]
int Maior(int v[], int n) {

  int maior = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] > maior) {
      maior = v[i];
    }
  }

  return maior;

}

void OrdenaDigitos(int A[][2], int n, int posicao) {

  // vetor que para armazenar as posições de cada elemento, de acordo com o
  // dígito significativo sendo considerado
  int B[10];
  for (int i = 0; i < 10; i++) {
    B[i] = 0;
  }

  // para cada elemento em A[i][0], incrementa a contagem em B para o dígito
  // significativo
  for (int i = 0; i <= n - 1; i++) {
    int digito = A[i][0] / posicao;
    digito = digito % 10;
    B[digito] = B[digito] + 1;
  }

  // encontra a última posição do dígito significativo considerado
  for (int i = 1; i <= 9; i++) {
    B[i] = B[i] + B[i-1];
  }

  int C[n][2];

  // coloca os elementos de A em suas posições ordenadas, considerando o dígito
  // utilizado
  for (int i = n - 1; i >= 0; i--)
  {
    int digito = A[i][0] / posicao;
    digito = digito % 10;
    B[digito] = B[digito] - 1;
    C[B[digito]][0] = A[i][0];
    C[B[digito]][1] = A[i][1];
  }

  // atualiza A para a próxima iteração
  for (int i = 0; i <= n - 1; i++) {
    A[i][0] = C[i][0];
    A[i][1] = C[i][1];
  }

}

void OrdenaNumeros(int A[][2], int n) {

  int v[n];

  for (int i = 0; i < n; i++) {
    v[i] = A[i][0];
  }

  int maior = Maior(v, n);
  int posicao = 1;

  // faz a chamada de OrdenaDigitos enquanto não acaba a quantidade de dígitos
  // significativos
  while ((maior / posicao) > 0) {
    OrdenaDigitos(A, n, posicao);
    posicao = posicao * 10;
  }

}

void ContagemIntersecoes(FILE *arquivo_A, FILE *arquivo_B, int nA, int nB, FILE *arquivo_saida) {

  int tam1 = 10000;
  char buffer1[tam1], buffer2[tam1];
  char *line, *record;

  int A[nA][2], B[nB][2];
  int contagens[nA];
  for (int i = 0; i < nA; i++) {
    contagens[i] = 0;
  }

  for (int i = 0; i <= nA - 1; i++) {
    line = fgets(buffer1, sizeof(buffer1), arquivo_A);
    record = strtok(line, ",");

    // separa os elementos de antes e depois da vírgula
    int inicio = atoi(record);
    record = strtok(NULL, ",");
    int fim = atoi(record);

    A[i][0] = inicio;
    A[i][1] = fim;
  }


  for (int i = 0; i <= nB - 1; i++) {
    line = fgets(buffer2, sizeof(buffer2), arquivo_B);
    int inicio, fim;

    // preenche as linhas que não foi possível ler o arquivo com o limite para
    // números inteiros, de forma que não interfira a contagem de interseções
    if (line == NULL) {
      inicio = INT_MAX;
      fim = INT_MAX;
    }
    else {
      record = strtok(line, ",");

      inicio = atoi(record);
      record = strtok(NULL, ",");
      fim = atoi(record);
    }

    B[i][0] = inicio;
    B[i][1] = fim;

  }


  OrdenaNumeros(A, nA);
  OrdenaNumeros(B, nB);
  
  /*
  clock_t inicio = clock();
  OrdenaNumeros(B, nB);
  clock_t fim = clock() - inicio;
  printf("Tempo decorrido: %f\n", (double) fim / CLOCKS_PER_SEC);
  */

  // faz a contagem das interseções
  int primeiro_iB = 0;
  for (int iA = 0; iA <= nA - 1; iA++) {
    for (int iB = primeiro_iB; iB <= nB - 1; iB++) {
      if (A[iA][1] < B[iB][0] || A[iA][0] > B[iB][1]) {
        if (contagens[iA] == 0) {
          primeiro_iB = iB;
        }
      }
      else {
        contagens[iA] = contagens[iA] + 1;
      }
    }
  }

  // imprime a contagem de interseções no arquivo de saída
  for (int i = 0; i < nA; i++) {
    fprintf(arquivo_saida, "%d\n", contagens[i]);
  }

}

void CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, FILE *arquivo_saida) {
  int tam = 1000010;
  char buffer_texto[tam];
  char *texto;

  texto = fgets(buffer_texto, sizeof(buffer_texto), arquivo_texto);

  while (!feof(arquivo_trechos)) {
    int tam2 = 1000;
    char buffer_trecho[tam2];
    char *trecho;
    trecho = fgets(buffer_trecho, sizeof(buffer_trecho), arquivo_trechos);

    int i = 0;
    while (texto[i] != '\0') {
      int j = 0;

      // confere se o texto é nulo para encerrar o laço
      if (trecho == NULL) {
        break;
      }

      while ((trecho[j] != '\0') && (texto[i + j] == trecho[j])) {
        j++;
      }
      if (trecho[j] == 10) {
        fprintf(arquivo_saida, "%d, %d\n", i, i + j - 1);
        break;
      }
      i++;
    }
  }

}

void ContagemLeituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes,  FILE *arquivo_fragmentos, FILE *arquivo_pos_fragmentos, int n_genes, int n_fragmentos, FILE *arquivo_saida) {

  CtrlF(arquivo_genoma, arquivo_fragmentos, arquivo_pos_fragmentos);

  fclose(arquivo_pos_fragmentos);

  arquivo_pos_fragmentos = fopen("Arquivos/pos_fragmentos.txt", "r");

  ContagemIntersecoes(arquivo_pos_genes, arquivo_pos_fragmentos, n_genes, n_fragmentos, arquivo_saida);

}
