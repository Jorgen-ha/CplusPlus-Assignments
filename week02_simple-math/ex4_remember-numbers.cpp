// Rmembering numbers
#include <iostream> // Import the library for input/output
#include <math.h>   // Import the library for math functions
using namespace std; // Use the standard namespace

int numbers[1000] = {0};

int numberChecker (int number){
    // Function to check how many times a number has already been given
    if (number == 0){
        return 0;
    }
    if (number > 0 && number <= 1000){
        // cout << number << " was given " << numbers[number] << " times before" << endl;
        cout << numbers[number] << endl;
        numbers[number] +=1;
    }
    else{
        return -1;
    }
    
}

int main()
{
    int number;
    cin >> number; 
    while (number != 0){
        numberChecker(number);
        cin >> number;
    }

    return 0;
}
