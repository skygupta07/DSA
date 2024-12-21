// you are given a string consisting of small alphabets. consider no repetition in the
// characters. Print all possible permutation of the string. ordering doesn't matter
#include <bits/stdc++.h>
using namespace std;

void permutation(string input, string output) {
    // Base case: If the input string is empty, we have formed one permutation
    if (input.size() == 0) {
        cout << output << "\n"; // Print the current permutation
        return;                // Terminate the recursive call
    }

    // Loop to iterate over each character in the input string
    for (int i = 0; i < input.size(); i++) {
        // Extract the character at the current index `i`
        char ch = input[i];

        // Get the part of the string before the current index
        // 0th index se leke (i - 1)th index tak characters se string bana dega...
        string left = input.substr(0, i);

        // Get the part of the string after the current index
        string right = input.substr(i + 1); // `i+1` to end of the string

        // Combine `left` and `right` to form the rest of the string (excluding `ch`)
        string ros = left + right;

        // Recursive call: Add the current character (`ch`) to the output
        // and find permutations of the rest of the string (`ros`)
        permutation(ros, output + ch);
    }
}



int main(){
    permutation("abc", " ");
    return 0;
}











// every character of input string is given a chance to become first character of output string
// then next element is appended at its end...

