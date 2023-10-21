#ifndef TRIGONOMETRY_H_
#define TRIGONOMETRY_H_
#include <iostream>
#include <cmath>
#include <iomanip>

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

        void performTrigonometry()
        {
            while (true)
            {
                int choice;
                double angleInDegrees;

                std::cout << "\nChoose trigonometric function:\n";
                std::cout << "1. Sine\n";
                std::cout << "2. Cosine\n";
                std::cout << "3. Tangent\n";
                std::cout << "0. Back to the previous menu\n";
                std::cout << "Enter your choice (0/1/2/3): ";
                std::cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 3)
                {
                    std::cout << "\nEnter the angle in degrees: ";
                    std::cin >> angleInDegrees;

                    switch (choice)
                    {
                    case 1:
                    {
                        double result = sinDegrees(angleInDegrees);
                        if (std::abs(result) < 1e-15)
                        {
                            result = 0.0;
                        }
                        std::cout << "Sine(" << angleInDegrees << ") = " << std::fixed << result << std::endl;
                        break;
                    }
                    case 2:
                    {
                        double result = cosDegrees(angleInDegrees);
                        if (std::abs(result) < 1e-15)
                        {
                            result = 0.0;
                        }
                        std::cout << "Cosine(" << angleInDegrees << ") = " << std::fixed << result << std::endl;
                        break;
                    }
                    case 3:
                    {
                        double result = tanDegrees(angleInDegrees);
                        if (std::abs(result) < 1e-15)
                        {
                            result = 0.0;
                        }
                        std::cout << "Tangent(" << angleInDegrees << ") = " << std::fixed << result << std::endl;
                        break;
                    }
                    }
                }
                else
                {
                    std::cout << "\nInvalid choice for the trigonometric function. Please enter 0, 1, 2, or 3.\n";
                }
            }
        }
    };
}
#endif
