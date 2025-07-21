// minimumTimeNeededToBuyTickets.cpp

#include <bits/stdc++.h>
using namespace std;

/*

There are n people in a line queuing to buy tickets, where the 0th person is at the front 
of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n 
where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. 
A person can only buy 1 ticket at a time and has to go back to the end of the line 
(which happens instantaneously) in order to buy more tickets. 
If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

 

Example 1:

Input: tickets = [2,3,2], k = 2

Output: 6

Explanation:

The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
Example 2:


Input: tickets = [5,1,1,1], k = 0

Output: 8

Explanation:

The queue starts as [5,1,1,1], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. 
The kth person has bought all their tickets, so return 8.
 

Constraints:

n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n

*/

class Solution {
public:

    int timeRequiredToBuy(vector <int> &tickets, int k) {
        queue <int> q;

        for (int i=0; i<tickets.size(); i++) q.push(i);     // pushing !!index* into the queue...

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
                                                        // back into the queue...
        }

        return timeNeeded;
    }

};


// -----------

class Solution {
public:

    int timeRequiredToBuy(vector <int> &tickets, int k) {
        int timeNeeded = 0;

        for (int i=0; i<tickets.size(); i++){

            if (i <= k) timeNeeded += min(tickets[k] , tickets[i]);   // dono case ka intersection dekha...
            else timeNeeded += min(tickets[k]-1 , tickets[i]);

        }

        return timeNeeded;
    }

};

/*

/*

Intuition / Logic:

-> Har second mein, ek banda ticket kharidta hai (1 ticket per second).
-> Humme dekhna hai ki 'k-th' position wale bande ko apna last ticket lene tak kitna time lagega.

-> Sochne ka tareeka:
   - Har banda sirf tab tak line mein rehta hai jab tak uske paas ticket bachi ho.
   - Agar koi banda 'i' position pe hai:
     -- Agar i <= k: toh is bande ko minimum of (tickets[i], tickets[k]) baar ticket milega
        (kyunki ye banda k ke pehle ya same position pe hai, toh uska poora effect k tak aata hai).

     -- Agar i > k: toh is bande ka effect 'k-th' ke last turn ke baad nahi aata,
        isliye hum uska contribution sirf (tickets[k] - 1) tak lenge.

   - Total time is just the sum of all these contributions.

Example:

Input: tickets = [2,3,2], k = 2

Meaning: person at index 2 (3rd person) ko apni 2 tickets lene tak kitna time lagega?

=> Logic se: person 0 contributes min(2,2) = 2 sec
             person 1 contributes min(3,2) = 2 sec
             person 2 contributes min(2,2) = 2 sec

=> Total time = 6 seconds




yrr matlab as such utna jyada phark nahi padta agar wo ek ticket leke picche lag jaata h ...
ab tujhe 1000 tickets leni ho mujhe pharak nahi padta...

*/



