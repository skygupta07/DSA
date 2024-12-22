#include <bits/stdc++.h>
using namespace std;


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
now iterate the array again.....assign gold , silver , bronze then 4th postion as rank everything as char / string...


*/