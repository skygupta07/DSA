// minPenaltyForAShop.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given the customer visit log of a shop represented by a 0-indexed string customers 
consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.


Example 1:

Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
Example 2:

Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.
Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.

*/




class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        // Initialize prefix and suffix penalty arrays
        vector<int> penaltyPsum(n, 0);
        vector<int> penaltySsum(n, 0);

        // Calculate prefix penalties
        penaltyPsum[0] = (customers[0] == 'N' ? 1 : 0);
        for (int i = 1; i < n; i++) {
            penaltyPsum[i] = penaltyPsum[i - 1] + (customers[i] == 'N' ? 1 : 0);
        }

        // Calculate suffix penalties
        penaltySsum[n - 1] = (customers[n - 1] == 'Y' ? 1 : 0);
        for (int i = n - 2; i >= 0; i--) {
            penaltySsum[i] = penaltySsum[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        // Calculate total penalties and find the minimum
        int minPenalty = INT_MAX;
        int bestHour = 0;
        for (int i = 0; i <= n; i++) {
            int totalPenalty = 0;
            if (i > 0) {
                totalPenalty += penaltyPsum[i - 1];
            }
            if (i < n) {
                totalPenalty += penaltySsum[i];
            }
            if (totalPenalty < minPenalty) {
                minPenalty = totalPenalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};




// At any index, the penalty is the sum of prefix count of ‘N’ and suffix count of ‘Y’.
// (good akash)

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();


        // n + 1 size ka isliye kyuki saare customers ko attend karke then last hour mai ghar gaye...
        vector <int> prefixNCount(n+1, 0);    // except self
        vector <int> suffixYCount(n+1, 0);    // except self

        prefixNCount[0] = 0;

        for (int i=1; i<=n; i++){
            prefixNCount[i] = prefixNCount[i-1] + (customers[i-1] == 'N' ? 1 : 0);
        }

        suffixYCount[n] = 0;

        for (int i=n-1; i>=0; i--){
            suffixYCount[i] = suffixYCount[i+1] + (customers[i+1] == 'Y' ? 1 : 0);
        }

        int minPenalty = INT_MAX;
        int bestTime = -1;

        for (int i=0; i <= n; i++){ 
            int currPenalty = prefixNCount[i] + suffixYCount[i] + (customers[i] == 'Y' ? 1 : 0);

            if (currPenalty < minPenalty){
                minPenalty = currPenalty;
                bestTime = i;
            }
        }


        return bestTime;
    }
};