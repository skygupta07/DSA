// maximumPointsYouCanObtainFromCard.cpp

#include <bits/stdc++.h>
using namespace std;

/*

There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1.
However, choosing the rightmost card first will maximize your total score.
The optimal strategy is to take the three cards on the right,
giving a final score of 1 + 6 + 5 = 12.

Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.


Constraints:

1 <= cardPoints.length <= 1e5
1 <= cardPoints[i] <= 1e4

1 <= k <= cardPoints.length

*/
class Solution {
public:

    int maxScore(vector<int> &cardPoints, int k) {
        
        int maxSum = 0;

        // Step 1: First k elements ko pick karte hain from the **left side** (0 to k-1)
        // Ye assume karte hain ki sabhi k cards left se hi uthaye hain
        for (int i = 0; i < k; i++) maxSum += cardPoints[i];

        // ab currSum ko maxSum ke barabar maan lo
        // aage changes karenge to try getting better score
        int currSum = maxSum;

        // Step 2: Ab hum gradually ek-ek card left se remove karenge
        // aur right se ek card uthayenge
        // i.e., window ko slide kar rahe hain from left-only to including right-end
        for (int i = k - 1; i >= 0; i--) {
            currSum -= cardPoints[i];  // left side se ek card hatao

            // right side se ek card add karo
            // yahan "cardPoints.size() - k + i" se correct right-end index milega
            currSum += cardPoints[cardPoints.size() - k + i]; 

            // maxSum ko update karo agar currSum bada ho
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
