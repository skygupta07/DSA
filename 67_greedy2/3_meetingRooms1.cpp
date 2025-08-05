// meetingRooms 1,2 - premium


/*

Given an array of meeting time interval objects consisting of start and end times 
[[start_1,end_1],[start_2,end_2],...] (start_i < end_i), 

determine if a person could add all meetings to their schedule without any conflicts.

Example 1:

Input: intervals = [(0,30),(5,10),(15,20)]
Output: false

Explanation:

(0,30) and (5,10) will conflict
(0,30) and (15,20) will conflict


Example 2:

Input: intervals = [(5,8),(9,15)]
Output: true

Note:

(0,8),(8,10) is not considered a conflict at 8
Constraints:

0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000

*/


#include <bits/stdc++.h>
using namespace std;


// Custom structure to represent an interval
struct Interval{
    int start;
    int end;
};

// Comparator to sort intervals by their start time
bool cmp(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution{
public:

    bool canAttendMeetings(vector <Interval> &intervals){
        if (intervals.size() <= 1) return true;

        // Start time ke basis par sort karo
        sort(intervals.begin(), intervals.end(), cmp);

        // Check karo ki koi bhi 2 intervals overlap to nahi kar rahe
        for (int i = 1; i < intervals.size(); i++){
            // Agar pehli meeting end hone se pehle doosri start ho gayi -> overlap {isko 111 baar dohrana padega..}
            if (intervals[i].start < intervals[i - 1].end){
                return false;
            }
        }

        // Kabhi bhi overlap nahi mila -> sab meetings attend kar sakte ho
        return true;
    }
    
};
