#include <bits/stdc++.h>
using namespace std;


vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n, INT_MIN); // Result for each window size

    // To find next smaller element to the right
    vector<int> nextSmaller(n, n);
    stack<int> s1;
    for (int i = n - 1; i >= 0; i--) {
        while (!s1.empty() && a[s1.top()] >= a[i]) s1.pop();
        if (!s1.empty()) nextSmaller[i] = s1.top();
        s1.push(i);
    }

    // To find next smaller element to the left
    vector<int> prevSmaller(n, -1);
    stack<int> s2;
    for (int i = 0; i < n; i++) {
        while (!s2.empty() && a[s2.top()] >= a[i]) s2.pop();
        if (!s2.empty()) prevSmaller[i] = s2.top();
        s2.push(i);
    }

    // Calculate the maximum of minimums for each window size
    for (int i = 0; i < n; i++) {
        // Length of the window in which `a[i]` is the minimum
        int len = nextSmaller[i] - prevSmaller[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }

    // Fill the remaining entries by propagating the maximums
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}

// Test the function
int main() {
    vector<int> a = {2, 1, 5, 6, 2, 3};
    int n = a.size();

    vector<int> result = maxMinWindow(a, n);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
