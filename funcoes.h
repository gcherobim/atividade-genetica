#define repeticoes 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

int Maior(int v[], int n);
void OrdenaDigitos(int A[][2], int n, int posicao);
void OrdenaNumeros(int A[][2], int n);
void ContagemIntersecoes(FILE *arquivo_A, FILE *arquivo_B, int nA, int nB, FILE *arquivo_saida);
void CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, FILE *arquivo_saida);
void ContagemLeituras(FILE *arquivo_genoma, FILE *arquivo_pos_genes,  FILE *arquivo_fragmentos, FILE *arquivo_pos_fragmentos, int n_genes, int n_fragmentos, FILE *arquivo_saida);
