#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "matrixManipulation.h"

using namespace std;
using namespace myLib; // Assuming you have both Conversion and Trigonometry namespaces in separate headers

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
            myLib2::Trigonometry trigonometry;
            trigonometry.performTrigonometry();
        }
        else if (libraryChoice == "unit")
        {
            ConversionManager conversionManager;
            conversionManager.performConversions();
        }
        // else if (libraryChoice == "temp")
        // {
        //     TemperatureConversion temperatureConversion;
        //     temperatureConversion.performTemperatureConversion();
        // }
        else if (libraryChoice == "mat")
        {
            MatrixLibrary::MatrixManager matrix ;
            matrix.chooseMatrixOperation();
        }
        else
        {
            cout << "Invalid library choice. Please enter 'tri,' 'unit,' 'temp,' 'mat' or 'exit'." << endl;
        }
    }

    return 0;
}
