#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "matrixManipulation.h"

using namespace std;
using namespace unit; 
using namespace trigonometry;
using namespace MatrixLibrary;

int main()
{
    string libraryChoice;

    while (true)
    {

        cout << "Choose a library ('Trigonometry,' 'Unit conversion,' 'Temperature,' 'Matrix Manipulation' or 'Exit' to Quit): ";
        getline(cin, libraryChoice);

        if (libraryChoice == "exit")
        {
            break;
        }
        
        else if (libraryChoice == "tri")
        {
            Trigonometry trigonometry;
            trigonometry.performTrigonometry();
        }

        else if (libraryChoice == "unit")
        {
            ConversionManager conversionManager;
            conversionManager.performConversions();
        }

        else if (libraryChoice == "mat")
        {
            MatrixManager matrix ;
            matrix.chooseMatrixOperation();
        }

        else
        {
            cout << "Invalid library choice. Please enter 'tri,' 'unit,' 'temp,' 'mat' or 'exit'." << endl;
        }
    }

    return 0;
}
