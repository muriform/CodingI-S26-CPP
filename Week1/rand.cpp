// Gavyn Garza Coding I Spring 2026
// Random Numbers Switch Statements and While Loops

// fill out the rest of the code so that it displays random numbers to the console, then run it
// cl /EHsc

#include <iostream>
#include <cstdlib> // for srand and rand
#include <ctime>   // for time

using namespace std;

int main() {
    // only once at beginning of program
    // seed the random number generator
    srand(time(0));

    cout << "Random Numbers\n";


    cout << "Here is our first random number: " << rand() << ".\n";

    int counter = 0;
    while(counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min;  // 50
        int clampedNumber = (number % range) + min;
        
        cout << clampedNumber << endl;
    }

   

        int randomRange = (rand() % 11) + 10;   // this gives us a number between 10 and 20, inclusive
        int number = (rand() % randomRange) + 1;
        int guess = -1;
        int totalGuesses = 0;

    
    while(true) {
    
    cout << "I'm thinking of a number between 1 and " << randomRange << ", can you guess it?\n>>";
    
    cin >> guess;
    totalGuesses++;

        if(guess > number) {
            cout << "Too high!\n";
        }
        
       else if(guess < number) {
            cout << "Too low!\n";
        }
        
        else {
            cout << "Correct!\n";
            cout << "It only took you " << totalGuesses << " guesses!\n";
            break;
        }
    // if incorrect keep looping

    }   
    

    return 0;
}