#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "matrixManipulation.h"
#include "quantitative.h"
#include "Logarithm.h"
#include "Arithmetic.h"

using namespace std;
using namespace unit;
using namespace trigonometry;
using namespace MatrixLibrary;
using namespace quantitative;
using namespace logarithm;
using namespace arithmetic;

int main()
{
    string libraryChoice;

    while (true)
    {
         #ifdef _WIN32
            system("cls");
        #endif

        cout << "Choose a library\n\n1. Trigonometry\n2. Unit conversion\n3. Matrix Manipulation\n4. Quantitative Operation\n5. Logarithmic Functions\n6. Calculator\n0. Exit\n";
        cout << "\nPlease enter [ 1/2/3/4/5/6/0 ]: ";
        getline(cin, libraryChoice);

        if (libraryChoice == "0")
        {
            break;
        }

        else if (libraryChoice == "1")
        {
            Trigonometry trigonometry;
            trigonometry.performTrigonometry();
        }

        else if (libraryChoice == "2")
        {
            ConversionManager conversionManager;
            conversionManager.performConversions();
        }

        else if (libraryChoice == "3")
        {
            MatrixManager matrix;
            matrix.performMatrixOperation();
        }

        else if (libraryChoice == "4")
        {
            QuantitativeManager quantitativeManager;
            quantitativeManager.performQuantitative();
        }
        else if (libraryChoice == "5")
        {
            Logarithm logarithm;
            logarithm.performLogarithms();
        }
        else if (libraryChoice == "6")
        {
            CalculatorManager calculatorManager;
            calculatorManager.performCalculation();
        }
        else
        {
            cout << "Invalid library choice. Please enter [ 1/2/3/4/5/6/0 ]" << endl;
        }
        
    }

    return 0;
}
