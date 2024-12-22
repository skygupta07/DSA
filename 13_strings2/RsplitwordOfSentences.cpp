#include <iostream>   // For input-output operations
#include <string>     // For string operations
#include <vector>     // For vector (not used here but included in original code)
#include <sstream>    // For stringstream functionality

using namespace std;

int main() {
    string s;  // This will store the user input string

    // Prompt the user to enter a string
    cout << "Enter the string: ";
    getline(cin, s);  // Reading the entire line of input including spaces into `s`

    string temp;  // Temporary string to store individual words
    stringstream ss(s);  // Create a stringstream object `ss` initialized with the input string `s`
    // `ss` will now act as a stream to read from the string `s`

    // Loop to extract words from the stringstream object `ss`
    while (ss >> temp) {
        // `ss >> temp` extracts the next word (separated by spaces) from the stream
        cout << temp << endl;  // Print the extracted word
    }
    
    // After the loop ends, all words in the string will have been printed line by line.
}
