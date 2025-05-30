// nonOverlappingInterval.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. 
Return the minimum number of intervals you need to remove to make the rest of the intervals 
non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.

*/


bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        
        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), cmp);
        
        int endTime = INT_MIN;
        int nonOverlappingCount = 0;

        for (const auto &interval : intervals) {
            // If the current interval's start time is greater than or equal to endTime
            if (interval[0] >= endTime) {
                endTime = interval[1]; // Update the endTime
                nonOverlappingCount++;
            }
        }

        // Total intervals - non-overlapping intervals = intervals to remove
        return intervals.size() - nonOverlappingCount;
    }
};