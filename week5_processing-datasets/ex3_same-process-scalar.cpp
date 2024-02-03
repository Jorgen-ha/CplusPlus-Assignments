// Processing datasets 3
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
/// Here: computes the scalar product of the two vectors
void sortAndPrint(vector<char> &a, vector<char> &b){
    int end, product = 0;
    if (a.size() > b.size()){
        end = a.size();
    } else {
        end = b.size(); // Make an iterator based on the biggest vector
    }
    for (int it = 0; it < end; it++){
        if (a[it] != *a.end() && b[it] != *b.end()){          // If both vectors have an element
            product += int(a[it] - '0') * int(b[it] - '0');
        } else {
            product += 0;
        }
    }
    cout << product << endl;
}

int main(){
    string input; 
    vector<char> a, b;
    getline(cin, input);     // Get the input from the user
    divideData(input, a, b); // Call the function to divide the data
    sortAndPrint(a, b);      // Call the function to sort and print the data

    return 0;
}


