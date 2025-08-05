// contiguousArray.cpp

// ye question mai if else if else samajhne ke liye karta hu...

#include <bits/stdc++.h>
using namespace std;


/*

Given a binary array nums, return the maximum length of a contiguous subarray 
with an equal number of 0 and 1. 

Example 1:

Input: nums = [0,1]
Output: 2

Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:

Input: nums = [0,1,0]
Output: 2

Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1

*/





/*
Interviews 



1. Initialize a hash map to store prefix sums along with their indices.

2. Initialize variables for sum, maximum subarray length, and iterate through the input array.

3. For each element in the array, update the sum according to the element
 (decrement by 1 for 0, increment by 1 for 1).

4. If the sum becomes zero at any index, update the maximum length to the current index plus one.

5. If the sum is encountered again (which means there is a subarray with equal 0s and 1s 
between the previous occurrence and the current index), update the maximum length if the 
current subarray length is greater than the previously stored maximum length.

6. Return the maximum subarray length.

*/


class Solution {
public:

    int findMaxLength(vector <int> &nums) {

        int n = nums.size();

        // stores the first occurence of unique sum found as its index.
        // sum, idx
        unordered_map <int, int> mp;

        int sum = 0;
        int maxLen = 0;

        // ye for loop chalane wali baat iss baar chalo mujhe yaad rahi...

        for (int i=0; i<n; i++){

            sum += (nums[i] == 0) ? -1 : 1;

            // ye wali cheej starting se hi ho gayi...
            if (sum == 0) maxLen = i + 1;

            // aur ha yaha if else if ka bhi significance dikh raha h...

            // beech wale jo cases ban rahe honge kya pata waha se maximum length mil jaye..
            else if (mp.find(sum) != mp.end()){
                maxLen = max(maxLen, i - mp[sum]);
            }

            // first occurence to store karega hi { actually jis cheej ke liye aaye they... }
            else mp[sum] = i;
        }

        return maxLen;
    }

};





class Solution {
public:

    int findMaxLength(vector <int> &nums) {
        
        int prefSum = 0;    // Ye prefix sum hai jisme hum 1 ko +1 aur 0 ko -1 treat karenge
        int maxLen = 0;     // Maximum length of subarray jisme equal number of 0s and 1s honge

        // Map to store first occurrence of a particular prefix sum
        // Agar koi prefix sum dobara milta hai, to unke beech ka subarray balanced hoga (0s == 1s)
        unordered_map <int, int> firstOcc{{0, -1}}; // key = prefixSum, value = first occurence index..

        // Hum 0 ka index -1 isliye store karte hain kyunki agar prefix sum 0 ho jaye i-th index pe,
        // to iska matlab hai ki index 0 se lekar i tak ka subarray balanced hai

        for (int i = 0; i < nums.size(); i++) {

            // Step 1: Update prefix sum
            // Agar nums[i] == 1 hai to +1 add karo, warna -1
            prefSum += (nums[i] == 1) ? 1 : -1;

            // Step 2: Check if same prefix sum pehle kabhi aaya tha
            if (firstOcc.count(prefSum)) {
                // Agar haan, to iska matlab hai ki beech ka subarray (firstOcc[prefSum] + 1 se lekar i tak)
                // ka prefix sum 0 hai i.e. equal number of 0s and 1s

                maxLen = max(maxLen, i - firstOcc[prefSum]);

            }

            else {
                // Agar ye prefix sum pehli baar mila hai, to uska index store karo
                firstOcc[prefSum] = i;
            }

        }

        // Return final maximum length of such a subarray
        return maxLen;  

    }
    
};



class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size(); // Get the size of the input array

        unordered_map <int, int> mp; 
        // This map will store the first index where a particular difference (nz - no) is seen.
        // Key: difference between number of 0s and 1s seen so far.
        // Value: the first index where that difference was seen.

        int nz = 0; // Counter for number of zeroes encountered so far
        int no = 0; // Counter for number of ones encountered so far
        
        int maxLen = 0; // Stores the maximum length of subarray with equal number of 0s and 1s

        mp[0] = -1; 
        // Initialize the map with difference 0 at index -1.
        // This is important because if we get equal number of 0s and 1s from the start of the array,
        // we want to include that subarray as a valid candidate.

        // Iterate through the array
        for (int i = 0; i < n; i++) {

            // Update counters based on the current element
            (nums[i] == 0) ? nz++ : no++;

            // Calculate the current difference between number of 0s and number of 1s
            int diff = nz - no;

            // If this difference was seen before, it means the subarray between
            // the previous index and current index has equal number of 0s and 1s
            if (mp.count(diff)) {
                // Update maxLen if this subarray is longer than previous best
                maxLen = max(maxLen, i - mp[diff]);
            } 
            
            else {
                // Otherwise, store the first index where this difference occurred
                // So that if we see this difference again, we can form a valid subarray
                mp[diff] = i;
            }
        }

        return maxLen; // Return the length of the longest such subarray
    }
};

/*

subarray by definition is contiguous
you can apply two pointer prefix sum sliding window here...

if you are given only two different characters
then you can track their occurences by simply assigning 0 and 1
using map to store the first occurence of specific character.....in prefix sum

*/

