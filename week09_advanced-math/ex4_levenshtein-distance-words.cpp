// Levenshtein distance
#include <iostream> // Import the library for input/output
#include <string>   // Import the library for strings
#include <vector>   // Import the library for vectors

using namespace std; // Use the standard namespace

void splitLineRecursively(string sentence, vector<string> &allWords){
    // Divide the input by the space character until the newline character
    if (sentence.find(' ') != string::npos){
        int space = sentence.find(' ');
        string word = sentence.substr(0, space);
        allWords.push_back(word);
        sentence = sentence.substr(space + 1);
        splitLineRecursively(sentence, allWords);
    }else{
        allWords.push_back(sentence);   // Remember to get the last word
    }
}

int levenshteinRecursively(string u, string v){
    if (u.length() == 0){
        return v.length();
    }else if (v.length() == 0){
        return u.length();
    }else{
        int tmp = min((levenshteinRecursively(u.substr(1), v)+1), 
                      (levenshteinRecursively(u, v.substr(1))+1));
        int tmp2 = levenshteinRecursively(u.substr(1), v.substr(1)) + int(u[0] != v[0]);
        int d = min(tmp, tmp2);
        return d;
    }
}
int main(){
    string line;
    vector<string> allWords;

    getline(cin, line);
    splitLineRecursively(line, allWords); // After this, allWords hold all the words
    string u = allWords[0];
    string v = allWords[1];
    int d = levenshteinRecursively(u, v);     // This will calculate the Levenshtein distance between the two words
    cout << d << endl;
    return 0;
}
