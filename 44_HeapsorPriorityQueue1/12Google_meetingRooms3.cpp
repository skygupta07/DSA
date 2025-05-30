#include <bits/stdc++.h>
using namespace std;

/*

You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] 
means that a meeting will be held during the half-closed time interval [starti, endi). 
All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. 
The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms,
return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.


Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 


Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).

Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.

*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Count of how many times each room is used
        vector<int> roomUsageCount(n, 0);

        // End time of current meeting running in each room
        vector<long long> roomEndTime(n, 0);

        // Sort meetings by their start time
        sort(meetings.begin(), meetings.end());

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            bool assigned = false;

            // Store the earliest available room if none are free at `start`
            int minRoom = -1;
            long long earliestFreeTime = LLONG_MAX;

            for (int room = 0; room < n; ++room) {
                // Track the room with earliest end time (in case no room is available)
                if (roomEndTime[room] < earliestFreeTime) {
                    earliestFreeTime = roomEndTime[room];
                    minRoom = room;
                }

                // If this room is available at or before the meeting starts
                if (roomEndTime[room] <= start) {
                    // Assign meeting to this room
                    roomUsageCount[room]++;
                    roomEndTime[room] = end;
                    assigned = true;
                    break; // no need to check other rooms
                }
            }

            // If no room was available, delay the meeting
            if (!assigned) {
                roomUsageCount[minRoom]++;
                // Delay the meeting: add the duration to the earliest free room
                roomEndTime[minRoom] += (end - start);
            }
        }

        // Find the room with the most bookings
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomUsageCount[i] > maxMeetings) {
                maxMeetings = roomUsageCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};


/*

logic : 

Free Room Hai → Use the room with the smallest ID.
Free Room Nahi Hai → Wait until the earliest endTime room becomes free, delay the meeting accordingly.
Track how many times each room is booked using a map<int, int>.
Finally, return the room with max bookings (if tie, smaller ID wins by default due to map ordering).

*/



/*
google->20 times last 6 month

// meeting delay karwa do theek hai... but time to pura utna hi lenge guru....


sort the meetings on basis of start time
keep track of free rooms also...and at a time you need to give the smallest free room

before asking for new unused room I should check if anyone of older room has been emptied or not..
agar koi meeting delay bhi ho rahi hai to ussey baad mai hi sahi room to allot karna hi hai...

ek min end time bhi dekhna hoga..
delayed meetings ka time change ho raha hai depending on when they got free rooms....

custom comparator mai priority queue ke case mai
return a.second > b.second  // smaller will come in beginnig...


pq.top() -> smallest occupied room

map <int, int> booked   -> roomid as key    and number of rooms alloted as value..

*/

// -----method-2 ------



class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Count of how many times each room is used
        vector<int> roomUsageCount(n, 0);

        // End time of current meeting running in each room
        vector<long long> roomEndTime(n, 0);

        // Sort meetings by their start time
        sort(meetings.begin(), meetings.end());

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            bool assigned = false;

            // Store the earliest available room if none are free at `start`
            int minRoom = -1;
            long long earliestFreeTime = LLONG_MAX;

            for (int room = 0; room < n; ++room) {
                // Track the room with earliest end time (in case no room is available)
                if (roomEndTime[room] < earliestFreeTime) {
                    earliestFreeTime = roomEndTime[room];
                    minRoom = room;
                }

                // If this room is available at or before the meeting starts
                if (roomEndTime[room] <= start) {
                    // Assign meeting to this room
                    roomUsageCount[room]++;
                    roomEndTime[room] = end;
                    assigned = true;
                    break; // no need to check other rooms
                }
            }

            // If no room was available, delay the meeting
            if (!assigned) {
                roomUsageCount[minRoom]++;
                // Delay the meeting: add the duration to the earliest free room
                roomEndTime[minRoom] += (end - start);
            }
        }

        // Find the room with the most bookings
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomUsageCount[i] > maxMeetings) {
                maxMeetings = roomUsageCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};









/*

roomUsageCount[i] → count of meetings held in room i.
roomEndTime[i] → current end time of the ongoing meeting in room i.
Meetings are sorted by start time so we always deal with earliest meetings first.
For each meeting:
Check if any room is free (i.e., roomEndTime <= start).
If yes → assign and update.
If no → delay meeting until the room with the earliest finish time is free.
Finally, among all rooms, return the one with the highest roomUsageCount.
⏱ Time and Space Complexity:
Time: O(m * n) where m = number of meetings, n = number of rooms.
You check all n rooms for each of the m meetings.
Space: O(n) for room usage and room end time arrays.


*/



