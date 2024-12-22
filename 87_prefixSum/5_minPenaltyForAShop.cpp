#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        // Initialize prefix and suffix penalty arrays
        vector<int> penaltyPsum(n + 1, 0);
        vector<int> penaltySsum(n + 1, 0);

        // Calculate prefix penalties
        for (int i = 1; i <= n; i++) {
            penaltyPsum[i] = penaltyPsum[i - 1] + (customers[i - 1] == 'N' ? 1 : 0);
        }

        // Calculate suffix penalties
        for (int i = n - 1; i >= 0; i--) {
            penaltySsum[i] = penaltySsum[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        // Calculate total penalties and find the minimum
        int minPenalty = INT_MAX;
        int bestHour = 0;
        for (int i = 0; i <= n; i++) {
            int totalPenalty = penaltyPsum[i] + penaltySsum[i];
            if (totalPenalty < minPenalty) {
                minPenalty = totalPenalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};












int main(){
    
}