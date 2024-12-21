#include <bits/stdc++.h>
using namespace std;



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0; // No transactions possible
        
        int res = 0; // Total profit
        int i = 0;

        while (i < n - 1) {
            // Find local minima (buy point)
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            if (i == n - 1) break; // No more transactions possible
            int lMin = prices[i];

            // Find local maxima (sell point)
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int lMax = prices[i];

            // Calculate profit
            res += (lMax - lMin);
        }

        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends