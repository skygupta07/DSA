#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        int currSum = 0;

        unordered_set <int> st;
        for (auto el : banned) st.insert(el);

        for (int i=1; i<=n; i++){
            if (st.find(i) == st.end() && currSum <= maxSum){
                count++;
                currSum += i;
            }

            if ( currSum > maxSum ){
                count--;
                break;
            }
        }

        return count;
    }
};
