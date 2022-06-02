// Copyright (c) 2022 Hunter Connolly All rights reserved
// Created by: Hunter Connolly
// Created on: May 31, 2022
// This program asks the user repeatedly for a mark between 0 and 100%
// The program uses a loop to enter each mark into a list of integers.
// When the user enters -1, the loop stops. It will then calculate the
// average and display the average


#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
#include <iomanip>
#include <list>


float CalcAverage(std::list<int> listOfInt) {
    // declare variable
    float avg;
    float roundedAverage;
    int sum;
    int intProcess;

    // calculate the sum
    if (listOfInt.size() == 0) {
        return -1;
    } else {
        sum = 0;
        for (int aNum : listOfInt) {
            sum += aNum;
        }
    }

    // calculate the average
    avg = sum / listOfInt.size();

    roundedAverage = (avg*pow(10, 0));
    intProcess = (static_cast<int>(roundedAverage + 0.5));
    roundedAverage = intProcess *pow(10, -0);

    // return the average
    return roundedAverage;
}


main() {
    // declare variables
    std::string markString;
    int markInt;
    float avg;

    // declare the list
    std::list<int> listOfInt;

    // greet the user
    std::cout << "This program calculates the average of all your marks!!"
" Enter -1 to end the program!\n";

    while (markInt != -1) {
        // get the mark
        std::cout << "Enter a mark(%) or -1 to stop: ";
        std::cin >> markString;
        try {
            // convert the string to an int
            markInt = std::stof(markString);

            // when the user enters -1 the program will stop asking for input
            // and it will then calculate the average, by calling the function
            if (markInt == -1) {
                avg = CalcAverage(listOfInt);
                break;
            }
            // append the input to the list
            listOfInt.push_back(markInt);
        } catch (std::invalid_argument) {
            // catch the invalid input and then get the user to go again
            std::cout << markString << " is not a valid input\n";
            continue;
        }
    }

    // display the average
    std::cout << "\n";
    std::cout << "The average is: " <<  avg << "%";
}
