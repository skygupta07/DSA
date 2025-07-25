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
        int n = customers.length(); // customers string ka size nikal liya

        // Dono prefix and suffix penalty arrays banaye:
        // penaltyPsum[i]: 0 se i tak kitne 'N' aaye jinka penalty lagega agar hum us time tak khule rahe
        // penaltySsum[i]: i se end tak kitne 'Y' aaye jinka penalty lagega agar hum us time ke baad band ho gaye
        vector <int> penaltyPsum(n, 0);
        vector <int> penaltySsum(n, 0);

        // Pehle customer ke liye check kar rahe ki agar 'N' hai to pehli penalty 1 se shuru hogi
        penaltyPsum[0] = (customers[0] == 'N' ? 1 : 0);

        // Prefix penalty calculate kar rahe: 
        // Agar koi customer 'N' bolta hai jab hum khule hain, to uska penalty lagta hai
        for (int i = 1; i < n; i++) {
            penaltyPsum[i] = penaltyPsum[i - 1] + (customers[i] == 'N' ? 1 : 0);
        }

        // Last customer ke liye check kar rahe ki agar 'Y' hai to uska penalty count 1 se shuru hoga
        penaltySsum[n - 1] = (customers[n - 1] == 'Y' ? 1 : 0);

        // Suffix penalty calculate kar rahe:
        // Agar hum band ho gaye aur koi customer 'Y' bolta hai, to uska penalty lagega
        for (int i = n - 2; i >= 0; i--) {
            penaltySsum[i] = penaltySsum[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        // Minimum penalty aur best closing hour track karne ke liye variables banaye
        int minPenalty = INT_MAX;
        int bestHour = 0;

        // Ab har possible closing hour ke liye total penalty nikalenge
        for (int i = 0; i <= n; i++) {
            int totalPenalty = 0;

            // Agar hum hour i pe band ho rahe hain, to:
            // - 0 se i-1 tak open the => yaha tak jitne 'N' aaye, unka penalty lagega
            if (i > 0) {
                totalPenalty += penaltyPsum[i - 1];
            }

            // - i se n-1 tak band the => yaha jitne 'Y' aaye, unka penalty lagega
            if (i < n) {
                totalPenalty += penaltySsum[i];
            }

            // Agar current totalPenalty ab tak ka minimum hai to bestHour update karo
            if (totalPenalty < minPenalty) {
                minPenalty = totalPenalty;
                bestHour = i;
            }
        }

        // Final best hour return karo
        return bestHour;
    }
};




// At any index, the penalty is the sum of prefix count of ‘N’ and suffix count of ‘Y’.
// (good akash)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        // Ye n + 1 size isliye le rahe hain kyuki ek possibility ye bhi hai ki hum shop ko
        // sab customers ke baad band karein (i.e., after hour n).

        // To handle that case, extra index chahiye.
        vector <int> prefixNCount(n + 1, 0);    // Ye track karega kitne 'N' aaye hain pehle se (left side se)
        vector <int> suffixYCount(n + 1, 0);    // Ye track karega kitne 'Y' baad me (right side se) aayenge

        // Initial condition: 0th hour pe koi bhi 'N' customer attend nahi kiya
        prefixNCount[0] = 0;

        // prefixNCount[i] = number of 'N' customers from index 0 to i-1
        for (int i = 1; i <= n; i++) {
            prefixNCount[i] = prefixNCount[i - 1] + (customers[i - 1] == 'N' ? 1 : 0);
            // i-1 isliye kiya because string is 0-based, but prefix is 1-based
        }

        // Initial condition: nth hour ke baad koi customer nahi aayega, to count 0
        suffixYCount[n] = 0;

        // suffixYCount[i] = number of 'Y' customers from index i to n-1 (excluding i)
        for (int i = n - 1; i >= 0; i--) {
            suffixYCount[i] = suffixYCount[i + 1] + (customers[i + 1] == 'Y' ? 1 : 0);
            // i+1 isliye check kiya because hum current index ko exclude kar rahe hain
        }

        int minPenalty = INT_MAX;  // Minimum penalty ka tracker
        int bestTime = -1;         // Best closing hour tracker

        // Har hour ke liye penalty calculate kar rahe hain
        for (int i = 0; i <= n; i++) {
            /*
            Closing at hour i ka matlab:
            - Pehle ke i hours tak hum open the (i.e., indexes 0 to i-1)
            - Baad ke n-i hours ke liye shop band rahegi (i.e., indexes i to n-1)
            
            So penalty hoga:
            - prefixNCount[i]: Un customers ka count jinhe humne khula hone ke bawajood ignore kiya ('N')
            - suffixYCount[i]: Un customers ka count jo hum band hone ke baad miss kar denge ('Y')
            */

            int currPenalty = prefixNCount[i] + suffixYCount[i];

            // Extra edge case: agar i < n aur customers[i] == 'Y', toh hum usko bhi miss kar rahe hain
            // But actually, suffixYCount already handles i to n-1 excluding i, so we don't need this:
            // + (customers[i] == 'Y' ? 1 : 0);

            if (currPenalty < minPenalty) {
                minPenalty = currPenalty;
                bestTime = i;
            }
        }

        return bestTime;  // Vo hour jisme penalty sabse kam hogi
    }
};


/*

PrefixNCount[i]: Tells us how many customers from 0 to i-1 said 'N' —
 we were open, but they didn’t come, so we get penalty for being unnecessarily open.

 SuffixYCount[i]: Tells us how many customers from i+1 to n-1 said 'Y' — 
 we were closed when they came, so we lose potential customers and get a penalty.

 Total penalty at hour i = people who didn’t come while we were open + people who came after we closed.

*/
