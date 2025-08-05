// zeroArrayTransformations.cpp

/*

You are given an integer array nums of length n and a 2D array queries, 
where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing 
all the queries sequentially, otherwise return false.
 

Example 1:

Input: nums = [1,0,1], queries = [[0,2]]

Output: true

Explanation:

For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.


Example 2:

Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]
Output: false

Explanation:

For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
The array will become [4, 2, 1, 0].
For i = 1:
Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
The array will become [3, 1, 0, 0], which is not a Zero Array.
 

Constraints:

1 <= nums.length <= 1e5
0 <= nums[i] <= 1e5
1 <= queries.length <= 1e5

queries[i].length == 2
0 <= li <= ri < nums.length


*/

#include <bits/stdc++.h> // Sabhi important headers include ho jate hain
using namespace std;

class Solution {
public:

    // Function check karega ki queries apply karne ke baad array nums poori tarah se zero ban sakti hai
    // ya nahi

    bool isZeroArray(vector <int> &nums, vector <vector<int>> &queries) {
        
        int n = nums.size();  // Array ka size nikal liya

        // Difference array banaya size n+1 ka. 
        // Ye use hota hai range updates ke liye efficient tarike se
        vector <int> diff(n + 1, 0);

        // Sabhi queries loop se process kar rahe hain
        for (const auto &query : queries) {
            
            int l = query[0]; // Range ka left index
            int r = query[1]; // Range ka right index

            // Difference array technique:
            // l se r tak +1 karna hai, toh diff[l] += 1
            // aur diff[r+1] -= 1 (taaki r ke baad wapas effect neutral ho jaye)
            diff[l]++;

            if (r + 1 < n) diff[r + 1]--;
        }

        // Isme cumulative frequency maintain karenge
        int count = 0; 

        // Actual array bana rahe hain diff array se, 
        // aur check kar rahe hain ki nums ke har element ko zero kiya ja sakta hai ya nahi
        
        for (int i = 0; i < n; i++) {
            
            count += diff[i]; // Current index tak total additions kitne hue, wo nikal rahe hain

            // Agar nums[i] > count hai, iska matlab itne operations se nums[i] zero nahi ban sakta
            if (nums[i] > count) return false;
        }

        // Agar sabhi elements cover ho gaye bina fail hue, to return true
        return true;
    }
};


/*

After performing all such queries we traverse over the diff array 
& maintain a running sum of diff known as cnt.

This running sum of cnt tells us at index i, 
how many total decrements we can apply to nums[i]

So now the situation we're in for both the arrays is that
nums[i] : Decrements we need to make inorder to turn this element 0.
cnt : Decrements we can make on element at index i

So if at any index, decrements (we need) to make are more than decrements (we can) make.

Then we simply return false as the number cannot be converted to 0.
So cnt checks whether there exists an element with value != 0 
in the array while we're traversing through it.

*/