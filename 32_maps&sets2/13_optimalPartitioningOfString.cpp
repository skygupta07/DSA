// optimalPartitioningOfString.cpp

/*

Given a string s, partition the string into one or more substrings such that the 
characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
        int partitionString(string s) {
            unordered_set<char> st; // Set to track unique characters in the current partition
            int count = 1; // Start with 1 partition as at least one is required
    
            for (char c : s) {
                // If the character is already present in the current partition, start a new partition
                if (st.find(c) != st.end()) {
                    count++; // Increase partition count
                    st.clear(); // Clear the set for the new partition
                }
                st.insert(c); // Add character to the current partition
            }
    
            return count;
        }
};
    