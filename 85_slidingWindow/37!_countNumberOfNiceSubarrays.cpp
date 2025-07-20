// countNumberOfNiceSubarrays.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].


Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 
Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 1e5
1 <= k <= nums.length

*/


class Solution {
public:

        int numberOfSubarrays(vector <int> &nums, int k) {
            // Get the size of the array
            int n = nums.size();
            
            // Prefix count array to store the frequency of odd count occurrences
            vector <int> prefix(n + 1, 0);
            
            // Variables to track the count of odd numbers and the result
            int oddCount = 0;
            int result = 0;
            
            // Initialize prefix[0] = 1 to handle cases where oddCount reaches k directly
            prefix[0] = 1;
    
            // Traverse through the array
            for (int num : nums) {

                // If the number is odd, increment the oddCount of odd numbers
                if (num % 2 == 1) oddCount++;
                
    
                // If there exist (oddCount - k) odd numbers before, add its frequency to result
                if (oddCount >= k) result += prefix[oddCount - k];
                
    
                // Store the frequency of the current oddCount of odd numbers
                prefix[oddCount]++;
            }
            
            // Return the total number of valid subarrays
            return result;

        }
    };
    


    class Solution {
        public:
            int numberOfSubarrays(vector <int> &nums, int k) {
               
                int n = nums.size();
        
                // Variable to store the final count of nice subarrays
                int count = 0;
        
                // Variable to keep track of the prefix sum (number of odd numbers encountered so far)
                int prefSum = 0;
        
                // Hashmap to store the frequency of prefix sums
                unordered_map <int, int> freqOfPrefSum;
                
                // Initialize freqOfPrefSum[0] = 1 to handle cases where prefix sum itself equals k
                freqOfPrefSum[0] = 1;
        
                // Traverse through the array
                for (int i = 0; i < n; i++) {
                    
                    // Convert the array into binary format: 1 for odd numbers, 0 for even numbers
                    // this was good that i didn't modified the array in the beginning instead just do 
                    // your computation by just adding one more conditional statement..
                    prefSum += (nums[i] % 2 == 1) ? 1 : 0;
        
                    // Check how many times (prefSum - k) has occurred before, 
                    // since it mecount a valid subarray ending at index i exists
                    count += freqOfPrefSum[prefSum - k]; // interesting point to remember...
        
                    // Store the current prefix sum occurrence count in the hashmap
                    freqOfPrefSum[prefSum]++;
                    
                }
        
                // Return the total count of nice subarrays
                return count;

            }

        };


/*

✅ Intuition:

The task is to count the number of subarrays with exactly k odd numbers.

Let’s say we are tracking the number of odd numbers seen so far (oddCount).
If at any point, we have seen this oddCount before, we can use its frequency to count 
the number of valid subarrays ending at the current index.

This is similar to prefix sum logic:

For exactly k odd numbers in a subarray ending at index i, we need:
oddCount[i] - oddCount[j] = k ⟹ oddCount[j] = oddCount[i] - k
So, for each index, if we know how many times we have seen oddCount - k before, 
we can add that to the answer.


 --- Approach:

Treat odd numbers as 1 and even as 0.

Maintain a prefix frequency array/map to count how many times a certain number of odd numbers 
has occurred so far.

For each element, track oddCount so far.
If oddCount - k has occurred before, we can form a subarray ending at current index 
with exactly k odd numbers.

Keep updating the result and the prefix frequency.

--- Algorithm:

Initialize:
oddCount = 0: count of odd numbers so far
result = 0: total subarrays found

prefix[0] = 1: for the case when the first k odd numbers start from index 0

Traverse the array:

If current number is odd, increment oddCount

If (oddCount - k) exists in prefix, add its frequency to result

Increment the frequency of current oddCount in prefix
Return result

*/
        
        /*
        👉 When we only need to count the number of nice subarrays based on odd numbers,
           we can simplify the problem by converting the array:
           - Replace odd numbers with 1
           - Replace even numbers with 0
        
        👉 This reduces the problem to **"counting binary subarrays with sum = k"**, 
           which can be efficiently solved using the **prefix sum + hashmap** approach.
        
        👉 **Subarray sum me Given an array of integers nums and an integer k. 
        A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].


Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.


Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 1e5
1 <= k <= nums.lengthans range sum**, which can be efficiently calculated using 
           the **prefix sum technique**.

*/
        