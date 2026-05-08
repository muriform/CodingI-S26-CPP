// Gavyn Garza Spring 26 Coding I
// Final Assignment

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>     
#include <cstdlib>   
#include <algorithm>

using namespace std;

vector<string> names;

class baseCreature {
private:
    //  base stats for the creatures.
    string name;
    int health;
    int hunger;
    int startingHealth = 0;

public:
    int damage;
    // constructor
    baseCreature(string givenName, int givenHealth, int givenHunger, int givenDamage) {
        name = givenName;
        health = givenHealth;
        hunger = givenHunger;
        damage = givenDamage;
        
        cout << "A new creature has appeared...\n";
    }

    void attack(baseCreature &opponent) {
    
        cout << name << " does " << damage << " base damage.\n";
        cout << opponent.name << " has " << opponent.health << " health\n";

            opponent.health -= damage;
        
    }

    void status() {
        cout << "My health is " << health << ".\n";
        cout << "I do " << damage << " base damage\n";
        cout << "My hunger is " << hunger << ".\n";
        cout << "I am ";

        if (hunger < 2)
            cout << "Full...\n";
        else if (hunger < 10)
            cout << "Starving...\n";
        else 
            cout << "Cannot battle or train...\n";
    }

    // getters

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getHunger() {
        return hunger;
    }
    int getDamage() {
        return damage;
    }

    // setter
    void setName(string givenName) {
        if (givenName.size() <= 10) {
            name = givenName;
        }
        else {
            cout << "error: " << givenName << "is too long.\n";
        }
    }

    void setHealth(int givenHealth) {
        if (givenHealth < 0)
            health = 0; 
        else if (givenHealth > 100)
            health = 100; 
        else
            health = givenHealth;
    }

    void setHunger(int givenHunger) {
        if (givenHunger > 20)
            hunger = 20; 
        hunger = givenHunger;
    }

    void setDamage(int givenDamage) {
        if (givenDamage < 2)
            damage = 0; 
        else if (givenDamage > 50)
            damage = 50; 
        else
            damage = givenDamage;
    }
};

class bossCreature : public baseCreature {
public:
    int damageMultiplier = 2;

    bossCreature()
        : baseCreature("Meep", 55, 1, 4) {
        damage *= damageMultiplier;
    }

    bossCreature(string givenName, int givenHealth, int givenHunger, int givenDamage)
        : baseCreature(givenName, givenHealth, givenHunger, givenDamage) {
        damage *= damageMultiplier;
    }
};

vector<string> read(string path = "creatureNames.txt") {
    string line;
    vector<string> vec;
    ifstream readFile(path);
    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            vec.push_back(line);
        }
        readFile.close();
        return vec;
    }
    cout << "Sorry, I couldn't open that file.\n";

    readFile.close();
    return vec;
}

int main() {
    string input;
    srand(time(0)); 

    cout << "What is your name?\n";
    getline(cin, input);

    cout << "You hear a rustle in the bushes...\n";

    baseCreature baby("Baby", 10, 1, 10);
    cout << "What would you like to name your new creature?\n";
    cout << "The name must be less than 10 letters.\n";

    cout << "Here's some examples: \n";
    names = read();
    for (int i = 0; i < names.size(); i++) {
        cout << "\t" << names[i] << "\n";
    }

    getline(cin, input);
    baby.setName(input);

    cout << "You named your creature: " <<baby.getName() << endl;

    do {
        cout << "What would you like to do?\n";
        cout << "You can 'train', 'feed', 'listen', 'battle', or 'end'...\n";
        getline(cin, input);

        if (baby.getHunger() > 5) {
            cout << "FEED ME" << endl;
            cout <<"My hunger level is: " << baby.getHunger();
            cout <<" I CANT FIGHT OR TRAIN IF MY HUNGER IS 10 OR MORE" << endl;
        }

        if (input == "train")  {
            if (baby.getHunger() > 10){
                cout << baby.getName() << " is too hungry to train..." << endl;
                continue;
            }
            cout << baby.getName() << " grows ever stronger...\n";
            baby.setHealth(baby.getHealth() + 3);
            baby.setDamage(baby.getDamage() + 1);
            baby.setHunger(baby.getHunger() + 1);
        }

        else if (input == "feed")  {
            cout << "You have fed your creature...\n";
            baby.setHunger(baby.getHunger() - 1);
        }
        else if (input == "listen")  {
            baby.status();
        }
        else if (input == "battle") {
            if (baby.getHunger() > 10){
                cout << "I'm too hungry to battle " << endl;
                continue;
            }

            bossCreature meep("Meep", 55, 1, 4);
            cout << "This is a boss-type creature.\n";
            

            while (meep.getHealth() > 0 && baby.getHealth() > 0)   {
                cout << "You can choose to 'attack', 'heal', or 'run'.\n";

                getline(cin, input);
                if(input == "attack") {
                    baby.attack(meep); 
                    cout << "The Meep now has " << meep.getHealth() << " health.\n";
                    meep.attack(baby);
                    cout << "Your creature has " << baby.getHealth() << " health left!\n";
                }
                else if(input == "heal") {
                    cout << "Your creature is being healed...\n";
                    baby.setHealth(baby.getHealth() + 5);
                    cout << baby.getName() << " has " << baby.getHealth() << " health now.\n";
                }
                else if(input == "run") {
                    cout << "You have ran away...\n";
                    break;
                }
                else {
                    cout << "The creature does not understand...\n";
                }
            
            }
        }

        else if (input == "end")  {
            return 0;
        }


        else {
            cout << "The creature does not understand...\n";
        }

    } while (true);

    return 0;
}