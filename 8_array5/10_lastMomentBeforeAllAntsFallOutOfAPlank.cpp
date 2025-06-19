//  lastMomentBeforeAllAntsFallOutOfAPlank.cpp

#include <bits/stdc++.h>
using namespace std;

/*

We have a wooden plank of the length n units. Some ants are walking on the plank,
each ant moves with a speed of 1 unit per second. Some of the ants move to the left,
the other move to the right.

When two ants moving in two different directions meet at some point,
they change their directions and continue moving again. Assume changing directions
does not take any additional time. When an ant reaches one end of the plank at a time t,
it falls out of the plank immediately.

Given an integer n and two integer arrays left[] and right[],
the positions of the ants moving to the left and the right,
return the moment when the last ant(s) fall out of the plank.

Examples :

Input: n = 4, left[] = [2], right[] = [0, 1, 3]
Output: 4

Explanation: As seen in the above image, the last ant falls off the plank at t = 4.

Constraints:

1 <= n <= 104
0 <= left.length <= n + 1
0 <= left[i] <= n
0 <= right.length <= n + 1
0 <= right[i] <= n
1 <= left.length + right.length <= n + 1
All values of left and right are unique, and each value can appear only in one of the two arrays.

*/



/*

if they are changing direction still they


*/



// 🧠 Intuition:

// Jab ants pole par chal rahe hote hain, aur agar 2 ants takra jaati hain,
// toh unka direction bas swap hota hai, aur agar hum unhe indistinguishable maan lein,
// toh final result pe koi farq nahi padta.
//  Matlab hum ants ko bina takraaye aage jaate hue maan sakte hain.

// So, agar koi ant left ja rahi hai, toh wo 0 tak jaayegi, and time = left[i] lagega.
// Aur agar koi ant right ja rahi hai, toh wo n tak jaayegi, and time = (n - right[i]) lagega.

// Sabse last mein pole se girne wali ant ka time = max(left[i], n - right[i]) hoga. => matlab single hi
// variable ko maximize kar do simply...

class Solution {
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right) {
        int maxTime = 0;

        // Left jaane wali har ant ke liye
        for (int i = 0; i < left.size(); i++) {
            // 0 tak jaane ka time = left[i] (kyunki origin 0 hai)
            maxTime = max(maxTime, left[i]);
        }

        //  Right jaane wali har ant ke liye
        for (int i = 0; i < right.size(); i++) {
            // n tak jaane ka time = (n - right[i])
            maxTime = max(maxTime, n - right[i]);
        }

        return maxTime;
    }
};

