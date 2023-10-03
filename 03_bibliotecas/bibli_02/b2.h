#ifndef _B2_H
#define _B2_H
#define MAX 100

void SomaMatriz(int linha1, int coluna1, int mat1[MAX][MAX], int linha2, int coluna2, int mat2[MAX][MAX]);
void SubtrairMatrizes(int linha1, int coluna1, int mat1[MAX][MAX], int linha2, int coluna2, int mat2[MAX][MAX]);
void MultiplicarMatrizes(int linha1, int coluna1, int mat1[MAX][MAX], int linha2, int coluna2, int mat2[MAX][MAX]);
void MultiplicarPorEscalar(int linha, int coluna, int mat[MAX][MAX], int escalar);
void ViraSuaTransposta(int linha, int coluna, int mat[MAX][MAX]);
void ImprimeMatriz(int linha, int coluna, int mat1[MAX][MAX]);

#endif