/*  Cameron
 *  Toy
 *  cjtoy
 */

#ifndef A1_HPP
#define A1_HPP
#include <vector>


void filter_2d(long long n, long long m, const std::vector<float>& K, std::vector<float>& A) {
    std::vector<float> newA = A;
    #pragma omp parallel default(none) shared(newA, A, K, n, m) 
    {   
        #pragma omp for schedule(static) 
        for (long long i = 1; i < n - 1; ++i) {
            for (long long j = 1; j < m - 1; ++j) {
                float sum = 0.0;
                for (int k = 0; k < 9; ++k) {
                    int kx = k / 3;
                    int ky = k % 3;
                    sum += A[(i - 1 + kx) * m + (j - 1 + ky)] * K[kx * 3 + ky];
                }
                newA[i * m + j] = sum;
            }
        }
    }
}

#endif // A1_HPP
