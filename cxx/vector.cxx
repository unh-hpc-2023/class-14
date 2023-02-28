
#include "linear_algebra.h"

#include <stdio.h>

vector::vector(int n) : data_(new double[n]), n_(n) {}

vector::~vector()
{
  delete[] data_;
  // The below isn't necessary, but may help make certain bugs more obvious.
  // data = NULL;
  // n = 0;
}

void vector::print() const
{
  printf("{ ");
  for (int i = 0; i < size(); i++) {
    printf("%g, ", (*this)(i));
  }
  printf("}\n");
}

bool operator==(const vector& x, const vector& y)
{
  if (x.size() != y.size()) {
    return false;
  }
  for (int i = 0; i < x.size(); i++) {
    if (x(i) != y(i)) {
      return false;
    }
  }
  return true;
}
