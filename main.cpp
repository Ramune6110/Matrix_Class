#include "matrix.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    Matrix m;

    // 行列定義
    float *A        = (float *)malloc(sizeof(float) * m.SIZE * m.SIZE);
    float *B        = (float *)malloc(sizeof(float) * m.SIZE * m.SIZE);
    float *solution = (float *)malloc(sizeof(float) * m.SIZE * m.SIZE);
    // 動的メモリ割り当て確認
    if (A == NULL || B == NULL || solution == NULL) {
        cout << "Memory Error" << endl;
        exit(1);
    }
    // 行列A
    printf("行列Aの選定\n");
    for (int i = 0; i < m.SIZE; i++) {
        for (int j = 0; j < m.SIZE; j++) {
            printf("%d, %d要素目", i + 1, j + 1);
            cin >> A[i * m.SIZE + j];
        }
    }
    printf("\n");
    // 行列B
    printf("行列Bの選定\n");
    for (int i = 0; i < m.SIZE; i++) {
        for (int j = 0; j < m.SIZE; j++) {
            printf("%d, %d要素目", i + 1, j + 1);
            cin >> B[i * m.SIZE + j];
        }
    }
    printf("\n");

    // 行列の和
    m.matrix_add(A, B, solution);
    m.print_matrix(solution);
    // 行列の差
    m.matrix_sub(A, B, solution);
    m.print_matrix(solution);
    // 行列の積
    m.matrix_mul(A, B, solution);
    m.print_matrix(solution);
    // 行列の転置
    m.matrix_tran(A, solution);
    m.print_matrix(solution);
    // 行列の定数倍
    m.matrix_mul_const(A, solution, 5);
    m.print_matrix(solution);
    // 逆行列
    m.matrix_inv(A, solution);
    m.print_matrix(solution);

    // メモリーの開放
    free(A);
    free(B);
    free(solution);

    return 0;
}
