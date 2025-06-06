#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int minimizeDifference(int n, int k, vector<int>& a){
        // Arrays to hold the minimum and maximum values of the prefix and suffix.
        vector<pair<int, int>> prefixMinMax(n), suffixMinMax(n);
        
        // Initializing prefix and suffix arrays.
        prefixMinMax[0] = {a[0], a[0]};
        suffixMinMax[n - 1] = {a[n - 1], a[n - 1]};
        
        for (int i = 1; i < n; i++) {

            int revIdx = n - i - 1;

            prefixMinMax[i] = {
                min(prefixMinMax[i - 1].first, a[i]),
                max(prefixMinMax[i - 1].second, a[i])
            };

            suffixMinMax[revIdx] = {
                min(suffixMinMax[revIdx + 1].first, a[revIdx]),
                max(suffixMinMax[revIdx + 1].second, a[revIdx])
            };

        }
        
        // Start with the difference for the first possible removal scenario.
        int minDiff = INT_MAX;

        // Compute the minimum difference considering the remaining segments after each potential removal.
        for (int i = 0; i <= n - k; i++){

            int minElem = i == 0 ? suffixMinMax[i + k].first : (i + k == n ? prefixMinMax[i - 1].first : min(prefixMinMax[i - 1].first, suffixMinMax[i + k].first));
            int maxElem = i == 0 ? suffixMinMax[i + k].second : (i + k == n ? prefixMinMax[i - 1].second : max(prefixMinMax[i - 1].second, suffixMinMax[i + k].second));
            
            minDiff = min(minDiff, maxElem - minElem);
        }
        
        return minDiff;

    }

};