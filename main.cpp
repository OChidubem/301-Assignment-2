/**
 * @file main.cpp
 * @author Chidubem Okoye
 * @class CSCI 301
 * @date 11/11/2024
 * @brief Implementation of LinkedStack.
 *
 * This program demonstrates stack operations using a LinkedStack.
 * It provides a menu-driven interface to push, pop, peek, and check
 * if the stack is empty. The program validates user input and handles
 * errors gracefully.
 */

#include <iostream>
#include <string>
#include <limits>
#include "LinkedStack.h"

using namespace std;

/**
 * @brief Main program to demonstrate stack operations using a LinkedStack.
 * 
 * This program provides a menu for the user to interact with a stack data
 * structure. The options include pushing an item onto the stack, popping an
 * item from the stack, peeking the top item, checking if the stack is empty,
 * and exiting the program.
 * 
 * The program uses a LinkedStack<int> object to perform the stack operations.
 * The user input is validated to handle invalid entries.
 * 
 * @return int Returns 0 on successful program execution.
 */
int main() {
    LinkedStack<int> stack;  // Create a stack of integers
    int choice = 0;
    int value;

    while (true) {
        // Display menu options
        cout << "\n----- Stack Operations -----\n";
        cout << "1. Push item onto stack\n";
        cout << "2. Pop item from stack\n";
        cout << "3. Peek top item\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        // Take input and validate
        if (!(cin >> choice)) {
            // Clear error state and ignore remaining input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1: // Push item onto the stack
                cout << "Enter the value to push onto the stack: ";
                if (!(cin >> value)) {
                    // Clear error state and ignore remaining input
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid integer.\n";
                } else {
                    stack.push(value);
                    cout << "Value " << value << " pushed onto the stack.\n";
                }
                break;

            case 2: // Pop item from the stack
                if (stack.pop()) {
                    cout << "Item popped from the stack.\n";
                } else {
                    cout << "Stack is empty! Cannot pop.\n";
                }
                break;

            case 3: // Peek top item
                try {
                    int topItem = stack.peek();
                    cout << "Top item on the stack: " << topItem << endl;
                } catch (const std::runtime_error& e) {
                    cout << "Stack is empty! Cannot peek.\n";
                }
                break;

            case 4: // Check if stack is empty
                if (stack.isEmpty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;

            case 5: // Exit
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please choose a valid option.\n";
        }
    }

    return 0;
}
