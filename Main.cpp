// Created by Spagget on 10/16/2025.


// Include Project Libraries / Headers that are being used.
#include <cmath>
#include <iostream>
#include <limits>
#include <cstdlib>

// Using namespace std so its not needed to type it in every time.
using namespace std;

#ifdef _WIN32
#include <windows.h>
static void enable_vt_mode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif

// Start
int main() {
#ifdef _WIN32
    enable_vt_mode();
#endif
    while (true) {

        // Initialize variables
        // side_a = to A side
        // side_b = to B side
        // side_c = side_p square root
        // side_p is being used to calculate the sum of side_a & side_b squared
        float side_a = 0;
        float side_b = 0;
        float side_c = 0;
        float side_p = 0;

        // Some ASCII Art cause why not
        cout<<"\033[32m"<<R"(
                                 _______      _________ _    _
                                 |  __ \ \   / /__   __| |  | |   /\    _     _
                                 | |__) \ \_/ /   | |  | |__| |  /  \ _| |_ _| |_
                                 |  ___/ \   /    | |  |  __  | / /\ \_   _|_   _|
                                 | |      | |     | |  | |  | |/ ____ \|_|   |_|
                                 |_|____ _|_|__ __|_|_ |_|__|_/_/___ \_\___ ______
                                 |______|______|______|______|______|______|______|

                                                                     by Eraklis Karatsaousides
                                                                        )" <<"\033[0m\n\n\n\n";
        // Cout Prompt to user giving brief description about the program
        // Give instructions to the user of how to use the program
        cout<<"\033[33mThis is a c++ program that helps with calculating the third side of a triangle using the pythagorean theorem \n"<<endl;
        cout<<"To continue input the given lengths (A, B) : \n\n\n \033[0m"<<endl;

        // Take input of side_a while trying to catch any user errors or errors in general.
        while (true) {
            cout << "A = ";
            if (!(cin >> side_a)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\033[31mInvalid input. Please enter a numeric value for A.\033[0m"<<endl;
                continue;
            }
            if (!isfinite(side_a)) {
                cout<<"\033[31mValue out of range. Please enter a finite number for A.\033[0m"<<endl;
                continue;
            }
            if (side_a < 0) {
                cout<<"\033[31mLength cannot be negative. Please enter a non-negative value for A.\033[0m"<<endl;
                continue;
            }
            break;
        }

        // Take input of side_b while trying to catch any user errors or errors in general.
        while (true) {
            cout << "B = ";
            if (!(cin >> side_b)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"\033[31mInvalid input. Please enter a numeric value for B.\033[0m"<<endl;
                continue;
            }
            if (!isfinite(side_b)) {
                cout<<"\033[31mValue out of range. Please enter a finite number for B.\033[0m"<<endl;
                continue;
            }
            if (side_b < 0) {
                cout<<"\033[31mLength cannot be negative. Please enter a non-negative value for B.\033[0m"<<endl;
                continue;
            }
            break;
        }

        // Calculate side_a squared + side_b squared
        side_p = pow(side_a, 2) + pow(side_b, 2);
        // Check if side_p is a finite number and if not throw error.
        if (!isfinite(side_p) || side_p < 0) {
            cout << "\033[31mAn error occurred while computing c (overflow or invalid input). Let's try again.\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n";
            continue;
        }
        // Calculate side_c (square root of side_p)
        side_c = sqrt(side_p);
        // Check if side_c is a finite number and if not throw error.
        if (!isfinite(side_c)) {
            cout << "\033[31mAn error occurred while computing c (invalid sqrt result). Let's try again.\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n";
            continue;
        }
        // Cout all the triangle sides.
        cout<<"\n\n\033[35mResults :"<<endl<<"____________________________";
        cout<<"\n\nSide A = "<<side_a<<endl<<"Side B = "<<side_b<<endl<<"Side C = "<<side_c<<endl<<"\033[0m";

        // Ask the user if they want to restart the program before returning 0;
        // Check user input for mistakes / try to catch general errors related to user input
        // If the user presses y = program resets and restarts
        // if the user presses n = program exists / returns 0;
        // if the user presses anything else (invalid input) then catch error and ask again.
        while (true) {
            cout << "\nCalculate again? (y/n): ";
            char again;
            if (!(cin >> again)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter y or n." << endl;
                continue;
            }
            if (again == 'y' || again == 'Y') {
                system("cls");
                cout<<"\n\n";
                break;
            }
            if (again == 'n' || again == 'N') {
                return 0;
            }
            cout << "Please enter y or n." << endl;
        }
    }
}
