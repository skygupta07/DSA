// bulbSwitcher2.cpp

#include <bits/stdc++.h>
using namespace std;

/*

There is a room with n bulbs labeled from 1 to n that all are turned on initially,
and four buttons on the wall. Each of the four buttons has a different functionality where:

Button 1: Flips the status of all the bulbs.
Button 2: Flips the status of all the bulbs with even labels (i.e., 2, 4, ...).
Button 3: Flips the status of all the bulbs with odd labels (i.e., 1, 3, ...).
Button 4: Flips the status of all the bulbs with a label j = 3k + 1 
where k = 0, 1, 2, ... (i.e., 1, 4, 7, 10, ...).

You must make exactly presses button presses in total. 
For each press, you may pick any of the four buttons to press.

Given the two integers n and presses, return the number of different possible statuses 
after performing all presses button presses.

 

Example 1:

Input: n = 1, presses = 1
Output: 2
Explanation: Status can be:
- [off] by pressing button 1
- [on] by pressing button 2
Example 2:

Input: n = 2, presses = 1
Output: 3
Explanation: Status can be:
- [off, off] by pressing button 1
- [on, off] by pressing button 2
- [off, on] by pressing button 3
Example 3:

Input: n = 3, presses = 1
Output: 4
Explanation: Status can be:
- [off, off, off] by pressing button 1
- [off, on, off] by pressing button 2
- [on, off, on] by pressing button 3
- [off, on, on] by pressing button 4


*/

class Solution {
public:
    int flipLights(int n, int m) {
        // If no operations are performed, only 1 possible state (all ON)
        if (m == 0) {
            return 1;
        } 
        else {
            switch (n) {  // Check based on number of bulbs
                case 1: 
                    return 2;  // Only 2 possible states: [ON], [OFF]
                    break;

                case 2: 
                    // If only 1 press, 3 possible states.
                    // If more than 1 press, we can reach 4 distinct states.
                    return (m == 1) ? 3 : 4;
                    break;

                default:  // n ≥ 3
                    switch (m) {  // Check based on number of presses
                        case 1: 
                            return 4;  // 4 possible states with 1 press
                            break;
                        case 2: 
                            return 7;  // 7 possible states with 2 presses
                            break;
                        default: 
                            return 8;  // Maximum 8 unique states with 3+ presses
                            break;
                    }
                    break;
            }
        }
    }
};
