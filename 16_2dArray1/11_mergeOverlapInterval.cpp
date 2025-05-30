// mergeOverlappingIntervals.cpp


#include <bits/stdc++.h>
using namespace std;

/*

Given an array of Intervals arr[][], where arr[i] = [starti, endi]. 
The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]

Explanation: In the given intervals we have only two overlapping intervals here, 
[1,3] and [2,4] which on merging will become [1,4]. 
Therefore we will return [[1,4], [6,8], [9,10]].


Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].


Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105

*/

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return {};  // Agar input empty hai toh directly empty answer return kar do

        // Intervals ko sort kar lo unke starting time ke basis pe
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> prevInterval = arr[0];  // Pehla interval le lo jisko hum baad mein compare karenge

        for (int i = 1; i < n; i++) {
            // Agar current interval ka start time <= prevInterval ka end time hai, toh overlap ho raha hai
            if (arr[i][0] <= prevInterval[1]) {
                // Merge kar do dono intervals ko by taking max end time
                prevInterval[1] = max(prevInterval[1], arr[i][1]);
            } else {
                // Agar overlap nahi ho raha, toh prevInterval ko answer mein daal do
                ans.push_back(prevInterval);
                // Aur ab naye interval ko prevInterval bana do
                prevInterval = arr[i];
            }
        }

        // Last interval ko bhi answer mein daalna na bhoolo
        ans.push_back(prevInterval);

        return ans;
    }
};


