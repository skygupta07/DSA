#include <bits/stdc++.h>
using namespace std;



// Function to find the length of the longest sentence

int find_longest_sentence_length(string s) {
    // Replace all periods (.) with commas (,)
    for (char &c : s) {
        if (c == '.') c = ',';
    }

    stringstream ss(s);  // Create a stream from the input string
    string sentence;     // To store each sentence

    int maxWordCount = 0; // Variable to track the maximum word count

    // Split the input into sentences using ',' as a delimiter
    while (getline(ss, sentence, ',')){
        stringstream sentenceStream(sentence); // Stream for the current sentence
        
        string word;                           // To store each word
        int currentWordCount = 0;              // Word count for this sentence

        // Count words in the current sentence
        while (sentenceStream >> word) {
            currentWordCount++;
        }

        // Update the maximum word count
        maxWordCount = max(maxWordCount, currentWordCount);
    }

    return maxWordCount; // Return the length of the longest sentence
}

int main() {
    string s;
    getline(cin, s); // Read the entire input string

    // Call the function and output the result
    int result = find_longest_sentence_length(s);
    cout << result << endl;

    return 0;
}
