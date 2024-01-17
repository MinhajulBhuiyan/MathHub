#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <cmath>

using namespace std;

namespace Graph
{

    double round(double number)
    {
        return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
    }
    double evaluateFunction(double x, char operation, double constant)
    {
        switch (operation)
        {
        case '+':
            return x + constant;
        case '-':
            return x - constant;
        case '*':
            return x * constant;
        case '/':
            return x / constant;
        default:
            cerr << "Invalid operation: " << operation << endl;
            return 0;
        }
    }
    static string axis = "+ ";
    static string line = "* ";
    static string graph = "  ";

    class GraphGenerator
    {

    public:
        static void performGraph()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int size = 25;
                double step = (1);

                int *values = new int[size + size + 1];
                string input;
                cout << "Enter the equation or enter q to go back: ";
                getline(cin, input);

                if(input == "q")
                {
                    break;
                }

                if (input == "x")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = x;
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "-x")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = -x;
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "x^2")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = x * x;
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    };
                }
                else if (input == "-x^2")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = -x * x;
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "x^3")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = x * x * x;
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "-x^3")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = -x * x * x;
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "tan(x)")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = tan(x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "sin(x)")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = sin(x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "cos(x)")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = cos(x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "tan(-x)")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = tan(-x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "sin(-x)")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = sin(-x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "cos(-x)")
                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        x = x * step;
                        // EQUATION
                        double value = cos(-x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }

                else if (input == "ln(x)")

                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = log(x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "ln(-x)")

                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = log(-x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "log(x)")

                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = log10(x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "log(-x)")

                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = log10(-x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "e^x")

                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = exp(x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }
                else if (input == "e^-x")

                {
                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));
                        // EQUATION
                        double value = exp(-x);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }

                else
                {
                    char operation;
                    double constant;

                    for (char c : input)
                    {
                        if (c == '+' || c == '-' || c == '*' || c == '/')
                        {
                            operation = c;
                        }
                        if (c != 'x' && c != '+' && c != '-' && c != '*' && c != '/')
                        {
                            constant = c - '0';
                        }
                    }

                    // Graph::EquationProcessor equationProcessor;

                    for (int i = 0; i < size + size + 1; ++i)
                    {
                        double x = (i - (size));

                        // EQUATION
                        double value = evaluateFunction(x, operation, constant);
                        // EQUATION
                        value = value / step;
                        values[i] = int(round(value));
                    }
                }

                for (int i = 0; i < size / 16; ++i)
                {
                    cout << endl;
                }

                for (int i = 0; i < size; ++i)
                {
                    for (int b = 0; b < size; ++b)
                    {
                        if (size - i == values[b])
                            cout << line;
                        else
                            cout << graph;
                    }

                    if (size - i == values[size])
                        cout << line;
                    else
                        cout << axis;

                    for (int b = 0; b < size; ++b)
                    {
                        if (size - i == values[b + size + 1])
                            cout << line;
                        else
                            cout << graph;
                    }
                    cout << endl;
                }

                for (int i = 0; i < size * 2 + 1; ++i)
                {
                    if (0 == values[i])
                        cout << line;
                    else
                        cout << axis;
                }
                cout << endl;

                for (int i = 0; i < size; ++i)
                {
                    for (int b = 0; b < size; ++b)
                    {
                        if (0 - i - 1 == values[b])
                            cout << line;
                        else
                            cout << graph;
                    }
                    if (0 - i - 1 == values[size])
                        cout << line;
                    else
                        cout << axis;

                    for (int b = 0; b < size; ++b)
                    {
                        if (0 - i - 1 == values[b + size + 1])
                            cout << line;
                        else
                            cout << graph;
                    }
                    cout << endl;
                }

                delete[] values;
                cout << "\nPress Enter to continue...";
                cin.get(); // This line will read the Enter keypress
            }
        }
    };
}

#endif
