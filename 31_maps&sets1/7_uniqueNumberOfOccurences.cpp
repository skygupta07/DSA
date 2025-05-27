#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers arr, return true if the number of occurrences of each value 
in the array is unique or false otherwise.
 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. 
No two values have the same number of occurrences.


Example 2:

Input: arr = [1,2]
Output: false


Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/


class Solution {
public:

    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Storing the frequency of each element in the array
        unordered_map <int, int> freq;

        for (auto el : arr) {
            freq[el]++;
        }

        // Step 2: Using an unordered_set to track the unique frequencies
        unordered_set<int> st;

        // Step 3: Checking if all frequencies are unique
        for (auto el : freq) {
            // If the frequency is already in the set, return false
            if (st.find(el.second) != st.end()) {
                return false;
            }
            // Otherwise, insert the frequency into the set
            st.insert(el.second);
        }

        // Step 4: If all frequencies are unique, return true
        return true;
    }
};
