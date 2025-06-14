// wordSubsets.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
{ab chutiyo ne diya h to maan lo..
aur jyada socho mat...}

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.


Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]


Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]
Output: ["leetcode"]

Example 3:

Input: words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]
Output: ["cccbb"]

 
Constraints:

1 <= words1.length, words2.length <= 10pow4
1 <= words1[i].length, words2[i].length <= 10

words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.

*/


#include <bits/stdc++.h>
using namespace std;


/*

💡 Problem Intuition:
======================

- Hume 2 list di gayi hai: `words1` and `words2`.
- Har word `a` in words1 tab "universal" hoga jab wo **har** word `b` in words2 ka **superset** ho.
- Superset ka matlab: `a` should contain **at least as many characters** as `b` — including **duplicates**.

🔁 Example:
-----------
words1 = ["amazon","apple","facebook","google","leetcode"]
words2 = ["e", "o"]

Toh "facebook", "google", "leetcode" me 'e' aur 'o' dono letters hai (sufficient times) — ✅ universal.


🧠 Efficient Approach:
-----------------------
- words2 ke sare words ke character frequency ka **maximum requirement** nikaalo.
- Fir words1 ke har word ko check karo ki wo is requirement ko fulfill karta hai ya nahi.
- Agar karta hai, toh wo universal hai.

*/

// ✅ Helper function to get character frequency count for a word
vector <int> getCharCount(const string &s) {
    
    // ha bhai simple vector se bhi frequency maintain kari jaa sakti h...
    vector <int> count(26, 0); // For all lowercase English letters
    
    for (char ch : s) {
        count[ch - 'a']++;  // Increment count for each character
    }

    return count;
}


class Solution {
public:

    vector <string> wordSubsets(vector <string> &words1, vector <string> &words2) {
        vector <string> ans;

        // Step 1: Build the "max required frequency" from words2
        // maxFreq[i] = max frequency of 'a'+i among all words2
        vector <int> maxFreq(26, 0);

        for (const string &word : words2) {
            vector <int> freq = getCharCount(word); // Current word ka freq

            // Update max frequency required for each character
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }

        }

        // Step 2: Check for each word in words1 if it fulfills the maxFreq condition
        for (const string &word : words1){

            vector <int> freq = getCharCount(word); // Current word ka freq
            
            bool isUniversal = true; // current word ko universal maana pehle then dekho kya sach much 
            // universal h kya ??

            // Check all characters
            for (int i = 0; i < 26; i++) {

                if (freq[i] < maxFreq[i]) {
                    // Agar frequency kam hai kisi required character ki, toh reject
                    isUniversal = false;
                    break;
                }

            }
            // Ye word universal hai
            if (isUniversal) ans.push_back(word); 
        }

        return ans;
    }
};
