/**
 * Created by Ashley Erickson on 1/25/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * basic_matrix_driver.cpp file.
 *
 * The purpose of this file is to test the DrawLine functions.
 */

#include "catch.hpp"
#include <iostream>
#include <fstream>
#include "../MatrixT.h"

using namespace std;

void Load_Matrices(string filename, MatrixT& a, MatrixT& b, MatrixT& c) {
    ifstream matFile;
    matFile.open(filename);

    int numRows, numCols;

    matFile >> numRows >> numCols;
    a.SetRows(numRows);
    a.SetColumns(numCols);

    // Init matrix a
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int elem;
            matFile >> elem;
            a.SetElement(elem, row, col);
        }
    }

    matFile >> numRows >> numCols;
    b.SetRows(numRows);
    b.SetColumns(numCols);

    // Init matrix b
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int elem;
            matFile >> elem;
            b.SetElement(elem, row, col);
        }
    }

    matFile >> numRows >> numCols;
    c.SetRows(numRows);
    c.SetColumns(numCols);

    // Init matrix result
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int elem;
            matFile >> elem;
            c.SetElement(elem, row, col);
        }
    }
}

string PrintMatrix(MatrixT& mat) {
    string rowStr = "";
    for (int row = 0; row < mat.GetNumRows(); row++) {
        for (int col = 0; col < mat.GetNumCols(); col++) {
            rowStr += to_string(mat.GetElement(row, col)) + "\t";
        }
        rowStr += "\n  ";
    }
    return rowStr;
}

TEST_CASE("MatrixT()") {
    MatrixT mat;

    if (mat.GetNumCols() != DEFAULT_COLS) {
        INFO("Default size of matrix not correct.");
        INFO("Expected size of 10");
        INFO("mat.GetNumCols() has size of " << mat.GetNumCols());
        FAIL();
    }

    if (mat.GetNumRows() != DEFAULT_ROWS) {
        INFO("Default size of matrix not correct.");
        INFO("Expected size of 10");
        INFO("mat.GetNumRows() has size of " << mat.GetNumRows());
        FAIL();
    }

    for (int row = 0; row < mat.GetNumRows(); row++) {
        for (int col = 0; col < mat.GetNumCols(); col++) {
            if (mat.GetElement(row, col) != 0) {
                INFO("Default constructor did not initialize matrix to 0");
                FAIL();
            }
        }
    }
}

TEST_CASE("MatrixT(int, int)") {

    // Run 10 tests with good values
    for (int i = 0; i < 10; i++) {

        // Get random size between 5 and 15
        int randRow = rand() % 10 + 6;
        int randCol = rand() % 10 + 6;

        MatrixT mat(randRow, randCol);

        if (mat.GetNumCols() != randCol) {
            INFO("Default size of matrix not correct.");
            INFO("Expected size of " << randCol);
            INFO("mat.GetNumCols() has size of " << mat.GetNumCols());
            FAIL();
        }

        if (mat.GetNumRows() != randRow) {
            INFO("Default size of matrix not correct.");
            INFO("Expected size of " << randRow);
            INFO("mat.GetNumRows() has size of " << mat.GetNumRows());
            FAIL();
        }

        for (int row = 0; row < mat.GetNumRows(); row++) {
            for (int col = 0; col < mat.GetNumCols(); col++) {
                if (mat.GetElement(row, col) != 0) {
                    INFO("Default constructor did not initialize matrix to 0");
                    FAIL();
                }
            }
        }
    }

    // Run 10 tests with negative values
    for (int i = 0; i < 10; i++) {

        // Get random size between 5 and 15
        int randRow = -(rand() % 15+1);
        int randCol = -(rand() % 15+1);
        bool errorThrown = false;

        try {
            MatrixT mat(randRow, randCol);
        }
        catch(const char* error) {
            if (string(error) != "Invalid size") {
                INFO("Expected MatrixT mat(" << randRow << ", " << randCol << ") to throw \"Invalid size\" error");
                FAIL();
            }
            errorThrown = true;
        }

        if (!errorThrown) {
            INFO("Constructor did not handle bad values");
            INFO("Expected MatrixT mat(" << randRow << ", " << randCol << ") to throw \"Invalid size\" error");
            FAIL();
        }
    }

    // Run 10 tests with values that are too large
    for (int i = 0; i < 10; i++) {

        // Get random size between 5 and 15
        int randRow = rand() % 10+MAX_ROWS;
        int randCol = rand() % 10+MAX_COLS;
        bool errorThrown = false;

        try {
            MatrixT mat(randRow, randCol);
        }
        catch(const char* error) {
            if (string(error) != "Invalid size") {
                INFO("Expected MatrixT mat(" << randRow << ", " << randCol << ") to throw \"Invalid size\" error");
                FAIL();
            }
            errorThrown = true;
        }

        if (!errorThrown) {
            INFO("Constructor did not handle bad values");
            INFO("Expected MatrixT mat(" << randRow << ", " << randCol << ") to throw \"Invalid size\" error");
            FAIL();
        }
    }
}

