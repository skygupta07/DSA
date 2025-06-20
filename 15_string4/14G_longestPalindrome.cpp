// longestPalindrome.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given an array of strings words.
Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words
and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create.
If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.


Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.


Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".


Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.


*/

class Solution{
public:
    int longestPalindrome(vector<string> &words){

        // Step 1: Count the frequency of each word
        unordered_map <string, int> freqMap;
        for (const auto &word : words) freqMap[word]++;

        int totalLen = 0;       // final length of the longest palindrome
        bool hasCenter = false; // to track if we can put a palindromic word in the middle

        // Step 2: Traverse through each word and handle two cases
        for (auto &[word, freq] : freqMap){

            string rev = word;
            reverse(rev.begin(), rev.end()); // create reverse of current word

            // Case 1: word is NOT a palindrome itself (like "ab", "ba")
            if (word != rev){

                // If reverse word also exists in the map
                if (freqMap.find(rev) != freqMap.end()){

                    // You can pair min(word freq, reverse word freq) times
                    int pairFreq = min(freq, freqMap[rev]);

                    // Each such pair contributes 4 characters (2 from word, 2 from rev)
                    totalLen += pairFreq * 4;

                    // Reduce the used frequency to avoid double counting
                    freqMap[word] -= pairFreq;
                    freqMap[rev] -= pairFreq;
                }

            }

            // Case 2: word is a palindrome itself (like "gg", "aa")
            else{

                // (freq / 2) pairs possible, each contributing 4 characters
                totalLen += (freq / 2) * 4;

                // If one leftover palindromic word exists (like "gg"), it can sit in the center
                if (freq % 2 == 1) hasCenter = true;
            }
        }

        // Step 3: If we had one palindromic word left unused, put it in the center
        if (hasCenter) totalLen += 2;

        return totalLen;
    }
};
