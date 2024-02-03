#include <iostream>  // This imports the library iostream ,
                     // which contains useful functions for
                     // reading and writing data
using namespace std; // This allows us to use some abbreviations
                     // For example, we can write cin instead of std ::cin int main()
int main(){          // This is the main entry of the program
    string name;           // We declare a string variable called "name"
    //cout << "What is your name? >";
    cin >> name ;          // We store the input in name
    cout << "Hello " << name << "!" << endl;  // We print a grant to the user
    return 0;              
}