#include <bits/stdc++.h>
using namespace std;


/*

There is a party where n friends numbered from 0 to n - 1 are attending. 
There is an infinite number of chairs in this party that are numbered from 0 to infinity. 
When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. 
If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], 
indicating the arrival and leaving times of the ith friend respectively, 
and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.


Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.

Since friend 1 sat on chair 1, we return 1.


Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
 

Constraints:

n == times.length
2 <= n <= 104
times[i].length == 2
1 <= arrivali < leavingi <= 105
0 <= targetFriend <= n - 1
Each arrivali time is distinct.


*/
 
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();

        // ✅ Min-heap to track busy chairs
        // Format: {leave_time, chair_index}
        // Sabse pehle jo friend leave karega, uski chair jaldi free hogi
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;

        // ✅ Min-heap for available/free chairs
        // Jo bhi smallest chair index free hogi, woh pehle milegi
        priority_queue <int, vector<int>, greater<int>> free;

        // ✅ Add friend index to each entry so we don’t lose original index after sorting
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);  // ab har entry ban gayi: {arrival, leave, index}
        }

        // ✅ Sort times by arrival time — because friends arrive at different times
        sort(times.begin(), times.end());

        int new_chair = 0; // Total chairs used till now (jitni zarurat ho utni banayenge)

        // ✅ Iterate over each friend's arrival in order
        for (int i = 0; i < n; ++i) {
            int arrival = times[i][0];      // Friend ka arrival time
            int leave_time = times[i][1];   // Friend ka leave time
            int fr = times[i][2];           // Original index of the friend

            // ✅ Check busy chairs: jo bhi friend ab tak chala gaya hai (leave_time <= current arrival),
            // unki chairs ko free kar do and available heap me daal do
            while (!busy.empty() && busy.top().first <= arrival) {
                free.push(busy.top().second); // chair index ko free heap me daal diya
                busy.pop();
            }

            // ✅ If koi chair free nahi hai, toh new chair banani padegi
            if (free.empty()) {
                if (fr == targetFriend) return new_chair; // agar yahi targetFriend hai, return this new chair
                busy.push({leave_time, new_chair});       // chair ab busy hai till leave_time
                new_chair++;                              // next chair ke liye index increment
            }

            // ✅ Else koi chair free hai, use the smallest available one
            else {
                int x = free.top(); // sabse chhoti index wali chair
                free.pop();

                if (fr == targetFriend) return x; // agar yahi targetFriend hai, return this chair
                busy.push({leave_time, x});       // chair busy ho gayi till leave_time
            }
        }

        return -1; // Should never reach here if input is valid
    }
};




/*

Two Heaps ka use:
busy to track kab kaunsi chair free hogi (based on leave time).
free to manage free chairs with smallest index first.
Arrival ke time pe:
Jo friends ja chuke hain, unki chair free karo.
Agar chair available hai → use karo.
Nahi hai → nayi chair banani padegi.
TargetFriend milte hi return kar do jo chair usko mili ho.

*/