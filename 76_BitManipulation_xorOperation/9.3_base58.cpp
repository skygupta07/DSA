#include <bits/stdc++.h>
using namespace std;


string encodeBase58(int N) {
    // Base58 character set
    const string base58Alphabet = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

    // Edge case: If N is 0, directly return the first character
    if (N == 0) return "1";

    string result = "";

    // Convert the number to base 58
    while (N > 0) {
        int remainder = N % 58; // Get the remainder when dividing by 58
        result += base58Alphabet[remainder]; // Append the corresponding character
        N /= 58; // Divide N by 58
    }

    // Since the digits are computed in reverse order, reverse the string
    reverse(result.begin(), result.end());

    return result;
}

int main() 
{
    // Read the number of test cases
    int T;
    cin >> T;

    // Process each test case
    while (T--) {
        int N;
        cin >> N;
        cout << encodeBase58(N) << endl;
    }

    return 0;
}
