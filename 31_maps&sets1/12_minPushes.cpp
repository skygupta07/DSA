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
        unordered_map<char, int> mp;

        for(auto ch : word) mp[ch]++;

        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);
        
        int count = 0; 
        int ans = 0;

        while(!pq.empty()){

            int n = pq.top();
            pq.pop();
            
            ans += n*(count/8 + 1);
            count++;
        }
        
        return ans;
    }
};



// ----------


class Solution {
public:

    unordered_map <char,int> mp;

    // Custom comparison function for sorting the freqVector in decreasing order
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
    }

    int minimumPushes(string word) {
        // Calculate frequency of each character
        for (auto ch : word) {
            mp[ch]++;
        }

        // Convert the frequency map to a vector of pairs for sorting -> good method
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());

        // Sort the characters based on frequency in decreasing order
        sort(freqVec.begin(), freqVec.end(), cmp);

        // Map to store push values
        unordered_map<char, int> pushes;
        int bunch = 8;  // 8 8 8 2 ka guccha hi form hoga max since 26 chars
        int push = 1;

        // Assign push values to the first 8 unique characters, then to the next 8, and so on
        for (int i = 0; i < freqVec.size(); i++) {
            if (bunch == 0) {       // good way to update things in for loop as well
                push++;
                bunch = 8;
            }
            pushes[freqVec[i].first] = push;    // corresponding character ko uski push value assign karwayi....
            bunch--;
        }

        // Calculate the minimum pushes required
        int ans = 0;
        for (int i = 0; i < word.length(); i++) {
            ans += pushes[word[i]];
        }

        return ans;
    }
};