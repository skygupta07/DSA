#include <bits/stdc++.h>
using namespace std;



// Function to generate permutations of a string
void permutation(string &str, int i) {
    
    // Base case: If the current index `i` reaches the last index, print the current permutation
    if (i == str.size() - 1) {
        cout << str << "\n"; // Output the current permutation
        return;             // Terminate the current recursive call
    }

    // Use an unordered_set to ensure no duplicate characters are processed at this level
    unordered_set <char> st;

    // Loop to iterate through the characters starting from index `i`
    for (int idx = i; idx < str.size(); idx++) {
        // Check if the character at `idx` has already been used at this level
        if (st.count(str[idx])) continue; // Skip if the character is already present in the set

        // Insert the character into the set to mark it as processed
        st.insert(str[idx]);

        // Swap the character at index `i` with the character at index `idx`
        // This fixes one character in the current position
        swap(str[idx], str[i]);

        // Recursive call to generate permutations for the substring starting at `i + 1`
        permutation(str, i + 1);

        // Backtracking step: Undo the swap to restore the original string
        swap(str[idx], str[i]);
    }
}



int main() {
    string str = "abc"; // Input string for generating permutations
    permutation(str, 0); // Call the function starting from index 0
    return 0;
}



// but this will not work for repetition of words...
// backtracking use: 1. avoid faltu call (prone)
            //       2. revert the state to original after fn call step (reversal)












// backtrack karte time apne original state me revert back karte jao...
// string ko byreference pass karenge... otherwise pehle call by value mai bahut jyada
// space lag rha tha ab hum output string nahi banayenge....

// unordered set se trace bhi karte rahenge ki kaun kaun si call hogayi hai aur kaun si baaki hai
