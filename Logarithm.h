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

            while (std::abs(numerator) > 1e-15)
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

            while (std::abs(term) > 1e-15)
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
                int choice;
                double value;

                std::cout << "\nChoose mathematical function:\n";
                std::cout << "1. Natural Logarithm (ln)\n";
                std::cout << "2. Exponential Function (e^x)\n";
                std::cout << "0. Back to the previous menu\n";
                std::cout << "Enter your choice (0/1/2): ";
                std::cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 2)
                {
                    std::cout << "Enter the value: ";
                    std::cin >> value;

                    switch (choice)
                    {
                    case 1:
                    {
                        double result = customNaturalLog(value);
                        if (std::isnan(result))
                        {
                            std::cout << "Custom Natural logarithm is undefined for x <= 0." << std::endl;
                        }
                        else
                        {
                            std::cout << "ln(" << value << ") = " << result << std::endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        double result = customExpFunction(value);
                        std::cout << "e^" << value << " = " << result << std::endl;
                        break;
                    }
                    }
                }
                else
                {
                    std::cout << "\nInvalid choice for the mathematical function. Please enter 0, 1, or 2.\n";
                }
            }
        }
    };
}

#endif
