// Palindrome
#include <iostream> // Import the library for input/output
#include <string>   // Import the library for strings
#include <vector>   // Import the library for vectors

using namespace std; // Use the standard namespace

void splitLineRecursively(string sentence, vector<int> &allNums){
    // Divide the input by the space character until the newline character
    if (sentence.find(' ') != string::npos){
        int space = sentence.find(' ');
        int num = stoi(sentence.substr(0, space));
        allNums.push_back(num);
        sentence = sentence.substr(space + 1);
        splitLineRecursively(sentence, allNums);
    }else{
        allNums.push_back(stoi(sentence)); // Remember to get the last number
    }
}

void palindromeRecursively(vector<int> &allNums){
    if (allNums.size() == 0){
        cout << "yes" << endl;
        return;
    }else{
        int first = allNums.front();
        int last = allNums.back();
        if (first == last){
            if (allNums.size() == 1){
                cout << "yes" << endl;
                return;
            }
            allNums.erase(allNums.begin());
            allNums.pop_back();
            palindromeRecursively(allNums);
        }else{
            cout << "no" << endl;
            return;
        }
    }
}

int main(){
    string line;
    vector<int> allNums;

    getline(cin, line);
    splitLineRecursively(line, allNums); // After this, allNums hold all the numbers
    palindromeRecursively(allNums);

    return 0;
}
