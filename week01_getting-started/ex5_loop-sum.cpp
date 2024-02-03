#include <iostream>  // This imports the library iostream ,
                     // which contains useful functions for
                     // reading and writing data
using namespace std; // This allows us to use some abbreviations
                     // For example, we can write cin instead of std::cin
int main(){
    int iterations;
    double num, sum = 0;        // Declare necessary variables
    // cout << "Enter the number of numbers you want to summarize: ";
    cin >> iterations;          // Store the number of iterations
    int i = 0;
    while (i < iterations){     // Loop through until all numbers are gotten
        // cout << "Enter a number: ";
        cin >> num;
        sum += num;             // Summarize the numbers
        i++;
    }

    cout << sum << endl;        // Output the sum to the user

    return 0;
}

