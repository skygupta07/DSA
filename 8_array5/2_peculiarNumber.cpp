#include <bits/stdc++.h>
using namespace std;


// Function to calculate the x-th Fibonacci number iteratively
int fib(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int prev1 = 0, prev2 = 1;
    for (int i = 2; i <= x; ++i) {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

// Helper function to check if a partition with the given max sum is possible

bool canPartition(vector<int>& arr, int k, int maxSum) {
    int partitions = 1, currentSum = 0;

    for (int num : arr) {
        if (currentSum + num > maxSum) {
            partitions++;
            currentSum = num;

            if (partitions > k) return false;

        } 
        else currentSum += num;
    }
    
    return true;
}

// Function to find the minimum possible maximum sum for K partitions
int maxSumMinPartition(vector<int>& arr, int k) {
    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);

    int result = hi;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (canPartition(arr, k, mid)) {
            result = mid;   // answer ye bhi ho sakta h isliye...
            hi = mid - 1;   // thoda aur lalach dikhao... and aur lower element ke liye try kiya..
        } 
        
        else lo = mid + 1;
    }

    return result;
}

// Function to calculate the peculiar number
int peculiarNumber(int n, int k, vector<int>& arr) {
    vector<int> v(n);

    // Step 1: Replace elements with their absolute difference from their index
    for (int i = 0; i < n; i++) {
        v[i] = abs(arr[i] - i);
    }

    // Step 2: Find the minimum maximum sum for K partitions
    int x = maxSumMinPartition(v, k);

    // Step 3: Return Fibonacci number if x < 100, otherwise return x
    return (x < 100) ? fib(x) : x;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call user logic function and print the output
    int result = peculiarNumber(n, k, arr);
    cout << result << endl;

    return 0;
}
