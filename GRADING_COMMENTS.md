

**Points for Assignment 11**

**Grading rubric (20 points possible)**

| Points | Requirements |
|----------|----------|
|2|Default constructor ``MatrixT()`` correctly defined in MatrixT.cpp (autograded).
|2|Constructor ``MatrixT(int rowSize, int colSize)`` correctly defined in MatrixT.cpp (autograded).
|1|Get and Set functions for Rows and Columns correctly defined in MatrixT.cpp (autograded).
|1|Get and Set functions for Elements correctly defined in MatrixT.cpp (autograded).
|2|Overloaded ``operator+`` correctly defined in MatrixT.cpp (autograded).
|2|Overloaded ``operator-`` correctly defined in MatrixT.cpp (autograded).
|2|Overloaded ``operator*`` correctly defined in MatrixT.cpp (autograded).
|2|Overloaded ``operator=`` correctly defined in MatrixT.cpp (autograded).
|2|Overloaded ``operator==`` correctly defined in MatrixT.cpp (autograded).
|2|Clear preconditions and postconditions written for all overloaded operators and member functions in MatrixT.h.
|2|Good coding practices followed for all 3 parts, including: self-commenting variable names, one statement per line, no more than 80 characters per line, properly indenting inside braces/loops/if statements, and including descriptive comments explaining changes with each commit and push to GitHub (manually graded).


**Your scores**


Autograded portion:  14/16
Manually graded portion: 3/4
Total: 17/20

Make sure you write clear and precise preconditions.  
Your precondition should clearly state what initial conditions are required for that function to run,
such as identifying specific variables that must be initialized. The postcondition should describe what happens after the function executes.
For example, in your function GetElement
int GetElement(int rowInd, int colInd);
    //pre: user inputs a row index value and a column index value
   the preconditon should be "rowInd and colInd must be initialized to valid int values"
   
   

| Part| Points Possible | Points Earned| Comments|
|----------|-----|----| -------|
|Good coding practices followed| 2| 2 | Nice work! |
|Clear preconditions and postconditions written | 2| 1 | partial |
