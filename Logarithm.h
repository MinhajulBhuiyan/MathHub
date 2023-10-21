#ifndef LOGARITHM_H_
#define LOGARITHM_H_

#include <iostream>
#include <cmath>

namespace logarithm {

    class Logarithm {

    public:
        // Calculate natural logarithm (ln)
        double naturalLog(double x) {
            if (x <= 0) {
                std::cerr << "Error: Natural logarithm is undefined for x <= 0." << std::endl;
                return NAN;
            }
            return log(x);
        }

        // Calculate base 10 logarithm (log10)
        double logBase10(double x) {
            if (x <= 0) {
                std::cerr << "Error: Logarithm base 10 is undefined for x <= 0." << std::endl;
                return NAN;
            }
            return log10(x);
        }

        // Calculate a custom base logarithm (log_b(x))
        double customLog(double x, double base) {
            if (x <= 0 || base <= 1) {
                std::cerr << "Error: Custom base logarithm is undefined for x <= 0 or base <= 1." << std::endl;
                return NAN;
            }
            return log(x) / log(base);
        }

        void performLogarithms() {
            while (true) {
                int choice;
                double value;

                std::cout << "\nChoose logarithmic function:\n";
                std::cout << "1. Natural Logarithm (ln)\n";
                std::cout << "2. Logarithm Base 10 (log10)\n";
                std::cout << "3. Custom Base Logarithm (log_b(x))\n";
                std::cout << "0. Back to the previous menu\n";
                std::cout << "Enter your choice (0/1/2/3): ";
                std::cin >> choice;

                if (choice == 0) {
                    break; // Return to the previous menu
                } else if (choice >= 1 && choice <= 3) {
                    std::cout << "Enter the value: ";
                    std::cin >> value;

                    switch (choice) {
                        case 1: {
                            double result = naturalLog(value);
                            if (std::isnan(result)) {
                                std::cout << "Natural logarithm is undefined for x <= 0." << std::endl;
                            } else {
                                std::cout << "ln(" << value << ") = " << result << std::endl;
                            }
                            break;
                        }
                        case 2: {
                            double result = logBase10(value);
                            if (std::isnan(result)) {
                                std::cout << "Logarithm base 10 is undefined for x <= 0." << std::endl;
                            } else {
                                std::cout << "log10(" << value << ") = " << result << std::endl;
                            }
                            break;
                        }
                        case 3: {
                            double base;
                            std::cout << "Enter the base for the custom logarithm: ";
                            std::cin >> base;
                            double result = customLog(value, base);
                            if (std::isnan(result)) {
                                std::cout << "Custom base logarithm is undefined for x <= 0 or base <= 1." << std::endl;
                            } else {
                                std::cout << "log_" << base << "(" << value << ") = " << result << std::endl;
                            }
                            break;
                        }
                    }
                } else {
                    std::cout << "\nInvalid choice for the logarithmic function. Please enter 0, 1, 2, or 3.\n";
                }
            }
        }
    };

}

#endif
