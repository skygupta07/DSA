// groupAnagrams.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.
 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.


Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 
Constraints:

1 <= strs.length <= 1e4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

// waah kya kaarigari h ...in haatho ko to kaat dena chahiye 🥲
class Solution {
public:

    /*
        Intuition:
        ----------
        - Anagrams are strings that, when sorted, become identical.
        - So, we can group words that are anagrams by sorting each string and using
          the sorted string as a key in a hash map.
        - All anagrams will map to the same sorted key.

        For example:
        - "eat", "tea", "ate" all become "aet" after sorting.
        - So, we can store them in the same group in a map.
    */

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp; // Map: sorted string → list of anagrams

        // Step 1: For every string in input
        for (auto s : strs) {
            string originalString = s;

            // Step 2: Sort the string to get the key
            sort(s.begin(), s.end());

            // Step 3: Group original string using the sorted key
            mp[s].push_back(originalString);
        }

        // Step 4: Push all grouped anagram vectors into result
        for (auto [key, vectOfStrings] : mp) {
            result.push_back(vectOfStrings);
        }

        return result;
    }
};



/*

Input: ["eat","tea","tan","ate","nat","bat"]

After sorting and grouping:
{
    "aet": ["eat", "tea", "ate"],
    "ant": ["tan", "nat"],
    "abt": ["bat"]
}

Output: [["eat","tea","ate"],["tan","nat"],["bat"]]


*/



/*

Time Complexity: O(N * K log K)
N = number of strings in the input.
K = maximum length of a string.
Sorting each string takes O(K log K).
Total = O(N * K log K)


🧠 Space Complexity: O(N * K)
We store all the strings in the hash map.
In the worst case, each string is in its own group.
So the map and result both take up to O(N * K) space.

*/

 