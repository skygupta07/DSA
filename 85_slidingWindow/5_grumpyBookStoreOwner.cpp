// grumpyBookstoreOwner.cpp

#include <iostream>
using namespace std;


/*

There is a bookstore owner that has a store open for n minutes. 
You are given an integer array customers of length n where customers[i]
is the number of the customers that enter the store at the start of the ith minute 
and all those customers leave after the end of that minute.

During certain minutes, the bookstore owner is grumpy. 
You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy 
during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. 
Otherwise, they are satisfied.

The bookstore owner knows a secret technique to remain not grumpy for minutes(K) consecutive minutes, 
but this technique can only be used once.

Return the maximum number of customers that can be satisfied throughout the day.

 
Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3

Output: 16

Explanation:

The bookstore owner keeps themselves not grumpy for the last 3 minutes.

The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Example 2:

Input: customers = [1], grumpy = [0], minutes = 1

Output: 1


*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        
        int initialSatisfaction = 0;
        
        // Calculate the initial satisfaction without using the trick
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                initialSatisfaction += customers[i];
            }
        }
        
        int additionalSatisfaction = 0;
        int maxAdditionalSatisfaction = 0;      // imp
        
        // calculating anything for the first window is important threshold for the next window.
        // Calculate the additional satisfaction in the first window of size k
        // jaha par grumpy == 1 hai waha to additional satisfaction milega..
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1) {
                additionalSatisfaction += customers[i];
            }
        }
        
        maxAdditionalSatisfaction = additionalSatisfaction; //now update it
        
        // Sliding window to find the maximum additional satisfaction

        for (int i = k; i < n; ++i) {
            if (grumpy[i] == 1) {
                additionalSatisfaction += customers[i];
            }

            if (grumpy[i - k] == 1) {    // purana wala window ka first element subtract karte huye.. 
                // (agar usne contribute kiya tha tabhi to subtract karenge)
                additionalSatisfaction -= customers[i - k];
            }
            
            maxAdditionalSatisfaction = max(maxAdditionalSatisfaction, additionalSatisfaction);
        }
        
        return initialSatisfaction + maxAdditionalSatisfaction;
    }
};


/*
jab grump[i] == 0  hoga tabhi to add hoga...


*/


/*
to satisfy more customers owner should remain calm in the time when he remain mostly 
grumpy and at the same time a lot of customers are visiting..

-> apply sliding window algorithm-> find that window that has most loss of satisfaction
and apply your calmness there

currLoss = prevLoss + arr[j] - arr[i-1] 
//                  but yaha condition lag jaegi ki tabhi adda aur subtract karo
                    jab grumpy[i] = 1 ho...
*/



//  --- -- -- - -- - - 


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        
        int initialSatisfaction = 0;
        
        // Calculate the initial satisfaction without using the trick
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                initialSatisfaction += customers[i];
            }
        }
        
        int additionalSatisfaction = 0;
        int maxAdditionalSatisfaction = 0;
        
        // Calculate the additional satisfaction in the first window of size k
        for (int i = 0; i < k; ++i) {
            if (grumpy[i] == 1) {
                additionalSatisfaction += customers[i];
            }
        }
        
        maxAdditionalSatisfaction = additionalSatisfaction;
        
        // Sliding window using two pointers i and j
        int i = 0;
        int j = k;
        
        while (j < n) {
            if (grumpy[j] == 1) {
                additionalSatisfaction += customers[j];
            }
            if (grumpy[i] == 1) {
                additionalSatisfaction -= customers[i];
            }
            
            maxAdditionalSatisfaction = max(maxAdditionalSatisfaction, additionalSatisfaction);
            i++;
            j++;
        }
        
        return initialSatisfaction + maxAdditionalSatisfaction;
    }
};

// finding that window that has max loss of satisfaction...
// or in other word find that window that has max additional satisfaction...




