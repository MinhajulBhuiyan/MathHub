#ifndef CONVERSION_H_
#define CONVERSION_H_
#include <iostream>

using namespace std;
namespace myLib
{
    class LengthConversion
    {
    public:
        double inchesToCentimeters(double inches)
        {
            return inches * 2.54;
        }

        double centimetersToInches(double cm)
        {
            return cm / 2.54;
        }

        double feetToMeters(double feet)
        {
            return feet * 0.3048;
        }

        double metersToFeet(double meters)
        {
            return meters / 0.3048;
        }

        double yardsToMeters(double yards)
        {
            return yards * 0.9144;
        }

        double metersToYards(double meters)
        {
            return meters / 0.9144;
        }

        double milesToKilometers(double miles)
        {
            return miles / 0.621371;
        }

        double kilometersToMiles(double kilometers)
        {
            return kilometers * 0.621371;
        }

        double nauticalMilesToMiles(double nauticalMiles)
        {
            return nauticalMiles * 1.15078;
        }

        double milesToNauticalMiles(double miles)
        {
            return miles / 1.15078;
        }
    };

    class TemperatureConversion
    {
    public:
        double CelsiusToFahrenheit(double celsius)
        {
            return (celsius * 9 / 5) + 32;
        }

        double FahrenheitToCelsius(double fahrenheit)
        {
            return (fahrenheit - 32) * 5 / 9;
        }

        double CelsiusToKelvin(double celsius)
        {
            return celsius + 273.15; // Conversion factor: Celsius to Kelvin
        }

        double KelvinToCelsius(double kelvin)
        {
            return kelvin - 273.15; // Conversion factor: Kelvin to Celsius
        }

        double FahrenheitToKelvin(double fahrenheit)
        {
            double celsius = FahrenheitToCelsius(fahrenheit);
            return CelsiusToKelvin(celsius);
        }

        double KelvinToFahrenheit(double kelvin)
        {
            double celsius = KelvinToCelsius(kelvin);
            return CelsiusToFahrenheit(celsius);
        }
    };

    class WeightConversion
    {
    public:
        double poundsToKilograms(double pounds)
        {
            return pounds * 0.453592;
        }

        double kilogramsToPounds(double kilograms)
        {
            return kilograms / 0.453592;
        }

        double ouncesToGrams(double ounces)
        {
            return ounces * 28.3495;
        }

        double gramsToOunces(double grams)
        {
            return grams / 28.3495;
        }
    };

    class SpeedConversion
    {
    public:
        double mphToKph(double mph)
        {
            return mph * 1.60934;
        }

        double kphToMph(double kph)
        {
            return kph / 1.60934;
        }

        double mpsToKph(double mps)
        {
            return mps * 3.6;
        }

        double kphToMps(double kph)
        {
            return kph / 3.6;
        }
    };

    class PressureConversion
    {
    public:
        double paToAtm(double pa)
        {
            return pa * 9.86923e-6;
        }

        double atmToPa(double atm)
        {
            return atm / 9.86923e-6;
        }

        double mmHgToPa(double mmHg)
        {
            return mmHg * 133.322;
        }

        double paToMmHg(double pa)
        {
            return pa / 133.322;
        }
    };

    class ConversionManager
    {
    public:
        void performConversions()
        {
            int choice;

            while (true)
            {
                cout << "Choose a conversion type:\n";
                cout << "1. Length Conversion\n";
                cout << "2. Temperature Conversion\n";
                cout << "3. Weight Conversion\n";
                cout << "4. Speed Conversion\n";
                cout << "5. Pressure Conversion\n";
                cout << "0. Exit\n";
                cout << "Enter your choice (0-5): ";
                cin >> choice;

                if (choice == 0)
                {
                    break; // Exit the program
                }

                switch (choice)
                {
                case 1:
                    performLengthConversions();
                    break;
                case 2:
                    performTemperatureConversions();
                    break;
                case 3:
                    performWeightConversions();
                    break;
                case 4:
                    performSpeedConversions();
                    break;
                case 5:
                    performPressureConversions();
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            }
        }

    private:
        void performLengthConversions()
        {
            myLib::LengthConversion lengthConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nLength Conversion Menu:\n\n";
                cout << "1. Inches to Centimeters\n";
                cout << "2. Centimeters to Inches\n";
                cout << "3. Feet to Meters\n";
                cout << "4. Meters to Feet\n";
                cout << "5. Yards to Meters\n";
                cout << "6. Meters to Yards\n";
                cout << "7. Miles to Kilometers\n";
                cout << "8. Kilometers to Miles\n";
                cout << "9. Nautical Miles to Miles\n";
                cout << "10. Miles to Nautical Miles\n";
                cout << "0. Back to Main Menu\n\n\n";
                cout << "Enter your choice (0-10): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "\n\nEnter the value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " inches is equal to " << lengthConversion.inchesToCentimeters(value) << " centimeters.\n\n\n\n\n\n\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " centimeters is equal to " << lengthConversion.centimetersToInches(value) << " inches.\n\n\n\n\n\n\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " feet is equal to " << lengthConversion.feetToMeters(value) << " meters.\n\n\n\n\n\n\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " meters is equal to " << lengthConversion.metersToFeet(value) << " feet.\n\n\n\n\n\n\n\n\n";
                    break;
                case 5:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " yards is equal to " << lengthConversion.yardsToMeters(value) << " meters.\n\n\n\n\n\n\n\n\n";
                    break;
                case 6:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " meters is equal to " << lengthConversion.metersToYards(value) << " yards.\n\n\n\n\n\n\n\n\n";
                    break;
                case 7:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " miles is equal to " << lengthConversion.milesToKilometers(value) << " kilometers.\n\n\n\n\n\n\n\n\n";
                    break;
                case 8:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " kilometers is equal to " << lengthConversion.kilometersToMiles(value) << " miles.\n\n\n\n\n\n\n\n\n";
                    break;
                case 9:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " nautical miles is equal to " << lengthConversion.nauticalMilesToMiles(value) << " miles.\n\n\n\n\n\n\n\n\n";
                    break;
                case 10:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << value << " miles is equal to " << lengthConversion.milesToNauticalMiles(value) << " nautical miles.\n\n\n\n\n\n\n\n\n";
                    break;
                default:
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << "Invalid choice. Please enter a valid option.\n\n\n\n\n\n\n\n\n";
                    break;
                }
            }
        }

