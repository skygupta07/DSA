// areAlmostEqual.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given two strings s1 and s2 consisting of only lowercase characters 
whose anagrams are almost equal. The task is to count the number of characters 
which needs to be edited(delete) to make s1 equal to s2.

Example:

Input:
s1 = madame
s2 = madam

Output:
1

Explanation:
String s1 = madame, string s2 = madam. 
character 'e' in first string needs to 
be deleted to make s1 equal to s2.
 

Your Task:
Print the count of characters needed to delete to make s1 and s2 equal. Complete the given function.

Expected Time Complexity: O(max(|s1|,|s2|))
Expected Auxilary Space: O(|s1| + |s2|) 

Constraints:
1 <= s1, s2 <= 1e4

*/


class Solution {
public:

    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Case when strings are already equal
        
        vector <int> diff;  // will store the index of characters wherever there will be mismatch
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        // There should be exactly 2 mismatched positions for a single swap to work
        if (diff.size() != 2) return false;
        
        // Check if swapping these positions makes them equal
        return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);

    }
    
};
