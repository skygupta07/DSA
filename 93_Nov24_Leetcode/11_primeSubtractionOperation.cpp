#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = getMaxElement(nums);
        
        // Step 1: Create Sieve of Eratosthenes array to identify prime numbers up to maxElement.
        // This allows us to efficiently check if a number is prime.
        vector<bool> sieve(maxElement + 1, true);
        sieve[1] = false;  // 1 is not a prime number.
        
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i]) {
                // Mark multiples of i as non-prime.
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        // Step 2: Check if the array can be made strictly increasing by adjusting elements with prime numbers.
        int currValue = 1;  // We start with 1 as the minimum required previous value.
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;
            
            // If the current element is already smaller than the required value (currValue), we can't make it strictly increasing.
            if (difference < 0) {
                return false;
            }
            
            // If the difference is a prime number or zero (no change needed), we move to the next element.
            if (sieve[difference] == true || difference == 0) {
                i++;             // Move to the next element in nums.
                currValue++;     // Increment currValue as it represents the required next minimum value.
            } else {
                currValue++;     // If difference is not prime, increment currValue to check if we can make a valid adjustment.
            }
        }
        return true;  // If all elements satisfy the strictly increasing condition, return true.
    }
    
private:
    // Helper method to find the maximum element in the array, needed for the sieve size.
    int getMaxElement(vector<int>& nums) {
        int max = -1;
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
};
