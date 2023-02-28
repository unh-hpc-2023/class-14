
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdbool.h>

// vector
//
// encapsulates what makes up a vector -- how many elements it contains (n), as
// well as the actual elements data[0] ... data[n-1]

struct vector
{
  vector(int n);
  ~vector();

  double& operator()(int i) { return data[i]; }
  const double& operator()(int i) const { return data[i]; }

  void print() const;

  double* data;
  int n;
};

bool operator==(const vector& x, const vector& y);

double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);

struct matrix
{
  matrix(int n_rows, int n_cols);
  ~matrix();

  double* data;
  int n_rows;
  int n_cols;
};

#define MAT(A, i, j) (A).data[(i) * (A).n_cols + (j)]

void matrix_print(const matrix& A);

void matrix_vector_mul(const matrix& A, const vector& x, vector& y);

#endif
