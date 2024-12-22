#include <iostream>
using namespace std;

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
        
        // Calculate the additional satisfaction in the first window of size k
        // jaha par grumpy == 1 hai waha to additional satisfaction milega..
        for (int i = 0; i < k; ++i) {
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
or in other word find that window that has max additional satisfaction...




