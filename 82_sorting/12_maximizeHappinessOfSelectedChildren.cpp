// maximizeHappinessOfSelectedChildren.cpp


#include <bits/stdc++.h>
using namespace std;

/*

You are given an array happiness of length n, and a positive integer k.
There are n children standing in a queue, where the ith child has happiness value happiness[i]. 
You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children 
that have not been selected till now decreases by 1. 
Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve
by selecting k children.
 

Example 1:

Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.


Example 2:

Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: We can pick 2 children in the following way:
- Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
- Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
The sum of the happiness values of the selected children is 1 + 0 = 1.


Example 3:

Input: happiness = [2,3,4,5], k = 1
Output: 5
Explanation: We can pick 1 child in the following way:
- Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
The sum of the happiness values of the selected children is 5.
 

Constraints:

1 <= n == happiness.length <= 2 * 105
1 <= happiness[i] <= 108
1 <= k <= n


*/



class Solution { // gives tle
public:
    long long maximumHappinessSum(vector<int>& happiness, int k){
        long long ans = 0;  // mistake 1 -> I created the variable long long ans , but didn't initialise it..


        // descending order mai sort karne ka rambaan hai teessra inbuilt comparator greater <int>() function pass kardo....
        sort(happiness.begin() , happiness.end() , greater<int>());

        int i = 0;
        while (k--){
            ans += happiness[i];

            // decreasing the happiness of next children
            for (int j=i+1; j<happiness.size(); j++){
                if (happiness[j]>0) happiness[j]--;
            }

            i++;
        }
        
        return ans;
    }
};

// correct optimal ans

class Solution {
public:
    long long maximumHappinessSum(vector <int> &h, int k){
        sort(h.begin(), h.end(), greater<int>());

        int i = 0;
        long long ans = 0;

        while(k--) {
            h[i] = max(h[i] - i, 0);

            ans += h[i];
            i++;
        }
        
        return ans;
    }
};