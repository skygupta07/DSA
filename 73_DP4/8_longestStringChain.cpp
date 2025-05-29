// longestStringChain.cpp
#include <bits/stdc++.h>
using namespace std;

/*

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, 
where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. 
A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 
Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].


Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].


Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.


*/


/*

Our primary weapon of choice for this challenge is Dynamic Programming, 
a strategy that breaks problems down into smaller, more manageable sub-problems. 
The beauty of this approach lies in its ability to remember past results, 
which significantly speeds up computing the final solution.

In dynamic programming, transition functions act like bridges, 
connecting sub-problems to construct the bigger picture.

*/


// using mp (any data structure could be used) as a dp here...

class Solution {
public:

    // Function to find longest string chain
    int longestStrChain(vector <string> &words) {

        // Pehle words ko sort karenge unki length ke hisaab se chhote se bade tak
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.length() < b.length();
        });

        // Ek map banayenge jisme har word ka maximum chain length store hoga

        unordered_map <string, int> mp;
        // string, maxChainLength

        int maxChain = 0; // Maximum chain length track karne ke liye

        // Har word ke liye loop chalana hai
        for (const auto &word : words){
            mp[word] = 1; // Har word ki shuruaat me chain length 1 hogi

            // current word ke ith character ko remove karke check karenge ki prevWord map me hai ya nahi
            for (int i=0; i<word.length(); i++){

                 // Character hata kar naye word ka creation
                string prevWord = word.substr(0, i) + word.substr(i+1);

                // Agar prevWord map me milta hai, to phir iss current word ki chain length update karenge
                if (mp.find(prevWord) != mp.end()){
                    mp[word] = max(mp[word], mp[prevWord] + 1); // Maximum chain length update karenge
                }
            }

            // Har iteration ke baad maximum chain length ko update karenge - jo bhi capable word hoga wo
            //  ultimately chain length maximize karta jayega...
            maxChain = max(maxChain, mp[word]);

        }

        return maxChain; // Maximum chain length return karenge
    }
};

