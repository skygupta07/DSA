#include <bits/stdc++.h>
using namespace std;

/*

You are given a 0-indexed integer array nums of even length consisting of an equal number of
positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

*/



class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr){
        int n = arr.size();
        vector<int> ans;

        vector <int> positive;
        vector <int> negative;

        for (int i=0; i<n; i++){
            if (arr[i]>=0) positive.push_back(arr[i]);
            else negative.push_back(arr[i]);
        }


        int pi = 0;
        int ni = 0;
        for (int i=0; i<n; i++){
          
            if (i%2 == 0){  // if index is even
                ans.push_back(positive[pi]);
                pi++;
            } 
            
            else{
                ans.push_back(negative[ni]);
                ni++;
            } 
            
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr){
        int n = arr.size();
        vector<int> ans;

        int pi = -1;
        int ni = -1;

        for (int i=0; i<n; i++){
          
            if (i%2 == 0){  // even index of ans array -> put first unvisited positive number
                for (int j = pi+1; j<n; j++){
                    if (arr[j]>=0){
                        ans.push_back(arr[j]);
                        pi = j;
                        break;
                    } 
                }
            } 
            
            else{
               for (int j = ni+1; j<n; j++){
                    if (arr[j]<0){
                        ans.push_back(arr[j]);
                        ni = j;
                        break;
                    } 
                }
            } 

        }
        return ans;
    }
};
