#include <bits/stdc++.h>
using namespace std;


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

        for (int i=0; i<nums.size(); i++){
            if (!visited[i]){
                visited[i] = 1; // kaam
                v.push_back(nums[i]);

                f(nums, v, ans, visited);   // recursion

                visited[i] = 0; // backtrack
                v.pop_back();
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