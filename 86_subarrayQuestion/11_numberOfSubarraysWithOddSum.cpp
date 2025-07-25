class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            long long evenCount = 1; // Initially, prefix sum 0 is even.
            long long oddCount = 0;
            long long count = 0;    // Final answer count.
            long long prefSum = 0;
    
            for (int i = 0; i < n; i++) {
                prefSum += arr[i];
    
                // Correctly check if prefSum is even. 
                // my mistake that I forgot brackets here..
                if ((prefSum & 1) == 0) {
                    // If current prefix sum is even, then a subarray ending here is odd
                    // if it starts after a prefix with odd sum.
                    count = (count + oddCount) % MOD;
                    evenCount++;
                } else {
                    // If current prefix sum is odd, then a subarray ending here is odd
                    // if it starts after a prefix with even sum.
                    count = (count + evenCount) % MOD;
                    oddCount++;
                }
            }
    
            return count;
        }
    };
    