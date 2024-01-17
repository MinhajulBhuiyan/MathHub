#ifndef PHYSICS_FORMULAS_H_
#define PHYSICS_FORMULAS_H_

#include <iostream>
#include <cmath>
#include <iomanip>

namespace physics
{
    class PhysicsFormulas
    {
    public:
        // Kinematics Formulas
        double calculateVelocity(double initialVelocity, double acceleration, double time)
        {
            return initialVelocity + acceleration * time;
        }

        double calculateDisplacement(double initialVelocity, double time, double acceleration)
        {
            return initialVelocity * time + 0.5 * acceleration * pow(time, 2);
        }

        // Dynamics Formulas
        double calculateForce(double mass, double acceleration)
        {
            return mass * acceleration;
        }

        double calculateWeight(double mass)
        {
            const double gravitationalAcceleration = 9.8;
            return mass * gravitationalAcceleration;
        }

        // Energy Formulas
        double calculateKineticEnergy(double mass, double velocity)
        {
            return 0.5 * mass * pow(velocity, 2);
        }

        double calculatePotentialEnergy(double mass, double height)
        {
            const double gravitationalAcceleration = 9.8;
            return mass * gravitationalAcceleration * height;
        }

        // Fluid Dynamics Formulas
        double calculateFluidPressure(double density, double gravity, double height)
        {
            return density * gravity * height;
        }

        double calculateBuoyantForce(double fluidDensity, double displacedVolume, double gravity)
        {
            return fluidDensity * displacedVolume * gravity;
        }

        double calculateFlowRate(double area, double velocity)
        {
            return area * velocity;
        }

        double calculateBernoullisEquation(double pressure, double density, double gravity, double height, double velocity)
        {
            return pressure + 0.5 * density * pow(velocity, 2) + density * gravity * height;
        }

        // Thermodynamics Formulas
        double calculateHeatEnergy(double mass, double specificHeat, double temperatureChange)
        {
            return mass * specificHeat * temperatureChange;
        }

        double calculateWorkDone(double force, double displacement, double angle)
        {
            double angleInRadians = angle * (M_PI / 180.0);

            return force * displacement * cos(angleInRadians);
        }

        double calculateHeatTransfer(double thermalConductivity, double area, double temperatureDifference, double thickness)
        {
            return (thermalConductivity * area * temperatureDifference) / thickness;
        }

        double calculateFirstLawOfThermodynamics(double heatAdded, double workDone)
        {
            return heatAdded - workDone;
        }

        double calculateEntropyChange(double heatTransfer, double temperature)
        {
            return heatTransfer / temperature;
        }

        // Wave Formulas
        double calculateWaveSpeed(double frequency, double wavelength)
        {
            return frequency * wavelength;
        }

        double calculateFrequency(double waveSpeed, double wavelength)
        {
            return waveSpeed / wavelength;
        }

        double calculateWavelength(double waveSpeed, double frequency)
        {
            return waveSpeed / frequency;
        }

        double calculateDopplerEffect(double observedFrequency, double sourceFrequency, double speedOfSound, double observerSpeed, double sourceSpeed)
        {
            return observedFrequency = sourceFrequency * (speedOfSound + observerSpeed) / (speedOfSound + sourceSpeed);
        }

        // Circular Motion Formulas
        double calculateCentripetalAcceleration(double velocity, double radius)
        {
            return pow(velocity, 2) / radius;
        }

        double calculateCentripetalForce(double mass, double velocity, double radius)
        {
            return mass * calculateCentripetalAcceleration(velocity, radius);
        }

        double calculateTangentialVelocity(double radius, double angularVelocity)
        {
            return angularVelocity * radius;
        }

        double calculateAngularVelocity(double tangentialVelocity, double radius)
        {
            return tangentialVelocity / radius;
        }

        // Electricity and Magnetism Formulas
        double calculateOhmsLaw(double voltage, double resistance)
        {
            return voltage / resistance;
        }

        double calculateResistance(double voltage, double current)
        {
            // Use Ohm's Law: R = V / I
            return voltage / current;
        }

        double calculateElectricPower(double voltage, double current)
        {
            // Use the formula: P = VI
            return voltage * current;
        }

        double calculateMagneticField(double magneticForce, double charge, double velocity)
        {
            // Use the formula: B = F / (q * v)
            return magneticForce / (charge * velocity);
        }

