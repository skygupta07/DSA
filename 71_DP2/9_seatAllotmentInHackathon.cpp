// seatAllotmentInHackathon.cpp

#include <bits/stdc++.h>
using namespace std;


// Using long long int to handle large numbers, especially with modulo arithmetic.
#define int long long int

// Define the modulo constant as per the problem statement.
const int MOD = 1000000007;

int32_t main() {
    int N; // Number of rows in the classroom.
    cin >> N;

    // If N is odd, the total number of seats (3 * N) will be odd,
    // making it impossible to fully pair all students. Return 0 in this case.
    if (N % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    // Initialize the dp array to store the number of ways to fill the rows up to N.
    vector<int> dp(N + 1, 0);

    // Base case: No valid arrangements for 0 rows.
    dp[0] = 0;

    // Base case: For 2 rows, there are exactly 3 valid arrangements.
    dp[2] = 3;

    // `sum` tracks the cumulative sum of dp values for efficient computation.
    // Start with 4 because dp[2] contributes to this sum for future calculations.
    int sum = 4;

    // Fill the dp array for even numbers of rows from 4 to N.
    for (int i = 4; i <= N; i += 2) {
        // Transition formula:
        // dp[i] = dp[i-2] + 2 * sum
        dp[i] = (dp[i - 2] + 2 * sum) % MOD;

        // Update the cumulative sum for the next iteration.
        sum = (sum + dp[i]) % MOD;
    }

    // Output the result stored in dp[N], which represents the number of valid arrangements
    // for a classroom with N rows.
    cout << dp[N] << endl;

    return 0;
}
