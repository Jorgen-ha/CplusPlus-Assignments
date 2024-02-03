// Fun with bags 2
#include <iostream> // Import the library for input/output

using namespace std; // Use the standard namespace

void splitLine(string sentence, string *allCmds, string *allValues){
    // Divide the input by the space character until the newline character
    int i = 0;
    while (sentence.find(' ') != string::npos){
        int space = sentence.find(' ');         
        string cmd = sentence.substr(0, space); 
        allCmds[i] = cmd;          
        sentence = sentence.substr(space + 1);   
        space = sentence.find(' ');     
        string value = sentence.substr(0, space); 
        allValues[i] = value;          
        i++;
        sentence = sentence.substr(space + 1);   
    }
    allCmds[i] = sentence; // Remember to get the last command
}

int main(){
    int bag[1001] = {0}; // Make a bag with room for numbers between 0 and 1000
    string line;
    string allCommands[10];
    string allValues[10];
    string command;
    int number;

    getline(cin, line);         // Read the input commands from the user
    splitLine(line, allCommands, allValues);
    int size = sizeof(allCommands)/sizeof(allCommands[0]);
    for (int i = 0; i < size; i++){
        command = allCommands[i];
        if (command == "quit"){
            return 0;
        }
        number = stoi(allValues[i]);
        if (command == "add"){
            bag[number] += 1;   // Add number to the bag (indicating it is here)
        }
        if (command == "del"){
            if (!bag[number] == 0){
                bag[number] -= 1;   // Remove one occurence from the bag
            } 
        }
        if (command == "qry"){
            if (bag[number] == 0){ // Check whether or not the number is in the bag
                cout << "F";
            }
            else if (bag[number] > 0){
                cout << "T";
            }
        }
    }
    cout << endl;

    return 0;
}
