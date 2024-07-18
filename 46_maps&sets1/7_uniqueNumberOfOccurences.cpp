#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Storing the frequency of each element in the array
        unordered_map<int, int> freq;
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
