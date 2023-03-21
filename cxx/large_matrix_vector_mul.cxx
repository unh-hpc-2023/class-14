
#include "linear_algebra.h"

#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int main(int argc, char** argv)
{
  const int N = 20000;
  vector x = xt::arange(N);
  matrix A = xt::eye(N);

  vector y = dot(A, x);

  return 0;
}
