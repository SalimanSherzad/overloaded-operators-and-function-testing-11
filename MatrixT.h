

#ifndef MATRIXT_H
#define MATRIXT_H

const int DEFAULT_ROWS = 10;
const int DEFAULT_COLS = 10;

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

class MatrixT {
public:
    MatrixT();
    MatrixT(int rowSize, int colSize);
    MatrixT(const MatrixT& other);

    void SetColumns(int newCols);
    void SetRows(int newRows);

    int GetNumRows() const;
    int GetNumCols() const;

    int GetElement(int rowInd, int colInd);
    void SetElement(int value, int rowInd, int colInd);

    // Overloads
    MatrixT operator+(const MatrixT& other);
    MatrixT operator-(const MatrixT& other);
    MatrixT operator*(const MatrixT& other);
    MatrixT& operator=(const MatrixT& other);
    bool operator==(const MatrixT& other);

private:
    // Size of the matrix
    int numRows;
    int numCols;

    int matrix[MAX_ROWS][MAX_COLS]; //Matrix data
};


#endif //MATRIXT_H
