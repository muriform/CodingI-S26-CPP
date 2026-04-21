// Gavyn Garza Spring 2026 Coding I
// Writing to and reading from files

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void read(string path = "save.txt") {
     string line;

    ifstream readFile("path");  // create a new var, try to open a file

    if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after done reading the file, close it

    readFile.close();
}

// overloaded function name
void read(vector<string>& vec, string path = "save.txt") {
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

void write(vector<string>& vec, string path = "save.txt") {
     ofstream writeFile(path);     // create a file to write to and open it
     if(writeFile.is_open()) {
        cout << "The writeFile is open.\n";
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
     }
        else {
        cout << "Couldn't open new writeFile.\n";
    }
    writeFile.close();
     cout << "End of write() function.\n";


}

int main() {
    cout << "Let's write to a file!\n";
    vector<string> favs;
    string input = "asdf";

    string path = "save.txt";

    cout << "What file would you like to open?\nType 'no' to use default.\n";
    getline(cin, input);
    if(input != "no") {
        path = input;       // this lets us open different files
    }
    



    // open or load the file
    // call the read function here
    // make soome changes

    read();         // show the current names
    read(favs, path);     // add the names to the vector


    // --------------------------------

    cout << "What names would you like to add?\n";
    cout << "Enter a empty line to stop.\n";

  


    while(input != "") {
        cout << "> ";
        getline(cin, input);
        if(input == "") {
            break;
        }
        // send to file
        // writeFile << input << endl;
        favs.push_back(input);
    }

    // now call the write function and send it our favs vector
    write(favs, path);


    return 0;
}