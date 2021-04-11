/*
    *   Authors:
    *   Kuntubayev Daniyar      d.kuntubayev@astanait.edu.kz
    *   Khusainov Zhakhongir    z.khusainov@astanait.edu.kz
*/

// importing header files from C++ STL
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>

using namespace std;

/*   
    functiom for Reading File
    It takes filename as parameter
    and returns string of chars
    that file contains
*/
string ReadFile(string fileName) {
    string result;
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            result = result + line + "\n";
        }
        myfile.close();
    }
    return result;
}

/*   
    functiom for Count Probabilities of 
    characters in text
    It takes string of characters as parameter
    and returns map of characters ASCII decimal values
    and their probabilities in text
*/
map<int, double> CountProbabilities(string inputString) {
    float oneCharProb = 0.0;
    map <int, double> charProbMap;
    oneCharProb = float(1) / float(inputString.size());
    
    for (int i=0; i<inputString.size(); i++) {
        int currentChar = inputString[i];
        // iterator is used for accessing element of map container
        map<int, double>::iterator it = charProbMap.find(currentChar);
        if (it != charProbMap.end()) {
            it->second = it->second + oneCharProb;
        } else {
            // function make_pair creates a key, value pair for
            // inserting into map
            charProbMap.insert(make_pair(int(inputString[i]), oneCharProb));
        }
    }
    
    return charProbMap;
}

/*   
    procedure for Printing Map of 
    characters and their probabilities
    It takes map of chars and probabilities as parameter
    and prints them in format:
    A - 0.02
    B - 0.4
    ...
*/
void PrintProbabilities(map<int, double> charProbMap) {
    map <int, double>::iterator itr;

    for (itr = charProbMap.begin(); itr != charProbMap.end(); ++itr) {
        if (itr->first == 10) {
            cout << "NL" << " - " << itr->second << "\n";
        } else if (itr->first == 32) {
            cout << "SPACE" << " - " << itr->second << "\n";
        } else {
        cout << char(itr->first) << " - " << itr->second << "\n";
        }
    }
}

int main() {
    string fileName = "Text.txt";
    string result;
    map <int, double> charProbMap;
    
    result = ReadFile(fileName);
    
    charProbMap = CountProbabilities(result);
    
    PrintProbabilities(charProbMap);

    return 0;
}
