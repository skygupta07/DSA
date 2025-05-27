// rankTransformOfAnArray.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, 
their rank must be the same.

Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 
30 is the third smallest.


Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.


Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109


*/


class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> ans(arr.size());   // when I need to pick
            //  or play with the  index of the vector ...
            // we will need to mention the size of vector ...
        if (arr.size() == 0) return ans;

       vector <int> v;
       v = arr; // this is how we copy a array 

        sort(v.begin() , v.end()); 

        unordered_map <int, int> mp;

        int rank = 1;   // thresholds
        mp[v[0]] = 1;

        for (int i=1; i<v.size(); i++){
            if (v[i] == v[i-1]){    // if consecutive elements are same they will share the same rank
                mp[v[i]] = rank;
            }
            else{
                rank++;
                mp[v[i]] = rank;
            }
        }


        for (int i=0; i<arr.size(); i++){
            ans[i] = mp[arr[i]];
        }
        
        return ans; 
    }
};