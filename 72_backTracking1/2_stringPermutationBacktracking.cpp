#include <bits/stdc++.h>
using namespace std;

void permutation(string &str, int i) { // The string is passed by reference to avoid copying and optimize performance
    // Base case: If the current index `i` reaches the last index, print the current permutation
    if (i == str.size() - 1) {
        cout << str << "\n"; // Output the current permutation
        return;             // Terminate (#important) the current recursive call
    }

    // Loop to iterate through the characters starting from the current index `i`
    for (int idx = i; idx < str.size(); idx++) {
        // Swap the character at the current index `i` with the character at `idx`
        // This brings one possible character to the current position
        swap(str[idx], str[i]);

        // Recursive call to generate permutations for the substring starting from `i + 1`
        permutation(str, i + 1);

        // Backtracking step: Undo the swap to revert the string to its original state
        // This ensures that the next iteration works with the unmodified string
        swap(str[idx], str[i]);
    }
}


int main(){
    string str = "abc";
    permutation(str, 0);
    return 0;
}


// but this will not work for repetition of words...
// i.e. only for distinct words
/*
here no need to create output strings instead swap in the original string and see permutation

*/

// backtrack karte time apne original state me revert back karte jao...

// apni string ko hi by reference pass karenge... otherwise pehle call by value mai bahut jyada
// space lag rha tha ab hum output string nahi banayenge.... 