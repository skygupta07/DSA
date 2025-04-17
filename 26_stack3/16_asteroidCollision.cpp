// asteroidCollision.cpp

/*
We are given an array asteroids of integers representing asteroids in a row. 
The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, 
and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet. 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans; // Result store karne ke liye vector
        stack<int> stk;  // Collision handle karne ke liye stack
        int i = 0;
        int n = asteroids.size(); // Total asteroids ka size

        // Saare asteroids ko process karna hai
        while(i < n) {
            // Agar stack empty hai, ya current asteroid right move kar raha hai (positive value), 
            // ya stack ka top left move kar raha hai (negative value), to asteroid ko stack me daal do
            if (stk.empty() || asteroids[i] > 0 || stk.top() < 0) {
                stk.push(asteroids[i++]); // Asteroid ko stack me daal kar agle asteroid par jao
            } 
            
            // Agar stack ka top asteroid ka size zyada hai, to current asteroid destroy hoga
            else if (stk.top() > abs(asteroids[i])) {
                i++; // Current asteroid destroy ho gaya, agle par move karo
            } 
            // Agar dono asteroids ka size equal hai, to dono destroy honge
            else if (stk.top() == abs(asteroids[i])) {
                stk.pop(); // Stack ka top asteroid destroy
                i++;       // Current asteroid bhi destroy
            } 
            // Agar current asteroid bada hai, to stack ka top asteroid destroy karo
            else {
                stk.pop(); // Top asteroid destroy
            }
        }

        // Jo asteroids bach gaye hain, unhe stack se nikal kar result vector me daalo
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        // Stack me values reverse order me hongi, to result ko reverse karo
        reverse(ans.begin(), ans.end());
        return ans; // Final result return karo
    }
};
