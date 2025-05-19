#include <bits/stdc++.h>
using namespace std;


/*
You are given two sorted arrays of distinct integers nums1 and nums2.

A valid path is defined as follows:

Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.

If you are reading any value that is present in nums1 and nums2 you are allowed to change your path 
to the other array. (Only one repeated value is considered in the valid path).

The score is defined as the sum of unique values in a valid path.

Return the maximum score you can obtain of all possible valid paths. 
Since the answer may be too large, return it modulo 109 + 7. 

Example 1:

Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].


Example 2:

Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].


Example 3:

Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
Output: 40
Explanation: There are no common elements between nums1 and nums2.
Maximum sum is obtained with the path [6,7,8,9,10].
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 107
nums1 and nums2 are strictly increasing.

*/

class Solution {
public:
    const int mod = 1e9 + 7;

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        long long sum1 = 0;
        long long sum2 = 0;

        long long ans = 0;

        while (i < n1 && j < n2){
            if (nums1[i] < nums2[j]){
                sum1 += nums1[i];
                i++;
            }

            else if (nums1[i] > nums2[j]){
                sum2 += nums2[j];
                j++;
            }
            
            else{   // both elements equal
                // khud ka plus pehle mai kisne max contribution diya hua hai...
                ans += nums1[i] + max(sum1, sum2);
                // ab dono index aage badhao
                i++;
                j++;

                // reset kara variable...
                sum1 = 0;
                sum2 = 0;
            }
        }

        // if array2 exhausted 
        while (i < n1){
            sum1 += nums1[i];
            i++;    // iske bina kuch while loop kam sa lagta hai...(abey saale infinite loop mai chala jayega..)
        }

        while (j < n2){
            sum2 += nums2[j];
            j++;
        }

        ans += max(sum1, sum2);
        ans = ans%mod;

        return ans;
    }
};





/*
two pointer use kara ....
ek sum1 variable aur ek sum2 variable use kara..jab tak same element nahi milte unko sum1 , sum2 
mai add karte rahenge.... phir usi ko final answer mai add karenge jiska max contribution tha pehle ...

now agar inme se koi bhi ek array khatam hogayi to aage ke sum ke liye again sum1 aur sum2 ko 
zero kara .... and then dekha kiska max constribution hai sum mai...


*/