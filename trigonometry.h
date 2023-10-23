#ifndef TRIGONOMETRY_H_
#define TRIGONOMETRY_H_
#include <iostream>



using namespace std;

namespace trigonometry
{
    const double PI = 3.14159265358979323846;
    const int ANGLE_MULTIPLIER = 1000; // Adjust this for desired precision

    class Trigonometry
    {
    public:
        // Convert degrees to radians
        double degreesToRadians(double degrees)
        {
            return degrees * PI / 180.0;
        }

        double factorial(int n)
        {
            double fact = 1.0;
            for (int i = 2; i <= n; ++i)
            {
                fact *= i;
            }
            return fact;
        }

        // Calculate sine using degrees
        double sinDegrees(double degrees)
        {
            double x = degreesToRadians(degrees); // Convert angle from degrees to radians
            double result = 0.0;
            for (int i = 0; i < 50; ++i)
            {
                result += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
            }
            return result;
        }

        // Calculate cosine using degrees
        double cosDegrees(double degrees)
        {
            return sinDegrees(90.0 - degrees); // Use the relationship between sine and cosine
        }

        // Calculate tangent using degrees
        double tanDegrees(double degrees)
        {
            double sine = sinDegrees(degrees);
            double cosine = cosDegrees(degrees);

            if (cosine < 1e-10 && cosine > -1e-10)
            {
                cerr << "Error: tan(" << degrees << ") is undefined (division by zero)." << endl;
                return 1.0 / 0.0; // Return positive infinity for undefined values
            }

            return sine / cosine;
        }

        // Calculate arcsine (inverse sine) using approximation
        double asinNormal(double value)
        {
            if (value < -1.0 || value > 1.0)
            {
                cerr << "Error: asin(" << value << ") is undefined (out of range)." << endl;
                return NAN; // Return NaN for undefined values
            }
            else if (value == -1.0)
            {
                return -90.0; // arcsin(-1) is -90 degrees
            }
            else if (value == 1.0)
            {
                return 90.0; // arcsin(1) is 90 degrees
            }
            else
            {

                double result = value;
                double term = value;
                int n = 1;

                while (fabs(term) > 1e-15)
                {
                    term *= (value * value * (2 * n - 1) * (2 * n - 1)) / ((2 * n) * (2 * n + 1));
                    result += term;
                    n++;
                }

                return result * 180.0 / PI;
            }
        }

        // Calculate arccosine (inverse cosine) using approximation
        double acosNormal(double value)
        {
            if (value < -1.0 || value > 1.0)
            {
                cerr << "Error: arccos(" << value << ") is undefined (out of range)." << endl;
                return NAN; // Return NaN for undefined values
            }
            else if (value == -1.0)
            {
                return 180.0; // arccos(-1) is 180 degrees
            }
            else if (value == 1.0)
            {
                return 0.0; // arccos(1) is 0 degrees
            }
            else
            {
                return 90.0 - asinNormal(value);
            }
        }

        // Calculate arctangent (inverse tangent) using approximation
        double atanNormal(double value)
        {
            if (value == 0.0)
            {
                return 0.0; // arctan(0) is 0 degrees
            }
            else if (value == -1.0)
            {
                return -45.0; // arctan(-1) is -45 degrees
            }
            else
            {
                double result = asinNormal(value / sqrt(1 + value * value));
                return result;
            }
        }

        void performTrigonometry()
        {
            while (true)
            {
                int choice;
                double angle;

                std::cout << "\nChoose trigonometric function:\n";
                std::cout << "1. Sine\n";
                std::cout << "2. Cosine\n";
                std::cout << "3. Tangent\n";
                std::cout << "4. Arcsine\n";
                std::cout << "5. Arccosine\n";
                std::cout << "6. Arctan\n";
                std::cout << "0. Back to the previous menu\n";
                std::cout << "Enter your choice (0/1/2/3/4/5/6): ";
                std::cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 6)
                {
                    std::cout << "Enter the angle or value: ";
                    std::cin >> angle;

                    switch (choice)
                    {
                    case 1:
                    {
                        double result = sinDegrees(angle);
                        if (std::abs(result) < 1e-15)
                        {
                            result = 0.0;
                        }
                        std::cout << "Sine(" << angle << ") = " << std::fixed << result << std::endl;
                        break;
                    }
                    case 2:
                    {
                        double result = cosDegrees(angle);
                        if (std::abs(result) < 1e-15)
                        {
                            result = 0.0;
                        }
                        std::cout << "Cosine(" << angle << ") = " << std::fixed << result << std::endl;
                        break;
                    }
                    case 3:
                    {
                        double result = tanDegrees(angle);
                        if (std::abs(result) < 1e-15)
                        {
                            result = 0.0;
                        }
                        std::cout << "Tangent(" << angle << ") = " << std::fixed << result << std::endl;
                        break;
                    }
                    case 4:
                    {
                        double result = asinNormal(angle);
                        if (std::isnan(result))
                        {
                            std::cout << "arcsin(" << angle << ") is undefined (out of range)." << endl;
                        }
                        else
                        {
                            std::cout << "arcsin(" << angle << ") = " << std::fixed << result << " degrees" << std::endl;
                        }
                        break;
                    }
                    case 5:
                    {
                        double result = acosNormal(angle);
                        if (std::isnan(result))
                        {
                            std::cout << "arccos(" << angle << ") is undefined (out of range)." << endl;
                        }
                        else
                        {
                            std::cout << "arccos(" << angle << ") = " << std::fixed << result << " degrees" << std::endl;
                        }
                        break;
                    }
                    case 6:
                    {
                        double result = atanNormal(angle);
                        std::cout << "arctan(" << angle << ") = " << std::fixed << result << " degrees" << std::endl;
                        break;
                    }
                    }
                }
                else
                {
                    std::cout << "\nInvalid choice for the trigonometric function. Please enter 0, 1, 2, 3, 4, 5, or 6.\n";
                }
            }
        }
    };
}

#endif
