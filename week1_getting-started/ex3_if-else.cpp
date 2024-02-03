#include <iostream>  // This imports the library iostream ,
                     // which contains useful functions for
                     // reading and writing data
using namespace std; // This allows us to use some abbreviations
                     // For example, we can write cin instead of std ::cin int main()
int main(){          // This is the main entry of the program
    string equal, bigger, smaller; // We declare several string variables
    int num1, num2;                // We declare two integer variables
    //cout << "Enter two integer numbers (separated by space): ";
    cin >> num1 >> num2;           // Read the 2 numbers
    // Define the three strings
    equal = to_string(num1) + " is equal to " + to_string(num2);
    bigger = to_string(num1) + " is bigger than " + to_string(num2);
    smaller = to_string(num1) + " is smaller than " + to_string(num2);

    if (num1 == num2){          // Check the value of the numbers and print the corresponding string
        cout << equal << endl;
    }
    else if (num1 > num2){
        cout << bigger << endl;
    }
    else{
        cout << smaller << endl;
    }

    return 0;
}