TEST_CASE("Get/Set Rows and Columns") {

    // Run tests with good values
    for (int col = 1; col < MAX_COLS; col++) {
        MatrixT mat;

        mat.SetColumns(col);
        if (mat.GetNumCols() != col) {
            INFO("Expected size of " << col);
            INFO("mat.GetNumCols() has size of " << mat.GetNumCols());
            FAIL();
        }
    }

    // Run tests with good values
    for (int row = 1; row < MAX_ROWS; row++) {
        MatrixT mat;

        mat.SetRows(row);
        if (mat.GetNumRows() != row) {
            INFO("Expected size of " << row);
            INFO("mat.GetNumRows() has size of " << mat.GetNumRows());
            FAIL();
        }
    }

    // Run 10 tests with negative values
    for (int i = 0; i < 10; i++) {

        // Get random size between 5 and 15
        int randRow = -(rand() % 15+1);
        int randCol = -(rand() % 15+1);
        bool errorThrown = false;

        try {
            MatrixT mat;
            mat.SetRows(randRow);
        }
        catch(const char* error) {
            if (string(error) != "Invalid size") {
                INFO("Expected mat.SetRows(" << randRow << ") to throw \"Invalid size\" error");
                FAIL();
            }
            errorThrown = true;
        }

        if (!errorThrown) {
            INFO("Setter did not handle bad values");
            INFO("Expected mat.SetCols(" << randCol << ") to throw \"Invalid size\" error");
            FAIL();
        }

        errorThrown = false;
        try {
            MatrixT mat;
            mat.SetColumns(randCol);
        }
        catch(const char* error) {
            if (string(error) != "Invalid size") {
                INFO("Expected mat.SetCols(" << randCol << ") to throw \"Invalid size\" error");
                FAIL();
            }
            errorThrown = true;
        }

        if (!errorThrown) {
            INFO("Setter did not handle bad values");
            INFO("Expected mat.SetCols(" << randCol << ") to throw \"Invalid size\" error");
            FAIL();
        }
    }

    // Run 10 tests with values that are too large
    for (int i = 0; i < 10; i++) {

        // Get random size between 5 and 15
        int randRow = rand() % 10+MAX_ROWS;
        int randCol = rand() % 10+MAX_COLS;
        bool errorThrown = false;

        try {
            MatrixT mat;
            mat.SetRows(randRow);
        }
        catch(const char* error) {
            if (string(error) != "Invalid size") {
                INFO("Expected mat.SetRows(" << randRow << ") to throw \"Invalid size\" error");
                FAIL();
            }
            errorThrown = true;
        }

        if (!errorThrown) {
            INFO("Setter did not handle bad values");
            INFO("Expected mat.SetCols(" << randCol << ") to throw \"Invalid size\" error");
            FAIL();
        }

        errorThrown = false;
        try {
            MatrixT mat;
            mat.SetColumns(randCol);
        }
        catch(const char* error) {
            if (string(error) != "Invalid size") {
                INFO("Expected mat.SetCols(" << randCol << ") to throw \"Invalid size\" error");
                FAIL();
            }
            errorThrown = true;
        }

        if (!errorThrown) {
            INFO("Setter did not handle bad values");
            INFO("Expected mat.SetCols(" << randCol << ") to throw \"Invalid size\" error");
            FAIL();
        }
    }
}

