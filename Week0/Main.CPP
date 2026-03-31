// Gavyn Garza Coding I Spring 2026
// This file is my first C++ program

// to compile, open the developer command prompt for vs 2022
// nav to this folder with cd for change directory
// use the cmd "cl /EHsc filename.cpp" this is "main.cpp"
// then type "filename" to run the .exe this is "main"

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