// ArraysAndVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Array.h>
#include <Vector.h>

int main()
{
    Vector<int> myVector;
    myVector.Resize(10);
    for (std::size_t i = 0; i < myVector.Size(); ++i) {
        std::cout << (myVector[i] += rand()) << "\n";
    }
    myVector.PopBack();
    myVector.PopBack();
    for (std::size_t i = 0; i < myVector.Size(); ++i) {
        std::cout << (myVector[i] += rand()) << "\n";
    }
   return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
int Excersice1() {

    // build and array of 10 integers
    // initialize all elements to 0
    //iterate through them all and set the values to random numbers
    //create a new array of 10 ints
    // make it equal to the first array
    // iterate through all the elemnts and add 5 (print the numbers)
    srand(static_cast<unsigned int>(time(nullptr)));

    // Build an array of 10 integers
    Array<int, 10> myCustomArray;

    // Initialize all elements to 0
    for (std::size_t i = 0; i < myCustomArray.Size(); ++i)
    {
        myCustomArray[i] = 0;
    }

    // Set the values to random numbers
    for (std::size_t i = 0; i < myCustomArray.Size(); ++i)
    {
        myCustomArray[i] = rand() % 100;
    }

    // Create a new array of 10 ints
    Array<int, 10> secondArray;

    // Make it equal to the first array
    secondArray = myCustomArray;

    // Add 5 and print
    for (std::size_t i = 0; i < secondArray.Size(); ++i)
    {
        secondArray[i] += 5;
        std::cout << secondArray[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}