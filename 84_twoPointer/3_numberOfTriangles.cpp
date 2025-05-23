#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        // Sort the array
        sort(arr.begin(), arr.end());

        int count = 0;

        // Iterate over the array to fix the largest side
        for (int k = n - 1; k >= 2; --k) {
            
            int i = 0, j = k - 1;

            // Use two-pointer approach to find valid pairs
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    // All pairs between i and j are valid
                    count += (j - i);
                    --j;    // ab sum thoda ghata ke dekh lo...
                } 
                else { // sum badhana padega...
                    ++i;
                }
            }
        }
        return count;
    }
};

// Driver code
int main() {
    vector<int> arr = {4, 6, 3, 7};
    Solution sol;
    cout << sol.countTriangles(arr) << endl; // Output: 3
    return 0;
}
