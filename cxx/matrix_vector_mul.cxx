
#include "linear_algebra.h"

#include <assert.h>

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  assert(A.n_cols == x.n && A.n_rows == y.n);

  for (int j = 0; j < y.n; j++) {
    y.at(j) = 0.;
    for (int i = 0; i < x.n; i++) {
      y.at(j) += MAT(A, j, i) * x.at(i);
    }
  }
}
