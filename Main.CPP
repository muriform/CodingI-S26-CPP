// Gavyn Garza Coding I Spring 2026
// This file is my first C++ program

#include <iostream>    // in out stream, for sending text to the console.
#include <string>      // for player name


using namespace std;  //so we dont have to type "std::"" all the time

// here is where we start the program
int main() {
    // variables declared at the top is best practice
    string playerName;                // variables use camelCase

    // ask the player for their name
    cout << "What is your name, player? "; 


    // assign what the player types as the value of playerName
    cin >> playerName;

    
    // greet the player by name
    cout << "Hello, " << playerName << "." << endl;


    // use ctrl+slash tp comment out lines
    // cout << "LALALALALALA!" << endl;  // endL = end line, cout = console out

    return 0;                        // end the program
}