// Gavyn Garza Coding I Spring 26
// Favorite Games Assignment

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>::iterator iter;


int main() {

    // To start:
    // Add global vector of favorite games
    // Add string input
    cout << "Welcome to Gavyn's Favorite Games!\n";

    vector<string> favGames = {"Minecraft", "Subnautica", "Breath of the Wild", "Animal Crossing"};

    string input;

    // Add do while loop to start program
    do {

    // Ask with text, what will player do
        cout << "What would you like to do?\n";

    // Give Player Options with text
        cout << " You can... 'view', 'add', 'edit', 'remove', or 'quit'\n";

    // ask for player input
        getline(cin, input);

    // start if statements
    // allow for input of "View", "Add", "Edit", "Remove", "Quit"

     // View: on input, display current list of favGames, and then give options
        if(input == "view") {
            cout << "These are my favorite games!\n";
            sort(favGames.begin(), favGames.end());

            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << endl;
            }

        }   // end of view

    // Add: on input, give player input oppurtunity to add a game to the vector, then give options
        else if(input == "add") {
            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }
            cout << "What game would you like to add?\n";
            // ask for player input
            getline(cin, input);

            favGames.push_back(input);

            cout << "Here is the new list of games!\n";

            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }

        }   // end of add

    // Edit:on input, ask player which entry to change, then give options
        else if (input == "edit") {
            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }

            // set up iter
            iter = favGames.begin();

            iter += 1;

            cout << "Which entry would you like to change?\n";
            getline(cin, input);

            // use the find algorithm
            iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "I've found " << *iter << "!\n";
                cout << "Would you like to change this entry?\n";
                getline(cin, input);

                if (input == "yes") {
                    cout << "What would you like to change this entry to?\n";
                    getline(cin, input);

                    *iter = input;
                }
                cout << "Here is your updated list!\n";
                for(int i = 0; i < favGames.size(); i++) {
                    cout << "\t" << favGames[i] << "\n";
                }


            }

            else {
                cout << "I couldn't find that name, sorry.\n";
            }

        }   // end of edit

    // Remove: on input, ask player which entry to remove, then give options
        else if(input == "remove") {
            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }

            cout << "What would you like to remove from the list?\n";
            getline(cin, input);

             auto iter = find(favGames.begin(), favGames.end(), input);

             if (iter != favGames.end()) {
                cout << "Removing now.\n";
                favGames.erase(iter);
            
            }

            cout << "Here is the updated list:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames [i] << endl;
            }


        }   // end of remove


        // Quit: on input, end program
        else if(input == "quit") {
            cout << "Thanks for playing.\n";
            break;
        }   // end of quit

        // Error: show error for other inputs
        else {
            cout << "Sorry, I don't recognise that one.\n";
        }   // end of error


    } while(true);  // end of do while loop

    // return program
    return 0;


}   // end of main