#ifndef CONVERSION_H_
#define CONVERSION_H_
#include <iostream>
#include <map>

using namespace std;
namespace unit
{
    enum class LengthUnit
    {
        Inches,
        Meters,
        Feet,
        Miles,
        Centimeters,
        Kilometers,
        Yards,
        NauticalMiles
    };

    map<string, LengthUnit> unitMap =
        {
            {"in", LengthUnit::Inches},
            {"m", LengthUnit::Meters},
            {"ft", LengthUnit::Feet},
            {"mile", LengthUnit::Miles},
            {"cm", LengthUnit::Centimeters},
            {"km", LengthUnit::Kilometers},
            {"nmile", LengthUnit::NauticalMiles},
            {"yd", LengthUnit::Yards},
    };

    string toLower(const string &str)
    {
        string lowerStr = str;
        for (char &c : lowerStr)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = static_cast<char>(c + 32);
            }
        }
        return lowerStr;
    }

    class LengthConversion
    {

    public:
        LengthConversion(double value, LengthUnit sourceUnit, LengthUnit targetUnit)
        {
            this->value = value;
            this->sourceUnit = sourceUnit;
            this->targetUnit = targetUnit;
        }

        double convert()
        {
            double valueInMeters = convertToMeter();
            double result = 0.0;

            switch (targetUnit)
            {
            case LengthUnit::Inches:
                result = valueInMeters / inchToMeter;
                break;
            case LengthUnit::Meters:
                result = valueInMeters;
                break;
            case LengthUnit::Feet:
                result = valueInMeters / footToMeter;
                break;
            case LengthUnit::Miles:
                result = valueInMeters / mileToMeter;
                break;
            case LengthUnit::Centimeters:
                result = valueInMeters / centimeterToMeter;
                break;
            case LengthUnit::Kilometers:
                result = valueInMeters / kilometerToMeter;
                break;
            case LengthUnit::Yards:
                result = valueInMeters / yardToMeter;
                break;
            case LengthUnit::NauticalMiles:
                result = valueInMeters / nauticalMileToMeter;
                break;
            default:
                cerr << "Unsupported target unit." << endl;
            }

            return result;
        }

    private:
        double value;
        LengthUnit sourceUnit;
        LengthUnit targetUnit;

        const double inchToMeter = 0.0254;
        const double footToMeter = 0.3048;
        const double mileToMeter = 1609.34;
        const double centimeterToMeter = 0.01;
        const double kilometerToMeter = 1000.0;
        const double yardToMeter = 0.9144;
        const double nauticalMileToMeter = 1852.0;

        double convertToMeter()
        {
            switch (sourceUnit)
            {
            case LengthUnit::Inches:
                return value * inchToMeter;
            case LengthUnit::Meters:
                return value;
            case LengthUnit::Feet:
                return value * footToMeter;
            case LengthUnit::Miles:
                return value * mileToMeter;
            case LengthUnit::Centimeters:
                return value * centimeterToMeter;
            case LengthUnit::Kilometers:
                return value * kilometerToMeter;
            case LengthUnit::Yards:
                return value * yardToMeter;
            case LengthUnit::NauticalMiles:
                return value * nauticalMileToMeter;
            default:
                cerr << "Unsupported source unit." << endl;
                return 0.0;
            }
        }
    };

    enum class TemperatureUnit
    {
        Celsius,
        Fahrenheit,
        Kelvin
    };

    map<string, TemperatureUnit> temperatureMap = {
        {"c", TemperatureUnit::Celsius},
        {"f", TemperatureUnit::Fahrenheit},
        {"k", TemperatureUnit::Kelvin}};

    class TemperatureConversion
    {
    public:
        TemperatureConversion(double value, TemperatureUnit sourceUnit, TemperatureUnit targetUnit)
        {
            this->value = value;
            this->sourceUnit = sourceUnit;
            this->targetUnit = targetUnit;
        }

        double convert()
        {
            double kelvinValue = convertToKelvin();
            double result = 0.0;

            switch (targetUnit)
            {
            case TemperatureUnit::Celsius:
                result = kelvinToCelsius(kelvinValue);
                break;
            case TemperatureUnit::Fahrenheit:
                result = kelvinToFahrenheit(kelvinValue);
                break;
            case TemperatureUnit::Kelvin:
                result = kelvinValue;
                break;
            default:
                std::cerr << "Unsupported target unit." << std::endl;
            }

            return result;
        }

    private:
        double value;
        TemperatureUnit sourceUnit;
        TemperatureUnit targetUnit;

        double convertToKelvin()
        {
            double kelvinValue = 0.0;

            switch (sourceUnit)
            {
            case TemperatureUnit::Celsius:
                kelvinValue = celsiusToKelvin(value);
                break;
            case TemperatureUnit::Fahrenheit:
                kelvinValue = fahrenheitToKelvin(value);
                break;
            case TemperatureUnit::Kelvin:
                kelvinValue = value;
                break;
            default:
                std::cerr << "Unsupported source unit." << std::endl;
            }

            return kelvinValue;
        }

        double celsiusToKelvin(double celsius)
        {
            return celsius + 273.15;
        }

        double fahrenheitToKelvin(double fahrenheit)
        {
            double celsius = (fahrenheit - 32) * 5.0 / 9.0;
            return celsius + 273.15;
        }

        double kelvinToCelsius(double kelvin)
        {
            return kelvin - 273.15;
        }

        double kelvinToFahrenheit(double kelvin)
        {
            double celsius = kelvinToCelsius(kelvin);
            return celsius * 9.0 / 5.0 + 32;
        }
    };

    enum class WeightUnit
    {
        Pounds,
        Kilograms,
        Ounces,
        Grams,
        Milligrams
    };

    map<string, WeightUnit> weightMap = {
        {"lb", WeightUnit::Pounds},
        {"kg", WeightUnit::Kilograms},
        {"oz", WeightUnit::Ounces},
        {"g", WeightUnit::Grams},
        {"mg", WeightUnit::Milligrams}};

    class WeightConversion
    {
    public:
        WeightConversion(double value, WeightUnit sourceUnit, WeightUnit targetUnit)
        {
            this->value = value;
            this->sourceUnit = sourceUnit;
            this->targetUnit = targetUnit;
        }

        double convert()
        {
            double valueInKilograms = convertToKilograms();
            double result = 0.0;

            switch (targetUnit)
            {
            case WeightUnit::Pounds:
                result = valueInKilograms * 2.20462; // Conversion factor: Kilograms to Pounds
                break;
            case WeightUnit::Kilograms:
                result = valueInKilograms;
                break;
            case WeightUnit::Ounces:
                result = valueInKilograms * 35.274; // Conversion factor: Kilograms to Ounces
                break;
            case WeightUnit::Grams:
                result = valueInKilograms * 1000; // Conversion factor: Kilograms to Grams
                break;
            case WeightUnit::Milligrams:
                result = valueInKilograms * 1e6; // Conversion factor: Kilograms to Milligrams
                break;
            default:
                cerr << "Unsupported target unit." << endl;
            }

            return result;
        }

    private:
        double value;
        WeightUnit sourceUnit;
        WeightUnit targetUnit;

        double convertToKilograms()
        {
            switch (sourceUnit)
            {
            case WeightUnit::Pounds:
                return value / 2.20462;
            case WeightUnit::Kilograms:
                return value;
            case WeightUnit::Ounces:
                return value / 35.274;
            case WeightUnit::Grams:
                return value / 1000;
            case WeightUnit::Milligrams:
                return value / 1e6;
            default:
                cerr << "Unsupported source unit." << endl;
                return 0.0;
            }
        }
    };

    enum class SpeedUnit
    {
        MetersPerSecond,
        KilometersPerHour,
        MilesPerHour,
        Knots
    };

    map<string, SpeedUnit> speedMap =
        {
            {"mph", SpeedUnit::MilesPerHour},
            {"kmph", SpeedUnit::KilometersPerHour},
            {"mps", SpeedUnit::MetersPerSecond},
            {"knt", SpeedUnit::Knots},
    };

    class SpeedConversion
    {
    public:
        SpeedConversion(double value, SpeedUnit sourceUnit, SpeedUnit targetUnit)
        {
            this->value = value;
            this->sourceUnit = sourceUnit;
            this->targetUnit = targetUnit;
        }

        double convert()
        {
            double valueInMetersPerSecond = convertToMetersPerSecond();
            double result = 0.0;

            switch (targetUnit)
            {
            case SpeedUnit::MetersPerSecond:
                result = valueInMetersPerSecond;
                break;
            case SpeedUnit::KilometersPerHour:
                result = metersPerSecondToKilometersPerHour(valueInMetersPerSecond);
                break;
            case SpeedUnit::MilesPerHour:
                result = metersPerSecondToMilesPerHour(valueInMetersPerSecond);
                break;
            case SpeedUnit::Knots:
                result = metersPerSecondToKnots(valueInMetersPerSecond);
                break;
            default:
                std::cerr << "Unsupported target unit." << std::endl;
            }

            return result;
        }

    private:
        double value;
        SpeedUnit sourceUnit;
        SpeedUnit targetUnit;

        double convertToMetersPerSecond()
        {
            switch (sourceUnit)
            {
            case SpeedUnit::MetersPerSecond:
                return value;
            case SpeedUnit::KilometersPerHour:
                return kilometersPerHourToMetersPerSecond(value);
            case SpeedUnit::MilesPerHour:
                return milesPerHourToMetersPerSecond(value);
            case SpeedUnit::Knots:
                return knotsToMetersPerSecond(value);
            default:
                std::cerr << "Unsupported source unit." << std::endl;
                return 0.0;
            }
        }

        double kilometersPerHourToMetersPerSecond(double kmph)
        {
            return kmph / 3.6;
        }

        double milesPerHourToMetersPerSecond(double mph)
        {
            return mph / 2.23694;
        }

        double knotsToMetersPerSecond(double knots)
        {
            return knots / 1.94384;
        }
        double metersPerSecondToKilometersPerHour(double mps)
        {
            return mps * 3.6;
        }

        double metersPerSecondToMilesPerHour(double mps)
        {
            return mps * 2.23694;
        }

        double metersPerSecondToKnots(double mps)
        {
            return mps * 1.94384;
        }
    };

    enum class PressureUnit
    {
        Pascals,
        Atmospheres,
        Bars,
        MillimetersOfMercury,
        PoundsPerSquareInch
    };

    std::map<std::string, PressureUnit> pressureUnitMap = {
        {"pa", PressureUnit::Pascals},
        {"atm", PressureUnit::Atmospheres},
        {"bar", PressureUnit::Bars},
        {"mmhg", PressureUnit::MillimetersOfMercury},
        {"psi", PressureUnit::PoundsPerSquareInch}};

    class PressureConversion
    {
    public:
        PressureConversion(double value, PressureUnit sourceUnit, PressureUnit targetUnit)
        {
            this->value = value;
            this->sourceUnit = sourceUnit;
            this->targetUnit = targetUnit;
        }

        double convert()
        {
            double valueInPascals = convertToPascals();
            double result = 0.0;

            switch (targetUnit)
            {
            case PressureUnit::Pascals:
                result = valueInPascals;
                break;
            case PressureUnit::Atmospheres:
                result = valueInPascals / atmosphereToPascal;
                break;
            case PressureUnit::Bars:
                result = valueInPascals / barToPascal;
                break;
            case PressureUnit::MillimetersOfMercury:
                result = valueInPascals / mmHgToPascal;
                break;
            case PressureUnit::PoundsPerSquareInch:
                result = valueInPascals / psiToPascal;
                break;
            default:
                std::cerr << "Unsupported target unit." << std::endl;
            }

            return result;
        }

    private:
        double value;
        PressureUnit sourceUnit;
        PressureUnit targetUnit;

        const double atmosphereToPascal = 101325.0;
        const double barToPascal = 100000.0;
        const double mmHgToPascal = 133.322;
        const double psiToPascal = 6894.76;

        double convertToPascals()
        {
            switch (sourceUnit)
            {
            case PressureUnit::Pascals:
                return value;
            case PressureUnit::Atmospheres:
                return value * atmosphereToPascal;
            case PressureUnit::Bars:
                return value * barToPascal;
            case PressureUnit::MillimetersOfMercury:
                return value * mmHgToPascal;
            case PressureUnit::PoundsPerSquareInch:
                return value * psiToPascal;
            default:
                std::cerr << "Unsupported source unit." << std::endl;
                return 0.0;
            }
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
#ifdef _WIN32
            system("cls");
#endif

            double value;
            string sourceUnitStr, targetUnitStr;

            cout << "Give input like this." << endl;
            cout << "'m', 'cm', 'km', 'in', 'ft', 'yd', 'mile', 'nmile'" << endl;
            cout << "\nEnter the source unit: ";
            cin >> sourceUnitStr;

            cout << "Enter the target unit: ";
            cin >> targetUnitStr;

            cout << "\nEnter the value: ";
            cin >> value;

            sourceUnitStr = toLower(sourceUnitStr);
            targetUnitStr = toLower(targetUnitStr);

            cout << "\n---------------------------------------------\n";

            if (unitMap.find(sourceUnitStr) != unitMap.end() && unitMap.find(targetUnitStr) != unitMap.end())
            {
                LengthUnit sourceUnit = unitMap[sourceUnitStr];
                LengthUnit targetUnit = unitMap[targetUnitStr];

                LengthConversion converter(value, sourceUnit, targetUnit);
                double result = converter.convert();

                cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << endl;
            }
            else
            {
                cerr << "Unsupported source or target unit." << endl;
            }

            cout << "---------------------------------------------\n";
            // Wait for the user to press Enter
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();

            // Clear the screen (Unix-like systems)
            system("clear");
        }
        void performTemperatureConversions()
        {
#ifdef _WIN32
            system("cls");
#endif

            double value;
            string sourceUnitStr, targetUnitStr;

            cout << "Give input like this." << endl;
            cout << "'c', 'f', 'k'" << endl;
            cout << "\nEnter the source unit: ";
            cin >> sourceUnitStr;

            cout << "Enter the target unit: ";
            cin >> targetUnitStr;

            cout << "\nEnter the value: ";
            cin >> value;

            sourceUnitStr = toLower(sourceUnitStr);
            targetUnitStr = toLower(targetUnitStr);

            cout << "\n---------------------------------------------\n";

            if (temperatureMap.find(sourceUnitStr) != temperatureMap.end() && temperatureMap.find(targetUnitStr) != temperatureMap.end())
            {
                TemperatureUnit sourceUnit = temperatureMap[sourceUnitStr];
                TemperatureUnit targetUnit = temperatureMap[targetUnitStr];

                TemperatureConversion converter(value, sourceUnit, targetUnit);
                double result = converter.convert();

                cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << endl;
            }
            else
            {
                cerr << "Unsupported source or target unit." << endl;
            }

            cout << "---------------------------------------------\n";
            // Wait for the user to press Enter
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();

            // Clear the screen (Unix-like systems)
            system("clear");
        }

        void performWeightConversions()
        {

#ifdef _WIN32
            system("cls");
#endif

            double value;
            string sourceUnitStr, targetUnitStr;

            cout << "Give input like this." << endl;
            cout << "'mg', 'g', 'kg', 'oz', 'lb'" << endl;
            cout << "\nEnter the source unit: ";
            cin >> sourceUnitStr;

            cout << "Enter the target unit: ";
            cin >> targetUnitStr;

            cout << "\nEnter the value: ";
            cin >> value;

            sourceUnitStr = toLower(sourceUnitStr);
            targetUnitStr = toLower(targetUnitStr);

            cout << "\n---------------------------------------------\n";

            if (weightMap.find(sourceUnitStr) != weightMap.end() && weightMap.find(targetUnitStr) != weightMap.end())
            {
                WeightUnit sourceUnit = weightMap[sourceUnitStr];
                WeightUnit targetUnit = weightMap[targetUnitStr];

                WeightConversion converter(value, sourceUnit, targetUnit);
                double result = converter.convert();

                cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << endl;
            }
            else
            {
                cerr << "Unsupported source or target unit." << endl;
            }

            cout << "---------------------------------------------\n";
            // Wait for the user to press Enter
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();

            // Clear the screen (Unix-like systems)
            system("clear");
        }

        void performSpeedConversions()
        {
#ifdef _WIN32
            system("cls");
#endif

            double value;
            string sourceUnitStr, targetUnitStr;

            cout << "Give input like this." << endl;
            cout << "'mph', 'kmph', 'mps', 'knt'" << endl;
            cout << "\nEnter the source unit: ";
            cin >> sourceUnitStr;

            cout << "Enter the target unit: ";
            cin >> targetUnitStr;

            cout << "\nEnter the value: ";
            cin >> value;

            sourceUnitStr = toLower(sourceUnitStr);
            targetUnitStr = toLower(targetUnitStr);

            cout << "\n---------------------------------------------\n";

            if (speedMap.find(sourceUnitStr) != speedMap.end() && speedMap.find(targetUnitStr) != speedMap.end())
            {
                SpeedUnit sourceUnit = speedMap[sourceUnitStr];
                SpeedUnit targetUnit = speedMap[targetUnitStr];

                SpeedConversion converter(value, sourceUnit, targetUnit);
                double result = converter.convert();

                cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << endl;
            }
            else
            {
                cerr << "Unsupported source or target unit." << endl;
            }

            cout << "---------------------------------------------\n";
            // Wait for the user to press Enter
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();

            // Clear the screen (Unix-like systems)
            system("clear");
        }
        void performPressureConversions()
        {
#ifdef _WIN32
            system("cls");
#endif

            double value;
            string sourceUnitStr, targetUnitStr;

            cout << "Give input like this." << endl;
            cout << "'pa', 'atm', 'bar', 'mmhg', 'psi'" << endl;
            cout << "\nEnter the source unit: ";
            cin >> sourceUnitStr;

            cout << "Enter the target unit: ";
            cin >> targetUnitStr;

            cout << "\nEnter the value: ";
            cin >> value;

            // Convert the user input to lowercase
            sourceUnitStr = toLower(sourceUnitStr);
            targetUnitStr = toLower(targetUnitStr);

            cout << "\n---------------------------------------------\n";

            if (pressureUnitMap.find(sourceUnitStr) != pressureUnitMap.end() && pressureUnitMap.find(targetUnitStr) != pressureUnitMap.end())
            {
                PressureUnit sourceUnit = pressureUnitMap[sourceUnitStr];
                PressureUnit targetUnit = pressureUnitMap[targetUnitStr];

                PressureConversion converter(value, sourceUnit, targetUnit);
                double result = converter.convert();

                cout << value << " " << sourceUnitStr  << " = " << result << " " << targetUnitStr << endl;
            }
            else
            {
                cerr << "Unsupported source or target unit." << endl;
            }

            cout << "---------------------------------------------\n";
            // Wait for the user to press Enter
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();

            // Clear the screen (Unix-like systems)
            system("clear");
        }
    };
}

#endif
