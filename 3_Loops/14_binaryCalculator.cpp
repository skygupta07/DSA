#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to convert a real number to its binary representation
string toBinaryCalculator(double num) {
    string binary = "0."; // Initialize the binary string
    int precision_limit = 32; // Set the precision limit

    while (num > 0) {
        // Check if binary representation exceeds the precision limit
        if (binary.length() > precision_limit + 2) { // +2 for "0."
            return "ERROR"; // Return error if limit is exceeded
        }

        num *= 2; // Multiply by 2 to extract the next binary digit

        if (num >= 1) {
            binary += "1"; // Add '1' if the result is greater than or equal to 1
            num -= 1;      // Subtract 1 from the result
        } else {
            binary += "0"; // Add '0' if the result is less than 1
        }
    }

    return binary; // Return the binary representation
}

int main() 
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t; // Read the number of test cases
    vector<string> results; // To store the results

    for (int i = 0; i < t; i++) {
        double num;
        cout << "Enter a real number between 0 and 1: ";
        cin >> num;

        // Validate input: It must be between 0 and 1
        if (num <= 0 || num >= 1) {
            results.push_back("ERROR");
        } else {
            results.push_back(toBinaryCalculator(num));
        }
    }

    // Print all results
    cout << "Output:" << endl;
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
