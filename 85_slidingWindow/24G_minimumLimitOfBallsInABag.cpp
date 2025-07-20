// minimumLimitOfBallsInABag

/*

You are given an integer array nums where the ith bag contains nums[i] balls. 
You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.

Your penalty is the maximum number of balls in a bag. You want to minimize your penalty 
after the operations.

Return the minimum possible penalty after performing the operations.

Example 1:

Input: nums = [9], maxOperations = 2
Output: 3

Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.


Example 2:

Input: nums = [2,4,8,2], maxOperations = 4
Output: 2

Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].

The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
 

Constraints:

1 <= nums.length <= 1e5
1 <= maxOperations, nums[i] <= 1e9

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        Helper function to determine if we can divide the elements (bags with balls)
        in such a way that no bag has more than 'maxBalls' balls after performing
        at most 'maxOperations' operations.

        Each operation consists of choosing a bag and dividing its balls into two bags
        such that the total number of balls remains the same, but we reduce the count
        in that particular bag.

        For a given bag with 'n' balls, to reduce it so that no sub-bag has > maxBalls,
        we calculate the number of required splits/operations as:

            (n + maxBalls - 1) / maxBalls - 1
        
        This formula gives the **minimum number of splits** required for that bag.

        - (n + maxBalls - 1) / maxBalls => ceil(n / maxBalls)
        
        - Subtracting 1 because we need "splits", not total pieces.
    */

    bool canDivide(const vector <int> &nums, int maxBalls, int maxOperations) {
        int ops = 0;

        for (int n : nums) {
            // Compute how many operations needed for this bag
            ops += (n + maxBalls - 1) / (maxBalls - 1);

            // If at any point operations exceed the limit, we cannot proceed
            if (ops > maxOperations) return false;
        }

        // If total operations used is within the allowed maxOperations
        return true;
    }

    /*

        Main function to compute the **minimum possible maximum size** of any bag
        after performing at most 'maxOperations' operations.

        Problem: Given an array `nums` where nums[i] is the number of balls in the i-th bag,
        we are allowed to perform at most `maxOperations` operations (each splits a bag into two),
        and we need to minimize the **maximum number of balls** in any bag after operations.

        Approach: Binary Search on Answer
        ----------------------------------
        - We know that the possible answer (max size of any bag) lies between 1 and max(nums)
        - So, we perform binary search on this value space:
            - For each mid (candidate answer), check if it's possible to divide the bags
              so that no bag has more than mid balls using ≤ maxOperations
            - If possible, try to find a smaller max size (right = mid)
            - Otherwise, increase mid (left = mid + 1)

        Finally, left will point to the smallest possible value that satisfies the condition.
    
    */

    
    int minimumSize(vector <int> &nums, int maxOperations) {

        // Search space: [1, max element in nums]
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());


        // Binary Search to find the minimal possible maxBalls value
        while (left < right) {
            
            int mid = left + (right - left) / 2;

            /*
                If it's possible to reduce all bags so that none exceeds 'mid' balls
                with at most 'maxOperations', we try to reduce the size further.
            */

            // try smaller maxBalls value 
            //  {kyuki yaha mujhe smaller chahiye tha... isliye smaller wale ki respect kari..}
            
            if (canDivide(nums, mid, maxOperations)) {
                right = mid; 
            }
             
            // need larger maxBalls value
            else {
                left = mid + 1; 
            }

        }

        // 'left' is now the minimum possible value of maxBalls satisfying the condition
        return left;

    }

};
