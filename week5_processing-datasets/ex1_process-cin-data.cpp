// Processing datasets 1
#include <iostream>  
#include <string>
#include <algorithm>

using namespace std; // Use the standard namespace

/// @brief Function that divides the input data into two vectors
void divideData(string input, vector<char> &a, vector<char> &b){
    bool readA = false;
    bool readB = false;
    for (char c : input){
        if (c == 'a'){
            readA = true;
            readB = false;
        } else if (c == 'b'){
            readB = true;
            readA = false;
        } else if (c == ' '){
            continue;
        } else{
            if (readA){
                a.push_back(c);
            }
            if (readB){
                b.push_back(c);
            }
        }
    }
}
/// @brief Function that sorts and prints the data as required by exercise
/// Here: from smallest to largest, and printing first a then b
void sortAndPrint(vector<char> &a, vector<char> &b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (char c : a){
        cout << c << " ";
    }
    for (char c : b){
        cout << c << " ";
    }
    cout << endl;
}

int main(){
    string input; 
    vector<char> a, b;
    getline(cin, input);     // Get the input from the user
    divideData(input, a, b); // Call the function to divide the data
    sortAndPrint(a, b);      // Call the function to sort and print the data

    return 0;
}


