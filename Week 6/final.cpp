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
class creature {
private:
    string name;
    int health;
    int startingHealth = 0;
    int damage;
    int hunger;
    // default constrctor

    creature() {
        cout << "A new creature has appeared...\n";
    }


}       // end of creature


void read(vector<string>& vec, string path = "creaturenames.txt") {
    string line;
    ifstream readFile(path);
    if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);        // add each line to the vector
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after done reading the file, close it

    readFile.close();

}













int main() {
    srand(time(0)); 
    string input;
    vector<string> favs;
    read();         // show the current names
    read(favs, path);     // add the names to the vector

    string path = "save.txt";

    creature creatureOne;
    creatureOne.name = "Meep";

    while(true) {
        cout << "What do you want to do?\n";
        

        getline(cin, input);

        // feed the critter
        if (input == "feed") {
            cout << "lalalalala\n"; 
        }


        // train critter (increase health or damage)
        else if (input == "train") {
            cout << "lalalalalala\n";
        }


        // listen to critter (display health, damage, hunger)
        else if (input == "listen") {
            cout << creatureOne.name << " is lalalalalala\n";
        }

    }


}       // end of main