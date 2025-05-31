#include <bits/stdc++.h>
using namespace std;

/*

Given a binary array arr[] (containing only 0s and 1s) and an integer k, 
you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's 
that can be obtained in the array after performing the operation at most k times.

Examples:

Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: Maximum subarray of consecutive 1's is of size 3 which can be obtained after flipping the zero present at the 1st index.


Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.


Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2


Constraints:
1 <= arr.size() <= 105
0 <= k <= arr.size()
0 <= arr[i] <= 1

*/



class Solution {
  public:

    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        //  BRUTEFORCE APPROACH- finding all subarray 
        // int res = 0;
        // // Exploring all subarrays
        // for(int i = 0; i < arr.size(); i++) {
            
        //     // Counter for zeroes
        //     int cnt = 0;
        //     for(int j = i; j < arr.size(); j++) {
        //         if(arr[j] == 0)
        //             cnt++;
                
        //         // If cnt is less than or equal to k, then  
        //         // all zeroes can be flipped to one
        //         if(cnt <= k)                   //  i=0      j=3-->j-i=3 but actual length is 4 so j-i+1
        //             res = max(res, (j - i + 1));//[1, 0, 0, 1, 0, 1, 0, 1]
        //     }
        // }
        // return res;
        //     }
        
        
        //OPTIMAL 
        int res = 0;
        int start = 0, end = 0; 
        int cnt = 0;
        
        while (end < arr.size()) {
            if (arr[end] == 0)
                cnt++;
             // Shrink the window from left if number of  zeroes are greater than k
            while (cnt > k) {
                if (arr[start] == 0)
                    cnt--;
                    
                start++;
            }
            
            res = max(res, (end - start + 1));
            end++; 
        }
        
        return res; 
   }
};





class Solution {
public:

    // Function to find the maximum number of consecutive 1s 
    // after flipping at most k zeros to 1s

    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();           // Size of input array
        
        int left = 0;                 // Sliding window left pointer
        
        int zeroCount = 0;            // Count of 0s in the current window
        int maxLength = 0;            // Maximum length of valid subarray

        // Traverse array with right pointer (I love this trick)
        for (int right = 0; right < n; right++) {

            // Step 1: Include arr[right] in window
            if (arr[right] == 0) {
                zeroCount++;          // 0 mila to flip count badhao
            }

            // Step 2: If zeroCount > k, move left pointer to shrink window
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;      // Window se 0 hata rahe hain, toh count kam karo
                }
                left++;               // Shrink the window from left
            }

            // Step 3: Update maxLength if current window is larger
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;  // Final answer — max length of subarray with at most k flips
    }
};
