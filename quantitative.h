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

    enum QuadrilateralType
    {
        SQUARE,
        RECTANGLE,
        GENERAL
    };

    class Quadrilateral
    {
    private:
        double side1;
        double side2;
        double side3;
        double side4;

    public:
        Quadrilateral(double s1, double s2, double s3, double s4)
            : side1(s1), side2(s2), side3(s3), side4(s4)
        {
            if (side1 > side2)
            {
                double temp = side1;
                side1 = side2;
                side2 = temp;
            }
            if (side2 > side3)
            {
                double temp = side2;
                side2 = side3;
                side3 = temp;
            }
            if (side3 > side4)
            {
                double temp = side3;
                side3 = side4;
                side4 = temp;
            }
            if (side1 > side2)
            {
                double temp = side1;
                side1 = side2;
                side2 = temp;
            }
            if (side2 > side3)
            {
                double temp = side2;
                side2 = side3;
                side3 = temp;
            }
        }

        QuadrilateralType classifyQuadrilateral() const
        {
            if (side1 == side2 && side2 == side3 && side3 == side4)
                return SQUARE;
            else if (side1 == side2 && side3 == side4)
                return RECTANGLE;
            else
                return GENERAL;
        }

        double calculateArea() const
        {
            QuadrilateralType type = classifyQuadrilateral();
            double area = 0;

            if (type == SQUARE)
            {
                area = side1 * side1;
            }
            else if (type == RECTANGLE)
            {
                area = side1 * side3;
            }
            else if (type == GENERAL)
            {
                // Calculate the area for a general quadrilateral here.
                // This would require more complex geometric calculations.
            }

            return area;
        }

        double calculatePerimeter() const
        {
            double perimeter = side1 + side2 + side3 + side4;
            return perimeter;
        }
    };

    class Circle
    {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        double getDiameter() const
        {
            return 2 * radius;
        }

        double getArea() const
        {
            return M_PI * radius * radius; // M_PI is a constant for pi
        }

        double getPerimeter() const
        {
            return 2 * M_PI * radius;
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
#ifdef _WIN32
                system("cls");
#endif

                cout << "Choose a Shape:\n\n";
                cout << "1. Triangle\n";
                cout << "2. Quadrilateral\n";
                cout << "3. Circle\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0/1/2/3): ";
                cin >> choice;

                system("cls");

                if (choice == 0)
                {
                    break; // Exit the program
                }

                switch (choice)
                {
                case 1:
                    calculateTriangleProperties();
                    break;
                case 2:
                    calculateQuadrilateralProperties();
                    break;
                case 3:
                    calculateCircleProperties();
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n\n\n";
                    break;
                }

                cout << "\nPress Enter to continue...";
                cin.get(); // This line will read the Enter keypress
                cin.get(); // This line will wait for an additional Enter keypress
            }
        }

    private:
        void calculateTriangleProperties()
        {
            double side1, side2, side3;

            // Input the sides of the triangle from the user
            cout << "Triangle\n";
            cout << "Enter the lengths of the three sides of the triangle: ";

            cin >> side1;
            cin >> side2;
            cin >> side3;

            cout << "\n---------------------------------------------\n";

            // Check if the sides can form a triangle
            if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
            {
                // Create a Triangle object
                Triangle triangle(side1, side2, side3);

                // Calculate and display the properties of the triangle
                cout << "Triangle Properties:\n\n";
                cout << "Area: " << triangle.calculateArea() << endl;
                cout << "Perimeter: " << triangle.calculatePerimeter() << endl;

                double angleA, angleB, angleC;
                triangle.calculateAngles(angleA, angleB, angleC);
                cout << "Angles of the triangle (in degrees)\n";
                cout << "<A: " << angleA << ", ";
                cout << "<B: " << angleB << ", ";
                cout << "<C: " << angleC << "." << endl;
                cout << "Triangle Type: ";

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
                    cout << "Equilateral."
                         << endl;
                }
                if (triangle.isScalene())
                {
                    cout << "Scalene."
                         << endl;
                }
                if (triangle.isIsosceles())
                {
                    cout << "Isosceles."
                         << endl;
                }
            }
            else
            {
                cout << "These side lengths cannot build a triangle." << endl;
            }

            cout << "---------------------------------------------\n";
        }

    private:
        void calculateQuadrilateralProperties()
        {
            double side1, side2, side3, side4;

            cout << "Quadrilateral\n";
            // Input the sides of the quadrilateral from the user
            cout << "Enter the lengths of the four sides of the quadrilateral: ";

            cin >> side1;
            cin >> side2;
            cin >> side3;
            cin >> side4;

            cout << "\n---------------------------------------------\n";

            // Check if the sides can form a quadrilateral

            Quadrilateral quadrilateral(side1, side2, side3, side4);

            // Determine the type of the quadrilateral
            QuadrilateralType type = quadrilateral.classifyQuadrilateral();

            // Calculate and display the properties of the quadrilateral
            cout << "Quadrilateral Properties:\n\n";
            cout << "Type: ";
            if (type == SQUARE)
                cout << "Square";
            else if (type == RECTANGLE)
                cout << "Rectangle";
            else
                cout << "General";

            cout << "\nArea: " << quadrilateral.calculateArea() << endl;
            cout << "Perimeter: " << quadrilateral.calculatePerimeter() << endl;

            cout << "---------------------------------------------\n";
        }

    private:
        void calculateCircleProperties()
        {
            double radius;

            cout << "Circle\n";
            // Input the radius of the circle from the user
            cout << "Enter the radius of the circle: ";
            cin >> radius;

            cout << "\n---------------------------------------------\n";

            // Check if the radius is non-negative
            if (radius >= 0)
            {
                Circle circle(radius);

                // Calculate and display the properties of the circle
                cout << "Circle Properties:\n\n";
                cout << "Diameter: " << circle.getDiameter() << endl;
                cout << "Area: " << circle.getArea() << endl;
                cout << "Circumference: " << circle.getPerimeter() << endl;
            }
            else
            {
                cout << "The radius of a circle cannot be negative." << endl;
            }

            cout << "---------------------------------------------\n";
        }
    };
}

#endif