// sortCharByFrequency.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.


Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.


Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

*/

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map <char, int> freqMap;
        for (char ch : s) freqMap[ch]++;
        

        // Step 2: Max heap to sort characters by frequency (higher frequency first)
        // The priority_queue stores pairs of (character, frequency)

        // simply jo karna h bas wahi return kar do... exactly yaha bhi wahi kiya h... like 
        // jiski kam frequency hogi wo maxHeap mai pehle hi chala jayega.. and finally 
        // elements with larger frequency will be higher up in the priority queue.

        // ye dekhne mai minHeap jaisi declaration lag sakti h ... but actually jab mujhe yaha custom
        // comparator pass karna hi h to phir mujhe iss tarah se hi karna padega...

        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;  // Max heap based on frequency
        };


        priority_queue <pair<char, int>, vector <pair <char, int>>, decltype(cmp)> maxHeap(cmp);

        for (const auto &entry : freqMap) {
            maxHeap.push(entry);
        }

        // Step 3: Build the result string using the heap
        string result;

        while (!maxHeap.empty()){
            auto [ch, freq] = maxHeap.top();  // character and its frequency
            maxHeap.pop();

            // Append 'ch' to result string 'freq' times
            result.append(freq, ch);
        }

        return result;

    }
};

