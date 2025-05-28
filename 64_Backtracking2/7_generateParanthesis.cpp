//  generateParenthesis.cpp


#include <bits/stdc++.h>
using namespace std;
/*
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
*/




class Solution {
    public:
    
        void solve(int n, vector <string> &ans, string temp, int open, int close){
            
            if (close == n){
                ans.push_back(temp);
                return;
            }
    
            if (open < n) solve(n, ans, temp + '(', open + 1, close);
            if (close < open) solve(n, ans, temp + ')', open, close + 1);
        }
    
        vector<string> generateParenthesis(int n) {
            vector <string> ans;

            // length, ans, temp, open, close
            solve(n, ans, "", 0, 0);

            return ans;
        }
    };



    class Solution {
        public:
        
            void solve(vector <int> &nums, vector <vector <int>> &ans, vector <int> &temp, vector <int> &visited){
                // base case
                if (temp.size() == nums.size()){
                    ans.push_back(temp);
                    return;
                }
        
                for (int i=0; i<nums.size(); i++){
                    if (!visited[i]){
                        visited[i] = 1;
                        temp.push_back(nums[i]);
        
                        solve(nums, ans, temp, visited);
        
                        visited[i] = 0;
                        temp.pop_back();
                    }
                }
            }
        
        
            vector<vector<int>> permute(vector<int>& nums) {
                int n = nums.size();
                vector <vector <int>> ans;
                vector <int> temp;
        
                vector <int> visited(n, 0);
        
                solve(nums, ans, temp, visited);
                return ans;
            }
        };