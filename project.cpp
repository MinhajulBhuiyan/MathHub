#include <iostream>
#include "Conversion.h"
#include "Trigonometry.h"
#include "graph.h"

using namespace std;
using namespace myLib; // Assuming you have both Conversion and Trigonometry namespaces in separate headers
using namespace Plotter;

int main()
{
    string libraryChoice;

    while (true)
    {
        cout << "Choose a library ('trigonometry,' 'unit conversion,' 'temperature,' 'graph' or 'exit' to quit): ";
        getline(cin, libraryChoice);

        if (libraryChoice == "exit")
        {
            break;
        }
        else if (libraryChoice == "trigonometry")
        {
            myLib2::Trigonometry trigonometry;
            trigonometry.performTrigonometry();
        }
        else if (libraryChoice == "unit conversion")
        {
            UnitConversion unitConversion;
            unitConversion.performUnitConversion();
        }
        else if (libraryChoice == "temperature")
        {
            TemperatureConversion temperatureConversion;
            temperatureConversion.performTemperatureConversion();
        }
        else if (libraryChoice == "graph")
        {
            ASCIIArtPlotter asciiArtPlotter;
            asciiArtPlotter.HandleUserInstructions();
        }
        else
        {
            cout << "Invalid library choice. Please enter 'trigonometry,' 'unit conversion,' 'temperature,' 'graph' or 'exit'." << endl;
        }
    }

    return 0;
}