        double calculateMagneticForce(double charge, double velocity, double magneticField)
        {
            return charge * velocity * magneticField;
        }

        double calculateMagneticFlux(double magneticField, double area, double angle)
        {
            return magneticField * area * cos(angle);
        }

        double calculateCapacitance(double charge, double voltage)
        {
            return charge / voltage;
        }

        // Optics Formulas
        double calculateSnellsLaw(double incidentAngle, double refractiveIndex1, double refractiveIndex2)
        {
            return asin(sin(incidentAngle) * refractiveIndex1 / refractiveIndex2);
        }

        double calculateLensFormula(double focalLength, double objectDistance)
        {
            return 1.0 / focalLength + 1.0 / objectDistance;
        }

        double calculateMagnification(double imageDistance, double objectDistance)
        {
            return -imageDistance / objectDistance;
        }

        double calculateCriticalAngle(double refractiveIndex1, double refractiveIndex2)
        {
            return asin(refractiveIndex2 / refractiveIndex1);
        }

        double calculateLensMakersEquation(double radiusOfCurvature, double refractiveIndex)
        {
            return (refractiveIndex - 1) * (1.0 / radiusOfCurvature);
        }

        // Atomic Physics Formulas
        double calculateEnergyLevel(double quantumNumber)
        {
            return -13.6 / (quantumNumber * quantumNumber);
        }

        double calculateWavelengthFromEnergy(double energy)
        {
            const double h = 6.626e-34; // Planck's constant
            const double c = 3.0e8;     // Speed of light
            return h / (energy * c);    // Placeholder formula
        }

        // Additional Formulas
        double calculateEscapeVelocity(double gravitationalAcceleration, double radius)
        {
            return sqrt(2 * gravitationalAcceleration * radius);
        }

        double calculateBlackHoleTemperature(double blackHoleMass)
        {
            return (1.0e-27) * blackHoleMass;
        }

        double calculateImpulse(double force, double time)
        {
            return force * time;
        }

        double calculateTorque(double force, double leverArm)
        {
            return force * leverArm;
        }

        double calculatePower(double work, double time)
        {
            return work / time;
        }
        // Gravitation Formulas
        double calculateGravitationalForce(double mass1, double mass2, double distance)
        {
            const double gravitationalConstant = 6.67430e-11;
            return gravitationalConstant * (mass1 * mass2) / pow(distance, 2);
        }

        double calculateGravitationalPotentialEnergy(double mass1, double mass2, double distance)
        {
            const double gravitationalConstant = 6.67430e-11;
            return -(gravitationalConstant * (mass1 * mass2) / distance);
        }

        // Nuclear Physics Formulas
        double calculateNuclearBindingEnergy(double massDeficiency)
        {
            const double speedOfLight = 3.0e8;
            return massDeficiency * pow(speedOfLight, 2);
        }

        double calculateDecayConstant(double halfLife)
        {
            return log(2) / halfLife;
        }

        // Special Relativity Formulas
        double calculateLorentzFactor(double velocity)
        {
            const double speedOfLight = 3.0e8;
            return 1.0 / sqrt(1 - pow(velocity / speedOfLight, 2));
        }

        double calculateTimeDilation(double time, double velocity)
        {
            return time / calculateLorentzFactor(velocity);
        }

        double calculateLengthContraction(double length, double velocity)
        {
            return length * calculateLorentzFactor(velocity);
        }

        // Quantum Mechanics Formulas
        double calculateWavefunction(double amplitude, double position, double wavelength, double time)
        {
            return amplitude * sin(2 * M_PI * position / wavelength - 2 * M_PI * time);
        }

        double calculateUncertainty(double momentum, double position)
        {
            return momentum * position;
        }

        // Astrophysics Formulas
        double calculateEscapeVelocityAstro(double gravitationalConstant, double mass, double radius)
        {
            return sqrt(2 * gravitationalConstant * mass / radius);
        }

        double calculateLuminosity(double brightness, double distance)
        {
            return 4 * M_PI * pow(distance, 2) * brightness;
        }
        // Quantum Mechanics Formulas
        double calculateComptonWavelength(double momentum)
        {
            const double h_bar = 1.0545718e-34;
            const double speedOfLight = 3.0e8;
            return h_bar / (momentum / speedOfLight);
        }

