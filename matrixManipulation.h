#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

namespace MatrixLibrary
{
    // Function to print a matrix in the specified format
    void printMatrix(const vector<vector<double>> &matrix, const string &matrixName)
    {
        cout << matrixName << ":" << endl;
        for (const auto &row : matrix)
        {
            for (double val : row)
            {
                cout << setw(8) << fixed << setprecision(2) << val;
            }
            cout << endl;
        }
    }
    class MatrixOperations
    {
    public:
        static vector<vector<double>> matrixAddition(const vector<vector<double>> &matrixA, const vector<vector<double>> &matrixB)
        {
            if (matrixA.size() != matrixB.size() || matrixA[0].size() != matrixB[0].size())
            {
                cerr << "Matrix dimensions do not match for addition." << endl;
                exit(1);
            }

            int rows = matrixA.size();
            int cols = matrixA[0].size();
            vector<vector<double>> result(rows, vector<double>(cols, 0.0));

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    result[i][j] = matrixA[i][j] + matrixB[i][j];
                }
            }

            return result;
        }

        static vector<vector<double>> matrixSubtraction(const vector<vector<double>> &matrixA, const vector<vector<double>> &matrixB)
        {
            if (matrixA.size() != matrixB.size() || matrixA[0].size() != matrixB[0].size())
            {
                cerr << "Matrix dimensions do not match for subtraction." << endl;
                exit(1);
            }

            int rows = matrixA.size();
            int cols = matrixA[0].size();
            vector<vector<double>> result(rows, vector<double>(cols, 0.0));

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    result[i][j] = matrixA[i][j] - matrixB[i][j];
                }
            }

            return result;
        }

        static vector<vector<double>> matrixMultiplication(const vector<vector<double>> &matrixA, const vector<vector<double>> &matrixB)
        {
            int rowsA = matrixA.size();
            int colsA = matrixA[0].size();
            int colsB = matrixB[0].size();

            if (colsA != matrixB.size())
            {
                cerr << "Matrix dimensions are not compatible for multiplication." << endl;
                exit(1);
            }

            vector<vector<double>> result(rowsA, vector<double>(colsB, 0.0));

            for (int i = 0; i < rowsA; ++i)
            {
                for (int j = 0; j < colsB; ++j)
                {
                    for (int k = 0; k < colsA; ++k)
                    {
                        result[i][j] += matrixA[i][k] * matrixB[k][j];
                    }
                }
            }

            return result;
        }

        static vector<vector<double>> matrixInversion(const vector<vector<double>> &matrix)
        {
            int rows = matrix.size();
            int cols = matrix[0].size();

            if (rows != cols)
            {
                cerr << "Matrix is not square and cannot be inverted." << endl;
                return {}; // Return an empty matrix to indicate an error.
            }

            vector<vector<double>> result(rows, vector<double>(cols, 0.0));

            if (rows == 2 && cols == 2)
            {
                double det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

                if (det == 0)
                {
                    cerr << "Matrix is not invertible (determinant is zero)." << endl;
                    return {}; // Return an empty matrix to indicate an error.
                }

                result[0][0] = matrix[1][1] / det;
                result[0][1] = -matrix[0][1] / det;
                result[1][0] = -matrix[1][0] / det;
                result[1][1] = matrix[0][0] / det;
            }
            else if (rows == 3 && cols == 3)
            {
                double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

                if (det == 0)
                {
                    cerr << "Matrix is not invertible (determinant is zero)." << endl;
                    return {}; // Return an empty matrix to indicate an error.
                }

                double invDet = 1.0 / det;

                result[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * invDet;
                result[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invDet;
                result[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * invDet;
                result[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invDet;
                result[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invDet;
                result[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) * invDet;
                result[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * invDet;
                result[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) * invDet;
                result[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) * invDet;
            }

            return result;
        }

        static double calculateDeterminant(const vector<vector<double>> &matrix)
        {
            int rows = matrix.size();
            int cols = matrix[0].size();

            if (rows != cols)
            {
                cerr << "Determinant can only be calculated for square matrices." << endl;
                return NAN; // Return NaN to indicate an error.
            }

            if (rows == 2 && cols == 2)
            {
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            }
            else if (rows == 3 && cols == 3)
            {
                return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            }

            cerr << "Determinant can only be calculated for 2x2 or 3x3 matrices." << endl;
            return NAN; // Return NaN to indicate an error.
        }
    };

    // Function to input a matrix
    vector<vector<double>> inputMatrix(int dimension, const string &matrixName)
    {
        vector<vector<double>> matrix(dimension, vector<double>(dimension, 0.0));

        cout << "Enter elements for " << matrixName << " matrix (" << dimension << "x" << dimension << "):" << endl;
        for (int i = 0; i < dimension; ++i)
        {
            for (int j = 0; j < dimension; ++j)
            {
                double val;
                if (!(cin >> val))
                {
                    cerr << "Invalid input. Please enter numeric values." << endl;
                    exit(1);
                }
                matrix[i][j] = val;
            }
        }
        cout << endl;

        return matrix;
    }
    class MatrixManager
    {
    public:
        // Function to choose the matrix operation
        void chooseMatrixOperation()
        {
            while (true)
            {
                int operationChoice;
                cout << "\n\nChoose a matrix operation:\n\n"
                     << endl;
                cout << "1. Matrix Addition" << endl;
                cout << "2. Matrix Subtraction" << endl;
                cout << "3. Matrix Multiplication" << endl;
                cout << "4. Matrix Inversion" << endl;
                cout << "5. Calculate Determinant" << endl;
                cout << "0. Exit\n\n\n";
                cout << "Enter your choice (0/1/2/3/4/5): ";
                cin >> operationChoice;

                if (operationChoice == 0)
                {
                    break; // Exit the program
                }

                if (operationChoice < 1 || operationChoice > 5)
                {
                    cerr << "\n\nInvalid choice for the matrix operation. Please enter 1, 2, 3, 4, or 5.\n"
                         << endl;
                    return;
                }

                int dimension;
                cout << "\nChoose the matrix dimension (2 for 2x2, 3 for 3x3): ";
                cin >> dimension;

                if (dimension < 2 || dimension > 3)
                {
                    cerr << "Invalid matrix dimension. Please enter 2 for 2x2 or 3 for 3x3." << endl;
                    return;
                }

                cin.ignore(); // Consume the newline character after entering dimension.

                vector<vector<double>> matrixA = inputMatrix(dimension, "Matrix A");

                switch (operationChoice)
                {
                case 1:
                {
                    vector<vector<double>> matrixB = inputMatrix(dimension, "Matrix B");
                    vector<vector<double>> resultAddition = MatrixLibrary::MatrixOperations::matrixAddition(matrixA, matrixB);
                    printMatrix(resultAddition, "\n\n\nMatrix A + Matrix B");
                    break;
                }
                case 2:
                {
                    vector<vector<double>> matrixB = inputMatrix(dimension, "Matrix B");
                    vector<vector<double>> resultSubtraction = MatrixLibrary::MatrixOperations::matrixSubtraction(matrixA, matrixB);
                    printMatrix(resultSubtraction, "\n\n\nMatrix A - Matrix B");
                    break;
                }
                case 3:
                {
                    int dimensionB;
                    cout << "Choose the dimension of Matrix B (2 for 2x2, 3 for 3x3): ";
                    cin >> dimensionB;
                    if (dimensionB < 2 || dimensionB > 3)
                    {
                        cerr << "Invalid matrix dimension for Matrix B. Please enter 2 for 2x2 or 3 for 3x3." << endl;
                        return;
                    }
                    cin.ignore();
                    vector<vector<double>> matrixB = inputMatrix(dimensionB, "Matrix B");
                    if (dimension != dimensionB)
                    {
                        cerr << "Matrix dimensions are not compatible for multiplication." << endl;
                        return;
                    }
                    vector<vector<double>> resultMultiplication = MatrixLibrary::MatrixOperations::matrixMultiplication(matrixA, matrixB);
                    printMatrix(resultMultiplication, "\n\n\nMatrix A * Matrix B");
                    break;
                }
                case 4:
                {
                    vector<vector<double>> resultInversion = MatrixLibrary::MatrixOperations::matrixInversion(matrixA);
                    if (!resultInversion.empty())
                    {
                        printMatrix(resultInversion, "Inverse of Matrix A");
                    }
                    break;
                }
                case 5:
                {
                    double determinant = MatrixLibrary::MatrixOperations::calculateDeterminant(matrixA);
                    if (!isnan(determinant))
                    {
                        cout << "\nDeterminant of Matrix A: " << determinant << endl;
                    }
                    break;
                }
                default:
                    cout << "\nInvalid choice. Please enter a valid option.\n\n";
                    break;
                }
            }
        }
    };
}

#endif
