// Gavyn Garza Spring 26 Coding I
// Final Assignment

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

// create a base class


//     // default constrctor
//     creature() {
//         name = creatureNames[rand() % creatureNames.size()];
//         hunger = rand() % 4 + 4;
//         damage = rand() % 5 + 5;
//         health = rand() % 4 + 4;
//         startingHealth = health;
//     }



// };       // end of creature











class baseCreature {
private:
    string name;
    int health;
    int startingHealth = health;
    int damage;
    int hunger;

    // constructor sets up the class with input variables, doesnt have a return type, must be named same as class
    baseCreature(string givenName, int givenCharge, int givenBoredom) {
        cout << "A new creature has appeared...\n";
        string name;
        int health;
        int startingHealth = 0;
        int damage;
        int hunger;
        status();

    }

    // default constructor
    baseCreature() {
        name = blank;
        damage = rand() % 4 + 4;
        health = rand() % 4 + 4;
        startingHealth = health;
        hunger = 1;
        status();
    }

    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my health is " << health << ".\n";\
        cout << "I am ";

        if(hunger < 2) cout << "Full";
        else if(hunger < 5) cout << "Peckish";
        else if(hunger < 10) cout << "Famished";
        else cout << "Starving";
        cout << ".\n";

        cout << "I do " << damage << " damage.\n";
    }

    // getters

    string getName() {
        return name;
    }

    int getCharge() {
        return charge;
    }

    int getHunger() {
        return hunger;
    }

    // setters
    void setName(string givenName) {
        if(givenName.size() <= 5) {
            name = givenName;
        }
        else{
            cout << "Error: " << givenName << " is too long.\n";
        }
    }

    void setCharge(int givenCharge) {
        // clamp charge to 0-100
        if(givenCharge < 0) {
            charge = 0;
        
        }
        else if(givenCharge > 100) {
            charge = 100;
        }
        else {
            charge = givenCharge;
        }
    }

    void setBoredom(int givenBoredom) {
        if(givenBoredom > 20) boredom = 20;
        boredom = givenBoredom;

    }


























// void read(vector<string>& vec, string path = "creatureNames.txt") {
//     string line;
//     ifstream readFile(path);
//     if(readFile.is_open()) {
//         cout << "The file is open.\n";
//         while(getline(readFile, line)) {
//             vec.push_back(line);        // add each line to the vector
//         }
//     }
//     else {
//         cout << "Couldn't open that file.\n";
//     }

//     // after done reading the file, close it

//     readFile.close();

// }













// int main() {
//     srand(time(0)); 
//     string input;
//     vector<string> names;
//     read(names);         // show the current names

//     string path = "creatureNames.txt";

//     creature creatureOne;
//     creatureOne.name = "Meep";

//     while(true) {
//         cout << "What do you want to do?\n";
        
//         getline(cin, input);

//         // name the critter
//         if (input == "name") {
//             cout << "What would you like to name your creature?\n";
//             getline(cin, input);
           
//         }


//         // feed the critter
//         else if (input == "feed") {
//             cout << "lalalalala\n"; 
//         }


//         // train critter (increase health or damage)
//         else if (input == "train") {
//             cout << "lalalalalala\n";
//         }


//         // listen to critter (display health, damage, hunger)
//         else if (input == "listen") {
//             cout << creatureOne.name << " is lalalalalala\n";
//         }

//     }


// }       // end of main