        double calculateQuantumTunnelingProbability(double barrierHeight, double particleEnergy, double particleMass)
        {
            const double h_bar = 1.0545718e-34;
            const double tunnelingConstant = 2.0;

            return exp(-2 * tunnelingConstant * sqrt(2 * particleMass * barrierHeight) / h_bar);
        }

        double calculateDragForce(double dragCoefficient, double density, double velocity, double area)
        {
            return 0.5 * dragCoefficient * density * pow(velocity, 2) * area;
        }

        // Optics Formulas
        double calculateFocalLengthMirror(double radius)
        {
            return radius / 2;
        }

        double calculateFocalLengthLens(double lensPower)
        {
            const double focalLengthMeterInverse = lensPower; // Assuming lens power is in diopters
            return 1.0 / focalLengthMeterInverse;
        }

        // Statistical Mechanics Formulas
        double calculateBoltzmannEntropy(double probability)
        {
            return -log(probability);
        }

        double calculateMaxwellBoltzmannDistribution(double mass, double temperature, double speed)
        {
            const double BoltzmannConstant = 1.380649e-23;
            return 4 * M_PI * pow(mass / (2 * M_PI * BoltzmannConstant * temperature), 1.5) * exp(-mass * pow(speed, 2) / (2 * BoltzmannConstant * temperature));
        }

        // Astrophysics Formulas
        double calculateBlackbodyRadiation(double temperature, double wavelength)
        {
            const double PlancksConstant = 6.626e-34;
            const double speedOfLight = 3.0e8;
            const double BoltzmannConstant = 1.380649e-23;

            return (2 * M_PI * PlancksConstant * pow(speedOfLight, 2)) / (pow(wavelength, 5) * (exp((PlancksConstant * speedOfLight) / (BoltzmannConstant * temperature * wavelength)) - 1));
        }

        double calculateWaveParticleDuality(double momentum, double position)
        {
            const double h_bar = 1.0545718e-34;
            return h_bar / (momentum * position);
        }

        double calculateQuantumHarmonicOscillatorEnergy(double mass, double frequency, int n)
        {
            const double h_bar = 1.0545718e-34;
            return (n + 0.5) * h_bar * frequency;
        }

        // Fluid Mechanics Formulas
        double calculateFluidVelocity(double flowRate, double area)
        {
            return flowRate / area;
        }

        // Optics Formulas
        double calculateMagnificationLens(double focalLength, double objectDistance)
        {
            return 1.0 + (objectDistance / focalLength);
        }

        double calculateRefractionAngle(double incidentAngle, double refractiveIndex1, double refractiveIndex2)
        {
            return asin(sin(incidentAngle) * refractiveIndex1 / refractiveIndex2);
        }

        // Statistical Mechanics Formulas
        double calculatePartitionFunction(double energyLevels, double temperature)
        {
            const double BoltzmannConstant = 1.380649e-23;
            return exp(-energyLevels / (BoltzmannConstant * temperature));
        }

        double calculateThermalDeBroglieWavelength(double temperature, double mass)
        {
            const double BoltzmannConstant = 1.380649e-23;
            const double h_bar = 1.0545718e-34;
            return h_bar / sqrt(2 * M_PI * mass * BoltzmannConstant * temperature);
        }

        // Astrophysics Formulas
        double calculateEscapeVelocityBlackHole(double mass, double radius)
        {
            const double gravitationalConstant = 6.67430e-11;
            const double speedOfLight = 3.0e8;
            return sqrt(2 * gravitationalConstant * mass * (1 - 2 * gravitationalConstant * mass / (speedOfLight * speedOfLight * radius)));
        }

        double calculateHubbleLaw(double recessionVelocity, double distance)
        {
            const double HubbleConstant = 70.0; // Hubble constant in km/s/Mpc
            return HubbleConstant * distance / recessionVelocity;
        }
        double calculateQuantumSpin(double angularMomentum, double magneticField)
        {
            const double electronCharge = 1.602176634e-19;
            return (angularMomentum * electronCharge) / (2 * M_PI * magneticField);
        }

        double calculateQuantumTunnelingTime(double barrierWidth, double particleMass, double energy)
        {
            const double h_bar = 1.0545718e-34;
            return h_bar / (2 * sqrt(2 * particleMass * energy)) * exp(barrierWidth * sqrt(2 * particleMass * energy) / h_bar);
        }

        // Optics Formulas
        double calculateFermatPrinciple(double pathDifference, double wavelength)
        {
            return pathDifference / wavelength;
        }

