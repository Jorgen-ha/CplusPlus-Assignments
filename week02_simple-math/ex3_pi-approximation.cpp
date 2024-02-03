// Approximating pi
#include <iostream> // Import the library for input/output
#include <math.h>   // Import the library for math functions
using namespace std; // Use the standard namespace

double pi (int n){
    // Implement the Leibniz formula for approximating pi
    double sum = 0;
    int i = 0;
    while (i < n){
        sum += pow(-1, i) / (2 * i + 1);
        i++;
    }
    return 4 * sum;
}

int main()
{
    int n;
    cin >> n; 
    double sum = pi(n);
    cout << sum << endl; 

    return 0;
}
