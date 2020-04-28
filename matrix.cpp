#include "matrix.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// コンストラクタ
Matrix::Matrix() 
{
    cout << "行列のサイズを指定してください" << endl;
    cin >> SIZE;
}
// デストラクタ
Matrix::~Matrix()
{
    cout << "Matrixオブジェクトの破棄" << endl;
}
// 行列の和
void Matrix::matrix_add(float *A, float *B, float *solution) 
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[i * SIZE + j] = A[i * SIZE + j] + B[i * SIZE + j];
        }
    }
}
// 行列の差
void Matrix::matrix_sub(float *A, float *B, float *solution)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[i * SIZE + j] = A[i * SIZE + j] - B[i * SIZE + j];
        }
    }
}
// 行列の積
void Matrix::matrix_mul(float *A, float *B, float *solution)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[i * SIZE + j] = 0.0;
            for (int k = 0; k < SIZE; k++) {
                solution[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
            }
        }
    }
}
// 転置行列
void Matrix::matrix_tran(float *A, float *solution)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[j * SIZE + i] = A[i * SIZE + j];
        }
    }
}
// 行列の定数倍
void Matrix::matrix_mul_const(float *A, float *solution, float c) 
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[i * SIZE + j] = c * A[i * SIZE + j];
        }
    }
}
// 逆行列(掃き出し法)
void Matrix::matrix_inv(float *mat, float *solution)
{
    float *temp = (float *)malloc(sizeof(float) * SIZE * SIZE * 2);
    // 動的メモリ割り当て確認
    if (temp == NULL) {
        cout << "Memory Error" << endl;
        exit(1);
    }
    // 拡張マトリックス生成
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp[i * (2 * SIZE) + j] = mat[i * SIZE + j];
        }
        for (int j = SIZE; j < 2 * SIZE; j++) {
            if (j - SIZE == i) {
                temp[i * (2 * SIZE) + j] = 1.0;
            } else {
                temp[i * (2 * SIZE) + j] = 0.0;
            }
        }
    }
    // 上から下にかけて行基本変形を行う
    for (int i = 0; i < SIZE; i++) {
        float pivot = temp[i * (2 * SIZE) + i];
        int pivot_index = i;
        float pivot_temp;
        // 一列目から一番要素の大きいものを探して、行の入れ替えを行う
        for (int j = i; j < SIZE; j++) {
            if (temp[j * (2 * SIZE) + i] > pivot) {
                pivot       = temp[j * (2 * SIZE) + i];
                pivot_index = j;
            }
        }
        // 各列の要素と比較して、自分よりも大きいものがあったら、要素の入れ替えを行う
        if (pivot_index != i) {
            for (int j = 0; j < 2 * SIZE; j++) {
                pivot_temp                         = temp[pivot_index * (2 * SIZE) + j];
                temp[pivot_index * (2 * SIZE) + j] = temp[i * (2 * SIZE) + j];
                temp[i * (2 * SIZE) + j]           = pivot_temp;
            }
        }
        // 比較対象とした要素で、入れ替えた行の各要素を割る
        for (int j = 0; j < 2 * SIZE; j++) {
            temp[i * (2 * SIZE) + j] /= pivot;
        }
        // 比較対象とした要素を入れ替えた行の各要素にかけて引く
        for (int j = i + 1; j < SIZE; j++) {
            float temp2 = temp[j * (2 * SIZE) + i];

            for (int k = 0; k < 2 * SIZE; k++) {
                temp[j * (2 * SIZE) + k] -= temp[i * (2 * SIZE) + k] * temp2;
            }
        }
    }
    // 下から上へ行基本変形
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            float pivot = temp[(SIZE - 1 - j) * (2 * SIZE) + (SIZE - 1 - i)];
            for (int k = 0; k < 2 * SIZE; k++) {
                temp[(SIZE - 1 - j) * (2 * SIZE) + k] -= temp[(SIZE - 1 - i) * (2 * SIZE) + k] * pivot;
            }
        }
    }
    // 最後に結果をコピー
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[i * SIZE + j] = temp[i * (2 * SIZE) + (j + SIZE)];
        }
    }
    // tempを開放
    free(temp);
}
// 行列の表示   
void Matrix::print_matrix(float *solution)
{
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
          printf("%5.8e\t", solution[i * SIZE + j]);
      }
      printf("\n");
  }
  printf("\n");
}
