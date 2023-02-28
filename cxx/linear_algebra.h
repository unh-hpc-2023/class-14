
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdbool.h>

// vector
//
// encapsulates what makes up a vector -- how many elements it contains (n), as
// well as the actual elements data[0] ... data[n-1]

class vector
{
public:
  vector(int n);
  ~vector();

  int size() const { return n_; }
  double& operator()(int i) { return data_[i]; }
  const double& operator()(int i) const { return data_[i]; }

  void print() const;

private:
  double* data_;
  int n_;
};

bool operator==(const vector& x, const vector& y);

double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);

struct matrix
{
  matrix(int n_rows, int n_cols);
  ~matrix();

  double& operator()(int i, int j) { return data[i * n_cols + j]; }
  const double& operator()(int i, int j) const { return data[i * n_cols + j]; }

  void print() const;

  double* data;
  int n_rows;
  int n_cols;
};

void matrix_vector_mul(const matrix& A, const vector& x, vector& y);

#endif
