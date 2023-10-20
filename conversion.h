#ifndef CONVERSION_H_
#define CONVERSION_H_
#include <iostream>

using namespace std;
namespace myLib
{
    class UnitConversion
    {
    public:
        double inchesToCentimeters(double inches)
        {
            return inches * 2.54;
        }

        double inchesToMeters(double inches)
        {
            return inches * 0.0254;
        }

        double centimetersToInches(double cm)
        {
            return cm / 2.54;
        }

        double metersToInches(double meters)
        {
            return meters / 0.0254;
        }

        void performUnitConversion()
        {
            while (true)
            {
                int choice;
                double value;

                cout << "\nChoose unit conversion:\n";
                cout << "1. Inches to Centimeters\n";
                cout << "2. Inches to Meters\n";
                cout << "3. Centimeters to Inches\n";
                cout << "4. Meters to Inches\n";
                cout << "0. Back to previous menu\n";
                cout << "Enter your choice (0/1/2/3/4): ";
                cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 4)
                {
                    cout << "\nEnter the value to convert: ";
                    cin >> value;

                    switch (choice)
                    {
                    case 1:
                        cout << endl
                             << value << " inches is equal to " << inchesToCentimeters(value) << " centimeters.\n";
                        break;
                    case 2:
                        cout << endl
                             << value << " inches is equal to " << inchesToMeters(value) << " meters.\n";
                        break;
                    case 3:
                        cout << endl
                             << value << " centimeters is equal to " << centimetersToInches(value) << " inches.\n";
                        break;
                    case 4:
                        cout << endl
                             << value << " meters is equal to " << metersToInches(value) << " inches.\n";
                        break;
                    }
                }
                else
                {
                    cout << endl
                         << "Invalid choice for unit conversion. Please enter 0, 1, 2, 3, or 4.\n";
                }
            }
        }
    };

    class TemperatureConversion
    {
    public:
        double Celsius_to_Fahrenheit(double celsius)
        {
            return (celsius * 9 / 5) + 32;
        }

        double Fahrenheit_to_Celsius(double fahrenheit)
        {
            return (fahrenheit - 32) * 5 / 9;
        }

        void performTemperatureConversion()
        {
            while (true)
            {
                int choice;
                double value;

                cout << "\nChoose temperature conversion:\n";
                cout << "1. Celsius to Fahrenheit\n";
                cout << "2. Fahrenheit to Celsius\n";
                cout << "0. Back to previous menu\n";
                cout << "Enter your choice (0/1/2): ";
                cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice == 1 || choice == 2)
                {
                    cout << "\nEnter the temperature value to convert: ";
                    cin >> value;

                    if (choice == 1)
                    {
                        cout << endl
                             << value << " Celsius is equal to " << Celsius_to_Fahrenheit(value) << " Fahrenheit.\n\n";
                    }
                    else if (choice == 2)
                    {
                        cout << endl
                             << value << " Fahrenheit is equal to " << Fahrenheit_to_Celsius(value) << " Celsius.\n\n";
                    }
                }
                else
                {
                    cout << endl
                         << "Invalid choice for temperature conversion. Please enter 0, 1, or 2.\n\n";
                }
            }
        }
    };

}

#endif
