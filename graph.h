#include <iostream>
#include <string>

namespace Plotter
{
    const int Width = 80;   // Width of the console
    const int Height = 20;  // Height of the console
    const double XMin = -5; // Minimum x-value
    const double XMax = 5;  // Maximum x-value

    class ASCIIArtPlotter
    {
    public:
        // Function to calculate y-values for a given function
        double CalculateYValue(const std::string &function, double x)
        {
            // Parse the user-provided function and calculate y
            // This is a simplified parser and calculator
            // You can extend it to handle more complex functions
            double y = 0.0;
            // Example: y = 2*x + 1
            size_t xPos = function.find("x");
            if (xPos != std::string::npos)
            {
                std::string expr = function.substr(0, xPos);
                double coefficient = std::stod(expr);
                y = coefficient * x + 1;
            }
            return y;
        }

        // Function to plot the graph
        void PlotGraph(const std::string &function)
        {
            for (int row = 0; row < Height; ++row)
            {
                double y = static_cast<double>(row) / Height; // Map row to y-value
                double x = XMin + y * (XMax - XMin);          // Map y to x-value

                // Calculate the corresponding y-value based on the user's function
                double result = CalculateYValue(function, x);

                // Map x-value to console coordinates
                int col = static_cast<int>((x - XMin) / (XMax - XMin) * Width);

                // Plot the graph using "." for points
                if (col >= 0 && col < Width && result >= 0.0 && result <= 1.0)
                {
                    std::cout << ".";
                }
                else
                {
                    std::cout << " "; // Empty space
                }

                // Move to the next row
                if (row == Height - 1)
                {
                    std::cout << std::endl; // Move to the next line after the last row
                }
            }
        }

        // Function to handle user instructions
        void HandleUserInstructions()
        {
            while (true)
            {
                int choice;
                std::string function;

                std::cout << "\nChoose an option:\n";
                std::cout << "1. Show Graph\n";
                std::cout << "0. Exit\n";
                std::cout << "Enter your choice (0/1): ";
                std::cin >> choice;

                if (choice == 0)
                {
                    break; // Exit the loop
                }
                else if (choice == 1)
                {
                    std::cin.ignore(); // Consume the newline character
                    std::cout << "Enter a function (e.g., 2*x + 1): ";
                    std::getline(std::cin, function);
                    PlotGraph(function);
                }
                else
                {
                    std::cout << "Invalid choice. Please enter 0 or 1.\n";
                }
            }
        }
    };
}
