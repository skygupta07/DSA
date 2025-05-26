// minimumTimeToReachLastRoom2.cpp

/*

There is a dungeon with n x m rooms arranged as a grid.
You are given a 2D array moveTime of size n x m, 
where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. 
You start from the room (0, 0) at time t = 0 and can move to an adjacent room. 
Moving between adjacent rooms takes one second for one move and two seconds for the next, 
alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.


Example 1:

Input: moveTime = [[0,4],[4,4]]
Output: 7

Explanation:

The minimum time required is 7 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.


Example 2:

Input: moveTime = [[0,0,0,0],[0,0,0,0]]
Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.


Example 3:

Input: moveTime = [[0,1],[1,2]]
Output: 4


Constraints:

2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 109


*/


#include <bits/stdc++.h>
using namespace std;

using info = tuple <int, short, short, bool>; // (time, i, j, adjust) — ek tuple jo time, row(i), column(j), aur adjust flag ko store karta hai
const static int d[5] = {0, 1, 0, -1, 0}; // direction array — 4 directions me move karne ke liye (right, down, left, up)

// Solution class define kar rahe hain
class Solution {
public:

    // check karta hai ki (i,j) matrix ke bahar toh nahi hai
    inline static bool isOutside(short i, short j, short n, short m){
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    // 64-bit integer me 4 values pack kar rahe hain: time, i, j, adjust
    static uint64_t pack(int t, short i, short j, bool adj1){
        return ((uint64_t)t<<32) + (i<<21) + (j<<11) + adj1;
    }

    // mask values to extract bits
    static constexpr unsigned mask11 = (1<<11) - 1; // 11 bits ka mask
    static constexpr unsigned mask10 = (1<<10) - 1; // 10 bits ka mask

    // ek 64-bit value ko unpack karke tuple (time, i, j, adjust) me convert karta hai
    static info unpack(uint64_t x){
        int t = x >> 32; // sabse pehle 32 bits time ke liye

        short i = (x >> 21) & mask11; // next 11 bits i ke liye
        short j = (x >> 11) & mask10; // uske baad 10 bits j ke liye

        bool adj = x & 1; // last bit adjust flag ke liye

        return {t, i, j, adj}; // tuple return
    }

    // main function jo minimum time calculate karta hai destination tak pahuchne ka
    int minTimeToReach(vector<vector<int>>& moveTime){
      
        short n = moveTime.size();     // rows
        short m = moveTime[0].size();  // columns

        vector <int> time(n*m, INT_MAX); // har cell ke liye minimum time store karte hain

        // min-heap priority queue jisme packed values dalenge
        priority_queue <uint64_t, vector <uint64_t>, greater <uint64_t>> pq;

        pq.emplace(pack(0,0,0,1)); // starting point (0,0) with time 0 and adjust = 1

        time[0] = 0; // start point ka time 0

        bool adjust = 0; // initial adjust value

        // jab tak queue empty nahi hoti
        while (!pq.empty()){
            auto [t, i, j, adjust] = unpack(pq.top()); // top element ko unpack karte hain
            pq.pop();

            // agar destination pahuch gaye ho to current time return karo
            if (i == n-1 && j == m - 1) return t;

            // 4 directions me move karne ki koshish karte hain
            for (int a = 0; a < 4; a++){
                int r = i + d[a];
                int s = j + d[a + 1];

                if (isOutside(r, s, n, m)) continue; // agar (r,s) valid nahi to skip

                // calculate nextTime — max of current time ya moveTime[r][s], +1 step time +1 agar adjust nahi tha
                int nextTime = max(t, moveTime[r][s]) + 1 + (!adjust);

                int rs = r * m + s; // (r,s) ko linear index me convert kar diya

                // agar naya time pehle se stored time se chhota hai to update karo
                if (nextTime < time[rs]){
                    time[rs] = nextTime;
                    pq.emplace(pack(nextTime, r, s, !adjust)); // queue me new state push karo
                }
            }
        }

        return -1; // agar destination tak nahi pahuch paaye
    }
};

// fast input/output ke liye lambda function
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
