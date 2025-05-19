// findDisappearedNumber.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums. 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]


Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.

*/


class Solution {
public:
    vector <int> findDisappearedNumbers(vector <int> &nums){
        int n = nums.size();
        vector <int> ans;

        // insert elements into set for faster lookup
        unordered_set <int> st;
        for (auto num : nums) st.insert(num);

        for (int i=1; i<=n; i++){
            // if the element is not present (or missing)
            if (st.find(i) == st.end()) ans.push_back(i);
        }

        return ans;
    }
};



class Solution{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
        int n = nums.size();
        vector<int> ans;
        
        // Pehla loop array ke har element ko traverse karta hai.  
        // Hum har element ki absolute value ka use karte hain to find the index.
        // Us index par value ko negative karte hain, agar pehle se negative nahi hai toh. 
        // Ye isliye kiya jata hai, taki pata chale ki element already aaya tha ya nahi.
        for (int i = 0; i < n; i++){
            // Absolute value lena zaroori hai, kyunki hum array ke indices ko access karte hain
            // aur negative index nahi chahiye.
            if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1; 
        }
        
        // Dusra loop array ko traverse karta hai aur positive values ko check karta hai.  
        // Jo indices positive hain, wo wahi elements hain jo missing hain 
        // (index + 1) array mein nahi aaye the.
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) ans.push_back(i + 1);  // Missing element ko result mein add karo.
        }
        
        return ans;
    }
};

/*

Approach:
1. Array ke har element ka use karte hue ek index calculate karo:
   - Index = abs(nums[i]) - 1
   - Agar wo index pe value positive hai, toh usse negative kar do. 
   - Iska matlab hai ki wo number (index + 1) array mein exist karta hai.
   
2. Dusre loop mein, array ko phir se traverse karo:
   - Agar kisi index ki value positive hai, iska matlab hai ki 
     (index + 1) array mein nahi tha. Us number ko result mein add karo.

3. Final result ans vector mein store hoga jo missing numbers ko represent karega.

Time Complexity: O(n)  
Space Complexity: O(1) (Input array ko hi modify kar rahe hain, extra space nahi lag rahi).

*/
