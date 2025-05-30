// lastStoneWeight.cpp

#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, 
we choose the heaviest two stones and smash them together. Suppose the heaviest two stones 
have weights x and y with x <= y. The result of this smash is:


If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.


Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1

Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.


Example 2:

Input: stones = [1]
Output: 1
 
Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000

*/

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

/*
v.begin(), v.end() karne ki aisi aadat lag gayi thi ki mai vector copy karte waqt bhi aisa hi 
kar raha tha... (#mistake #chutiya)

--> correct approach

vector <int> v;
vector <int> vCopy;

vCopy = v;

*/

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


