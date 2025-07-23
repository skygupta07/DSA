// rankTransformOfAnArray.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. 
The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, 
their rank must be the same.

Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]

Explanation: 40 is the largest element. 
10 is the smallest. 
20 is the second smallest. 
30 is the third smallest.


Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]

Explanation: Same elements share the same rank.


Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 1e5
-1e9 <= arr[i] <= 1e9

*/


/*

Problem: Har number ko uska "rank" dena hai — smallest number ko rank 1, uske baad wale ko rank 2, etc.
Agar 2 ya usse zyada numbers same hain → unka rank bhi same hoga.
Socha jaye toh ye ek coordinate compression type ka problem hai.

*/

class Solution {
public:

    vector <int> arrayRankTransform(vector <int> &arr) {
        
        // `ans` vector will store the final rank values
        // We initialize it with the same size as `arr`
        vector <int> ans(arr.size());

        // Edge case: if input array is empty, return empty result
        if (arr.size() == 0) return ans;

        // Create a copy of `arr` so we can sort it without modifying the original
        // This is a common trick when we want to sort the array
        vector <int> v = arr;  

        // Step 1: Sort the copied array to get elements in increasing order
        sort(v.begin(), v.end()); 

        // Step 2: Map to assign rank to each unique number
        unordered_map <int, int> mp;

        int rank = 1; // First element will get rank 1

        // First element will always get rank 1
        mp[v[0]] = rank;

        // Step 3: Assign ranks to sorted elements
        for (int i = 1; i < v.size(); i++) {

            if (v[i] == v[i - 1]) {
                // Duplicate element => same rank as previous one
                mp[v[i]] = rank;
            } 
            
            else {
                // New (unique) element => increase rank first then assign rank
                rank++;
                mp[v[i]] = rank;
            }

        }

        // Step 4: Fill the result array using the original array values
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = mp[arr[i]]; // Replace value with its rank
        }

        return ans; 
    }

};