        double calculateCriticalAngleTotalInternalReflection(double refractiveIndex1, double refractiveIndex2)
        {
            return asin(refractiveIndex2 / refractiveIndex1);
        }

        // Statistical Mechanics Formulas
        double calculateMeanFreePath(double pressure, double diameter, double numberDensity)
        {
            const double BoltzmannConstant = 1.380649e-23;
            return (BoltzmannConstant * pressure) / (sqrt(2) * M_PI * diameter * diameter * numberDensity);
        }

        double calculateEntropyIdealGas(double volume, double temperature)
        {
            const double BoltzmannConstant = 1.380649e-23;
            return (3.0 / 2.0) * BoltzmannConstant * log(volume / temperature);
        }

        double calculateParticleEnergy(double mass, double velocity)
        {
            // Using the classical kinetic energy formula: KE = 0.5 * mass * velocity^2
            return 0.5 * mass * pow(velocity, 2);
        }

        double calculateDeBroglieWavelength(double momentum)
        {
            // Using the De Broglie wavelength formula: λ = h / p, where h is Planck's constant
            const double h = 6.626e-34;
            return h / momentum;
        }

        double calculateCosmologicalRedshift(double observedWavelength, double emittedWavelength)
        {
            return observedWavelength / emittedWavelength - 1;
        }
        double calculateQuantumAngularMomentum(double quantumNumber)
        {
            const double h_bar = 1.0545718e-34;
            return quantumNumber * h_bar;
        }

        // Fluid Mechanics Formulas
        double calculateStokesLawDragForce(double viscosity, double radius, double velocity)
        {
            return 6 * M_PI * viscosity * radius * velocity;
        }

        double calculateMachNumber(double velocity, double speedOfSound)
        {
            return velocity / speedOfSound;
        }

        // Optics Formulas
        double calculateDiffractionAngle(double wavelength, double slitWidth)
        {
            return asin(wavelength / (2 * slitWidth));
        }

        double calculateLensPower(double focalLength)
        {
            return 1.0 / focalLength;
        }

        // Statistical Mechanics Formulas
        double calculateSpecificHeatIdealGas(double degreesOfFreedom, double gasConstant)
        {
            return degreesOfFreedom * gasConstant / 2;
        }


        // Astrophysics Formulas
        double calculateHubbleParameter(double recessionVelocity, double distance)
        {
            return recessionVelocity / distance;
        }

        double calculateQuantumHarmonicOscillatorEnergy(double quantumNumber, double angularFrequency)
        {
            const double h_bar = 1.0545718e-34;
            return (quantumNumber + 0.5) * h_bar * angularFrequency;
        }

        double calculateVenturiEffectVelocity(double area1, double area2, double velocity1)
        {
            return (area1 * pow(velocity1, 2)) / area2;
        }

        // Optics Formulas
        double calculateFresnelDiffraction(double apertureSize, double wavelength, double distance, double angle)
        {
            return sin(angle) * (apertureSize / (2 * distance)) * wavelength;
        }

        double calculateMirrorEquation(double focalLength, double objectDistance)
        {
            return 1.0 / focalLength - 1.0 / objectDistance;
        }

        // Statistical Mechanics Formulas
        double calculateBoseEinsteinDistribution(double energy, double temperature)
        {
            const double BoltzmannConstant = 1.380649e-23;
            return 1.0 / (exp(energy / (BoltzmannConstant * temperature)) - 1);
        }

        double calculateFermiDiracDistribution(double energy, double fermiEnergy, double temperature)
        {
            const double BoltzmannConstant = 1.380649e-23;
            return 1.0 / (exp((energy - fermiEnergy) / (BoltzmannConstant * temperature)) + 1);
        }

        double calculatePhotonWavelength(double energy)
        {
            const double PlancksConstant = 6.626e-34;
            const double speedOfLight = 3.0e8;
            return PlancksConstant / (energy / speedOfLight);
        }
    };

    class PhysicsFormulasManager
    {
    private:
        PhysicsFormulas formulas;

    public:
        void performPhysicsCalculations()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int choice;