TEST_CASE("Get/Set Elements") {
    MatrixT mat;

    // Check Setter and Getters
    for (int row = 0; row < mat.GetNumRows(); row++) {
        for (int col = 0; col < mat.GetNumCols(); col++) {
            mat.SetElement(row * col, row, col);
            if (mat.GetElement(row, col) != row * col) {
                INFO("Setter did not set value at " << row << ", " << col << " correctly.");
                FAIL();
            }
        }
    }

    // Checking bounds handling
    bool errorThrown = false;
    try {
        MatrixT matA;
        matA.SetElement(42, -10, 10);
    }
    catch (const char *error) {
        if (string(error) != "Index out of bounds") {
            INFO("Expected throw \"Index out of bounds\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("SetElement did not handle bad row,col coordinate");
        INFO("Expected SetElement to throw \"Index out of bounds\"");
        FAIL();
    }

    errorThrown = false;
    try {
        MatrixT matA;
        matA.SetElement(42, 10, -10);
    }
    catch (const char *error) {
        if (string(error) != "Index out of bounds") {
            INFO("Expected throw \"Index out of bounds\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("SetElement did not handle bad row,col coordinate");
        INFO("Expected SetElement to throw \"Index out of bounds\"");
        FAIL();
    }

    errorThrown = false;
    try {
        MatrixT matA;
        matA.SetElement(42, 100, 5);
    }
    catch (const char *error) {
        if (string(error) != "Index out of bounds") {
            INFO("Expected throw \"Index out of bounds\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("SetElement did not handle bad row,col coordinate");
        INFO("Expected SetElement to throw \"Index out of bounds\"");
        FAIL();
    }

    errorThrown = false;
    try {
        MatrixT matA;
        matA.SetElement(42, 5, 500);
    }
    catch (const char *error) {
        if (string(error) != "Index out of bounds") {
            INFO("Expected throw \"Index out of bounds\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("SetElement did not handle bad row,col coordinate");
        INFO("Expected SetElement to throw \"Index out of bounds\"");
        FAIL();
    }
}

TEST_CASE("operator+") {
    bool errorThrown = false;
    try {
        MatrixT matA;
        matA.SetRows(4);
        matA.SetColumns(10);

        MatrixT matB;
        matB.SetRows(10);
        matB.SetColumns(10);

        matA + matB;
    }
    catch (const char* error) {
        if (string(error) != "Dimensions do not match") {
            INFO("Expected throw \"Dimensions do not match\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("operator+ did not handle dimension mismatch");
        INFO("operator+ should only work for matricies of the same size.")
        FAIL();
    }

    errorThrown = false;
    try {
        MatrixT matA;
        matA.SetRows(10);
        matA.SetColumns(4);

        MatrixT matB;
        matB.SetRows(10);
        matB.SetColumns(10);

        matA + matB;
    }
    catch (const char* error) {
        if (string(error) != "Dimensions do not match") {
            INFO("Expected throw \"Dimensions do not match\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("operator+ did not handle dimension mismatch");
        INFO("operator+ should only work for matricies of the same size.")
        FAIL();
    }

    for (int i = 1; i <= 3; i++) {
        MatrixT matA;
        MatrixT matB;
        MatrixT result;
        Load_Matrices("unit_tests/add_matrix_0" + to_string(i) + ".txt", matA, matB, result);

        MatrixT test = matA + matB;
        for (int row = 0; row < result.GetNumRows(); row++) {
            for (int col = 0; col < result.GetNumCols(); col++) {
                if (result.GetElement(row, col) != test.GetElement(row, col)) {
                    INFO("Elements did not match at ");
                    INFO("row: " << row);
                    INFO("col: " << col);
                    INFO("..Expected: " << result.GetElement(row, col));
                    INFO("....Actual: " << test.GetElement(row, col));
                    FAIL();
                }
            }
        }
    }
}

TEST_CASE("operator-") {
    bool errorThrown = false;
    try {
        MatrixT matA;
        matA.SetRows(4);
        matA.SetColumns(10);

        MatrixT matB;
        matB.SetRows(10);
        matB.SetColumns(10);

        matA - matB;
    }
    catch (const char* error) {
        if (string(error) != "Dimensions do not match") {
            INFO("Expected throw \"Dimensions do not match\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("operator- did not handle dimension mismatch");
        INFO("operator- should only work for matricies of the same size.")
        FAIL();
    }

    errorThrown = false;
    try {
        MatrixT matA;
        matA.SetRows(10);
        matA.SetColumns(4);

        MatrixT matB;
        matB.SetRows(10);
        matB.SetColumns(10);

        matA - matB;
    }
    catch (const char* error) {
        if (string(error) != "Dimensions do not match") {
            INFO("Expected throw \"Dimensions do not match\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("operator- did not handle dimension mismatch");
        INFO("operator- should only work for matricies of the same size.")
        FAIL();
    }

    for (int i = 1; i <= 3; i++) {
        MatrixT matA;
        MatrixT matB;
        MatrixT result;
        Load_Matrices("unit_tests/sub_matrix_0" + to_string(i) + ".txt", matA, matB, result);

        MatrixT test = matA - matB;
        for (int row = 0; row < result.GetNumRows(); row++) {
            for (int col = 0; col < result.GetNumCols(); col++) {
                if (result.GetElement(row, col) != test.GetElement(row, col)) {
                    INFO("Expected:");
                    INFO(PrintMatrix(result));
                    INFO("----------");
                    INFO("Actual:")
                    INFO(PrintMatrix(test));
                    INFO("----------------------------");
                    INFO("unit_tests/sub_matrix_0" << i << ".txt");
                    INFO("Elements did not match at ");
                    INFO("row: " << row);
                    INFO("col: " << col);
                    INFO("..Expected: " << result.GetElement(row, col));
                    INFO("....Actual: " << test.GetElement(row, col));
                    FAIL();
                }
            }
        }
    }
}

TEST_CASE("operator*") {

    bool errorThrown = false;
    try {
        MatrixT matA;
        matA.SetRows(4);
        matA.SetColumns(10);

        MatrixT matB;
        matB.SetRows(40);
        matB.SetColumns(2);

        MatrixT matC = matA * matB;
    }
    catch (const char* error) {
        if (string(error) != "Dimensions do not match") {
            INFO("Expected throw \"Dimensions do not match\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("operator* did not handle dimension mismatch");
        INFO("operator* should only work for matricies of the same size.")
        FAIL();
    }

    errorThrown = false;
    try {
        MatrixT matA;
        matA.SetRows(40);
        matA.SetColumns(10);

        MatrixT matB;
        matB.SetRows(35);
        matB.SetColumns(10);

        MatrixT matC = matA * matB;
    }
    catch (const char* error) {
        if (string(error) != "Dimensions do not match") {
            INFO("Expected throw \"Dimensions do not match\" error");
            FAIL();
        }
        errorThrown = true;
    }

    if (!errorThrown) {
        INFO("operator* did not handle dimension mismatch");
        INFO("operator* should only work for matricies of the same size.")
        FAIL();
    }


    for (int i = 1; i <= 3; i++) {
        MatrixT matA;
        MatrixT matB;
        MatrixT result;
        Load_Matrices("unit_tests/mult_matrix_0" + to_string(i) + ".txt", matA, matB, result);

        MatrixT test = matA*matB;
        for (int row = 0; row < result.GetNumRows(); row++) {
            for (int col = 0; col < result.GetNumCols(); col++) {
                if (result.GetElement(row, col) != test.GetElement(row, col)) {
                    INFO("Expected:");
                    INFO(PrintMatrix(result));
                    INFO("----------");
                    INFO("Actual:")
                    INFO(PrintMatrix(test));
                    INFO("----------------------------");
                    INFO("Elements did not match at ");
                    INFO("row: " << row);
                    INFO("col: " << col);
                    INFO("..Expected: " << result.GetElement(row, col));
                    INFO("....Actual: " << test.GetElement(row, col));
                    FAIL();
                }
            }
        }
    }
}

TEST_CASE("operator=") {
    for (int i = 1; i <= 3; i++) {
        MatrixT matA;
        MatrixT matB;
        MatrixT matC;
        // matA, matB, and matC should all be the same (won't use matC).
        Load_Matrices("unit_tests/assign_matrix_0" + to_string(i) + ".txt", matA, matB, matC);

        MatrixT result = matB;

        if (result.GetNumCols() != matB.GetNumCols() ||
            result.GetNumRows() != matB.GetNumRows()) {
            INFO("Dimensions do not match.");
            INFO("Expected: size " << result.GetNumRows() << "x" << result.GetNumCols());
            INFO("..Actual: size " << matB.GetNumRows() << "x" << matB.GetNumCols());
            FAIL();
        }

        // Changing matB should NOT change result
        for (int row = 0; row < matB.GetNumRows(); row++) {
            for (int col = 0; col < matB.GetNumCols(); col++) {
                matB.SetElement(-9999, row, col);
            }
        }

        // matA and result should be the same
        for (int row = 0; row < result.GetNumRows(); row++) {
            for (int col = 0; col < result.GetNumCols(); col++) {
                if (result.GetElement(row, col) != matA.GetElement(row, col)) {
                    INFO("Expected:");
                    INFO(PrintMatrix(matA));
                    INFO("----------");
                    INFO("Actual:")
                    INFO(PrintMatrix(result));
                    INFO("----------------------------");
                    INFO("Elements did not match at ");
                    INFO("row: " << row);
                    INFO("col: " << col);
                    INFO("..Expected: " << matA.GetElement(row, col));
                    INFO("....Actual: " << result.GetElement(row, col));
                    FAIL();
                }
            }
        }
    }
}

TEST_CASE("operator==") {
    MatrixT matA;
    MatrixT matB;
    MatrixT matC;

    Load_Matrices("unit_tests/equal_matrix.txt", matA, matB, matC);

    MatrixT matD;
    MatrixT matE;
    MatrixT matF;
    Load_Matrices("unit_tests/equal_matrix.txt", matD, matE, matF);

    if (!(matA == matD)) {
        INFO("Expected matricies to be equal");
        INFO("\"==\" returned false");
        FAIL();
    }

    if (!(matB == matE)) {
        INFO("Expected matricies to be equal");
        INFO("\"==\" returned false");
        FAIL();
    }

    if (!(matC == matF)) {
        INFO("Expected matricies to be equal");
        INFO("\"==\" returned false");
        FAIL();
    }

    if (matA == matB) {
        INFO("Expected matricies to NOT be equal");
        INFO("\"==\" returned false");
        FAIL();
    }

    if (matB == matC) {
        INFO("Expected matricies to NOT be equal");
        INFO("\"==\" returned false");
        FAIL();
    }
}