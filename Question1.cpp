#include <iostream>
#include <string>
using namespace std;

// Class representing a date
class dateType {
public:
    dateType(int m = 1, int d = 1, int y = 2000); // Constructor with default values

    // Getters for month, day, and year
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Function to check if a year is a leap year
    bool isLeapYear(int year);

    // Function to set the date with validation
    void setDate(int m, int d, int y);

private:
    int month;
    int day;
    int year;
};

// Constructor definition
dateType::dateType(int m, int d, int y) {
    setDate(m, d, y);
}

// Getter definitions
int dateType::getMonth() const {
    return month;
}

int dateType::getDay() const {
    return day;
}

int dateType::getYear() const {
    return year;
}

// Function to check if a year is a leap year
bool dateType::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to set the date with validation
void dateType::setDate(int m, int d, int y) {
    if (m < 1 || m > 12 || d < 1 || d > 31 || y < 0) {
        cerr << "Invalid date. Setting to default date (1/1/2000)." << endl;
        month = 1;
        day = 1;
        year = 2000;
        return;
    }

    // Validate day based on month
    if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30)) {
        cerr << "Invalid date for the given month. Setting to default date (1/1/2000)." << endl;
        month = 1;
        day = 1;
        year = 2000;
        return;
    }

    if (m == 2) {
        if (isLeapYear(y) && d > 29) {
            cerr << "Invalid date for February in a leap year. Setting to default date (1/1/2000)." << endl;
            month = 1;
            day = 1;
            year = 2000;
            return;
        } else if (!isLeapYear(y) && d > 28) {
            cerr << "Invalid date for February in a non-leap year. Setting to default date (1/1/2000)." << endl;
            month = 1;
            day = 1;
            year = 2000;
            return;
        }
    }

    // Date is valid, set the date
    month = m;
    day = d;
    year = y;
}

// Class representing a person
class personType {
public:
    void print() const;
    void setName(string first, string last);
    string getFirstName() const;
    string getLastName() const;
    personType(string first = "", string last = "");

private:
    string firstName;
    string lastName;
};

void personType::print() const {
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last) {
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const {
    return firstName;
}

string personType::getLastName() const {
    return lastName;
}

personType::personType(string first, string last) {
    firstName = first;
    lastName = last;
}

// Class representing an extended person with additional details
class extPersonType : public personType {
public:
    void printInfo() const;
    extPersonType(string first = "", string last = "", string pn = "", dateType dob = dateType(), string pt = "");

private:
    string phoneNumber;
    dateType dateOfBirth;
    string type;
};

void extPersonType::printInfo() const {
    personType::print();
    cout << ", Phone: " << phoneNumber << ", DOB: " << dateOfBirth.getMonth() << "/" << dateOfBirth.getDay() << "/" << dateOfBirth.getYear() << ", Type: " << type << endl;
}

extPersonType::extPersonType(string first, string last, string pn, dateType dob, string pt)
    : personType(first, last), phoneNumber(pn), dateOfBirth(dob), type(pt) {}

int main() {
    // Test the classes
    dateType dob(3, 21, 1990);
    extPersonType person("John", "Doe", "123-456-7890", dob, "Friend");
    person.printInfo();
    return 0;
}
