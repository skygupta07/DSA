#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order 
return an array of the squares of each number sorted in non-decreasing order.
*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        vector <int> ans(n);

        int val;
        for (int i=n-1; i>=0; i--){
            if ( abs(arr[left]) < abs(arr[right]) ){
                val = arr[right];
                right--;
            }
            else{
                val = arr[left];
                left++;
            }

            ans[i] = val*val;
        }
        return ans;
    }
};


/*
when to use two pointer approach? => 
case 1 : use when you can see that two points are representing some information 
about some changes there like (both inc. inc). (both decs. decs.) 

(also somewhat similar intuition is built in case of binary search but remember that in case of binary search you have
increasing decreasing values and you need the middle one from them...)


case 2: when there are 2 or 3 kind of strings in the array/string... 

I will compare the absolute value and put the corresponding square values there...


*/
