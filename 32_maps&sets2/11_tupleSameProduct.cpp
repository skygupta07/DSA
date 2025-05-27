#include <bits/stdc++.h>
using namespace std;

/*

Given an array nums of distinct positive integers, 
return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d 
are elements of nums, and a != b != c != d.
 

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)


Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.

*/


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        unordered_map <int, int> mp;  // Yeh map product store karega aur uska count track karega

        // Har do alag-alag elements ka product nikal rahe hain
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                // Agar yeh product pehle aa chuka hai, 
                // toh usko 8 se multiply karke count mein add karenge
                count += 8 * mp[nums[i] * nums[j]];  
                
                // Is product ka count badha rahe hain kyunki ab yeh ek baar aur dekhne ko mila
                mp[nums[i] * nums[j]]++;
            }
        }

        return count;  // Total valid tuples ka count return karenge
    }
};
