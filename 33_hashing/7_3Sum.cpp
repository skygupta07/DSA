// 3Sum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v){
        int n = v.size();
        vector <vector <int>> ans;

        sort(v.begin(), v.end());

        for (int i=0; i <= n-3; i++){
            // skipping duplicates
            if (i > 0 && v[i] == v[i-1]) continue;

            int l = i+1, r = n-1;   // maintaining l and r at correct position
        
            while (l < r){
                int sum = v[i] + v[l] + v[r];
                
                if (sum < 0) l++;   // trying to increase the sum to make it zero
                else if (sum > 0) r--;    // dec. sum to make it zero (ultimate maksad)
                
                else{   // sum zero found
                    ans.push_back( vector<int> {v[i], v[l], v[r]} );
                    
                    // we need to access index l+1 here... 
                    while (l + 1 < r && v[l] == v[l+1]) l++; // for avoiding duplicate answers maintaining 
                                                           
                    // l and r...BY JUMPING OVER THE DUPLICATES...  
                    while (r - 1 > l && v[r] == v[r-1]) r--;

                    // whenever values at left and right add up to give remaining, we move both the pointers for next step...
                    l++; r--;   // agar jyada repetition nahi hai to bas ek ek aage peeche kar do...
                }  
            }   
        }
        return ans; 
    }
};


/*


1. sort v 
2. trace from i=0 to i=n-3  and taking the first element as distinct...so continue when v[i] == v[i-1]
3. we will take i l=i+1 and r=n-1 as three numbers...initially..
4. then there will be three case for sum if sum == 0 then push i l r ans vector by making a vector..
5. then next pair find karne ke liye...l aur r ko maintain kara...


*/
