// subsets

/*


Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

        // Recursive function jo subsets generate karega
        void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int idx) {
            // Base case: Agar idx pura traverse ho gaya, toh temp ko ans mein add kar do
            
            if (idx == nums.size()) {
                ans.push_back(temp);
                return;
            }

            // ye subsets wale case mai koi loop wagera nahi lagta..{ye aapki galat fehmi h...}
            // aap bas ye dhyan rakho ki  yaha par fn call hi two times karni 
            // hogi ek baar normal hi then push karo then dubara call then pop karo...
            
            // Exclude case: Current element ko ignore kar rahe hain
            solve(nums, ans, temp, idx + 1); 
    
            // Include case: Current element ko subset mein add kar rahe hain
            temp.push_back(nums[idx]);  

            solve(nums, ans, temp, idx + 1); 
    
            // Backtracking: Last added element ko hata diya
            temp.pop_back(); 
        }
        
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector <vector<int>> ans;  // Final answer store karega
            vector <int> temp;  // Temporary vector jo subset banayega
    
            solve(nums, ans, temp, 0); // Recursive function call
            
            return ans;
        }


    };
    



// inclusion and exclusion principle...

class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>> &ans,vector <int> &sub, int idx ){
        // koi base bhi nahi likha...
        ans.push_back(sub);

        for (int j=idx; j<nums.size(); j++){
            
            sub.push_back(nums[j]); // push the element
            helper(nums, ans, sub, j+1);    // go to next index     
            sub.pop_back(); // pop the element
        }

    }



vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> sub;

        helper(nums,ans,sub,0);
        return ans;
    }
};



// !bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();  
        int p = 1 << n;  // 2^n subsets honge, kyunki har element ke paas 2 choices hain: include ya exclude

        vector <vector <int>> subs(p);  // Itne subsets ke liye ek vector of vectors bana rahe hain

        // Har subset ko generate karne ke liye loop
        for (int i = 0; i < p; i++) {  
            // Har element ke liye check karenge ki wo subset me hai ya nahi
            for (int j = 0; j < n; j++) {  
                // Agar j-th bit set hai, to nums[j] is subset ka part hoga
                if ((i >> j) & 1)  subs[i].push_back(nums[j]);  // nums[j] ko current subset me daal do
            }
        }

        return subs;  // Saare subsets return kar do
    }
};
