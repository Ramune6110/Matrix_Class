#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix {
    public:
        int SIZE;
    public:
        // コンストラクタ
        Matrix();
        // デストラクタ
        virtual ~Matrix();
        // 行列の和
        void matrix_add(float *A, float *B, float *solution);
        // 行列の差
        void matrix_sub(float *A, float *B, float *solution);
        // 行列の積
        void matrix_mul(float *A, float *B, float *solution);
        // 転置行列
        void matrix_tran(float *A, float *solution);
        // 行列の定数倍
        void matrix_mul_const(float *A, float *solution, float c);
        // 逆行列(掃き出し法)
        void matrix_inv(float *mat, float *solution);
        // 行列の表示   
        void print_matrix(float *solution);
};

#endif // _MATRIX_H_
