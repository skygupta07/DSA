#include <bits/stdc++.h>
using namespace std;

// Function to find all factors of a number
vector<int> findFactors(int n) {
    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) { // Avoid duplicate for perfect squares
                ans.push_back(n / i);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

// Function to check if a string is periodic
bool isPeriodic(string s) {
    int n = s.length();

    // Get all factors of the string length
    vector <int> factors = findFactors(n);

    // Check for each factor
    for (int k : factors) {
        bool isValid = true;

        // Check if the string is composed of substrings of length k
        for (int i = k; i < n; i++) {

            if (s[i] != s[i % k]) {
                isValid = false;
                break;
            }
        }

        if (isValid) return true; // Found a valid periodic pattern
    }

    return false;
}

// Main function for testing
int main() {
    string s;
    cin >> s;

    if (isPeriodic(s)) {
        cout << "The string is periodic." << endl;
    } else {
        cout << "The string is not periodic." << endl;
    }

    return 0;
}
