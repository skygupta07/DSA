// minPushes.cpp

#include <bits/stdc++.h>
using namespace std;

/*


You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, 
which can be used to form words by pushing them. For example, the key 2 is mapped with 
["a","b","c"], we need to push the key one time to type "a", two times to type "b",
and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. 
You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. 
Note that 1, *, #, and 0 do not map to any letters.
 

Example 1:


Input: word = "abcde"
Output: 5

Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.


Example 2:

Input: word = "xyzxyzxyzxyz"
Output: 12

Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> one push on key 3
"z" -> one push on key 4
Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
It can be shown that no other mapping can provide a lower cost.
Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.


Example 3:
Input: word = "aabbccddeeffgghhiiiiii"
Output: 24

Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
"f" -> one push on key 7
"g" -> one push on key 8
"h" -> two pushes on key 9
"i" -> one push on key 9

Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
It can be shown that no other mapping can provide a lower cost.

*/


class Solution {
public:
    int minimumPushes(string word) {

        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character in the word
        for (auto ch : word) {
            freq[ch]++;
        }

        // Step 2: Max-heap to prioritize characters with highest frequency
        priority_queue<int> pq;

        for (auto it : freq) {
            pq.push(it.second); // Push frequency values
        }

        int count = 0; // How many unique characters we've processed
        int ans = 0;   // Final answer to store total pushes

        // Step 3: Assign keys to characters in decreasing order of frequency
        while (!pq.empty()) {
            int f = pq.top();
            pq.pop();

            // For every 8 characters, cost level increases by 1
            // 0–7 characters → cost = 1, 8–15 → cost = 2, etc.
            ans += f * (count / 8 + 1);

            count++;
        }

        return ans;
    }
};


/*

There are only 8 keys per page/level, so:
First 8 characters have cost multiplier 1
Next 8 have cost multiplier 2, and so on…

To minimize total cost, assign high-frequency characters first, i.e., with the lowest multiplier.
That’s why we use a max heap (priority queue) to process characters with highest frequency first.

*/


// ----------



class Solution {
public:

    unordered_map <char, int> mp;  // freq map banane ke liye global rakha

    // Comparator function to sort characters based on decreasing frequency
    static bool cmp(pair<char, int> &a, pair<char, int> &b) {
        return a.second > b.second;
    }

    int minimumPushes(string word) {

        // Step 1: Count frequency of each character
        for (auto ch : word) {
            mp[ch]++;
        }

        // Step 2: Convert freq map into a vector of pairs
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());

        // Step 3: Sort vector based on frequency in decreasing order
        sort(freqVec.begin(), freqVec.end(), cmp);

        // Step 4: Har 8 unique character ke bunch ko ek push level assign karenge
        unordered_map <char, int> pushes;
        
        int bunch = 8;  // ek level mein 8 characters max assign kar sakte hain
        int push = 1;   // starting push level

        for (int i = 0; i < freqVec.size(); i++) {
            if (bunch == 0) {
                // naye level ke liye reset kar diya
                push++;
                bunch = 8;
            }

            // current character ko push level assign kar diya
            pushes[freqVec[i].first] = push;
            bunch--;
        }

        // Step 5: Final answer = har character ke frequency * uska assigned push level
        int ans = 0;
        
        for (char ch : word) {
            ans += pushes[ch];
        }

        return ans;
    }

};
