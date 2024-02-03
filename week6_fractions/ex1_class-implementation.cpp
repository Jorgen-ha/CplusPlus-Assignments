// Fractions and integers
#include <iostream>  
#include <string>
#include <algorithm>

using namespace std; // Use the standard namespace

class Fraction{

    private:
        int numerator, denominator;
    
    public:
        Fraction(int numerator, int denominator){ // Constructor
            this->numerator = numerator;
            this->denominator = denominator;
        }; 
        ~Fraction(){};                            // Destructor
        
        // Helper functions
        void add(Fraction f);
        void mult(Fraction f);
        void div(Fraction f);
        void simplify(void);
        void disp(void);
};

/// @brief Function adding a fraction to this fraction
void Fraction::add(Fraction f){
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
}

/// @brief Function multiplying a fraction to this fraction
void Fraction::mult(Fraction f){
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;
}

/// @brief Function dividing a fraction to this fraction
void Fraction::div(Fraction f){
    numerator = numerator * f.denominator;
    denominator = denominator * f.numerator;
}

/// @brief Function simplifying a fraction to the lowest common denominator 
void Fraction::simplify(void){
    int gcd = __gcd(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

/// @brief Function displaying a fraction 
void Fraction::disp(void){
    cout << numerator << " / " << denominator << endl;
}

/// @brief Function reading one fraction from a string
/// @param input string containing the fraction
/// @return the fraction
Fraction readFraction(string &input){
    int space = input.find(' ');
    int num = stoi(input.substr(0, space));
    input = input.substr(space + 3);
    space = input.find(' ');
    int denom = stoi(input.substr(0, space));
    input = input.substr(space + 1);
    return Fraction(num, denom);
}
/// @brief Function that splits the input string and performs the calculation
void splitCalculate(string input){
    // Read first fraction
    Fraction f1 = readFraction(input);

    // Read the arithmetic operation
    int space = input.find(' ');
    string arith = input.substr(0, space);
    
    // Read second fraction
    input = input.substr(space + 1);
    Fraction f2 = readFraction(input);

    // Perform the operation
    if (arith == "+"){
        f1.add(f2);
    }else if (arith == "*"){
        f1.mult(f2);
    }else {
        f1.div(f2);
    }

    // Simplify and display the result
    f1.simplify();
    f1.disp();
}


int main(){
    string input;
    getline(cin, input);        // Get user input
    while(cin && input != ""){
        splitCalculate(input);  // Perform the calculation
        getline(cin, input);    // Get user input
    }

    return 0;
}


