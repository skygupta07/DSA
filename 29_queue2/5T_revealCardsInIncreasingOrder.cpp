// revealCardsInIncreasingOrder.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given an integer array deck. There is a deck of cards where every card has a unique
integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down
(unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.

If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

*/


class Solution {
public:

    vector <int> deckRevealedIncreasing(vector <int> &deck) {
        int n = deck.size();
        queue <int> q;

        for (int i=0; i<n; i++) q.push(i);      // pushing idx to queue..
        
        sort(deck.begin(), deck.end());

        vector <int> ans(n);
        // jayenge to saare hi index pe...

        for (int i=0; i<n; i++){
            // queue ke order ke hisaab se hi chalo...
            ans[q.front()] = deck[i];
            q.pop();
            
            // putting second element at the back also....wo bhi queue se index fetch karke hi (discipline matters)
            if (!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        
        return ans;
    }
};

// taas ke paato ko aisa feeto (and uska order batao) ki jab usko reveal kiya jaye
//  (saath mai ek ko back mai daal diya)
// wo increasing order mai reveal ho....

/*
if I perform given operations on  output string... I get the input string in sorted form....
let's reverse the phenomena and see the magic...

remember we need to follow the queue pattern also...
queue of indexes will help to place the element...

*/