                cout << "Choose Physics Formula Category:\n\n";
                cout << "1. Kinematics\n";
                cout << "2. Dynamics\n";
                cout << "3. Energy\n";
                cout << "4. Fluid Dynamics\n";
                cout << "5. Thermodynamics\n";
                cout << "6. Wave\n";
                cout << "7. Circular Motion\n";
                cout << "8. Electricity and Magnetism\n";
                cout << "9. Optics\n";
                cout << "10. Atomic Physics\n";
                cout << "11. Gravitation\n";
                cout << "12. Nuclear Physics\n";
                cout << "13. Special Relativity\n";
                cout << "14. Quantum Mechanics\n";
                cout << "15. Astrophysics\n";
                cout << "16. Fluid Mechanics\n";
                cout << "17. Statistical Mechanics\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0-17): ";
                cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 17)
                {
                    switch (choice)
                    {
                    case 1:
                        performKinematicsCalculations();
                        break;
                    case 2:
                        performDynamicsCalculations();
                        break;
                    case 3:
                        performEnergyCalculations();
                        break;
                    case 4:
                        performFluidDynamicsCalculations();
                        break;
                    case 5:
                        performThermodynamicsCalculations();
                        break;
                    case 6:
                        performWaveCalculations();
                        break;
                    case 7:
                        performCircularMotionCalculations();
                        break;
                    case 8:
                        performElectricityMagnetismCalculations();
                        break;
                    case 9:
                        performOpticsCalculations();
                        break;
                    case 10:
                        performAtomicPhysicsCalculations();
                        break;
                    case 11:
                        performGravitationCalculations();
                        break;
                    case 12:
                        performNuclearPhysicsCalculations();
                        break;
                    case 13:
                        performSpecialRelativityCalculations();
                        break;
                    case 14:
                        performQuantumMechanicsCalculations();
                        break;
                    case 15:
                        performAstrophysicsCalculations();
                        break;
                    case 16:
                        performFluidMechanicsCalculations();
                        break;
                    case 17:
                        performStatisticalMechanicsCalculations();
                        break;
                    }

                    // cout << "\nPress Enter to continue...";
                    // cin.get(); // This line will read the Enter keypress
                    cin.get(); // This line will wait for an additional Enter keypress
                }
                else
                {
                    cout << "\nInvalid choice. Please enter a number between 0 and 17.\n";
                }
            }
        }

    private:
        // Methods for each category of physics formulas
        void performKinematicsCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif

            int kinematicsChoice;

            cout << "Choose Kinematics Formula:\n\n";
            cout << "1. Calculate Velocity\n";
            cout << "2. Calculate Displacement\n";
            cout << "0. Back to the previous menu\n\n";
            cout << "Enter your choice (0-2): ";
            cin >> kinematicsChoice;

            if (kinematicsChoice == 0)
            {
                return; // Return to the previous menu
            }
            else if (kinematicsChoice >= 1 && kinematicsChoice <= 2)
            {
                switch (kinematicsChoice)
                {
                case 1:
                    performCalculateVelocity();
                    break;

                case 2:
                    performCalculateDisplacement();
                    break;
                }

                cout << "\nPress Enter to continue...";
                cin.ignore(); // Clear the newline character from the buffer
                cin.get();    // This line will wait for an additional Enter keypress
            }
            else
            {
                cout << "\nInvalid choice. Please enter a number between 0 and 2.\n";
            }
        }

        void performCalculateVelocity()
        {
#ifdef _WIN32
            system("cls");
#endif

            double initialVelocity, acceleration, time;
            cout << "Enter initial velocity(m/s): ";
            cin >> initialVelocity;
            cout << "Enter acceleration(m/s2): ";
            cin >> acceleration;
            cout << "Enter time(s): ";
            cin >> time;

            double velocity = formulas.calculateVelocity(initialVelocity, acceleration, time);

            cout << "Calculated velocity: " << velocity << " m/s\n";
        }

        void performCalculateDisplacement()
        {
#ifdef _WIN32
            system("cls");
#endif

            double initialVelocity, time, acceleration;
            cout << "Enter initial velocity(m/s): ";
            cin >> initialVelocity;
            cout << "Enter time(s): ";
            cin >> time;
            cout << "Enter acceleration(m/s): ";
            cin >> acceleration;

            double displacement = formulas.calculateDisplacement(initialVelocity, time, acceleration);

            cout << "Calculated displacement: " << displacement << " m\n";
        }

        void performDynamicsCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif

            int dynamicsChoice;

            cout << "Choose Dynamics Formula:\n\n";
            cout << "1. Calculate Force\n";
            cout << "2. Calculate Weight\n";
            cout << "0. Back to the previous menu\n\n";
            cout << "Enter your choice (0-2): ";
            cin >> dynamicsChoice;

            if (dynamicsChoice == 0)
            {
                return; // Return to the previous menu
            }
            else if (dynamicsChoice >= 1 && dynamicsChoice <= 2)
            {
                switch (dynamicsChoice)
                {
                case 1:
                    performCalculateForce();
                    break;

                case 2:
                    performCalculateWeight();
                    break;
                }

                cout << "\nPress Enter to continue...";
                cin.ignore(); // Clear the newline character from the buffer
                cin.get();    // This line will wait for an additional Enter keypress
            }
            else
            {
                cout << "\nInvalid choice. Please enter a number between 0 and 2.\n";
            }
        }

        void performCalculateForce()
        {
#ifdef _WIN32
            system("cls");
#endif

            double mass, acceleration;
            cout << "Enter mass(kg): ";
            cin >> mass;
            cout << "Enter acceleration(m/s2): ";
            cin >> acceleration;

            double force = formulas.calculateForce(mass, acceleration);

            cout << "Calculated force: " << force << " N\n";
        }

        void performCalculateWeight()
        {
#ifdef _WIN32
            system("cls");
#endif

            double mass;
            cout << "Enter mass(kg): ";
            cin >> mass;

            double weight = formulas.calculateWeight(mass);

            cout << "Calculated weight: " << weight << " N\n";
        }

        void performEnergyCalculations()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int choice;

                cout << "Choose Energy Formula:\n\n";
                cout << "1. Kinetic Energy\n";
                cout << "2. Potential Energy\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0-2): ";
                cin >> choice;

                if (choice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (choice >= 1 && choice <= 2)
                {
                    switch (choice)
                    {
                    case 1:
                        performKineticEnergyCalculations();
                        break;
                    case 2:
                        performPotentialEnergyCalculations();
                        break;
                    }

                    cout << "\nPress Enter to continue...";
                    cin.ignore(); // Clear the newline character from the buffer
                    cin.get();    // This line will wait for an additional Enter keypress
                }
                else
                {
                    cout << "\nInvalid choice. Please enter a number between 0 and 2.\n";
                }
            }
        }

        void performKineticEnergyCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double mass, velocity;
            cout << "Enter mass(kg): ";
            cin >> mass;
            cout << "Enter velocity(m/s): ";
            cin >> velocity;

            double kineticEnergy = formulas.calculateKineticEnergy(mass, velocity);

            cout << "Calculated kinetic energy: " << kineticEnergy << " Joule\n";
        }

        void performPotentialEnergyCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double mass, height, gravitationalAcceleration;
            cout << "Enter mass(kg): ";
            cin >> mass;
            cout << "Enter height(m): ";
            cin >> height;
            double potentialEnergy = formulas.calculatePotentialEnergy(mass, height);

            cout << "Calculated potential energy: " << potentialEnergy << " Joule\n";
        }

        void performFluidDynamicsCalculations()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int fluidDynamicsChoice;

                cout << "Choose Fluid Dynamics Formula:\n\n";
                cout << "1. Fluid Pressure\n";
                cout << "2. Buoyant Force\n";
                cout << "3. Flow Rate\n";
                cout << "4. Bernoulli's Equation\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0-4): ";
                cin >> fluidDynamicsChoice;

                if (fluidDynamicsChoice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (fluidDynamicsChoice >= 1 && fluidDynamicsChoice <= 4)
                {
                    switch (fluidDynamicsChoice)
                    {
                    case 1:
                        performFluidPressureCalculations();
                        break;
                    case 2:
                        performBuoyantForceCalculations();
                        break;
                    case 3:
                        performFlowRateCalculations();
                        break;
                    case 4:
                        performBernoullisEquationCalculations();
                        break;
                    }

                    cout << "\nPress Enter to continue...";
                    cin.get();    // This line will read the Enter keypress
                    cin.ignore(); // Clear the newline character from the buffer
                }
                else
                {
                    cout << "\nInvalid choice. Please enter a number between 0 and 4.\n";
                }
            }
        }

        void performFluidPressureCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double density, gravity, height;
            cout << "Enter fluid density(kg/m3): ";
            cin >> density;
            cout << "Enter gravitational acceleration(m/s2): ";
            cin >> gravity;
            cout << "Enter height(m): ";
            cin >> height;

            double fluidPressure = formulas.calculateFluidPressure(density, gravity, height);

            cout << "Calculated fluid pressure: " << fluidPressure << " Pa\n";
        }

        void performBuoyantForceCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double fluidDensity, displacedVolume, gravity;
            cout << "Enter fluid density(kg/m3): ";
            cin >> fluidDensity;
            cout << "Enter displaced volume(m3): ";
            cin >> displacedVolume;
            cout << "Enter gravitational acceleration(m/s2): ";
            cin >> gravity;

            double buoyantForce = formulas.calculateBuoyantForce(fluidDensity, displacedVolume, gravity);

            cout << "Calculated buoyant force: " << buoyantForce << " N\n";
        }

        void performFlowRateCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double area, velocity;
            cout << "Enter area(m2): ";
            cin >> area;
            cout << "Enter velocity(m/s): ";
            cin >> velocity;

            double flowRate = formulas.calculateFlowRate(area, velocity);

            cout << "Calculated flow rate: " << flowRate << " m3/s\n";
        }

        void performBernoullisEquationCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double pressure, density, gravity, height, velocity;
            cout << "Enter pressure(Pa): ";
            cin >> pressure;
            cout << "Enter fluid density(kg/m3): ";
            cin >> density;
            cout << "Enter gravitational acceleration(m/s2): ";
            cin >> gravity;
            cout << "Enter height(m): ";
            cin >> height;
            cout << "Enter velocity(m/s): ";
            cin >> velocity;

            double bernoullisEquation = formulas.calculateBernoullisEquation(pressure, density, gravity, height, velocity);

            cout << "Calculated Bernoulli's equation: " << bernoullisEquation << "\n";
        }

        void performThermodynamicsCalculations()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int thermodynamicsChoice;

                cout << "Choose Thermodynamics Formula:\n\n";
                cout << "1. Work Done\n";
                cout << "2. Heat Transfer\n";
                cout << "3. First Law of Thermodynamics\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0-3): ";
                cin >> thermodynamicsChoice;

                if (thermodynamicsChoice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (thermodynamicsChoice >= 1 && thermodynamicsChoice <= 3)
                {
                    switch (thermodynamicsChoice)
                    {
                    case 1:
                        performWorkDoneCalculations();
                        break;
                    case 2:
                        performHeatTransferCalculations();
                        break;
                    case 3:
                        performFirstLawOfThermodynamicsCalculations();
                        break;
                    }

                    cout << "\nPress Enter to continue...";
                    cin.get();    // This line will read the Enter keypress
                    cin.ignore(); // Clear the newline character from the buffer
                }
                else
                {
                    cout << "\nInvalid choice. Please enter a number between 0 and 3.\n";
                }
            }
        }

        void performWorkDoneCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double force, displacement, angle;
            cout << "Enter force(N): ";
            cin >> force;
            cout << "Enter displacement(m): ";
            cin >> displacement;
            cout << "Enter angle(degree): ";
            cin >> angle;

            double workDone = formulas.calculateWorkDone(force, displacement, angle);

            cout << "Calculated work done: " << workDone << " Joule\n";
        }

        void performHeatTransferCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double thermalConductivity, area, temperatureDifference, thickness;
            cout << "Enter thermal conductivity(W/m.K): ";
            cin >> thermalConductivity;
            cout << "Enter area(m2): ";
            cin >> area;
            cout << "Enter temperature difference(K): ";
            cin >> temperatureDifference;
            cout << "Enter thickness(m): ";
            cin >> thickness;

            double heatTransfer = formulas.calculateHeatTransfer(thermalConductivity, area, temperatureDifference, thickness);

            cout << "Calculated heat transfer: " << heatTransfer << " Joule\n";
        }

        void performFirstLawOfThermodynamicsCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double heatAdded, workDone;
            cout << "Enter heat added(K): ";
            cin >> heatAdded;
            cout << "Enter work done(J): ";
            cin >> workDone;

            double changeInInternalEnergy = formulas.calculateFirstLawOfThermodynamics(heatAdded, workDone);

            cout << "Calculated change in internal energy: " << changeInInternalEnergy << " Joule\n";
        }

        void performWaveCalculations()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int waveChoice;

                cout << "Choose Wave Formula:\n\n";
                cout << "1. Wave Speed\n";
                cout << "2. Frequency\n";
                cout << "3. Wavelength\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0-3): ";
                cin >> waveChoice;

                if (waveChoice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (waveChoice >= 1 && waveChoice <= 3)
                {
                    switch (waveChoice)
                    {
                    case 1:
                        performWaveSpeedCalculations();
                        break;
                    case 2:
                        performFrequencyCalculations();
                        break;
                    case 3:
                        performWavelengthCalculations();
                        break;
                    }

                    cout << "\nPress Enter to continue...";
                    cin.get();    // This line will read the Enter keypress
                    cin.ignore(); // Clear the newline character from the buffer
                }
                else
                {
                    cout << "\nInvalid choice. Please enter a number between 0 and 3.\n";
                }
            }
        }

        void performWaveSpeedCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif

            double frequency, wavelength;
            cout << "Enter frequency(Hz): ";
            cin >> frequency;
            cout << "Enter wavelength(m): ";
            cin >> wavelength;

            double waveSpeed = formulas.calculateWaveSpeed(frequency, wavelength);

            cout << "Calculated wave speed: " << waveSpeed << " m/s\n";
        }

        void performFrequencyCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double waveSpeed, wavelength;
            cout << "Enter wave speed(m/s): ";
            cin >> waveSpeed;
            cout << "Enter wavelength(m): ";
            cin >> wavelength;

            double frequency = formulas.calculateFrequency(waveSpeed, wavelength);

            cout << "Calculated frequency: " << frequency << " Hz\n";
        }

        void performWavelengthCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double waveSpeed, frequency;
            cout << "Enter wave speed(m/s): ";
            cin >> waveSpeed;
            cout << "Enter frequency(Hz): ";
            cin >> frequency;

            double wavelength = formulas.calculateWavelength(waveSpeed, frequency);

            cout << "Calculated wavelength: " << wavelength << " m\n";
        }

        void performCircularMotionCalculations()
        {
            while (true)
            {
#ifdef _WIN32
                system("cls");
#endif
                int circularMotionChoice;

                cout << "Choose Circular Motion Formula:\n\n";
                cout << "1. Centripetal Force\n";
                cout << "2. Centripetal Acceleration\n";
                cout << "3. Tangential Velocity\n";
                cout << "4. Angular Velocity\n";
                cout << "0. Back to the previous menu\n\n";
                cout << "Enter your choice (0-4): ";
                cin >> circularMotionChoice;

                if (circularMotionChoice == 0)
                {
                    break; // Return to the previous menu
                }
                else if (circularMotionChoice >= 1 && circularMotionChoice <= 4)
                {
                    switch (circularMotionChoice)
                    {
                    case 1:
                        performCentripetalForceCalculations();
                        break;
                    case 2:
                        performCentripetalAccelerationCalculations();
                        break;
                    case 3:
                        performTangentialVelocityCalculations();
                        break;
                    case 4:
                        performAngularVelocityCalculations();
                        break;
                    }

                    cout << "\nPress Enter to continue...";
                    cin.get();    // This line will read the Enter keypress
                    cin.ignore(); // Clear the newline character from the buffer
                }
                else
                {
                    cout << "\nInvalid choice. Please enter a number between 0 and 4.\n";
                }
            }
        }

        void performCentripetalForceCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double mass, radius, tangentialVelocity;
            cout << "Enter mass(kg): ";
            cin >> mass;
            cout << "Enter radius(m): ";
            cin >> radius;
            cout << "Enter tangential velocity(m/s): ";
            cin >> tangentialVelocity;

            double centripetalForce = formulas.calculateCentripetalForce(mass, radius, tangentialVelocity);

            cout << "Calculated centripetal force: " << centripetalForce << " N\n";
        }

        void performCentripetalAccelerationCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double tangentialVelocity, radius;
            cout << "Enter tangential velocity(m/s): ";
            cin >> tangentialVelocity;
            cout << "Enter radius(m): ";
            cin >> radius;

            double centripetalAcceleration = formulas.calculateCentripetalAcceleration(tangentialVelocity, radius);

            cout << "Calculated centripetal acceleration: " << centripetalAcceleration << " m/s2\n";
        }

        void performTangentialVelocityCalculations()
        {
#ifdef _WIN32
            system("cls");
#endif
            double radius, angularVelocity;
            cout << "Enter radius(m): ";
            cin >> radius;
            cout << "Enter angular velocity(rad/s): ";
            cin >> angularVelocity;