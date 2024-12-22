#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1_freq(26, 0);
        vector <int> window_freq(26,0);

        // Count frequency of each character in s1
        for (char ch : s1) s1_freq[ch - 'a']++; // taaki zeroth index pe a ki frequency store ho..


        // Sliding window over s2 of size s1.length()
        int window_size = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            // Add current character to the window frequency
            window_freq[s2[i] - 'a']++;

            // Remove the character left out of the sliding window
            if (i >= window_size) { // ratto step
                window_freq[s2[i - window_size] - 'a']--;
            }

            // Compare frequency vectors
            if (window_freq == s1_freq) return true;
        }

        return false;
    }
};


/*

Hint 1
Obviously, brute force will result in TLE. Think of something else.

Hint 2
How will you check whether one string is a permutation of another string?

Hint 3
One way is to sort the string and then compare. But, Is there a better way?

Hint 4
If one string is a permutation of another string then they must have one common metric. What is that?

Hint 5
Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?

Hint 6
What about hash table? An array of size 26?

*/
