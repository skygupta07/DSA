// findAllTripletsWithZeroSum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.


Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-1e5 <= nums[i] <= 1e5

*/

// User function Template for C++
class Solution {
public:

    vector <vector <int>> findTriplets(vector <int> &arr){
        // Code here
        
        // Yeh set triplets ko unique banane ke liye use kiya hai
        set <vector<int>> st;
        
        int n = arr.size();
        
        // Yeh map har possible pair ka sum ko store karega 
        // aur saath mein pair ka index bhi store karega
        unordered_map <int, vector<pair<int, int>> > mp;
        
        // Pehle step mein, har pair ka sum calculate karke map mein daal do
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                mp[arr[i] + arr[j]].push_back({i, j}); 

                // `arr[i] + arr[j]` ek key banega aur value mein index pairs honge
            }
        }

        // Ab ek-ek element ko fix karo aur uska complement dhoondo
        for (int i = 0; i < n; i++) {
            
            int rem = -arr[i]; // Complement calculate kiya (-arr[i])

            // Check karo ki complement map mein hai ya nahi
            if (mp.find(rem) != mp.end()) {

                vector <pair <int, int>> pairs = mp[rem]; 
                // Jo pairs is complement ke liye hain, unhe fetch kiya
                
                for (auto p : pairs) { 
                    // Har pair ko check karo jo complement ke liye match kar raha hai
                    
                    if (p.first != i && p.second != i) { 
                        // Ensure karo ki current fixed element i, pair ke indices se match na kare
                        vector <int> curr = {i, p.first, p.second}; 
                        
                        // Triplet banaya
                        sort(curr.begin(), curr.end()); 
                        // Ensure ki triplet sorted ho (i < j < k)

                        st.insert(curr); 
                        // Unique triplet ko set mein daal diya
                    }
                }
            }

        }

        // Ab set ke unique elements ko vector mein convert karke return karo
        vector <vector <int>> res(st.begin(), st.end());
        
        return res;
    }
};
