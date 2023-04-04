#include <stdio.h>

#define I 50
#define J 50
#define K 50
#define BLOCK_SIZE_I 50
#define BLOCK_SIZE_J 50
#define BLOCK_SIZE_K 50

void matmul(int a[][K], int b[][J], int c[][J], int Ni, int Nj, int Nk);

int main() {
    int a[I][K] = {[0 ... I-1][0 ... K-1] = 1};
    int b[K][J] = {[0 ... K-1][0 ... J-1] = 2};
    int c[I][J] = {{0}};
    matmul(a, b, c, I, J, K);
    printf("%d\n", c[0][0]);
    return 0;
}

void matmul(int a[][K], int b[][J], int c[][J], int Ni, int Nj, int Nk) {
    for (int it = 0; it < Ni; it += BLOCK_SIZE_I) {
        for (int jt = 0; jt < Nj; jt += BLOCK_SIZE_J) {
            for (int kt = 0; kt < Nk; kt += BLOCK_SIZE_K) {
                for (int i = 0; i < BLOCK_SIZE_I; i++) {
                    for (int j = 0; j < BLOCK_SIZE_J; j++) {
                        for (int k = 0; k <  BLOCK_SIZE_K; k++) {
                            c[i+it][j+jt] += a[i+it][k+kt] * b[k+kt][j+jt];
                        }
                    }
                }
            }
        }
    }
 }
