// countElementsWithMaxFrequency.cpp

#include <bits/stdc++.h>
using namespace std;

/*


You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.

 
Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4

Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.


Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/


class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {

        int freq[101] = {0};

        int maxF = 0;
        int f = 0;

        for (int x : arr){  // har element pe gaye
            freq[x]++;  // us element ki frequency badhai

            f += (freq[x] == maxF); // agar wo element ki freq maxFrequecy h to frequency mai 1 add ho jaega

            // agar koi aisa element milta h jiski freq maxF se jyada h to ... freq ko reset karna hoga 1 se and maxF ko bhi 
            // update karna padega...
            if (freq[x] > maxF){
                f = 1;
                maxF = freq[x];
            }

        }

        // finally number of elements (f here) jinhone maxF maintain karke rakha h .. their product will give answer
        return (f*maxF);
    }
};


// without extra space 

