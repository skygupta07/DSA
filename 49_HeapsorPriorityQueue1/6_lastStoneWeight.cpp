#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones){
        priority_queue <int> pq(stones.begin(), stones.end());
        while(pq.size()>1){ // jab last ke do elements ke liye chalega to last tak aate aate ek hi element ko 
                            // push kar rha hoga priority queue mai...
            // kyuki andar aapne do baar pop operation lagaya hua hai so andar minimum do elements to hone hi chahiye...

            int y = pq.top();   // first max
            pq.pop();
            int x = pq.top();  // second max
            pq.pop();
            int rem = y-x;
            if (rem!=0){
                pq.push(rem);   // wo apne aap sahi position par laga dega..
            }
        }
        if (pq.size() == 0) return 0;
        else return pq.top();
    }
};


// mere ko koi given vector v hoga aur mujhe ussey agar priority queue or max heap mai convert karna hai to..
// priority_queue <int> pq (v.begin(), v.end());

// yes priority queue mai (to po push) hota hai because queue hai bhaiya....

/*

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones.
 On each turn, we choose the heaviest two stones and smash them together.
  Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

*/


