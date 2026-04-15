#include <stdio.h>

void mat_vec_mul(const float* restrict matrix, const float* restrict vector, float* result, int m, int n) {
    for (int i = 0; i < m; i++) {
        float sum = 0.0f;
        const float* row = &matrix[i * n];
        int j = 0;

        for (; j <= n - 4; j += 4) {
            sum += row[j]     * vector[j];
            sum += row[j + 1] * vector[j + 1];
            sum += row[j + 2] * vector[j + 2];
            sum += row[j + 3] * vector[j + 3];
        }

        for (; j < n; j++) {
            sum += row[j] * vector[j];
        }

        result[i] = sum;
    }
}




int main() {
    float A[6] = {2, 1, 0, 3};
    float v[3] = {4, 1};
    float res[3] = {};

    mat_vec_mul(A, v, res, 2, 2);

    printf("[%.1f, %.1f]", res[0], res[1]);
    return 0;
}
