class Solution {
public:
    int numTeams(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            // Count increasing sequences
            int leftLess = 0, rightGreater = 0;
            for (int left = 0; left < i; left++) {
                if (arr[left] < curr) leftLess++;
            }
            for (int right = i + 1; right < n; right++) {
                if (arr[right] > curr) rightGreater++;
            }
            ans += leftLess * rightGreater;

            // Count decreasing sequences
            int leftGreater = 0, rightLess = 0;
            for (int left = 0; left < i; left++) {
                if (arr[left] > curr) leftGreater++;
            }
            for (int right = i + 1; right < n; right++) {
                if (arr[right] < curr) rightLess++;
            }
            ans += leftGreater * rightLess;
        }
        return ans;
    }
};