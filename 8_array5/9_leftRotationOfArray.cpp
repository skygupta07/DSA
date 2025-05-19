#include <bits/stdc++.h>
using namespace std;

// Function to perform left rotations on the array
vector<vector<int>> leftRotations(vector<int> arr, vector<int> queries) {
    int n = arr.size(); // Size of the array
    vector<vector<int>> result;

    for (int k : queries) {
        // Calculate effective rotations
        int rotations = k % n;
        
        // Perform the rotation using slicing
        vector<int> rotated(arr.begin() + rotations, arr.end());
        rotated.insert(rotated.end(), arr.begin(), arr.begin() + rotations);
        
        // Store the result for this query
        result.push_back(rotated);
    }
    return result;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, q; // Size of array and number of queries
        cin >> n >> q;

        vector<int> arr(n); // Input array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> queries(q); // Queries array
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }

        // Get results for the current test case
        vector<vector<int>> results = leftRotations(arr, queries);

        // Print results
        for (const auto& res : results) {
            for (int x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
