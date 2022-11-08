#include <iostream>

#include "MatrixT.h"
using namespace std;





void Print(MatrixT&);
MatrixT CopyConstructorTest();

int main() {

    cout << "This program runs through some basic testing of the MatrixT class." << endl;
    cout << "You should make sure these tests work first before trying to pass" << endl;
    cout << "the \"official\" tests.  This will help you debug problems more" << endl;
    cout << "easily.  Feel free to modify any part of this program. It is not" << endl;
    cout << "used for grading." << endl << endl;

    MatrixT mat;

    cout << "Default constructor basic test" << endl;
    cout << "Should be all zeros and 10x10" << endl;
    Print(mat);
    cout << endl;

    cout << "Testing alternate constructor" << endl;
    cout << "Should be all zeros and 4x2" << endl;
    MatrixT matAlt(4,2);
    Print(matAlt);
    cout << endl;


    mat.SetRows(6);
    mat.SetColumns(5);
    cout << "Testing the resizing functions" << endl;
    cout << "Row size should be 6: " << mat.GetNumRows() << endl;
    cout << "Col size should be 5: " << mat.GetNumCols() << endl;

    cout << endl;
    cout << "After resizing:" << endl;
    Print(mat);
    cout << endl;

    cout << "Testing the setter." << endl;
    cout << "Should show a 6x5 \"times\" table:" << endl;
    for (int row = 0; row < mat.GetNumRows(); row++) {
        for (int col = 0; col < mat.GetNumCols(); col++) {
            mat.SetElement(row*col, row, col);
        }
    }
    Print(mat);
    cout << endl;

    MatrixT matA, matB, matC;

    matC.SetRows(6);
    matC.SetColumns(5);

    cout << "Testing operator=" << endl;
    matA = mat;
    cout << "matA and mat should be the same." << endl << endl;
    cout << "matA" << endl;
    cout << "--------------------------------" << endl;
    Print(matA);
    cout << endl;
    cout << "mat" << endl;
    cout << "--------------------------------" << endl;
    Print(mat);
    cout << endl;

    cout << "If these values are all 1's, then the operator= is" << endl;
    cout << "likely not working. If you see the times table, then" << endl;
    cout << "operator= is likely working." << endl;
    for (int row = 0; row < matA.GetNumRows(); row++) {
        for (int col = 0; col < matA.GetNumCols(); col++) {
            matA.SetElement(1, row, col);
            matC.SetElement(1, row, col);
        }
    }
    Print(mat);
    cout << endl;

    cout << "Testing operator+" << endl;
    matB = matA + mat;
    cout << "This should show the times table with 1 added to" << endl;
    cout << "all the entries" << endl;
    Print(matB);
    cout << endl;

    cout << "Testing operator-" << endl;
    matB = matB - matA;
    cout << "This should show the times table" << endl;
    Print(matB);
    cout << endl;



    cout << "Testing operator*" << endl;
    matB.SetRows(matA.GetNumCols());
    MatrixT mult = matA*matB;
    cout << "This should show 0 10 20 30 40 for each row." << endl;
    Print(mult);
    cout << endl;


    cout << "Testing operator==" << endl;
    if (matA == mat) {
        cout << "Uh oh... your operator== is saying " << endl;
        cout << "matA and mat are the same" << endl << endl;
        cout << "matA" << endl;
        Print(matA);
        cout << endl << endl;
        cout << "mat" << endl;
        Print(mat);
    } else {
        cout << "Looks like operator== can tell when two matricies are NOT equal" << endl;
    }

    if (matA == matC) {
        cout << "Looks like operator== can tell when two matricies ARE equal" << endl;
    } else {
        cout << "Uh oh... your operator== is saying " << endl;
        cout << "matA and matC are NOT the same" << endl << endl;
        cout << "matA" << endl;
        Print(matA);
        cout << endl << endl;
        cout << "matC" << endl;
        Print(matC);
    }
    cout << endl;

    cout << "Testing the copy constructor" << endl;
    cout << "This should print a 4x2 matrix of 42's." << endl;
    MatrixT copyMat = CopyConstructorTest();
    Print(copyMat);
    cout << endl;

    return 0;

}


void Print(MatrixT& mat) {

    for (int row = 0; row < mat.GetNumRows(); row++) {
        for (int col = 0; col < mat.GetNumCols(); col++) {
            cout << mat.GetElement(row, col) << "\t";
        }
        cout << endl;
    }
}

// Returns a matrix containing the ultimate answer of the universe.
MatrixT CopyConstructorTest() {
    MatrixT mat;
    mat.SetRows(4);
    mat.SetColumns(2);

    for (int row = 0; row < mat.GetNumRows(); row++) {
        for (int col = 0; col < mat.GetNumCols(); col++) {
            mat.SetElement(42, row, col);
        }
    }

    return mat;
}