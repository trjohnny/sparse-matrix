// CSRMatrix.h

#ifndef CSR_MATRIX_H
#define CSR_MATRIX_H

#include "SparseMatrix.h"
#include <vector>

template<typename T>
class CSRMatrix : public SparseMatrix<T> {
private:
    std::vector<T> values;
    std::vector<int> colIndices;
    std::vector<int> row_idx;

public:
    CSRMatrix(int rows, int cols);

    int getNonZeros() const override;
    T operator()(int row, int col) const override;
    T& operator()(int row, int col) override;
    std::vector<T> operator*(const std::vector<T>& vec) const override;

    std::string toString() const override;

    void addValue(int row, int col, T value);
};

#include "CSRMatrix.tpp"  // Include the template implementation

#endif // CSR_MATRIX_H