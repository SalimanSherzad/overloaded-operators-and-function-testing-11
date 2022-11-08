

#ifndef MATRIXT_H
#define MATRIXT_H

const int DEFAULT_ROWS = 10;
const int DEFAULT_COLS = 10;

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

class MatrixT {
public:
    MatrixT();
    // pre: none (default constructor)
    // post: initializes numRows, numCols and matrix to zero
    MatrixT(int rowSize, int colSize);
    //pre: taken row size and column size from user
    //post: sets row size equal to rowSize and colSize
    MatrixT(const MatrixT& other);

    void SetColumns(int newCols);
    // pre: numCols is set to 0 and user gives value for newCols
    //post: numCols is now equal to newCols
    void SetRows(int newRows);
    // pre: numRows is set to 0 and user gives value for newRows
    //post: numRows is now equal to newRows
    int GetNumRows() const;
    // pre: there is variable numRows
    //post: this returns numRows
    int GetNumCols() const;
    // pre; there is a variable numCols
    // post: this returns numCold

    int GetElement(int rowInd, int colInd);
    //pre: user inputs a row index value and a column index value
    //post: returns the value of a matrix stored at specified index
    void SetElement(int value, int rowInd, int colInd);
    //pre: user inputs a value and the row index and column index they want the value to update to
    //post: the matrix at the row and column index specified will be updated to the users new value


    // Overloads
    MatrixT operator+(const MatrixT& other);
    //pre: the current instance of an object needs its values added to the other object matrix values
    //post: return a MatrixT object with the values of the matrix other added to the current instance of MatrixT

    MatrixT operator-(const MatrixT& other);
    //pre: the other object has values in the matrix that will subtract from the instance matrix values
    //post: return a MatrixT object with the values of the matrix other subtracted from the current instance of MatrixT



    MatrixT operator*(const MatrixT& other);
    // pre: the current instance of an object needs its values multiplied to the other object matrix values
    //post: return a matrix object with the values of the current instance multiplied by other matrix


    MatrixT& operator=(const MatrixT& other);
    // pre: takes other class which its values will be equal to the current instance of the MatrixT
    // post: returns the current instance of matrixT

    bool operator==(const MatrixT& other);
    // pre: the other class is used to compare the current instance of the class
    //post: returns true if the current instance of the class is equal to the other class


private:
    // Size of the matrix
    int numRows;
    int numCols;

    int matrix[MAX_ROWS][MAX_COLS]; //Matrix data
};


#endif //MATRIXT_H
