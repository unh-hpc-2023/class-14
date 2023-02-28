
#include "linear_algebra.h"

#include <stdio.h>

vector::vector(int n_) : data(new double[n_]), n(n_) {}

vector::~vector()
{
  delete[] data;
  // The below isn't necessary, but may help make certain bugs more obvious.
  // data = NULL;
  // n = 0;
}

void vector::print() const
{
  printf("{ ");
  for (int i = 0; i < n; i++) {
    printf("%g, ", at(i));
  }
  printf("}\n");
}

bool vector_is_equal(const vector& x, const vector& y)
{
  if (x.n != y.n) {
    return false;
  }
  for (int i = 0; i < x.n; i++) {
    if (x.at(i) != y.at(i)) {
      return false;
    }
  }
  return true;
}
