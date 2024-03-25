#include "Employee.h"
#include <string>

using namespace std;

class Manager :public Employee
{
private:
    double bonus;

public:
    //constructor
    Manager(string theName, double theWage, double theHours, double theBonus) : Employee(theName, theWage, theHours) , bonus(theBonus) {}

    // Redefined function to calculate manager's pay
    double calcPay() const {
        // Calculate base pay using Employee's calcPay() method and add bonus
        return Employee::calcPay() + bonus;
    }

    // Accessor for bonus
    double getBonus() const {
        return bonus;
    }
};