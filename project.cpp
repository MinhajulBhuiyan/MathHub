#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "matrixManipulation.h"
#include "quantitative.h"

using namespace std;
using namespace unit;
using namespace trigonometry;
using namespace MatrixLibrary;
using namespace quantitative;

int main()
{
    string libraryChoice;

    while (true)
    {

        cout << "Choose a library\n\n1. Trigonometry\n2. Unit conversion\n3. Matrix Manipulation\n4. Quantitative Operation\n0. Exit\n";
        cout << "\nPlease enter [ 1/2/3/4/0 ]: ";
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
            matrix.chooseMatrixOperation();
        }

        else if (libraryChoice == "4")
        {
            QuantitativeManager quantitativeManager;
            quantitativeManager.performQuantitative();
        }

        else
        {
            cout << "Invalid library choice. Please enter [ 1/2/3/4/0 ]" << endl;
        }
    }

    return 0;
}
