
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <cassert>
#include <stdbool.h>
#include <vector>

// uncomment the following to enable bounds checking
//#define BOUNDS_CHECK

// vector
//
// encapsulates what makes up a vector -- how many elements it contains (n), as
// well as the actual elements data[0] ... data[n-1]

class vector
{
public:
  vector(int n);

  int size() const { return data_.size(); }
  double& operator()(int i)
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < size());
#endif
    return data_[i];
  }
  const double& operator()(int i) const
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < size());
#endif
    return data_[i];
  }

  void print() const;

private:
  std::vector<double> data_;
};

bool operator==(const vector& x, const vector& y);

double dot(const vector& x, const vector& y);
vector operator+(const vector& x, const vector& y);

class matrix
{
public:
  matrix(int n_rows, int n_cols);

  int n_rows() const { return n_rows_; }
  int n_cols() const { return n_cols_; }
  double& operator()(int i, int j)
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < n_rows());
    assert(j >= 0 && j < n_cols());
#endif
    return data_[i * n_cols_ + j];
  }
  const double& operator()(int i, int j) const
  {
#ifdef BOUNDS_CHECK
    assert(i >= 0 && i < n_rows());
    assert(j >= 0 && j < n_cols());
#endif
    return data_[i * n_cols_ + j];
  }

  void print() const;

private:
  std::vector<double> data_;
  int n_rows_;
  int n_cols_;
};

vector dot(const matrix& A, const vector& x);

#endif
