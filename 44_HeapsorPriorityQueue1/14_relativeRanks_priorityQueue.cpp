// relativeRanks.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an integer array score of size n, 
where score[i] is the score of the ith athlete in a competition. 
All the scores are guaranteed to be unique.

The athletes are placed based on their scores, 
where the 1st place athlete has the highest score, 
the 2nd place athlete has the 2nd highest score, and so on. 
The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number 

(i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.

 
Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].


Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].


Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.

*/


class Solution {
public:

    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());   // akash -> you forgot to initialise the size of vector...
       

        priority_queue <pair <int,int>> pq;
        for (int i=0; i<score.size(); i++){

            pq.push({score[i] , i});
            // my mistake was that in the priority_queue I was pushing index and score obviously as key : value pair
            // now when I am fetching the element....It will fetch according to the first argument in the priority_queue
            // but we have to fetch according to the score values... so push score first...
            // pq.push({i,score[i]});
            // // index, score 

        }

        // jab tak priority queue empty nahi ho jaati tab tak top pop...

        int rank = 1;
        
        while (!pq.empty()){
            auto el = pq.top();
            pq.pop();
            
            // one more mistake that I kept rank variable inside ... but the same rank will be updated to 1 again and again
 
            // int rank = 1; !!mistake
            if (rank == 1) ans[el.second] = "Gold Medal";
            else if (rank == 2) ans[el.second] = "Silver Medal";
            else if (rank == 3) ans[el.second] = "Bronze Medal";
            else ans[el.second] = to_string(rank);

            rank++;
        }

        return ans;
    }
};

/*

push into priority queue / max heap.... then fetch the max element of that time and assign him the rank...
now iterate the array again.....assign gold, silver, bronze 
then 4th postion as rank everything as char / string...

*/