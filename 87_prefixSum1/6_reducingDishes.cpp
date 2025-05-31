#include <bits/stdc++.h>
using namespace std;

/*

A chef has collected data on the satisfaction level of his n dishes. 
Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including 
previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing 
some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient
will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.


Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)


Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.

*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        // Step 1: Sort the array (so negative values come first, and max ones come at the end)
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        // Step 2: Suffix sum array bana lo
        // suff[i] = satisfaction[i] + satisfaction[i+1] + ... + satisfaction[n-1]
        vector<int> suff(n, 0);

        // Initialize last element
        suff[n-1] = satisfaction[n-1];

        // Build suffix sum from right to left
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = satisfaction[i] + suff[i + 1];
        }

        // Step 3: Find the pivot index from where suffix sum is non-negative
        int pivotIdx = -1;

        for (int i = 0; i < n; i++) {
            // Jab pehli baar positive suffix mila → wahi se start karenge cooking
            if (suff[i] >= 0) {
                pivotIdx = i;
                break;
            }
        }

        // Agar koi positive suffix nahi mila, to koi dish cook hi mat karo
        if (pivotIdx == -1) return 0;

        // Step 4: Calculate the final satisfaction starting from pivot index
        int time = 1, ans = 0;

        for (int i = pivotIdx; i < n; i++) {
            ans += satisfaction[i] * time;
            time++;
        }

        return ans;
    }
};
