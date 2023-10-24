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
                cerr << "\nUnsupported target unit." << endl;
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
   
    enum class TemperatureUnit {
    Celsius,
    Fahrenheit,
    Kelvin
};

std::map<std::string, TemperatureUnit> temperatureMap = {
    {"C", TemperatureUnit::Celsius},
    {"F", TemperatureUnit::Fahrenheit},
    {"K", TemperatureUnit::Kelvin}
};

class TemperatureConversion {
public:
    TemperatureConversion(double value, TemperatureUnit sourceUnit, TemperatureUnit targetUnit)
        : value(value), sourceUnit(sourceUnit), targetUnit(targetUnit) {}

    double convert() {
        double result = 0.0;

        switch (targetUnit) {
            case TemperatureUnit::Celsius:
                result = convertToCelsius();
                break;
            case TemperatureUnit::Fahrenheit:
                result = convertToFahrenheit();
                break;
            case TemperatureUnit::Kelvin:
                result = convertToKelvin();
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

    double convertToCelsius() {
        if (sourceUnit == TemperatureUnit::Celsius) {
            return value;
        } else if (sourceUnit == TemperatureUnit::Fahrenheit) {
            return (value - 32) * 5.0 / 9.0;
        } else if (sourceUnit == TemperatureUnit::Kelvin) {
            return value - 273.15;
        } else {
            std::cerr << "Unsupported source unit." << std::endl;
            return 0.0;
        }
    }

    double convertToFahrenheit() {
        if (sourceUnit == TemperatureUnit::Fahrenheit) {
            return value;
        } else if (sourceUnit == TemperatureUnit::Celsius) {
            return (value * 9.0 / 5.0) + 32;
        } else if (sourceUnit == TemperatureUnit::Kelvin) {
            double celsius = value - 273.15;
            return (celsius * 9.0 / 5.0) + 32;
        } else {
            std::cerr << "Unsupported source unit." << std::endl;
            return 0.0;
        }
    }

    double convertToKelvin() {
        if (sourceUnit == TemperatureUnit::Kelvin) {
            return value;
        } else if (sourceUnit == TemperatureUnit::Celsius) {
            return value + 273.15;
        } else if (sourceUnit == TemperatureUnit::Fahrenheit) {
            double celsius = (value - 32) * 5.0 / 9.0;
            return celsius + 273.15;
        } else {
            std::cerr << "Unsupported source unit." << std::endl;
            return 0.0;
        }
    }
};
    enum class WeightUnit {
    Pounds,
    Kilograms,
    Ounces,
    Grams,
    Milligrams
};



class WeightConversion {
public:
    WeightConversion(double value, WeightUnit sourceUnit, WeightUnit targetUnit) {
        this->value = value;
        this->sourceUnit = sourceUnit;
        this->targetUnit = targetUnit;
    }

    double convert() {
        double valueInKilograms = convertToKilograms();
        double result = 0.0;

        switch (targetUnit) {
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
                std::cerr << "Unsupported target unit." << std::endl;
        }

        return result;
    }

private:
    double value;
    WeightUnit sourceUnit;
    WeightUnit targetUnit;

    double convertToKilograms() {
        switch (sourceUnit) {
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
                std::cerr << "Unsupported source unit." << std::endl;
                return 0.0;
        }
    }
    
};
    enum speedUnit
    {
        MilesPerHour,
        KilometersPerHour,
        MetersPerSecond,
        Knots
    };
    map<string, speedUnit> speedMap =
        {
            {"Mph", speedUnit::MilesPerHour},
            {"kmph", speedUnit::KilometersPerHour},
            {"mps", speedUnit::MetersPerSecond},
            {"kn", speedUnit::Knots},
    };
    class SpeedConversion
    {
    public:
        double MphTokmph(double mph)
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

        double kmphTomps(double kmph)
        {
            return kmph / 3.6;
        }
        double mpsToMph(double mps)
        {
            return mps * 2.23694;
        }
        double MphTomps(double mph)
        {
            return mph / 2.23694;
        }
        double mpsToKnots(double mps)
        {
            return mps * 1.94384;
        }
        double knotsTomps(double knots)
        {
            return knots / 1.94384;
        }

        double kilometersPerHourToMetersPerSecond(double kmph)
        {
            return kmphTomps(kmph);
        }

    };
    enum class PressureUnit {
    Pascals,
    Atmospheres,
    Bars,
    MillimetersOfMercury,
    PoundsPerSquareInch
};

std::map<std::string, PressureUnit> pressureUnitMap = {
    {"Pa", PressureUnit::Pascals},
    {"atm", PressureUnit::Atmospheres},
    {"bar", PressureUnit::Bars},
    {"mmHg", PressureUnit::MillimetersOfMercury},
    {"psi", PressureUnit::PoundsPerSquareInch}
};

class PressureConversion {
public:
    PressureConversion(double value, PressureUnit sourceUnit, PressureUnit targetUnit) {
        this->value = value;
        this->sourceUnit = sourceUnit;
        this->targetUnit = targetUnit;
    }

    double convert() {
        double valueInPascals = convertToPascals();
        double result = 0.0;

        switch (targetUnit) {
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

    double convertToPascals() {
        switch (sourceUnit) {
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
#ifdef _WIN32
                system("cls");
#endif

                cout << "Choose a conversion type:\n\n";
                cout << "1. Length Conversion\n";
                cout << "2. Temperature Conversion\n";
                cout << "3. Weight Conversion\n";
                cout << "4. Speed Conversion\n";
                cout << "5. Pressure Conversion\n";
                cout << "0. Back to previous menu\n\n";
                cout << "Enter your choice (0/1/2/3/4/5): ";
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
                    cout << "\nInvalid choice. Please enter a valid option.\n\n";
                    break;
                }

                // Wait for the user to press Enter
                // cout << "Press Enter to continue...";
                // cin.ignore();
                // cin.get();

                // // Clear the screen (Unix-like systems)
                // system("clear");
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

        if (choice == 0) {
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
