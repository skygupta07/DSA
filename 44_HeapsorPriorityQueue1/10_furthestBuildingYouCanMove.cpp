#include <bits/stdc++.h>
using namespace std;


/*

You are given an integer array heights representing the heights of buildings,
 some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

*/



class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders){
        priority_queue <int, vector<int>, greater <int>> pq;

        for (int i=0; i<heights.size()-1; i++){
            int jumpLen = heights[i+1] - heights[i];

            if (jumpLen > 0) pq.push(jumpLen);
            
            if (pq.size() > ladders){
                bricks -= pq.top();    
                pq.pop();
            }

            if (bricks < 0) return i;
        }

        return heights.size() - 1;  // i.e. you reached the last index doesn't matter if you saved the bricks or not..
    }
};



/*
most optimal approach will be use min heap 
in general push the difference of h[i+1] - h[i] uptill we have number of ladders left yet....
but as soon as you cross the limits of ladder then pick the min element from the min heap and try
jumping or utilising it through your bricks remaining....

i to i+1 pe agar negative to phir simply move on...


*/
