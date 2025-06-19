// longestUnequalAdjacentGroupSubsequence.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given a string array words and a binary array groups both of length n.

A subsequence of words is alternating if for any two consecutive strings in the sequence,
their corresponding elements at the same indices in groups are different
(that is, there cannot be consecutive 0 or 1).

Your task is to select the longest alternating subsequence from words.

Return the selected subsequence. If there are multiple answers, return any of them.
Note: The elements in words are distinct.

Example 1:

Input: words = ["e","a","b"], groups = [0,0,1]

Output: ["e","b"]
Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2].
Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2].
It can be demonstrated that the length of the longest subsequence of indices that satisfies
the condition is 2.


Example 2:
Input: words = ["a","b","c","d"], groups = [1,0,1,1]
Output: ["a","b","c"]

Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1]
and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"]
because groups[0] != groups[1] and groups[1] != groups[3].
It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.


Constraints:

1 <= n == words.length == groups.length <= 100
1 <= words[i].length <= 10
groups[i] is either 0 or 1.
words consists of distinct strings.
words[i] consists of lowercase English letters.

*/

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups){
        vector<string> ans;

        bool oneFlag = 1;

        vector<int> oneStart;
        vector<int> zeroStart;

        for (int i = 0; i < groups.size(); i++){
            if (groups[i] == oneFlag){

                oneStart.push_back(i);
                oneFlag = !oneFlag;

            }
        }

        // reset
        oneFlag = 0;

        for (int i = 0; i < groups.size(); i++){
            if (groups[i] == oneFlag) {

                zeroStart.push_back(i);
                oneFlag = !oneFlag;

            }
        }

        bool winnerCase = (oneStart.size() > zeroStart.size());

        if (winnerCase) {

            for (int i = 0; i < oneStart.size(); i++){
                ans.push_back(words[oneStart[i]]);
            }

        }

        else{

            for (int i = 0; i < zeroStart.size(); i++){
                ans.push_back(words[zeroStart[i]]);
            }
        }

        return ans;
    }
};

/*
longest alternating subsequence

for any two consecutive strings in the sequence,
their corresponding elements in the binary array groups differ.


take two case
starting from 1 , starting from zero
take max of two case
alternating zero count, one count
*/

// asli dsa
class Solution {
public:
    vector <string> getLongestSubsequence(vector <string> &words, vector <int> &groups) {
        vector <string> ans;

        int last = -1;

        for (int i = 0; i < words.size(); i++){
            
            if (groups[i] != last) {
                ans.push_back(words[i]);

                // jo abhi encounter kiya wo mention bhi to karega...
                last = groups[i];
            }

        }
        
        return ans;

    }
};