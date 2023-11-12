#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
namespace arithmetic
{
    class Calculator
    {
    public:
        double degreesToRadians(double degrees)
        {
            return degrees * M_PI / 180.0;
        }

    public:
        double evaluateTrigonometric(const string &function, double angle)
        {
            if (function == "sin")
            {
                return sin(degreesToRadians(angle));
            }
            else if (function == "cos")
            {
                return cos(degreesToRadians(angle));
            }
            else if (function == "tan")
            {
                return tan(degreesToRadians(angle));
            }
            else
            {
                cout << "\n\nUnsupported function: " << function << endl;
                return 0.0;
            }
        }

    public:
        double evaluateExpression(const string &expression, double a)
        {
            stack<char> operators;
            stack<double> operands;

            size_t pos = 0;
            while (pos < expression.length())
            {
                if (isdigit(expression[pos]) || expression[pos] == '.')
                {
                    size_t endPos = expression.find_first_not_of("0123456789.", pos);
                    string operand = expression.substr(pos, endPos - pos);
                    operands.push(stod(operand));
                    pos = endPos;
                }
                else if (expression[pos] == '(')
                {
                    operators.push(expression[pos]);
                    pos++;
                }
                else if (expression[pos] == ')')
                {
                    while (!operators.empty() && operators.top() != '(')
                    {
                        char op = operators.top();
                        operators.pop();

                        double operand2 = operands.top();
                        operands.pop();

                        double operand1 = operands.top();
                        operands.pop();

                        if (op == '+')
                        {
                            operands.push(operand1 + operand2);
                        }
                        else if (op == '-')
                        {
                            operands.push(operand1 - operand2);
                        }
                        else if (op == '*')
                        {
                            operands.push(operand1 * operand2);
                        }
                        else if (op == '/')
                        {
                            operands.push(operand1 / operand2);
                        }
                        else if (op == '^')
                        {
                            operands.push(pow(operand1, operand2));
                        }
                        else if (op == 'l')
                        {
                            operands.push(log(operand2) / log(operand1)); // Logarithm base operand1 of operand2
                        }
                    }
                    operators.pop(); // Pop the '('
                    pos++;
                }
                else if (expression[pos] == '+' || expression[pos] == '-')
                {
                    while (!operators.empty() && (operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/' || operators.top() == '^' || operators.top() == 'l'))
                    {
                        char op = operators.top();
                        operators.pop();

                        double operand2 = operands.top();
                        operands.pop();

                        double operand1 = operands.top();
                        operands.pop();

                        if (op == '+')
                        {
                            operands.push(operand1 + operand2);
                        }
                        else if (op == '-')
                        {
                            operands.push(operand1 - operand2);
                        }
                        else if (op == '*')
                        {
                            operands.push(operand1 * operand2);
                        }
                        else if (op == '/')
                        {
                            operands.push(operand1 / operand2);
                        }
                        else if (op == '^')
                        {
                            operands.push(pow(operand1, operand2));
                        }
                        else if (op == 'l')
                        {
                            operands.push(log(operand2) / log(operand1)); // Logarithm base operand1 of operand2
                        }
                    }
                    operators.push(expression[pos]);
                    pos++;
                }
                else if (expression[pos] == '*' || expression[pos] == '/' || expression[pos] == '^' || (expression[pos] == 'l' && expression[pos + 1] == 'o' && expression[pos + 2] == 'g'))
                {
                    operators.push(expression[pos]);
                    pos++;
                    if (expression[pos] == 'l' && expression[pos + 1] == 'o' && expression[pos + 2] == 'g')
                    {
                        pos += 2; // Skip 'lo'
                    }
                }
                else if (expression[pos] == 'a')
                {
                    operands.push(a);
                    pos++;
                }
                else
                {
                    // Handle trigonometric functions
                    size_t endPos = expression.find('(', pos);
                    string trigFunction = expression.substr(pos, endPos - pos);
                    pos = endPos + 1; // Skip '('

                    endPos = expression.find(')', pos);
                    string argument = expression.substr(pos, endPos - pos);
                    pos = endPos + 1; // Skip ')'

                    // Evaluate the inner expression before applying the trigonometric function
                    double innerResult = evaluateExpression(argument, a);

                    double result = 0.0;
                    if (trigFunction == "sin")
                    {
                        result = sin(degreesToRadians(innerResult));
                    }
                    else if (trigFunction == "cos")
                    {
                        result = cos(degreesToRadians(innerResult));
                    }
                    else if (trigFunction == "tan")
                    {
                        result = tan(degreesToRadians(innerResult));
                    }
                    else
                    {
                        cout << "\n\nUnsupported function: " << trigFunction << endl;
                        return 0.0;
                    }

                    operands.push(result);
                }
            }

            while (!operators.empty())
            {
                char op = operators.top();
                operators.pop();

                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                if (op == '+')
                {
                    operands.push(operand1 + operand2);
                }
                else if (op == '-')
                {
                    operands.push(operand1 - operand2);
                }
                else if (op == '*')
                {
                    operands.push(operand1 * operand2);
                }
                else if (op == '/')
                {
                    operands.push(operand1 / operand2);
                }
                else if (op == '^')
                {
                    operands.push(pow(operand1, operand2));
                }
                else if (op == 'l')
                {
                    operands.push(log(operand2) / log(operand1)); // Logarithm base operand1 of operand2
                }
            }

            return operands.top();
        }
    };

    class CalculatorManager
    {
    public:
        void performCalculation()
        {
            Calculator calculator;
            cout << "Scientific Calculator\n";
            double a = 0.0;                // Initialize variable to store the previous result
            string previousOperation = ""; // Store the previous operation

            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                cout << "Enter a mathematical expression: ";

                string input;
                getline(cin, input);

                if (input == "exit")
                {
                    break; // Exit the loop if the user enters 'exit'
                }

                if (input == "p")
                {
                    if (!previousOperation.empty())
                    {
                        cout << "\n\nPrevious operation: " << previousOperation << endl;
                    }
                    else
                    {
                        cout << "\n\nNo previous operation available.\n";
                    }
                    continue; // Skip the rest of the loop and ask for a new expression
                }

                double result = 0.0;

                if (input == "a")
                {
                    cout << "Result: " << a << endl;
                }
                else
                {
                    result = calculator.evaluateExpression(input, a);
                    cout << "Result: " << result << endl;

                    // Save the current operation with the result
                    previousOperation = input + " = " + to_string(result);

                    // Save the result for future use
                    a = result;
                }

                // Print the additional line after every operation
                cout << "-------------------------------------" << endl;
                cout << "\nPress Enter to continue...";
                //cin.ignore(); // Consume the newline character
                cin.get();    // This line will wait for the user to press Enter
            }

            cout << "Exiting the calculator. Thank you!\n";
        }
    };
}
#endif
