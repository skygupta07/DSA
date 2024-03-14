// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         ans[0] = nums[0];
//         for(int i=1; i<n; i++){
//             ans[i] = ans[i-1] + nums[i];
//         }
//         return ans;
//     }
// };







// class Solution {    // no extra memory used..
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         int n = nums.size();
//         for (int i=1; i<n; i++){
//             nums[i] = nums[i]+nums[i-1];
//         }
//         return nums;  
//     }
// };



// leetcode pe result vector banate ho to uska size bhi mention kar diya karo.. otherwise heap memory full wala 
//error de deta hai.. 