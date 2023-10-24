#ifndef CUSTOM_MATH_FUNCTIONS_H_
#define CUSTOM_MATH_FUNCTIONS_H_

#include <iostream>

namespace logarithm
{

    class Logarithm
    {
    public:
        // Calculate natural logarithm (ln)
        double customNaturalLog(double x)
        {
            if (x <= 0)
            {
                return NAN;
            }

            if (x == 1.0)
            {
                return 0.0;
            }

            double result = 0.0;
            double term = (x - 1) / (x + 1);
            double term_squared = term * term;
            double numerator = term;
            int n = 1;

            while (abs(numerator) > 1e-15)
            {
                result += numerator / n;
                numerator *= term_squared;
                n += 2;
            }

            return 2 * result;
        }

        // Calculate the exponential function (e^x)
        double customExpFunction(double x)
        {
            double result = 1.0;
            double term = 1.0;
            double factorial = 1.0;
            int n = 1;

            while (abs(term) > 1e-15)
            {
                term *= x / n;
                result += term;
                n++;
            }

            return result;
        }

        void performLogarithms()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int choice;
                double value;

                cout << "Choose Logarithmic function:\n\n";
                cout << "1. Natural Logarithm (ln)\n";
                cout << "2. Exponential Function (e^x)\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0/1/2): ";
                cin >> choice;

                system("clear");

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 2)
                {

                    switch (choice)
                    {
                    case 1:
                    {
                        cout << "ln()" ;
                        cout << "\nEnter the value: ";
                        cin >> value;
                        double result = customNaturalLog(value);
                        if (isnan(result))
                        {
                            cout << "\nError !!!\nCustom Natural logarithm is undefined for x <= 0." << endl;
                        }
                        else
                        {
                            cout << "\n---------------------------------------------\nln(" << value << ") = " << result << "\n---------------------------------------------" << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "e^()" ;
                        cout << "\nEnter the value: ";
                        cin >> value;
                        double result = customExpFunction(value);
                        cout << "\n---------------------------------------------\ne^" << value << " = " << result << "\n---------------------------------------------" << endl;
                        break;
                    }
                    }

                    // Wait for the user to press Enter before proceeding
                    cout << "\nPress Enter to continue...";
                    cin.ignore(); // Consume the newline character
                    cin.get();    // This line will wait for the user to press Enter
                }
                else
                {
                    cout << "\nInvalid choice for the mathematical function. Please enter 0, 1, or 2.\n";
                }
            }
        }
    };
}

#endif