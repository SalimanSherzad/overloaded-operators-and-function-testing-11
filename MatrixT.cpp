//
// Created by we7289 on 10/30/2021.
//

#include "MatrixT.h"

MatrixT::MatrixT() {

    numRows = DEFAULT_ROWS;
    numCols = DEFAULT_COLS;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = 0;
        }
    }
}

MatrixT::MatrixT(int rowSize, int colSize) {

    SetRows(rowSize);
    SetColumns(colSize);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = 0;
        }
    }
}

MatrixT::MatrixT(const MatrixT &other) {
    // Resize to other
    numRows = other.numRows;
    numCols = other.numCols;

    // Initialize the matrix and copy over the data
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

void MatrixT::SetColumns(int newCols) {
    if (newCols < 0 || newCols >= MAX_COLS) {
        throw "Invalid size";
    }

    numCols = newCols;
}

void MatrixT::SetRows(int newRows) {
    if (newRows < 0 || newRows >= MAX_ROWS) {
        throw "Invalid size";
    }

    numRows = newRows;
}


int MatrixT::GetNumRows() const {
    return numRows;
}

int MatrixT::GetNumCols() const {
    return numCols;
}

int MatrixT::GetElement(int rowInd, int colInd) {
    if (rowInd < 0 || rowInd >= numRows || colInd < 0 || colInd >= numCols) {
        throw "Index out of bounds";
    }

    return matrix[rowInd][colInd];
}

void MatrixT::SetElement(int value, int rowInd, int colInd) {
    if (rowInd < 0 || rowInd >= numRows || colInd < 0 || colInd >= numCols) {
        throw "Index out of bounds";
    }

    matrix[rowInd][colInd] = value;
}


// matA = matB + matC;
// matA = matB.operator+(matC);
MatrixT MatrixT::operator+(const MatrixT &other) {
    MatrixT result;

    if (numRows != other.numRows || numCols != other.numCols) {
        throw "Dimensions do not match";
    }

    result.SetRows(numRows);
    result.SetColumns(numCols);
    for (int i = 0; i < other.numRows; i++) {
        for (int j = 0; j < other.numCols; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }

    return result; // result needs to get copied into a hidden variable called the function return value
}

MatrixT MatrixT::operator-(const MatrixT &other) {
    MatrixT result;

    if (numRows != other.numRows || numCols != other.numCols) {
        throw "Dimensions do not match";
    }

    result.SetRows(numRows);
    result.SetColumns(numCols);
    for (int i = 0; i < other.numRows; i++) {
        for (int j = 0; j < other.numCols; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }

    return result;
}

MatrixT MatrixT::operator*(const MatrixT &other) {
    MatrixT result;

    if (numCols != other.numRows) {
        throw "Dimensions do not match";
    }

    result.SetRows(numRows);
    result.SetColumns(other.numCols);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < other.numCols; j++) {
            for (int k = 0; k < numCols; k++) {
                result.matrix[i][j] += matrix[i][k]*other.matrix[k][j];
            }
        }
    }

    return result;
}

// matA = matA;
MatrixT& MatrixT::operator=(const MatrixT &other) {

    // If trying to assign to self.
    if (&other == this) {
        return *this;
    }

    numRows = other.numRows;
    numCols = other.numCols;

    // Initialize the matrix and copy over the data
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }

    return *this;
}

bool MatrixT::operator==(const MatrixT &other) {

    // Size doesn't match
    if (other.numCols != numCols || other.numRows != numRows) {
        return false;
    }

    // Check each element
    for (int i = 0; i < other.numRows; i++) {
        for (int j = 0; j < other.numCols; j++) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}
