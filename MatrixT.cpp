
#include "MatrixT.h"

MatrixT::MatrixT() {
    numRows = DEFAULT_ROWS;
    numCols = DEFAULT_COLS;
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            matrix[i][j] = 0;
        }
    }

}

MatrixT::MatrixT(int rowSize, int colSize) {
    if (rowSize < 0 || colSize < 0){
        throw "Invalid size";
    }
    if (rowSize > MAX_ROWS || colSize > MAX_COLS){
        throw "Invalid size";
    }
     numRows = rowSize;
     numCols = colSize;
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            matrix[i][j] = 0;
        }
    }

}

MatrixT::MatrixT(const MatrixT &other) {
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }

}

void MatrixT::SetColumns(int newCols) {
    if (newCols < 0 || newCols > MAX_COLS){
        throw "Invalid size";
    }
    numCols = newCols;
}

void MatrixT::SetRows(int newRows) {
    if (newRows < 0 || newRows > MAX_ROWS){
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
    if (rowInd < 0 || colInd < 0 || rowInd > numRows || colInd > numCols){
        throw "Index out of bounds";
    }
    return matrix[rowInd][colInd];
}

void MatrixT::SetElement(int value, int rowInd, int colInd) {
    if (rowInd < 0 || colInd < 0 || rowInd > numRows || colInd > numCols){
        throw "Index out of bounds";
    }
    matrix[rowInd][colInd] = value;
}



 MatrixT MatrixT::operator+(const MatrixT &other) {
    MatrixT sumMatrix;
    if (numRows != other.GetNumRows() || numCols != other.GetNumCols()){
        throw "Dimensions do not match";
    }
    sumMatrix.SetRows(numRows);
    sumMatrix.SetColumns(numCols);

      for (int i = 0; i < numRows; i++){
          for(int j = 0; j < numCols; j++){
              sumMatrix.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
          }
      }
      return sumMatrix;

}


MatrixT MatrixT::operator-(const MatrixT &other) {
    MatrixT sumMatrix;
    if (numRows != other.GetNumRows() || numCols != other.GetNumCols()){
        throw "Dimensions do not match";
    }
    sumMatrix.SetRows(numRows);
    sumMatrix.SetColumns(numCols);

    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            sumMatrix.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return sumMatrix;
}

MatrixT MatrixT::operator*(const MatrixT &other) {
    MatrixT sumMatrix;
    if (numCols != other.GetNumCols()){
        throw "Dimensions are not valid";
    }


    sumMatrix.SetRows(numRows);
    sumMatrix.SetColumns(numCols);

    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            for (int k = 0; k < numCols; k++) {
                sumMatrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return sumMatrix;
}




MatrixT &MatrixT::operator=(const MatrixT &other) {
    numRows = other.GetNumRows();
    numCols = other.GetNumCols();
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}




bool MatrixT::operator==(const MatrixT &other) {
    bool value = true;
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCols; j++)
            if (matrix[i][j] != other.matrix[i][j])
                value = false;
    return value;

}

