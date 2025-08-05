// meetingRooms2.cpp

// Neetcode


/*

Given an array of meeting time interval objects consisting of start and end times 
[[start_1,end_1],[start_2,end_2],...] (start_i < end_i), 

find the minimum number of days required to schedule all meetings without any conflicts.

Example 1:

Input: intervals = [(0,40),(5,10),(15,20)]
Output: 2

Explanation:
day1: (0,40)
day2: (5,10),(15,20)


Example 2:

Input: intervals = [(4,9)]
Output: 1

Note:

(0,8),(8,10) is not considered a conflict at 8
Constraints:

0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000

*/


#include <bits/stdc++.h>
using namespace std;

/*

Given an array of meeting time intervals consisting of start and end times,
return the minimum number of conference rooms required.

Approach:
1. Sab meetings ke start time aur end time ko alag arrays mai daalo.
2. Dono arrays ko sort karo.
3. Ek room tab chahiye hota hai jab ek nai meeting start ho jaaye aur *koi bhi* meeting 
abhi tak khatam na hui ho.

4. Har meeting ke start pe dekho koi purani meeting khatam hui kya?

   - Agar haan, toh room free kar do.
   - Nahi toh ek naya room chahiye.

*/


class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        // If there are no meetings, no rooms are required.
        if (intervals.empty()) return 0;

        // Separate the start and end times of the meetings.
        vector <int> startTimes, endTimes;

        for (const auto& interval : intervals) {
            startTimes.push_back(interval[0]);
            endTimes.push_back(interval[1]);
        }

        // Sort the start and end times.
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int startPointer = 0; // Pointer to traverse startTimes
        int endPointer = 0;   // Pointer to traverse endTimes
        
        int roomsInUse = 0;   // Tracks currently used rooms
        int maxRooms = 0;     // Stores the maximum number of rooms used at any time

        // Iterate through all the start times
        while (startPointer < startTimes.size()) {

            if (startTimes[startPointer] < endTimes[endPointer]) {
                // A meeting is starting before the previous one ends, need a new room
                roomsInUse++;

                maxRooms = max(maxRooms, roomsInUse);
                
                startPointer++;
            }
            
            else {
                // A meeting has ended, free up a room
                roomsInUse--;

                endPointer++; // meeting end hui h to bhaiya end karo na.. pareshan ho gaye yrr
            }
        }

        return maxRooms;

    }
      
};

