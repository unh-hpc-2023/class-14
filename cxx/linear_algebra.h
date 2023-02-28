
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdbool.h>
#include <vector>

// vector
//
// encapsulates what makes up a vector -- how many elements it contains (n), as
// well as the actual elements data[0] ... data[n-1]

class vector
{
public:
  vector(int n);

  int size() const { return data_.size(); }
  double& operator()(int i) { return data_[i]; }
  const double& operator()(int i) const { return data_[i]; }

  void print() const;

private:
  std::vector<double> data_;
};

bool operator==(const vector& x, const vector& y);

double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);

class matrix
{
public:
  matrix(int n_rows, int n_cols);
  ~matrix();

  int n_rows() const { return n_rows_; }
  int n_cols() const { return n_cols_; }
  double& operator()(int i, int j) { return data_[i * n_cols_ + j]; }
  const double& operator()(int i, int j) const
  {
    return data_[i * n_cols_ + j];
  }

  void print() const;

private:
  double* data_;
  int n_rows_;
  int n_cols_;
};

void matrix_vector_mul(const matrix& A, const vector& x, vector& y);

#endif
