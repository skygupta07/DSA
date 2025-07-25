//  Count Subarrays with given XOR

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp; // Map to store the frequency of prefix XORs
        long count = 0;            // To store the count of subarrays with XOR equal to k
        int prefixXOR = 0;         // To maintain the current prefix XOR
        
        // Traverse the array
        for (int num : arr) {
            // Update the prefix XOR
            prefixXOR ^= num;

            // If the current prefix XOR is equal to k, increment count
            if (prefixXOR == k) {
                count++;
            }

            // Check if the required XOR to form k exists in the map
            int requiredXOR = prefixXOR ^ k;

            if (mp.find(requiredXOR) != mp.end()) {
                count += mp[requiredXOR];
            }

            // Update the frequency of the current prefix XOR
            mp[prefixXOR]++;
        }

        return count; // Return the total count of subarrays
    }
};
