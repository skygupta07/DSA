#include <bits/stdc++.h>
using namespace std;

    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        
        vector<int> ans;                  // To store the majority elements
        map <int, int> mp;       // To count occurrences of each element
    
        for (int el : arr) {
            mp[el]++;                     // Increment count for each element
        }
    
        int minVote = arr.size() / 3;     // Threshold for majority
        for (auto& el : mp) {             // Iterate over map
            if (el.second > minVote) {    // Check if count exceeds threshold
                ans.push_back(el.first);  // Add to result
            }
        }
    
        return ans;                       // Return majority elements
    }