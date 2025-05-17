#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array arr[] and a number k. 
Find the count of distinct elements in every window of size k in the array.

Examples:

Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output:  [3, 4, 4, 3]
Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.

Input: arr[] = [4, 1, 1], k = 2
Output: [2, 1]
Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2. 
Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1. 

Input: arr[] = [1, 1, 1, 1, 1], k = 3
Output: [1, 1, 1]


Constraints:
1 <= k <= arr.size() <= 105
1 <= arr[i] <= 105

*/

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> ans;

        unordered_map <int, int> freq; // Frequency map to count elements

        // Process the first window
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        
        ans.push_back(freq.size()); // Add distinct count for the first window

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            // Remove the leftmost element of the previous window
            freq[arr[i - k]]--;
            
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]); // Remove from map if count becomes 0
            }

            // Add the new element
            freq[arr[i]]++;

            // Add the count of distinct elements for the current window
            ans.push_back(freq.size());
        }

        return ans;
    }
};

// Example usage
int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    Solution sol;
    vector<int> result = sol.countDistinct(arr, k);

    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
