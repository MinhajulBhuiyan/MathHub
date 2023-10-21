#ifndef QUANTATITIVE_H_
#define QUANTATITIVE_H_
#include <iostream>
#include <cmath>

using namespace std;
namespace quantitative
{
    class Triangle
    {
    private:
        double base;
        double height;
        double side1;
        double side2;
        double side3;

    public:
        // Constructor for three sides
        Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3)
        {
        }

    public:
        double customSqrt(double x, double epsilon = 1e-6)
        {
            if (x < 0)
            {
                std::cerr << "Error: Cannot calculate the square root of a negative number." << std::endl;
                return -1.0; // You can choose to handle the error differently if needed.
            }

            if (x == 0)
            {
                return 0;
            }

            double guess = x; // Initial guess

            while (true)
            {
                double newGuess = 0.5 * (guess + x / guess); // Newton-Raphson iteration
                if (std::abs(newGuess - guess) < epsilon)
                {
                    return newGuess;
                }
                guess = newGuess;
            }
        }

        double calculateArea()
        {
            double s = (calculatePerimeter() / 2.0);
            return customSqrt(s * (s - side1) * (s - side2) * (s - side3));
        }

        double calculatePerimeter()
        {
            return side1 + side2 + side3;
        }

        void calculateAngles(double &angleA, double &angleB, double &angleC) const
        {
            double a = side1;
            double b = side2;
            double c = side3;

            angleA = acos((b * b + c * c - a * a) / (2.0 * b * c)) * (180.0 / M_PI);
            angleB = acos((c * c + a * a - b * b) / (2.0 * c * a)) * (180.0 / M_PI);
            angleC = 180.0 - angleA - angleB;
        }

        bool isRightAngle()
        {
            return (side1 * side1 + side2 * side2 == side3 * side3) ||
                   (side1 * side1 + side3 * side3 == side2 * side2) ||
                   (side2 * side2 + side3 * side3 == side1 * side1);
        }

        bool isAcuteAngle()
        {
            double a = side1 * side1;
            double b = side2 * side2;
            double c = side3 * side3;
            return (a + b > c) && (a + c > b) && (b + c > a);
        }

        bool isObtuseAngle()
        {
            double a = side1 * side1;
            double b = side2 * side2;
            double c = side3 * side3;
            return (a + b < c) || (a + c < b) || (b + c < a);
        }

        bool isEquilateral()
        {
            return (side1 == side2) && (side2 == side3);
        }

        bool isIsosceles()
        {
            return (side1 == side2) || (side1 == side3) || (side2 == side3);
        }

        bool isScalene()
        {
            return (side1 != side2) && (side1 != side3) && (side2 != side3);
        }
    };

    class QuantitativeManager
    {
    public:
        void performQuantitative()
        {
            int choice;

            while (true)
            {
                cout << "\n\nChoose a Shape:\n\n";
                cout << "1. Triangle\n";
                cout << "2. Quadrilateral\n";
                cout << "3. Circle\n";
                cout << "0. Exit\n\n\n";
                cout << "Enter your choice (0-3): ";
                cin >> choice;

                if (choice == 0)
                {
                    break; // Exit the program
                }

                switch (choice)
                {
                case 1:
                    calculateTriangleProperties();
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n\n\n";
                    break;
                }
            }
        }

    private:
        void calculateTriangleProperties()
        {
            double side1, side2, side3;

            // Input the sides of the triangle from the user
            cout << "Enter the lengths of the three sides of the triangle:\n";

            cin >> side1;
            cin >> side2;
            cin >> side3;

            // Check if the sides can form a triangle
            if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
            {
                // Create a Triangle object
                Triangle triangle(side1, side2, side3);

                // Calculate and display the properties of the triangle
                cout << "\n\nTriangle Properties:\n";
                cout << "Area: " << triangle.calculateArea() << endl;
                cout << "Perimeter: " << triangle.calculatePerimeter() << endl << endl;

                double angleA, angleB, angleC;
                triangle.calculateAngles(angleA, angleB, angleC);
                cout << "Angles of the triangle (in degrees)\n";
                cout << "<A: " << angleA << ", ";
                cout << "<B: " << angleB << ", ";
                cout << "<C: " << angleC << "." << endl;

                if (triangle.isRightAngle())
                {
                    cout << "Right-angled & ";
                }
                if (triangle.isAcuteAngle())
                {
                    cout << "Acute-angled & ";
                }
                if (triangle.isObtuseAngle())
                {
                    cout << "Obtuse-angled & ";
                }

                if (triangle.isEquilateral())
                {
                    cout << "Equilateral Triangle\n" << endl;
                }
                if (triangle.isScalene())
                {
                    cout << "Scalene Triangle\n" << endl;
                }
                if (triangle.isIsosceles())
                {
                    cout << "Isosceles Triangle\n" << endl;
                }
            }
            else
            {
                cout << "These side lengths cannot build a triangle." << endl;
            }
        }
    };
}

#endif
