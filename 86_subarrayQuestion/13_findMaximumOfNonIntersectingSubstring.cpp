// findMaximumOfNonIntersectingSubstring.cpp

/*

You are given a string word.

Return the maximum number of non-intersecting substrings of word 
that are at least four characters long and start and end with the same letter.

 
Example 1:

Input: word = "abcdeafdef"
Output: 2

Explanation:

The two substrings are "abcdea" and "fdef".

Example 2:

Input: word = "bcdaaaab"
Output: 1

Explanation:

The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" 
since it intersects with the other substring.

 

Constraints:

1 <= word.length <= 2 * 1e5
word consists only of lowercase English letters.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxSubstrings(string word) {
        int n = word.length();
        
        vector <pair <int, int>> candidates;

        // Step 1: Find all valid substrings (length >= 4 & same start and end)
        for (int i = 0; i < n; i++) {
            for (int j = i + 3; j < n; j++) {
                if (word[i] == word[j]) {
                    candidates.push_back({i, j});
                }
            }
        }

        // Step 2: Sort by end index for greedy selection
        sort(candidates.begin(), candidates.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Step 3: Select maximum non-overlapping substrings
        int count = 0;
        int lastEnd = -1;

        for (auto &[start, end] : candidates) {
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        return count;
    }
};


class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        int count = 0;
        int lastEnd = -1;

        // For all characters from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++) {
            vector<int> positions;

            // Step 1: Store all positions of current character
            for (int i = 0; i < n; i++) {
                if (word[i] == ch) {
                    positions.push_back(i);
                }
            }

            // Step 2: Try forming valid substrings with same start and end character
            int sz = positions.size();
            for (int i = 0; i < sz; i++) {
                for (int j = sz - 1; j > i; j--) {
                    int start = positions[i];
                    int end = positions[j];

                    // Check: length >= 4 and no overlap
                    if (end - start + 1 >= 4 && start > lastEnd) {
                        count++;
                        lastEnd = end;
                        i = j; // skip overlapping ones
                        break;
                    }
                }
            }
        }

        return count;
    }
};

