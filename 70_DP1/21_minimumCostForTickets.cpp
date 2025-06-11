// minimumCostForTickets.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector <int> dp;

    int solve(vector<int> &days, vector<int> &costs, int idx) {
        int n = days.size();

        if (idx >= n) return 0; // Base case: no more days left

        if (dp[idx] != -1) return dp[idx]; // Use memoized result if available

        // Option 1: Buy a daily ticket
        int dailyCost = costs[0] + solve(days, costs, idx + 1);

        // Option 2: Buy a weekly ticket
        int i;
        for (i = idx; i < n && days[i] < days[idx] + 7; i++);
        int weeklyCost = costs[1] + solve(days, costs, i);

        // Option 3: Buy a monthly ticket
        for (i = idx; i < n && days[i] < days[idx] + 30; i++);
        int monthlyCost = costs[2] + solve(days, costs, i);

        // Take the minimum of the three options
        return dp[idx] = min({dailyCost, weeklyCost, monthlyCost});
    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1); // Initialize dp array with -1
        
        return solve(days, costs, 0);
    }

};