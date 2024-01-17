#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "matrixManipulation.h"
#include "quantitative.h"
#include "Logarithm.h"
#include "Statistics.h" 
#include "physics_formula.h"

using namespace std;
using namespace unit;
using namespace trigonometry;
using namespace MatrixLibrary;
using namespace quantitative;
using namespace logarithm;
using namespace StatisticsLibrary; 
using namespace physics;

int main()
{
    string libraryChoice;

    while (true)
    {
#ifdef _WIN32
        system("cls");
#endif

        cout << "Choose a library:\n"
                "1. Trigonometry\n"
                "2. Unit conversion\n"
                "3. Matrix Manipulation\n"
                "4. Quantitative Operation\n"
                "5. Logarithmic Functions\n"
                "6. Statistics\n"
                "7. Physics Formula\n"
                "0. Exit\n";
        cout << "\nEnter the corresponding number (or 0 to Exit): ";

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
            StatisticsManager statisticsManager;
            statisticsManager.performStatistics();
        }
        else if (libraryChoice == "7")
        {
            PhysicsFormulasManager physicsFormulasManager;
            physicsFormulasManager.performPhysicsCalculations();
        }
        else
        {
            cout << "Invalid library choice. Please enter a valid number (or 0 to Exit).\n";
        }
    }

    return 0;
}
