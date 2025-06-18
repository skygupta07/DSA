// removeDuplicatesFromSortedArray.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array nums sorted in non-decreasing order, 
(matlab same reh sakta h aur increase kar sakta h..)

remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.

Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted,
you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements
in the order they were present in nums initially.
The remaining elements of nums are not important as well as the size of nums.

Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 
respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100

nums is sorted in non-decreasing order.

*/


class Solution{
public:

    int removeDuplicates(vector<int> &nums){
        int n = nums.size();

        // idx ko bhi 1 and iterate bhi 1 se hi start kar dena...
        int idx = 1;

        for (int i = 1; i < n; i++){
            // if the current element is not equal to the previous one .. means this current element
            // is the new distinct element.. so simply update array nums
            if (nums[i] != nums[i - 1]){
                nums[idx] = nums[i];
                idx++;
            }
        }
        
        return idx;

    }
};

/*
rattne wale algo h ye sab... {I have understood now ..}
*/

class Solution{
public:

    int removeDuplicates(vector<int> &nums){
        int n = nums.size();
        int idx = 1; // Yeh index track karega ki unique elements ko kaha place karna hai

        for (int i = 1; i < n; i++){
            // Agar current element previous wale se different hai to use store karenge
            if (nums[i] != nums[i - 1]){
                nums[idx] = nums[i]; // Unique element ko correct position par daal diya
                idx++;               // Index aage badhaya taaki agli unique value yaha aaye
            }
        }
        return idx; // Kitne unique elements array me bach gaye, wahi return karenge
    }
};

/*
👉 **Logic Samajhne Wala Part**:

1️⃣ **Base Concept**:
   - Sorted array diya hai, jisme duplicate values ho sakti hain.
   - Hume inplace unique elements ko rakhnna hai, aur unka count return karna hai.
   - Extra space use nahi karna hai.

2️⃣ **Loop Ka Kaam**:
   - Ek pointer (`idx`) track karega ki naya unique element kaha store hoga.
   - Agar `nums[i]` aur `nums[i-1]` different hai, to `nums[idx] = nums[i]` karke store karenge.

3️⃣ **Final Output**:
   - Function return karega `idx`, jo batayega ki unique elements kitne hai.
   - Baaki elements ka koi matter nahi, kyunki problem mai sirf first `k` elements important hai.

   **Time Complexity**: `O(N)`, kyunki ek hi pass me traverse kar rahe hain.
   **Space Complexity**: `O(1)`, kyunki inplace modifications kar rahe hain.
*/