// reorganizeString.cpp

/*

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"


Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string reorganizeString(string s) {
        unordered_map<char, int> mp;  // Step 1: Count frequencies

        for (char ch : s) {
            mp[ch]++;
        }

        // Step 2: Max Heap to store characters sorted by freq (max first)
        priority_queue<pair<int, char>> pq;

        for (auto el : mp) {
            pq.push({el.second, el.first});  // {freq, char}
        }

        string ans = "";

        // Step 3: While heap has more than 1 character
        while (pq.size() > 1) {

            auto [freq1, ch1] = pq.top(); pq.pop();
            auto [freq2, ch2] = pq.top(); pq.pop();

            // Add both to result (as they won't be adjacent)
            ans += ch1;
            ans += ch2;

            // Decrease their freq (since used once)
            if (--freq1 > 0) {
                pq.push({freq1, ch1});
            }

            if (--freq2 > 0) {
                pq.push({freq2, ch2});
            }
        }

        // Step 4: Handle the last remaining char (if any)
        if (!pq.empty()) {
            auto [freq, ch] = pq.top(); pq.pop();

            if (freq > 1) return ""; // Not possible to place without repeat
            ans += ch;  // else safe to add one occurrence
        }

        return ans;
    }
};


/*
alternatively put characters with the maximum frequency.

maxHeap with {freq, char}
while (heap.size() > 1) -> take two character append them to ans decrease their freq and push 
them again into heap

when loop break , either heap became empty or of size 1.


if empty() => return ans;
else{
    if the remaining element's freq is 1 then add it in ans and return 
    else return ""
}

*/


/*

Count frequencies of all characters using a map<char, int>.
Push all {freq, char} into a max heap (priority queue in descending order of freq).
While the heap has at least 2 characters:
Pop two most frequent characters (say ch1, ch2)
Append both to the result string
Decrease their frequencies by 1
If any still have remaining freq, push them back into heap
After the loop:
If one character is left, check if its frequency is 1, if yes, append to result
If more than 1 → impossible ⇒ return ""
Return the result.

*/


/*

O(N log K) where:

N = s.length()
K = unique characters (max 26 for lowercase)

Why log K? Because each push/pop in heap takes log K.

✅ Space Complexity

O(K) for heap + map

*/