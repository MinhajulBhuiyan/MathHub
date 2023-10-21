#ifndef QUANTATIVE_H_
#define QUANTATIVE_H_
#include <iostream>

using namespace std;
namespace quantative
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
            // Calculate the base and height using Heron's formula
            double s = 0.5 * (side1 + side2 + side3);
            base = (2.0 / side1) * sqrroot(s * (s - side1) * (s - side2) * (s - side3));
            height = (2.0 * base) / side1;
        }

    public:
        double sqrroot(double value)
        {
            double x = value;
            double prev = 0.0;
            while (x - prev > 0.00001)
            {
                prev = x;
                x = 0.5 * (x + value / x);
            }
            return x;
        }

        double calculateArea()
        {
            return 0.5 * base * height;
        }

        double calculatePerimeter()
        {
            return side1 + side2 + side3;
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

        void calculateTriangleProperties()
        {
            double side1, side2, side3;

            // Input the sides of the triangle from the user
            cout << "Enter the lengths of the three sides of the triangle:\n";
            cout << "Side 1: ";
            cin >> side1;
            cout << "Side 2: ";
            cin >> side2;
            cout << "Side 3: ";
            cin >> side3;

            // Create a Triangle object
            Triangle triangle(side1, side2, side3);

            // Calculate and display the properties of the triangle
            cout << "Triangle Properties:\n";
            cout << "Area: " << triangle.calculateArea() << endl;
            cout << "Perimeter: " << triangle.calculatePerimeter() << endl;

            if (triangle.isRightAngle())
        {
            cout << "Right-angled" << endl;
        }

        if (triangle.isEquilateral())
        {
            cout << "Equilateral" << endl;
        }

        if (triangle.isAcuteAngle())
        {
            cout << "Acute-angled" << endl;
        }
        if (triangle.isObtuseAngle())
        {
            cout << "Obtuse-angled" << endl;
        }

        if (triangle.isScalene())
        {
            cout << "Scalene" << endl;
        }
        }
    };
}

#endif
