// Address book
#include <iostream> // Import the library for input/output

using namespace std; // Use the standard namespace

/// A struct containing the information about a person
struct person {
string firstname;
string middlename;
string lastname;
string phonenumber;
string address;
string housenumber;
string zipcode;
string region;
};

/// Prints all the information about a person
void printInfo(person person){
    if (person.firstname != ""){
        cout << person.firstname << "," << person.middlename << "," << person.lastname << "," 
            << person.phonenumber << "," << person.address << "," << person.housenumber << ","
            << person.zipcode << "," << person.region << endl;
    }
}

/// Clears the contents of a given page
void clearPage(person *addressBook, int pageNum){
    // Function to clear the contents of a page
    addressBook[pageNum].firstname = "";
    addressBook[pageNum].middlename = "";
    addressBook[pageNum].lastname = "";
    addressBook[pageNum].phonenumber = "";
    addressBook[pageNum].address = "";
    addressBook[pageNum].housenumber = "";
    addressBook[pageNum].zipcode = "";
    addressBook[pageNum].region = "";
}

/// Splits the information string 
string splitInfo(string allInfo, string *informationArray){
    // Divide the input by the space character until the newline character
    int i = 0;
    while (allInfo.find(' ') != string::npos && i < 8){
        int space = allInfo.find(' ');          // Find the first space
        string info = allInfo.substr(0, space); // Get the info
        informationArray[i] = info;          // Add the info to the array
        i++;
        allInfo = allInfo.substr(space + 1);   // Remove the word from the allInfo
    }
    string rest = allInfo;
    return rest;
}


/// Processes add
string processAdd(string allInfo, person *addressBook){
    string infoArray[8]; 
    int space = allInfo.find(' ');          
    int pageNum = stoi(allInfo.substr(0, space)); 
    allInfo = allInfo.substr(space + 1);
    string restLine = splitInfo(allInfo, infoArray);
    person newPerson = {infoArray[0], infoArray[1], infoArray[2],
                        infoArray[3], infoArray[4], infoArray[5],
                        infoArray[6], infoArray[7]};

    if (addressBook[pageNum].firstname == ""){
        addressBook[pageNum] = newPerson;       // Add the person to the book if page is empty
    }
    return restLine;
}
/// Processes clr and qry 
string processClrQry(string line, person *addressBook){
    while(line.find(' ') != string::npos){
        int space = line.find(' ');
        string cmd = line.substr(0, space);             // Finds the cmd
        line = line.substr(space + 1);  
        space = line.find(' ');
        int pageNum = stoi(line.substr(0, space));      // Finds the page number
        if (cmd == "clr"){
            clearPage(addressBook, pageNum);
            line = line.substr(space + 1);                  // Reads rest of line
        }
        if (cmd == "qry"){
            printInfo(addressBook[pageNum]);
            line = line.substr(space + 1); // Reads rest of line
        }
        if (cmd == "add"){
            line = processAdd(line, addressBook);
        }
    }

    return line;
}

/// Processes all possible commands
int processCommands(string input, person *addressBook){
    while (input.find(' ') != string::npos){
        int space = input.find(' ');
        string cmd = input.substr(0, space);
        if (cmd == "add"){
            input = processAdd(input.substr(space + 1), addressBook);
        }
        if (cmd == "clr" || cmd == "qry"){
            input = processClrQry(input, addressBook);
        }
        if (cmd == "quit"){
            return 1;
        }
    }
}

int main(){
    person addressBook[50]; // Make the address book with room for 50 people
    string input;

    getline(cin, input);         // Read the inputted person info
    int finished = processCommands(input, addressBook);

    while (!finished){           // Process the input until "quit"
        getline(cin, input);
        finished = processCommands(input, addressBook);
    }

    return 0;
}
