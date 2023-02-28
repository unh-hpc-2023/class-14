
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int main(int argc, char** argv)
{
  const int N = 3;
  vector x(N), y(N), y_ref(N);

  for (int i = 0; i < x.n; i++) {
    x.at(i) = 1 + i;
  }
  matrix A(N, N);

  for (int i = 0; i < N; i++) {
    MAT(A, i, i) = i + 1; // set diagonal
    y_ref.at(i) = (1 + i) * (1 + i);
  }
  MAT(A, 0, 1) = 1.; // add one non-zero off-diagonal element
  y_ref.at(0) += 2;  // adjust reference solution correspondingly

  matrix_vector_mul(A, x, y);
  assert(y == y_ref);

  return 0;
}
