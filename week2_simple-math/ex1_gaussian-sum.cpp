// Gaussian sum
#include <iostream>  // Import the library for input/output
                     
                     
using namespace std; // Use the standard namespace
                     
int main()
{
    int gaussian;
    int sum = 0;     
    cin >> gaussian; // Store the number of iterations
    int i = 1;
    while (i <= gaussian)
    {   
        sum += i; // Add current number to the sum
        i++;
    }

    cout << sum << endl; // Output the sum to the user

    return 0;
}
