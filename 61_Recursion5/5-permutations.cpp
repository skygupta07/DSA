// permutations1.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order. 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]


Example 3:

Input: nums = [1]
Output: [[1]]
 
Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/


class Solution {
public:
    void p(vector<int>&arr, vector<vector<int>>&ans, vector <int>&ds, vector <int> &mp){
        if (ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }
        // calculate hash array or simple vector to store the acknowledgement whether taken the element or not..
        for (int i=0; i<arr.size(); i++){
            if (!mp[i]){   // or if (map[i] == 0) -> i.e. the element has not been taken for corresponding step
                ds.push_back(arr[i]);
                mp[i] = 1;
                p(arr,ans,ds,mp);   // recursive call
                ds.pop_back();
                mp[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> ans;
        vector <int> ds;
        vector<int> mp(n);
        for (int i=0; i<mp.size(); i++) mp[i] = 0;
        p(arr,ans,ds,mp);
        return ans;
    }
};
 
// any dataStructures can be used...

class Solution {
public:

    void f(vector<int>& nums, vector <int> &v, vector <vector <int>> &ans, vector <int> &visited){
        // base case 
        if (v.size() == nums.size()){
            ans.push_back(v);
            return; // imp
        }

        // har element ko starting point manega...
        // kyu ye loop na chalai jaa rahi ... huppp ye barger ki howe !! 

        for (int i=0; i<nums.size(); i++){
            // agar ith element visited nahi h tabhi kaam karna h...
            if (!visited[i]){
                visited[i] = 1; // kaam (visited mark karna and push)
                v.push_back(nums[i]);

                f(nums, v, ans, visited);   // recursion (enjoy)

                visited[i] = 0; // backtrack
                v.pop_back();  // (visited unmark karna and pull)
            }  
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        
        vector <int> v;
        vector <vector <int>> ans;

        vector <int> visited(nums.size() , 0);

       f(nums, v, ans, visited); 

       return ans;
    }
};

/*
generating all the permutations...
recursion , backtrack 
kaam recursion backtrack
*/


// interview
class Solution {
public:


    void solve(vector <int> &nums, vector <vector <int>> &ans, int idx){
        // base case
        if (idx >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for (int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);

            solve(nums, ans, idx+1);

            swap(nums[idx], nums[i]);
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};



