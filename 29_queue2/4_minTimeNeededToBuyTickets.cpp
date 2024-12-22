#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue <int> q;

        for (int i=0; i<tickets.size(); i++) q.push(i);     // pushing index into the queue...
        int timeNeeded = 0;

        while (!q.empty()){
            timeNeeded++;

            // front pop push
            int idFront = q.front();    // fetch the id of frontElement...
            q.pop();
            tickets[idFront]--;     // decreased the front person ticket by one...

            // check the base cases and condition.....

            if (k == idFront && tickets[idFront] == 0) return timeNeeded;
            if (tickets[idFront] != 0) q.push(idFront);     // if our friend want more ticket then push him again
                                                        // back into the queue....

        }
        return timeNeeded;
    }
};


// -----------

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeNeeded = 0;

        for (int i=0; i<tickets.size(); i++){
            if (i<=k) timeNeeded += min(tickets[k] , tickets[i]);   // dono case ka intersection dekha...
            else timeNeeded += min(tickets[k]-1 , tickets[i]);
        }

        return timeNeeded;
    }
};