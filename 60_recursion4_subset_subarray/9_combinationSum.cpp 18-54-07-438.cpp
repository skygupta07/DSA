// combinationSum.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target 
is less than 150 combinations for the given input.


Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.


Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]


Example 3:

Input: candidates = [2], target = 1
Output: []
 
Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

*/


void combination(vector <int> v, int arr[], int n, int target, int idx){
    // recursion ke questions mai ye khali vector bhejan is somewhat trend
    if (target == 0){ // base case
        for (int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
    // base case
    if (target < 0) return;

    // agar above mai se kucch bhi nahi hota to simply dubara se recursive call laga do..
    for (int i=idx; i<n; i++){
        v.push_back(arr[i]);

        combination(v,arr,n, target-arr[i], i);   // idx = i passed here to avoid repetetive call..
        
        v.pop_back();   // dp ka concept recursive call se pehle kiya hue kaam recursive call ke baad revert karna
    }

}

// leetcode ka auxiliary fn saara kaam karke value ready karke de deta hai...


int main(){
    vector <int> v;
    int arr[]={2,3,5};

    int n = sizeof(arr)/sizeof(arr[0]);

    combination(v,arr,n,5,0);
}















/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

*/