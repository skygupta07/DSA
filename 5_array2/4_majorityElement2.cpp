#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;

        unordered_map <int,int> mp;
        for (auto el: nums) mp[el]++;

        for(auto el: mp){
            if (el.second > n/3) ans.push_back(el.first);
        }

        return ans;
    }
};

// ---------   ------

class Solution {
public:
  vector<int> majorityElement(vector<int> &a) 
  {
      // Variables to store two potential candidates and their respective counts
	  int y(-1), z(-1), cy(0), cz(0); 
    
      // First pass: Find potential majority candidates
	  for (const auto &x : a) 
	  {
          // Increment count if the current element matches candidate `y`
		  if (x == y) 
              cy++;
          // Increment count if the current element matches candidate `z`
		  else if (x == z) 
              cz++;
          // Assign `y` to the current element if its count is zero
		  else if (!cy) 
              y = x, cy = 1;
          // Assign `z` to the current element if its count is zero
		  else if (!cz) 
              z = x, cz = 1;
          // If both candidates are non-zero and no match, reduce both counts
		  else 
              cy--, cz--;
      }
      
      // Reset counts for validation
      cy = cz = 0;

      // Second pass: Count occurrences of the two candidates
      for (const auto &x : a)
          if (x == y) 
              cy++; // Increment count for `y`
          else if (x == z) 
              cz++; // Increment count for `z`
  
      vector<int> r; // Vector to store the result

      // Check if `y` is a valid majority element (appears more than n/3 times)
      if (cy > size(a)/3) 
          r.push_back(y);
      
      // Check if `z` is a valid majority element (appears more than n/3 times)
      if (cz > size(a)/3) 
          r.push_back(z);

      return r; // Return the result
  }
};
