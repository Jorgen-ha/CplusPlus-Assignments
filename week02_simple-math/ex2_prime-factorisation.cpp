// Prime Factorisation
#include <iostream> // Import the library for input/output

using namespace std; // Use the standard namespace

int main()
{
    int factorMe;
    cin >> factorMe;              // Store the number to be factorised
    int i = 2;
    while (factorMe > 1)
    {
        if (factorMe % i == 0){  // Check if the number is divisible by i
            if (factorMe != i){
                cout << i << " * ";
            }
            factorMe /= i;      // Divide the number
        }
        else{
            i++;
        }
    }

    cout << i << endl; 

    return 0;
}
