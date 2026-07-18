// IteratorsAndPriorityQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
#include "Vector.h"
#include "PriorityQueue.h"

int main()
{
    
    std::cout << "Hello World!\n";

    Array<int, 20> arrayNumbers;
    Vector<int> vectorNumbers;
    PriorityQueue<int> pqNumbers;

    for (int i = 0; i < 20; ++i) {
        arrayNumbers[i] = (rand() % 100) + 1;
        int value = (rand() % 100) + 1;
        vectorNumbers.PushBack(value);
        pqNumbers.Push(value);
    }
    std::cout << "Iterate through Array\n";
    for (Array<int, 20>::Iterator it = arrayNumbers.Begin(); it != arrayNumbers.End(); ++it) {
        std::cout << (*it) << " ";
     }
    std::cout << "\n\n";
    std::cout << "Iterate through Vector\n";

    for (Array<int, 20>::Iterator it = vectorNumbers.Begin(); it != vectorNumbers.End(); ++it) {
        std::cout << (*it) << " ";
    }
    std::cout << "\n\n";

    std::cout << "Iterate through Queue\n";
    while (!pqNumbers.Empty())
    {
        std::cout << pqNumbers.Top() << " ";
        pqNumbers.Pop();
    }
    std::cout << "\n\n";

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
