#include <bits/stdc++.h>

using namespace std;

namespace StatisticsLibrary
{
    double calculateStandardDeviation(const vector<double> &numbers, double mean)
    {
        double sumOfSquaredDifferences = 0.0;

        for (double num : numbers)
        {
            sumOfSquaredDifferences += pow(num - mean, 2);
        }

        double variance = sumOfSquaredDifferences / numbers.size();
        return sqrt(variance);
    }

    string getClassRange(double value, double rangeSize)
    {
        int lowerBound = static_cast<int>(floor(value / rangeSize) * rangeSize);
        int upperBound = static_cast<int>(lowerBound + rangeSize);

        return to_string(lowerBound) + "-" + to_string(upperBound - 1);
    }

    class StatisticsManager
    {
    private:
        double maximum;
        double minimum;

    public:
        StatisticsManager() : maximum(0.0), minimum(0.0) {}

        void performStatistics()
        {
#ifdef _WIN32
            system("cls"); // Clear the console screen for Windows
#endif

            cout << "Enter a series of numbers (enter a non-numeric value to stop):" << endl;

            vector<double> numbers;
            double input;

            // Read numbers until a non-numeric value is entered
            while (cin >> input)
            {
                numbers.push_back(input);
            }

            // Check if at least one number is entered
            if (numbers.empty())
            {
                cerr << "No numbers entered. Exiting." << endl;

                // Clear the input stream to avoid issues
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Pause to see the message before returning
                cout << "\nPress Enter to continue...";
                cin.get(); // This line will read the Enter keypress

                return; // Return without performing statistics
            }

            // Clear the input stream to avoid issues
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Calculate statistics
            double sum = 0.0;
            double average, mean, standardDeviation;

            // Calculate sum
            for (double num : numbers)
            {
                sum += num;
            }

            // Calculate average
            average = sum / numbers.size();

            // Calculate mean
            mean = numbers[numbers.size() / 2];

            // Calculate maximum and minimum
            maximum = *max_element(numbers.begin(), numbers.end());
            minimum = *min_element(numbers.begin(), numbers.end());

            // Calculate standard deviation
            standardDeviation = calculateStandardDeviation(numbers, mean);

            // Display results
            cout << "\nStatistics:\n";
            cout << "\n---------------------------------------------\n";
            cout << "Average: " << average << endl;
            cout << "Mean: " << mean << endl;
            cout << "Maximum: " << maximum << endl;
            cout << "Minimum: " << minimum << endl;
            cout << "Standard Deviation: " << standardDeviation << endl;
            cout << "\n---------------------------------------------\n";

            // Determine the range size dynamically based on the input values
            double rangeSize = pow(10, floor(log10(maximum - minimum) - 1));

            // Calculate and display tally with specified class ranges
            map<string, int> tally;
            for (double num : numbers)
            {
                string classRange = getClassRange(num, rangeSize);
                tally[classRange]++;
            }

            cout << "\nTally with Class Ranges:\n";
            cout << "\n---------------------------------------------\n";
            cout << setw(20) << "Class Range" << setw(10) << "Frequency" << endl;

            for (const auto &entry : tally)
            {
                cout << setw(20) << entry.first << setw(10) << entry.second << endl;
            }

            // Pause to see the results before returning
            cout << "\nPress Enter to continue...";
            cin.get(); // This line will read the Enter keypress
        }
    };
}