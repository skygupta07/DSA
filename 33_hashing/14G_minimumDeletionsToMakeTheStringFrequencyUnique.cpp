// minimumDeletionsToMakeTheStringFrequencyUnique.cpp

#include <bits/stdc++.h>
using namespace std;


/*

A string s is called good if there are no two different characters in s that have the same frequency.
Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. 
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.


Example 2:

Input: s = "aaabbbcc"
Output: 2

Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".


Example 3:

Input: s = "ceabaacb"
Output: 2

Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end 
(i.e. frequency of 0 is ignored).
 

Constraints:

1 <= s.length <= 1e5
s contains only lowercase English letters.

*/


class Solution {
public:

    int minDeletions(string s) {
        // Step 1: Frequency count of all characters (a to z)

        vector <int> freq(26, 0);

        for (auto ch : s) freq[ch - 'a']++;

        // Step 2: Sort the frequency array in ascending order
        sort(freq.begin(), freq.end());

        int delCount = 0;

        // Step 3: Start from second highest frequency and go downwards
        // Hum ensure karenge ki freq[i] < freq[i+1] (i.e., unique frequencies)

        for (int i = 24; i >= 0; i--) {

            // Agar frequency 0 aa gayi to aage sab 0 hi hoga, toh break
            if (freq[i] == 0) break; 

            // Agar current frequency >= next frequency

            if (freq[i] >= freq[i + 1]) {
                // Store current frequency
                int prev = freq[i];

                // Reduce freq[i] to make it strictly less than freq[i+1]
                // max(0, freq[i+1] - 1) => isse frequency 0 se kam nahi hogi
                freq[i] = max(0, freq[i + 1] - 1);

                // Kitne deletions kiye uss character se => prev - freq[i]
                delCount += prev - freq[i];
            }
        }
        return delCount;
    }

};


class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freqMap;

        // Step 1: Count frequency of each character
        for (const auto &ch : s)
            freqMap[ch]++;

        // Step 2: Max-heap (priority_queue) to store all frequencies
        priority_queue<int> pq;
        for (const auto &[ch, freq] : freqMap) {
            pq.push(freq);
        }

        int delCount = 0;

        // Step 3: Process frequencies from max to min
        while (pq.size() > 1) {
            int topFreq = pq.top(); // Top frequency (max value)
            pq.pop();

            // Agar top aur next top frequency same hai -> frequency clash ho raha hai
            if (pq.top() == topFreq) {
                // Delete 1 occurrence (reduce freq by 1)
                delCount++;

                // Agar reduced frequency > 0 hai to heap me dubara daalo
                if (topFreq - 1 > 0)
                    pq.push(topFreq - 1);
            }
            // Else: frequency unique hai, kuch nahi karna
        }

        return delCount;
    }
};
