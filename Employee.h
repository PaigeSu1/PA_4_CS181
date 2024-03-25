//
// Created by agent on 3/19/2024.
//

#ifndef PA_4_VER_4_EMPLOYEE_H
#define PA_4_VER_4_EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double wage;
    double hours;

public:
    // Create a new employee
    Employee(string theName, double theWage, double theHours);

    // Calculate the employee’s pay.
    double calcPay() const;

    //Get the employee's name
    string getName() const;
};

#endif //PA_4_VER_4_EMPLOYEE_H
