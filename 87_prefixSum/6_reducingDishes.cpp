    sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        int totalSatisfaction = 0;
        int currSum = 0;
        
        // Iterate from the end to the start
        for (int i = n - 1; i >= 0; --i) {
            // If adding the current dish satisfaction increases the total satisfaction
            if (currSum + satisfaction[i] > 0) {
                currSum += satisfaction[i];
                totalSatisfaction += currSum;
            } else {
                break;
            }
        }
        
        return totalSatisfaction;

//  -----------     ------- - -- - - - -


    // Sort the satisfaction array in ascending order
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        vector<int> prefixSum(n + 1, 0);
        
        // Calculate prefix sums
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + satisfaction[i - 1];
        }
        
        int maxSatisfaction = 0;
        
        // Iterate from the end to the start
        for (int i = n - 1; i >= 0; --i) {
            int currSatisfaction = 0;
            int time = 1;
            
            // Calculate the like-time coefficient starting from this point
            for (int j = i; j < n; ++j) {
                currSatisfaction += time * satisfaction[j];
                ++time;
            }
            
            // Update the maximum satisfaction
            maxSatisfaction = max(maxSatisfaction, currSatisfaction);
        }
        
        return maxSatisfaction;



// --------------------


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();

        vector <int> suff(n+1 , 0);

        suff[n-1] = satisfaction[n-1];

        for (int i=n-2; i>=0; i--){
            suff[i] = satisfaction[i] + suff[i+1];
        }

        int pivotIdx = -1;

        for (int i=0; i<n; i++){
            if (suff[i] >= 0){
                pivotIdx = i;
                break;
            }
        }

        if (pivotIdx == -1) return 0;

        // start from pivotIdx and calculate sum

        int time = 1;
        int ans = 0;
        for (int i=pivotIdx; i<n; i++){
            ans += satisfaction[i]*time;
            time++;
        }

        return ans;
    }
};


/*
suffix array se kara... 
jaha pehla positive element mila ... wahi mera pivot index hoga...

agar positive element hi nahi mila .....

*/