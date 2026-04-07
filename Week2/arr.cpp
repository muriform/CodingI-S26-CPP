// Gavyn Garza Coding I Spring 26
// Arrays, For Loops, Enums, and Switchs statements

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    cout << "Lets make some arrays!\n";

    // Arrays cannot change their size
    // Arrays dont know where the last item/index is
    // Arrays are a list of similar variable types
    // Arrays are ordered
    
    int scores[5];  // This is creating an integer array with a size of 5

    scores[0] = 4545;
    scores[1] = 13;
    scores[2] = 9001;
    scores[3] = 2456;
    scores[4] = -4;
    // scores[5] = 999;

    cout << "The first high score is " << scores[0] << ".\n";

    cout << "Here are all of the scores:\n";

    int index = 0;
    while(index < 5) {
        cout << scores[index] << ".\n";
        index++;
    }


    cout << "Using a for loop:\n";
    // for loop has the iterator built in
    // for(setup; test; action)
    for(int i = 0; i < 5; i++) {
        cout << scores[i] << "\n";
    }

    // string array for names
    string names[10];
    string input;
    index = 0;  
    // we want the user to add names to the array
    while(index < 10) {
        cout << "Type name, or 'done': ";
        cin >> input;
    
    // until they type done
    if (input == "done") {
        cout << "\nDone adding names.\n";
        break;
    }

    // add the name to the array
    names[index++] = input;


    }
    // or until the list is filled
    // show the list of names
    for(int i = 0; i < 10; i++) {
        if(names[i] == "") {
            continue;   // start the loop over early
        }
        cout << names[i] << "\n";

    }

    // create a new string array
    string newNames [] = {"Mario", "Luigi", "Toad", 
                        "Peach", "Bowser", "Rosalina", 
                        "Yoshi", "Bowser Jr."};


    cout << "Here are the new names:\n";
    for(int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << newNames[i] << "\n";
    }

    // pick a random name from our newNames array
    int randIndex = rand() % 8;
    string character = newNames[rand() % 8];

    cout << character << ", Lets talk about them.\n";
    

    // an enumerator is a custom variable type with only the vaules we specify
    // they correspond to numbers starting with 0 at default
    enum favor {LOVE, LIKE, DISLIKE, LOATHE};
    

    switch(rand() % 4) {
        case LOVE:
            cout << "I love " << character << ".\n";
            break;
        case LIKE:
            cout << "I like " << character << ".\n";
            break;
        case DISLIKE:
            cout << "I dislike " << character << ".\n";
            break;
        case LOATHE:
            cout << "I loathe " << character << ".\n";
            break;
    }


    return 0;
}