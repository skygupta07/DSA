// nMeetingsInOneRoom.cpp


#include <bits/stdc++.h>
using namespace std;

/*

You are given timings of n meetings in the form of (start[i], end[i]) 
where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. 

Return the maximum number of meetings that can be accommodated in a single meeting room, 
when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings.
The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Input: start[] = [1, 2], end[] = [100, 99]
Output: 1

*/


class Solution {
    public:
      // Function to find the maximum number of meetings that can be performed in a meeting room.
      int maxMeetings(vector <int> &start, vector <int> &end) {

          int n = start.size();
          vector <pair <int, int>> v; // end, start time
          
          // Storing meetings as {end time, start time} pairs
          for (int i = 0; i < n; i++) {
              v.push_back({end[i], start[i]});
          }
  
          // Sorting meetings by **end time** (Greedy Approach) 
        //   - kyuki first parameter ke basis par hi hoti h cheeje har jagah..

          sort(v.begin(), v.end());
  
          int count = 1; // First meeting can always be attended

          int lastTime = v[0].first; // Store end time of the first meeting
  
          for (int i = 1; i < n; i++) {
              // If the current meeting starts after the last attended meeting ends
              if (v[i].second > lastTime) {
                  lastTime = v[i].first; // Update last attended meeting's end time
                  count++; // Increment count of meetings
              }
          }
  
          return count; // Return the maximum number of non-overlapping meetings
      }
  };
  