        void performTemperatureConversions()
        {
            myLib::TemperatureConversion tempConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nTemperature Conversion Menu:\n\n";
                cout << "1. Celsius to Fahrenheit\n";
                cout << "2. Fahrenheit to Celsius\n";
                cout << "3. Celsius to Kelvin\n";
                cout << "4. Kelvin to Celsius\n";
                cout << "5. Fahrenheit to Kelvin\n";
                cout << "6. Kelvin to Fahrenheit\n";
                cout << "0. Back to Main Menu\n\n\n";
                cout << "Enter your choice (0-6): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "\n\nEnter the temperature value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << "\n\n\n\n\n\n\n\n"
                         << value << " Celsius is equal to " << tempConversion.CelsiusToFahrenheit(value) << " Fahrenheit.\n\n\n\n\n\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n\n\n\n\n\n"
                         << value << " Fahrenheit is equal to " << tempConversion.FahrenheitToCelsius(value) << " Celsius.\n\n\n\n\n\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n\n\n\n\n\n"
                         << value << " Celsius is equal to " << tempConversion.CelsiusToKelvin(value) << " Kelvin.\n\n\n\n\n\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n\n\n\n\n\n"
                         << value << " Kelvin is equal to " << tempConversion.KelvinToCelsius(value) << " Celsius.\n\n\n\n\n\n\n\n";
                    break;
                case 5:
                    cout << "\n\n\n\n\n\n\n\n"
                         << value << " Fahrenheit is equal to " << tempConversion.FahrenheitToKelvin(value) << " Kelvin.\n\n\n\n\n\n\n\n";
                    break;
                case 6:
                    cout << "\n\n\n\n\n\n\n\n"
                         << value << " Kelvin is equal to " << tempConversion.KelvinToFahrenheit(value) << " Fahrenheit.\n\n\n\n\n\n\n\n";
                    break;
                default:
                    cout << "\n\n\n\n\n\n\n\nInvalid choice. Please enter a valid option.\n\n\n\n\n\n\n\n";
                    break;
                }
            }
        }

        void performWeightConversions()
        {
            myLib::WeightConversion weightConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nWeight Conversion Menu:\n";
                cout << "1. Pounds to Kilograms\n";
                cout << "2. Kilograms to Pounds\n";
                cout << "3. Ounces to Grams\n";
                cout << "4. Grams to Ounces\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter your choice (0-4): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "Enter the weight value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << value << " pounds is equal to " << weightConversion.poundsToKilograms(value) << " kilograms.\n";
                    break;
                case 2:
                    cout << value << " kilograms is equal to " << weightConversion.kilogramsToPounds(value) << " pounds.\n";
                    break;
                case 3:
                    cout << value << " ounces is equal to " << weightConversion.ouncesToGrams(value) << " grams.\n";
                    break;
                case 4:
                    cout << value << " grams is equal to " << weightConversion.gramsToOunces(value) << " ounces.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            }
        }

        void performSpeedConversions()
        {
            myLib::SpeedConversion speedConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nSpeed Conversion Menu:\n";
                cout << "1. Miles per Hour to Kilometers per Hour\n";
                cout << "2. Kilometers per Hour to Miles per Hour\n";
                cout << "3. Meters per Second to Kilometers per Hour\n";
                cout << "4. Kilometers per Hour to Meters per Second\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter your choice (0-4): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "Enter the speed value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << value << " miles per hour is equal to " << speedConversion.mphToKph(value) << " kilometers per hour.\n";
                    break;
                case 2:
                    cout << value << " kilometers per hour is equal to " << speedConversion.kphToMph(value) << " miles per hour.\n";
                    break;
                case 3:
                    cout << value << " meters per second is equal to " << speedConversion.mpsToKph(value) << " kilometers per hour.\n";
                    break;
                case 4:
                    cout << value << " kilometers per hour is equal to " << speedConversion.kphToMps(value) << " meters per second.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            }
        }

        void performPressureConversions()
        {
            myLib::PressureConversion pressureConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nPressure Conversion Menu:\n";
                cout << "1. Pascals to Atmospheres\n";
                cout << "2. Atmospheres to Pascals\n";
                cout << "3. Millimeters of Mercury to Pascals\n";
                cout << "4. Pascals to Millimeters of Mercury\n";
                cout << "0. Back to Main Menu\n";
                cout << "Enter your choice (0-4): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "Enter the pressure value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << value << " pascals is equal to " << pressureConversion.paToAtm(value) << " atmospheres.\n";
                    break;
                case 2:
                    cout << value << " atmospheres is equal to " << pressureConversion.atmToPa(value) << " pascals.\n";
                    break;
                case 3:
                    cout << value << " millimeters of mercury is equal to " << pressureConversion.mmHgToPa(value) << " pascals.\n";
                    break;
                case 4:
                    cout << value << " pascals is equal to " << pressureConversion.paToMmHg(value) << " millimeters of mercury.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            }
        }
    };
}

#endif
