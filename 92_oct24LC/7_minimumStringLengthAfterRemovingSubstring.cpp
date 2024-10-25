#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the minimum length of the string after erasing certain pairs
    int minLength(string s) {
        // Initialize a stack to help process the string and remove valid pairs
        stack<char> stack;

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            char cur_char = s[i]; // Current character being processed

            // If the stack is empty, push the current character
            if (stack.empty()) {    
                stack.push(cur_char);
            }

            // Check if the current character forms a valid pair with the top of the stack
            // If current character is 'B' and the top of the stack is 'A', pop the stack (erase the pair "AB")
            else if (cur_char == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            // Similarly, if current character is 'D' and the top of the stack is 'C', pop the stack (erase the pair "CD")
            else if (cur_char == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            // If no valid pair is formed, push the current character onto the stack
            else {
                stack.push(cur_char);
            }
        }

        // The remaining size of the stack represents the length of the modified string
        return stack.size();
    }
};


class Solution {
public:
    int minLength(string s) {
        vector<char> v(s.begin(), s.end()); // Initialize the vector with characters from string s

        if (v.size() < 1) return v.size();

        bool nextPassAllow = true;

        while (nextPassAllow && v.size() > 1) {
            bool changesMade = false;
            for (int i = 0; i < v.size() - 1; i++) {
                // Create a string with the current and next character
                string curr = string(1, v[i]) + string(1, v[i + 1]);

                // Check if it's "AB" or "CD"
                if (curr == "AB" || curr == "CD") {
                    // Erase these two characters from the vector
                    v.erase(v.begin() + i, v.begin() + i + 2);
                    changesMade = true;
                    break;  // Break to restart the loop since the vector size has changed
                }
            }

            // If no changes were made in this pass, exit the loop
            if (!changesMade) nextPassAllow = false;
        }

        return v.size();  // Return the remaining size of the vector
    }
};