#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "MatrixManipulation.h"
#include "Quantitative.h"
#include "Logarithm.h"
#include "Statistics.h"
#include "physics_formula.h"
#include "Graph.h"
#include "Arithmetic.h" 

using namespace std;
using namespace unit;
using namespace trigonometry;
using namespace MatrixLibrary;
using namespace quantitative;
using namespace logarithm;
using namespace StatisticsLibrary;
using namespace physics;
using namespace Graph;
using namespace arithmetic; 
int main()
{
    string libraryChoice;

    while (true)
    {
#ifdef _WIN32
        system("cls");
#endif

        cout << "Choose a library:\n"
                "1. Arithmetic\n"
                "2. Trigonometry\n"
                "3. Unit conversion\n"
                "4. Matrix Manipulation\n"
                "5. Quantitative Operation\n"
                "6. Logarithmic Functions\n"
                "7. Statistics\n"
                "8. Physics Formula\n"
                "9. Graph\n"
                "0. Exit\n";
        cout << "\nEnter the corresponding number (or 0 to Exit): ";

        getline(cin, libraryChoice);

        if (libraryChoice == "0")
        {
            break;
        }
        else if (libraryChoice == "1")
        {
            // Include arithmetic calculations here
            CalculatorManager calculatorManager;
            calculatorManager.performCalculation();
        }
        else if (libraryChoice == "2")
        {
            Trigonometry trigonometry;
            trigonometry.performTrigonometry();
        }
        else if (libraryChoice == "3")
        {
            ConversionManager conversionManager;
            conversionManager.performConversions();
        }
        else if (libraryChoice == "4")
        {
            MatrixManager matrix;
            matrix.performMatrixOperation();
        }
        else if (libraryChoice == "5")
        {
            QuantitativeManager quantitativeManager;
            quantitativeManager.performQuantitative();
        }
        else if (libraryChoice == "6")
        {
            Logarithm logarithm;
            logarithm.performLogarithms();
        }
        else if (libraryChoice == "7")
        {
            StatisticsManager statisticsManager;
            statisticsManager.performStatistics();
        }
        else if (libraryChoice == "8")
        {
            PhysicsFormulasManager physicsFormulasManager;
            physicsFormulasManager.performPhysicsCalculations();
        }
        else if (libraryChoice == "9")
        {
            GraphGenerator graphgenerator;
            graphgenerator.performGraph();
        }
        else
        {
            cout << "Invalid library choice. Please enter a valid number (or 0 to Exit).\n";
        }
    }

    return 0;
}