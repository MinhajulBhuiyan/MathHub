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
            double value;
            string sourceUnitStr, targetUnitStr;

            cout << "Give input like this." << endl;
            cout << "'m', 'cm', 'km', 'in', 'ft', 'yd', 'mile', 'nmile'" << endl;
            cout << "Enter the source unit: ";
            cin >> sourceUnitStr;

            cout << "Enter the target unit: ";
            cin >> targetUnitStr;

            cout << "Enter the value: ";
            cin >> value;

            sourceUnitStr = toLower(sourceUnitStr);
            targetUnitStr = toLower(targetUnitStr);

            cout << "------------------------------------------------------------------------------------------------------------------------\n\n";

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

            cout << "\n\n------------------------------------------------------------------------------------------------------------------------\n\n";
        }
void performTemperatureConversions() {
    std::map<std::string, TemperatureUnit> temperatureMap = {
        {"C", TemperatureUnit::Celsius},
        {"F", TemperatureUnit::Fahrenheit},
        {"K", TemperatureUnit::Kelvin}
    };

    while (true) {
        std::cout << "\nTemperature Conversion Menu:\n";
        std::cout << "1. Celsius to Fahrenheit\n";
        std::cout << "2. Fahrenheit to Celsius\n";
        std::cout << "3. Celsius to Kelvin\n";
        std::cout << "4. Kelvin to Celsius\n";
        std::cout << "5. Fahrenheit to Kelvin\n";
        std::cout << "6. Kelvin to Fahrenheit\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter your choice (0-6): ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break; // Return to the main menu
        }

        if (choice < 1 || choice > 6) {
            std::cerr << "Invalid choice. Please enter a valid option.\n";
            continue;
        }

        std::string sourceUnitStr, targetUnitStr;
        double value;

        std::cout << "\nEnter the temperature value to convert: ";
        std::cin >> value;

        if (!std::cin) {
            std::cerr << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
          
            continue;
        }

        std::cout << "Enter the source temperature unit (C, F, or K): ";
        std::cin >> sourceUnitStr;
        std::cout << "Enter the target temperature unit (C, F, or K): ";
        std::cin >> targetUnitStr;

        sourceUnitStr = toLower(sourceUnitStr);
        targetUnitStr = toLower(targetUnitStr);

        if (temperatureMap.find(sourceUnitStr) == temperatureMap.end() ||
            temperatureMap.find(targetUnitStr) == temperatureMap.end()) {
            std::cerr << "Unsupported source or target temperature unit.\n";
            continue;
        }

        TemperatureUnit sourceUnit = temperatureMap[sourceUnitStr];
        TemperatureUnit targetUnit = temperatureMap[targetUnitStr];

        TemperatureConversion converter(value, sourceUnit, targetUnit);
        double result = converter.convert();

        std::cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << "\n";
    }
}


        void performWeightConversions() {
    std::map<std::string, WeightUnit> weightMap = {
        {"lb", WeightUnit::Pounds},
        {"kg", WeightUnit::Kilograms},
        {"oz", WeightUnit::Ounces},
        {"g", WeightUnit::Grams},
        {"mg", WeightUnit::Milligrams}
    };

    while (true) {
        std::cout << "\nWeight Conversion Menu:\n";
        std::cout << "1. Pounds to Kilograms\n";
        std::cout << "2. Kilograms to Pounds\n";
        std::cout << "3. Ounces to Kilograms\n";
        std::cout << "4. Kilograms to Ounces\n";
        std::cout << "5. Grams to Kilograms\n";
        std::cout << "6. Kilograms to Grams\n";
        std::cout << "7. Milligrams to Kilograms\n";
        std::cout << "8. Kilograms to Milligrams\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter your choice (0-8): ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break; // Return to the main menu
        }

        if (choice < 1 || choice > 8) {
            std::cerr << "Invalid choice. Please enter a valid option.\n";
            continue;
        }

        std::string sourceUnitStr, targetUnitStr;
        double value;

        std::cout << "\nEnter the weight value to convert: ";
        std::cin >> value;

        if (!std::cin) {
            std::cerr << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
           
        }

        std::cout << "Enter the source weight unit (lb, kg, oz, g, or mg): ";
        std::cin >> sourceUnitStr;
        std::cout << "Enter the target weight unit (lb, kg, oz, g, or mg): ";
        std::cin >> targetUnitStr;

        sourceUnitStr = toLower(sourceUnitStr);
        targetUnitStr = toLower(targetUnitStr);

        if (weightMap.find(sourceUnitStr) == weightMap.end() ||
            weightMap.find(targetUnitStr) == weightMap.end()) {
            std::cerr << "Unsupported source or target weight unit.\n";
            continue;
        }

        WeightUnit sourceUnit = weightMap[sourceUnitStr];
        WeightUnit targetUnit = weightMap[targetUnitStr];

        WeightConversion converter(value, sourceUnit, targetUnit);
        double result = converter.convert();

        std::cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << "\n";
    }
}

        void performSpeedConversions() {
    std::map<std::string, speedUnit> speedMap = {
        {"m/s", speedUnit::MetersPerSecond},
        {"km/h", speedUnit::KilometersPerHour},
        {"mph", speedUnit::MilesPerHour},
        {"kn", speedUnit::Knots}
    };

    while (true) {
        std::cout << "\nSpeed Conversion Menu:\n";
        std::cout << "1. Meters per Second to Kilometers per Hour\n";
        std::cout << "2. Kilometers per Hour to Meters per Second\n";
        std::cout << "3. Meters per Second to Miles per Hour\n";
        std::cout << "4. Miles per Hour to Meters per Second\n";
        std::cout << "5. Meters per Second to Knots\n";
        std::cout << "6. Knots to Meters per Second\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter your choice (0-6): ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break; // Return to the main menu
        }

        if (choice < 1 || choice > 6) {
            std::cerr << "Invalid choice. Please enter a valid option.\n";
            continue;
        }

        std::string sourceUnitStr, targetUnitStr;
        double value;

        std::cout << "\nEnter the speed value to convert: ";
        std::cin >> value;

        if (!std::cin) {
            std::cerr << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
        }

        std::cout << "Enter the source speed unit (m/s, km/h, mph, or kn): ";
        std::cin >> sourceUnitStr;
        std::cout << "Enter the target speed unit (m/s, km/h, mph, or kn): ";
        std::cin >> targetUnitStr;

        sourceUnitStr = toLower(sourceUnitStr);
        targetUnitStr = toLower(targetUnitStr);

        if (speedMap.find(sourceUnitStr) == speedMap.end() ||
            speedMap.find(targetUnitStr) == speedMap.end()) {
            std::cerr << "Unsupported source or target speed unit.\n";
            continue;
        }

        speedUnit sourceUnit = speedMap[sourceUnitStr];
        speedUnit targetUnit = speedMap[targetUnitStr];

        SpeedConversion converter;
        double result = 0.0;

        // Perform the specified speed conversion based on the user's choice
        switch (choice) {
            case 1:
                result = converter.mpsTokmph(value);
                break;
            case 2:
                result = converter.kmphToMph(value);
                break;
            case 3:
                result = converter.mpsToMph(value);
                break;
            case 4:
                result = converter.MphTomps(value);
                break;
            case 5:
                result = converter.mpsToKnots(value);
                break;
            case 6:
                result = converter. knotsTomps(value);
                break;
        }

        std::cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << "\n";
    }
}
void performPressureConversions() {
    std::map<std::string, PressureUnit> pressureMap = {
        {"Pa", PressureUnit::Pascals},
        {"atm", PressureUnit::Atmospheres},
        {"bar", PressureUnit::Bars},
        {"mmHg", PressureUnit::MillimetersOfMercury},
        {"psi", PressureUnit::PoundsPerSquareInch}
    };

    while (true) {
        std::cout << "\nPressure Conversion Menu:\n";
        std::cout << "1. Pascals to Atmospheres\n";
        std::cout << "2. Atmospheres to Pascals\n";
        std::cout << "3. Pascals to Bars\n";
        std::cout << "4. Bars to Pascals\n";
        std::cout << "5. Pascals to Millimeters of Mercury\n";
        std::cout << "6. Millimeters of Mercury to Pascals\n";
        std::cout << "7. Pascals to Pounds per Square Inch\n";
        std::cout << "8. Pounds per Square Inch to Pascals\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter your choice (0-8): ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break; // Return to the main menu
        }

        if (choice < 1 || choice > 8) {
            std::cerr << "Invalid choice. Please enter a valid option.\n";
            continue;
        }

        std::string sourceUnitStr, targetUnitStr;
        double value;

        std::cout << "\nEnter the pressure value to convert: ";
        std::cin >> value;

        if (!std::cin) {
            std::cerr << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
        }

        std::cout << "Enter the source pressure unit (Pa, atm, bar, mmHg, or psi): ";
        std::cin >> sourceUnitStr;
        std::cout << "Enter the target pressure unit (Pa, atm, bar, mmHg, or psi): ";
        std::cin >> targetUnitStr;

        sourceUnitStr = toLower(sourceUnitStr);
        targetUnitStr = toLower(targetUnitStr);

        if (pressureMap.find(sourceUnitStr) == pressureMap.end() ||
            pressureMap.find(targetUnitStr) == pressureMap.end()) {
            std::cerr << "Unsupported source or target pressure unit.\n";
            continue;
        }

        PressureUnit sourceUnit = pressureMap[sourceUnitStr];
        PressureUnit targetUnit = pressureMap[targetUnitStr];

        PressureConversion converter(value, sourceUnit, targetUnit);
        double result = converter.convert();

        std::cout << value << " " << sourceUnitStr << " = " << result << " " << targetUnitStr << "\n";
    }
}

    };
}

#endif
