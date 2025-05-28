// nonOverLappingIntervals.cpp

/*

Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals 
non-overlapping.

Note that intervals which only touch at a point are non-overlapping. 
For example, [1, 2] and [2, 3] are non-overlapping.
 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.


Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.


Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 10pow4 <= starti < endi <= 5 * 10pow4

*/


#include <bits/stdc++.h>
using namespace std;

 // sort in asc order on basis of end time ...(chota pehle)
//  comparator ke parameter mai ek level kam ki cheeje jaati h...{one bottle down}

bool cmp(vector <int> &a, vector <int> &b){
    return a[1] < b[1];  
}

class Solution {
public:
    int eraseOverlapIntervals(vector <vector <int>> &intervals){
        int ans = 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int lastEndTime = intervals[0][1];  // initially value daali..

        for (int i=1; i<intervals.size(); i++){
            // if current interval start time is lesser than the lastEndTime 
            // - it means there is overlapping interval

            // otherwise make this interval endtime as the lastEndTime...
            
            if (intervals[i][0] < lastEndTime) ans++;
            else lastEndTime = intervals[i][1];
            
        }   

        return ans; 
    }
};



/*

agar do interval overlap kar rahe hai to...wo interval pick karo jo jaldi khatam ho raha hai..
lowest hanging apple algorithm pehle ussey hi tod lo...

*/