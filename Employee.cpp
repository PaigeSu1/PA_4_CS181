//
// Created by agent on 3/19/2024.
//

#include<string>
#include<cstdlib>

using namespace std;

#include "Employee.h"

// Employee Constructor definition
Employee::Employee(string theName, double theWage, double theHours)
{
    name = theName;
    wage = theWage;
    hours = theHours;
}

// Calculate the employee’s pay.
double Employee::calcPay() const
{
    return wage * hours;
}

string Employee::getName() const
{
    return name;
}

