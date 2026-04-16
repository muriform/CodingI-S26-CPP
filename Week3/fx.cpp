// Gavyn Garza Coding I Spring 2026
// Functions!
// cl /EHsc fx.cpp && fx


/* This is a block comment
This is all a comment yay

Functions:
returnType, funcationName, (input parameters), {code}
passing by value
passing by reference

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;

string input;

// declaring and defining a new fucntion, return type is void
// it returns nothing
// the name of the ufunction is sayHello
// input parameters go in the ()
// call this function in main by typing "sayHello()""

void sayHello() {
    cout << "Hello!\n";

}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";


}

int dieRoll(int sides = 6, int min = 1) {
    return rand() % sides + min;
}

bool askYesNo(string question = "Do you want to keep playing?") {
    while(true) {
    cout << question << " ('yes'/'no')\n";
    getline(cin, input);

    if(input == "yes") {
        return true;
    }

    else if(input == "no") {
        return false;
    }

    else {
        cout << "I didn't understand, please type 'yes' or 'no'.\n";
    }

}
}

// variable scope
// passing by reference
// global variables

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}


// create a refernce with a & next to the variable type
// int& number; or string& name

// references let us edit the original
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    getline(cin, input);

    vec.push_back(input);

    // showVec(vec);   // the added name exists here
}


int main() {
    srand(time(0));     // seed the rand. num. generater
    vector<string> names = {"Finn", "Jake", "Marceline", "BMO", "PB"};

    showVec(names);

    addStringToVec(names);      // add a string to 

    showVec(names);             // it doesnt add to 

    cout << "Finally, functions!\n";

    sayHello();

    doAddition(14,3);

    cout << "Let's roll the dice! Our first number is " << dieRoll(6) << ".\n";

    doAddition(dieRoll(20), dieRoll(20));
    doAddition(dieRoll(), dieRoll(222));

    if(askYesNo()) {
        cout << "Lets start the next level!\n";
    
    }
    else {
        cout << "Thank you for playing!\n";
        return 0;
    }

    if(askYesNo("Do you like apples?")) {
        cout << "YIPPE!\n";
    
    }
    else {
        cout << "Begone.\n";
    }




    return 0;
}