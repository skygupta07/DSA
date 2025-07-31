// minimumSwapsToSortByDigitSum.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given an array nums of distinct positive integers. 
You need to sort the array in increasing order based on the sum of the digits of each number. 
If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.


Example 1:

Input: nums = [37,100]
Output: 1

Explanation:

Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 1.


Example 2:

Input: nums = [22,14,33,7]
Output: 0

Explanation:

Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
Thus, the minimum number of swaps required to rearrange nums is 0.
Example 3:

Input: nums = [18,43,34,16]
Output: 2

Explanation:

Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
Sort the integers based on digit sum: [16, 34, 43, 18]. 

Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 2.
 

Constraints:

1 <= nums.length <= 1e5
1 <= nums[i] <= 1e9

nums consists of distinct positive integers.

*/

class Solution {
public:

    // Ye function ek number ka digit sum nikalta hai

    // Example: digitSum(123) -> 6 (1+2+3)

    static int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += (x % 10);  // last digit add karo
            x /= 10;          // last digit hata do
        }

        return sum;
    }

    // Ye comparator function custom sorting ke liye hai
    // Pehle digit sum ke basis pe sort karega, agar same hua to value compare karega

    static bool cmp(int a, int b) {

        int sumA = digitSum(a);
        int sumB = digitSum(b);

        // agar digit sum same hai to choti value pehle aayegi
        if (sumA == sumB) return (a < b);

        // warna jiski digit sum choti hai wo pehle
        return sumA < sumB;
    }

    // Main function to find minimum number of swaps
    
    int minSwaps(vector <int> &nums) {

        int n = nums.size();

        // Step 1️⃣: Copy original array and sort it using custom comparator
        vector <int> sortedNums = nums;
         
        sort(sortedNums.begin(), sortedNums.end(), cmp); // custom sort on digit sum

        // Step 2️⃣: Map banao original values ke against sorted array me unka index
        // Queue use kiya hai taaki agar duplicate hote to handle ho sake (though problem says "distinct")
        unordered_map <int, queue<int>> posMap;

        for (int i = 0; i < n; i++) {
            // sortedNums[i] kis index pe hai, wo push kar rahe
            posMap[sortedNums[i]].push(i); 
        } 

        // Step 3️⃣: Har nums[i] ko sorted array me kis index pe hona chahiye, uska mapping banao
        vector <bool> visited(n, false);     // visited array for cycle detection
        vector <int> indexMapping(n);        // indexMapping[i] = nums[i] sorted me kis index pe jayega

        for (int i = 0; i < n; i++) {
            // posMap[nums[i]] -> queue of sorted indices for that value
            indexMapping[i] = posMap[nums[i]].front(); // sabse pehle index uthao
            posMap[nums[i]].pop();                     // us index ko pop kar do
        }

        // Step 4️⃣: Count minimum swaps using cycle detection logic
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // Agar element already visited hai ya usi position pe hai, skip karo
            if (visited[i] || indexMapping[i] == i) continue;

            int cycleSize = 0;

            int j = i;

            // ek cycle traverse karo
            while (!visited[j]) {
                visited[j] = true;         // mark current index visited
                j = indexMapping[j];       // jump to where it should be
                
                // cycle ka size badhao
                cycleSize++;              
            }


            // Agar cycle ka size > 1 hai to (size - 1) swaps lagenge
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
            
        }

        return swaps;
    }
};
