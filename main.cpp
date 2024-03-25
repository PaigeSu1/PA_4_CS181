/*
# Author: Paige Su
# BannerID: 001395655
# Course: CS 181
# Assignment: PA4
# Date Assigned: Monday, March 18, 2024
# Date/Time Due: Saturday, March 30, 2024 -- 11:55 pm
# Description: This program will exercise Object-Oriented concepts with C++.
# Certification of Authenticity:
I certify that this assignment is entirely my own work.
*/

/*
 * Introduction comment ::
 * This program takes user input to gather information about managers, and calculates the highest paid manager and the average pay between the manager(s).
 * Show casing Inheritance with Dynamically created objects.
 */


//the problem is the formatting fix this, totalPay is looking odd? the average result is not giving a good result
//how do you move the terminal cursor over one space to meet the input requirement of the assigment.

/*------------------------------------------------------------------------------------------------------------------------------------
 * Things not working average pay calculation, The math calculation or calcPay something is not right
 * MAX_MANAGERS this not working or used at all? Need to return an error code?
 * The output format enter manager hourly is spaces over odd.
 * before the user enter in input there should be a blank space before it to move the cursor how do i dix this?
 * -------------------------------------------------------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip> //used for set-precision functions
#include <string>
#include "Employee.h"
#include "Manager.cpp"

using namespace std;

int main()
{
    // Declare variables
    const int MAX_MANAGERS = 99;
    int numManagers;

    //Get user input for the number of manager
    cout << "Enter number of managers:  " ;
    cin >> numManagers;

    //Do I need this?
    if (numManagers > MAX_MANAGERS) {
        return 1; // Exit the program with an error code
    }

    cout << " " << endl; //creates a blank line space
    cin.ignore(); //clear the input buffer

    //Dynamic allocation of an array of pointers to Manager objects
    //Employee** managers = new Employee*[numManagers];
    auto **managers = new Manager*[numManagers];


    //Ask for input information for each manager and store the pointer in the array
    for(int i = 0; i < numManagers; ++i){
        string name;
        double wage, hours, bonus;

        //Ask user to fill in the data for each manager
        //Name
        cout << "Enter manager " << i << " name:  " ;
        getline(cin,name); //need to use the getLine func for something
        //cin >> name; //This will not take the first and last name in at the same time


        //Hourly wage
        cout << "Enter manager " << i << " hourly wage:  " ;
        cin >> wage;

        //Hours worked
        cout << "Enter manager " << i << " hours worked:  " ;
        cin >> hours;

        //Bonus
        cout << "Enter manager " << i << " bonus:  " ;
        cin >> bonus;

        cout << " " << endl; //creates a blank line space between the managers


        //store the managers information into a list
        //managers[i] = reinterpret_cast<Employee*>(new Manager(name, wage, hours, bonus));
        managers[i] = new Manager(name, wage, hours, bonus);

        cin.ignore();
    }


    //Find the manager who is most highly paid version 2
    Manager *highestPaidManager = managers[0];
    for(int i = 1; i < numManagers; i++){
        if(managers[i]->calcPay() > highestPaidManager->calcPay()){
            highestPaidManager = managers[i];
        }
    }

    /*
     * Version 1
    // Calculate highest paid manager and average pay
    double highestPay = 0;
    double totalPay = 0;
    string highestPaidManagerName;

    for (int i = 0; i < numManagers; ++i) {
        double pay;
        pay = managers[i]->calcPay();
        totalPay += pay;
        if (pay > highestPay) {
            highestPay = pay;
            highestPaidManagerName = managers[i]->getName();
        }
    }
    */

    //Calculate the average pay of all the managers
    double totalPay = 0.0;
    for(int i = 0; i < numManagers; ++i){
        totalPay += managers[i]->calcPay();
    }
    double averagePay = totalPay / numManagers;

    //Print out the information
    cout << "Highest paid manager is " << highestPaidManager->getName() << "who is paid $" << fixed << setprecision(2) << highestPaidManager->calcPay()  << endl;
    cout << "Average pay is $" << averagePay << endl;

    /*
     * version 1 of the Calculate the average pay of all the managers.
    double averagePay = totalPay / numManagers;

    // Print highest paid manager and average pay
    cout << fixed << setprecision(2); // Set output to 2 decimal places
    cout << "Highest paid manager is " << highestPaidManagerName
         << " who is paid $" << highestPay << endl;
    cout << "Average pay is $" << averagePay << endl;
    */


    // Cleanup: Delete dynamically allocated Manager objects and array
    for (int i = 0; i < numManagers; ++i) {
        delete managers[i];
    }
    delete[] managers;

    return 0;
} //end of main bracket
