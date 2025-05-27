// https://unstop.com/code/practice/296904

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum size of any subset such that:
// For every element in a subset, there is no other element in the same subset 
// whose value differs by exactly 2.

int subsetMaximization(vector<int> &A, int N) {
    // Sort the input array to process elements in order.
    sort(A.begin(), A.end());

    // Map to store subsets using min-heaps for each key.
    // Key: Element in the array
    // Value: Min-heap of subset sizes ending at this key.
    map<int, priority_queue<int, vector<int>, greater<int>>> subsets;

    for (int i = 0; i < N; i++) {
        int current = A[i];
        int minSubsetSize = 0;

        // Check if there exists a subset ending at (current - 2).
        auto it = subsets.find(current - 2);
        if (it != subsets.end() && !it->second.empty()) {
            // Get the smallest subset size ending at (current - 2).
            minSubsetSize = it->second.top();
            it->second.pop();
        }

        // Increment the size for the current subset.
        minSubsetSize++;

        // Add this subset size to the heap for the current element.
        subsets[current].push(minSubsetSize);
    }

    // Find the smallest subset size across all elements.
    int result = N; // Initialize with the largest possible size.
    for (const auto &entry : subsets) {
        if (!entry.second.empty()) {
            result = min(result, entry.second.top());
        }
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Call the function and print the result.
    int result = subsetMaximization(A, N);
    cout << result << endl;

    return 0;
}
