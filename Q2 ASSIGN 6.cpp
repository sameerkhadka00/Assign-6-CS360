#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Abstract class representing a CarbonFootprint
class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0; // Pure virtual function
    virtual string getType() const = 0; // Pure virtual function to get type
};

// Class representing a Building
class Building : public CarbonFootprint {
public:
    Building(string type, double area, double electricityUsage)
        : type(type), area(area), electricityUsage(electricityUsage) {}

    double getCarbonFootprint() const override {
        // Carbon footprint calculation for buildings
        return electricityUsage * 0.5; // Just a simple calculation for demonstration
    }

    string getType() const override {
        return type;
    }

private:
    string type;
    double area; // Area of the building
    double electricityUsage; // Electricity usage in kWh
};

// Class representing a Car
class Car : public CarbonFootprint {
public:
    Car(string make, string model, double milesDriven, double fuelEfficiency)
        : make(make), model(model), milesDriven(milesDriven), fuelEfficiency(fuelEfficiency) {}

    double getCarbonFootprint() const override {
        // Carbon footprint calculation for cars
        return milesDriven * (1 / fuelEfficiency) * 19.6; // Just a simple calculation for demonstration
    }

    string getType() const override {
        return make + " " + model;
    }

private:
    string make;
    string model;
    double milesDriven; // Miles driven per year
    double fuelEfficiency; // Fuel efficiency in miles per gallon (mpg)
};

// Class representing a Bicycle
class Bicycle : public CarbonFootprint {
public:
    Bicycle(string brand, string type)
        : brand(brand), type(type) {}

    double getCarbonFootprint() const override {
        // Carbon footprint for bicycles is negligible
        return 0;
    }

    string getType() const override {
        return brand + " " + type;
    }

private:
    string brand;
    string type; // Type of bicycle (e.g., road bike, mountain bike)
};

int main() {
    // Create objects of each class
    Building building("Office", 1000, 2000);
    Car car("Toyota", "Camry", 12000, 30);
    Bicycle bicycle("Giant", "Mountain");

    // Create a vector of CarbonFootprint pointers and store the addresses of the objects
    vector<CarbonFootprint*> carbonFootprints;
    carbonFootprints.push_back(&building);
    carbonFootprints.push_back(&car);
    carbonFootprints.push_back(&bicycle);

    // Iterate through the vector and invoke getCarbonFootprint() polymorphically
    for (const auto& cf : carbonFootprints) {
        cout << "Type: " << cf->getType() << ", Carbon Footprint: " << cf->getCarbonFootprint() << " kg CO2" << endl;
    }

    return 0;
}
