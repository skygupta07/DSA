#include <iostream>
#include <vector>
using namespace std;
int main(){

}

class Solution {
public:

    int dp[101][101];
    
    int solve(int startStick, int endStick, vector <int> &cuts, int left, int right){
        if (left > right) return 0;

        if (dp[left][right] != -1) return dp[left][right];

        int cost = INT_MAX;

        for (int i=left; i<=right; i++){
            int leftCost = solve(startStick, cuts[i], cuts, left, i-1);
            int rightCost = solve(cuts[i], endStick, cuts, i+1, right);
            int currCost = (endStick - startStick) + leftCost + rightCost;
            cost = min(cost, currCost);
        }

        return dp[left][right] = cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin() , cuts.end());
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};