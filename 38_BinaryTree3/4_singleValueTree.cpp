#include <bits/stdc++.h>
using namespace std;

bool isSingleValuedTree(const vector<int>& arr) {
    int rootValue = -1;

    for (int val : arr) {
        if (val != -1) { // Ignore NULL nodes represented by -1
            if (rootValue == -1) {
                rootValue = val; // Set the root value
            } else if (rootValue != val) {
                return false; // Found a differing value
            }
        }
    }
    return true; // All non-NULL values are the same
}

int main() {
    vector<int> arr;
    int temp;

    while (cin >> temp) { // Read input until EOF
        arr.push_back(temp);
    }

    if (isSingleValuedTree(arr)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}qq