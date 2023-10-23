#ifndef CONVERSION_H_
#define CONVERSION_H_
#include <iostream>

using namespace std;
namespace unit
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
        double mphTokmph(double mph)
        {
            return mph * 1.60934;
        }

        double kmphToMph(double kmph)
        {
            return kmph / 1.60934;
        }

        double mpsTokmph(double mps)
        {
            return mps * 3.6;
        }

        double kmphToMps(double kmph)
        {
            return kmph / 3.6;
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
                cout << "\n\nChoose a conversion type:\n\n";
                cout << "1. Length Conversion\n";
                cout << "2. Temperature Conversion\n";
                cout << "3. Weight Conversion\n";
                cout << "4. Speed Conversion\n";
                cout << "5. Pressure Conversion\n";
                cout << "0. Exit\n\n\n";
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
                    cout << "Invalid choice. Please enter a valid option.\n\n\n";
                    break;
                }
            }
        }

    private:
        void performLengthConversions()
        {
            unit::LengthConversion lengthConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\n\nLength Conversion Menu:\n\n";
                cout << "1. in -> cm\n";
                cout << "2. cm -> in\n";
                cout << "3. ft -> m\n";
                cout << "4. m -> ft\n";
                cout << "5. yd -> m\n";
                cout << "6. m -> yd\n";
                cout << "7. mile -> km\n";
                cout << "8. km -> mile\n";
                cout << "9. n mile -> mile\n";
                cout << "10. mile -> n mile\n";
                cout << "0. Back to Main Menu\n\n";
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
                    cout << "\n\n\n"
                         << value << " in = " << lengthConversion.inchesToCentimeters(value) << " cm.\n\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n"
                         << value << " cm = " << lengthConversion.centimetersToInches(value) << " in.\n\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n"
                         << value << " ft = " << lengthConversion.feetToMeters(value) << " m.\n\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n"
                         << value << " m = " << lengthConversion.metersToFeet(value) << " ft.\n\n\n\n";
                    break;
                case 5:
                    cout << "\n\n\n"
                         << value << " yd = " << lengthConversion.yardsToMeters(value) << " m.\n\n\n\n";
                    break;
                case 6:
                    cout << "\n\n\n"
                         << value << " m = " << lengthConversion.metersToYards(value) << " yd.\n\n\n\n";
                    break;
                case 7:
                    cout << "\n\n\n"
                         << value << " mile = " << lengthConversion.milesToKilometers(value) << " km.\n\n\n\n";
                    break;
                case 8:
                    cout << "\n\n\n"
                         << value << " km = " << lengthConversion.kilometersToMiles(value) << " mile.\n\n\n\n";
                    break;
                case 9:
                    cout << "\n\n\n"
                         << value << " n mile = " << lengthConversion.nauticalMilesToMiles(value) << " mile.\n\n\n\n";
                    break;
                case 10:
                    cout << "\n\n\n"
                         << value << " mile = " << lengthConversion.milesToNauticalMiles(value) << " n mile.\n\n\n\n";
                    break;
                default:
                    cout << "\n\n\n"
                         << "Invalid choice. Please enter a valid option.\n\n";
                    break;
                }
            }
        }

        void performTemperatureConversions()
        {
            unit::TemperatureConversion tempConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nTemperature Conversion Menu:\n";
                cout << "1. C -> F\n\n";
                cout << "2. F -> C\n";
                cout << "3. C -> K\n";
                cout << "4. K -> C\n";
                cout << "5. F -> K\n";
                cout << "6. K -> F\n";
                cout << "0. Back to Main Menu\n\n";
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
                    cout << "\n\n\n"
                         << value << " C = " << tempConversion.CelsiusToFahrenheit(value) << " F.\n\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n"
                         << value << " F = " << tempConversion.FahrenheitToCelsius(value) << " C.\n\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n"
                         << value << " C = " << tempConversion.CelsiusToKelvin(value) << " K.\n\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n"
                         << value << " K = " << tempConversion.KelvinToCelsius(value) << " C.\n\n\n\n";
                    break;
                case 5:
                    cout << "\n\n\n"
                         << value << " F = " << tempConversion.FahrenheitToKelvin(value) << " K.\n\n\n\n";
                    break;
                case 6:
                    cout << "\n\n\n"
                         << value << " K = " << tempConversion.KelvinToFahrenheit(value) << " F.\n\n\n\n";
                    break;
                default:
                    cout << "\n\n\n"
                         << "Invalid choice. Please enter a valid option.\n\n";
                    break;
                }
            }
        }

        void performWeightConversions()
        {
            unit::WeightConversion weightConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nWeight Conversion Menu:\n\n";
                cout << "1. lb -> kg\n";
                cout << "2. kg -> lb\n";
                cout << "3. oz -> g\n";
                cout << "4. g -> oz\n";
                cout << "0. Back to Main Menu\n\n";
                cout << "Enter your choice (0-4): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "\n\nEnter the weight value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << "\n\n\n"
                         << value << " lb = " << weightConversion.poundsToKilograms(value) << " kg.\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n"
                         << value << " kg = " << weightConversion.kilogramsToPounds(value) << " lb.\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n"
                         << value << " oz = " << weightConversion.ouncesToGrams(value) << " g.\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n"
                         << value << " g = " << weightConversion.gramsToOunces(value) << " oz.\n\n\n";
                    break;
                default:
                    cout << "\n\n\n"
                         << "Invalid choice. Please enter a valid option.\n\n";
                    break;
                }
            }
        }

        void performSpeedConversions()
        {
            unit::SpeedConversion speedConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nSpeed Conversion Menu:\n\n";
                cout << "1. mph -> kmph\n";
                cout << "2. kmph -> mph\n";
                cout << "3. m/s -> kmph\n";
                cout << "4. kmph -> m/s\n";
                cout << "0. Back to Main Menu\n\n";
                cout << "Enter your choice (0-4): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "\n\nEnter the speed value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << "\n\n\n"
                         << value << " mph = " << speedConversion.mphTokmph(value) << " kmph.\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n"
                         << value << " kmph = " << speedConversion.kmphToMph(value) << " mph.\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n"
                         << value << " m/s = " << speedConversion.mpsTokmph(value) << " kmph.\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n"
                         << value << " kmph = " << speedConversion.kmphToMps(value) << " m/s.\n\n\n";
                    break;
                default:
                    cout << "\n\n\n"
                         << "Invalid choice. Please enter a valid option.\n\n";
                    break;
                }
            }
        }

        void performPressureConversions()
        {
            unit::PressureConversion pressureConversion;
            int subChoice;
            double value;

            while (true)
            {
                cout << "\nPressure Conversion Menu:\n\n";
                cout << "1. Pa -> atm\n";
                cout << "2. atm -> Pa\n";
                cout << "3. mmHg -> Pa\n";
                cout << "4. Pa -> mmHg\n";
                cout << "0. Back to Main Menu\n\n";
                cout << "Enter your choice (0-4): ";
                cin >> subChoice;

                if (subChoice == 0)
                {
                    break; // Return to the main menu
                }

                cout << "\n\nEnter the pressure value to convert: ";
                cin >> value;

                switch (subChoice)
                {
                case 1:
                    cout << "\n\n\n"
                         << value << " Pa = " << pressureConversion.paToAtm(value) << " atm.\n\n\n";
                    break;
                case 2:
                    cout << "\n\n\n"
                         << value << " atm = " << pressureConversion.atmToPa(value) << " Pa.\n\n\n";
                    break;
                case 3:
                    cout << "\n\n\n"
                         << value << " mmHg = " << pressureConversion.mmHgToPa(value) << " Pa.\n\n\n";
                    break;
                case 4:
                    cout << "\n\n\n"
                         << value << " Pa = " << pressureConversion.paToMmHg(value) << " mmHg.\n\n\n";
                    break;
                default:
                    cout << "\n\n\n"
                         << "Invalid choice. Please enter a valid option.\n\n";
                    break;
                }
            }
        }
    };
}

#endif
