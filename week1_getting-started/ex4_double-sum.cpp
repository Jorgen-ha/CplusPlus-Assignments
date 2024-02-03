#include <iostream>  // This imports the library iostream ,
                     // which contains useful functions for
                     // reading and writing data
using namespace std; // This allows us to use some abbreviations
                     // For example, we can write cin instead of std::cin
int main(){           
    double num1, num2, num3, sum;      // Declare several double variables
    // cout << "Enter three double numbers (separated by space): ";
    cin >> num1 >> num2 >> num3; // Read the 3 numbers
    sum = (num1 + num2) - num3;  // Compute the sought for sum
    
    cout << sum << endl;         // Output the sum to the user

    return 0;
}