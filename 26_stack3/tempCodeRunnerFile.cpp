#include <bits/stdc++.h>
using namespace std;

bool validStackPermutation(vector<int> &first, vector<int> &other) {
    stack<int> st;  // Simulate the stack
    int j = 0;      // Pointer for the 'other' array

    for (int i = 0; i < first.size(); ++i) {
        // Push the current element of 'first' into the stack
        st.push(first[i]);

        // Keep popping from the stack as long as the top matches 'other[j]'
        while (!st.empty() && st.top() == other[j]) {
            st.pop();
            j++;  // Move to the next element in 'other'
        }
    }

    // If the stack is empty, all elements were matched correctly
    return st.empty();
}

int main() {
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> other = {4, 5, 3, 2, 1};

    if (validStackPermutation(first, other)) {
        cout << "Yes, it is a valid stack permutation." << endl;
    } else {
        cout << "No, it is not a valid stack permutation." << endl;
    }

    return 0;
}
