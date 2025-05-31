#include <bits/stdc++.h>
using namespace std;

/*

You have n boxes. You are given a binary string boxes of length n, 
where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. 
Box i is adjacent to box j if abs(i - j) == 1. 

Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed 
to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.


Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.

3) Third box: you will have to move one ball from the first box to the third box in two operations, 
and move one ball from the second box to the third box in one operation.


Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.

*/

class Solution {
public:

    vector <int> minOperations(string boxes) {
        int n = boxes.size();
        vector <int> ans(n, 0);  // Final answer array — har index ke liye total operations

        // --------------------------
        // Left-to-right pass
        // --------------------------

        int count = 0;       // Ab tak kitne '1' mil chuke hain (balls)
        int operations = 0;  // Ab tak kitni operations lagi hain (distance total)

        for (int i = 0; i < n; i++) {
            ans[i] = operations;  // i-th box tak total operations store karo

            if (boxes[i] == '1') count++;  // Agar current box mein ball hai, toh count++
            operations += count;           // Har '1' ko ek step aage le jaana hoga, isliye count add karo
        }

        // Ab tak humne left side se right side tak ka contribution calculate kar liya
        // Example: [0 1 0 1 0] => for box 2 (index 1-based), we count how far left-side balls are


        // --------------------------
        // Right-to-left pass
        // --------------------------

        count = 0;
        operations = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] += operations;  // Ab right side se aane wali cost bhi add karni hai

            if (boxes[i] == '1') count++;   // Ball mila to count increase
            operations += count;            // Ball ko left le jaane ke liye count steps lagte hain
        }

        return ans;  // Final array return karo, jisme dono directions ka total cost hai
    }
};



/*

Har box ke liye hum calculate kar rahe hain:
Left side ke sabhi balls ko yaha lane me kitni cost lagi
Right side ke sabhi balls ko yaha lane me kitni cost lagi


So, 2 passes karte hain:
Left-to-right: left side ke contributions
Right-to-left: right side ke contributions

*/