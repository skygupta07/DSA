// queueReconstructionByHeight.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an array of people, people, which are the attributes of some people 
in a queue (not necessarily in order). Each people[i] = [hi, ki] 
represents the ith person of height hi with exactly ki other people in front 
who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people.
The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] 
is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] -> kehne ka matlab h like [4, 4] is telling that meri 
height 4 h and mere aage char log h jinki height mere equal ya mere se jyada h...

Explanation:

Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.

Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.

Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.


Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]


*/


class Solution {
public:

    // Comparator function for sorting logic.
    // Static function kyunki ise class ke kisi object ke bina call karna hai.
    static bool cmp(vector <int> &a, vector <int> &b) {
        // Agar dono persons ki height equal ho, 
        // toh jis person ke aage kam log lage ho usse priority milegi, i.e. k is small -> means come first..
        if(a[0] == b[0]) return a[1] < b[1];

        // Heights ke basis par decreasing order mein sorting karenge.
        // Pehle lambe height wale person ko rakhenge.
        return a[0] > b[0];
    }

    vector <vector<int>> reconstructQueue(vector<vector<int>>& people) {   
        // Pehle array ko sort karte hain custom comparator ke basis par.
        sort(people.begin(), people.end(), cmp);  // Sorting according to cmp function.

        vector <vector <int>> ans;  // Final queue banane ke liye ek vector create kiya.

        // Ab har person ko unki required position par insert karte hain.

        // man itself will be a vector here... ha wahi 2 size wala..
        for(auto man : people) {
            
            // `man[1]` hume batata hai ki is person ke aage kitne log hone chahiye.
            // Us position par person ko insert kar dete hain.

            // vector.insert(position_iterator, element_to_insert);
            ans.insert(ans.begin() + man[1], man);  // Position + value insert karenge.
        }

        // Final queue return karte hain.
        return ans;
    }
};
