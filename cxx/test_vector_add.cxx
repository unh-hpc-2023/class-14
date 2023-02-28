
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_add() function

void test_vector_add(int N)
{
  vector x(N), y(N), z_ref(N);

  for (int i = 0; i < N; i++) {
    x(i) = 1 + i;
    y(i) = 2 + i;
    z_ref(i) = 3 + 2 * i;
  }

  vector z = x + y;
  assert(z == z_ref);
}

int main(int argc, char** argv)
{
  test_vector_add(3);
  test_vector_add(4);

  return 0;
}
