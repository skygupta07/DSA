#include <bits/stdc++.h>
using namespace std;



// Function to find the k-th character in the decrypted string
char kThCharaterOfDecryptedString(string s, long long k) {
    long long currentLength = 0;  // Tracks the length of the decrypted string processed so far
    string substring = "";        // To store the current substring
    long long repeatCount = 0;    // To store the repeat count of the substring

    for (int i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) { 
            // If it's an alphabet, start or continue forming the substring
            substring += s[i];
        } else {
            // If it's a digit, extract the complete repeat count
            repeatCount = 0;
            while (i < s.length() && isdigit(s[i])) {
                repeatCount = repeatCount * 10 + (s[i] - '0');
                ++i;
            }
            --i; // Adjust index as the loop increments it one extra time
            
            // Calculate the total contribution of this substring
            long long segmentLength = substring.length() * repeatCount;

            // If k lies in the current segment, determine the exact character
            if (currentLength + segmentLength >= k) {
                long long relativePosition = (k - currentLength - 1) % substring.length();
                return substring[relativePosition];
            }

            // Update the current processed length and reset the substring
            currentLength += segmentLength;
            substring = "";
        }
    }

    return '\0'; // This should never be reached if k is valid
}

int main() {
    string s;
    long long k;

    // Input the encrypted string and k
    cin >> s >> k;

    // Find and output the k-th character in the decrypted string
    cout << kThCharaterOfDecryptedString(s, k) << endl;

    return 0;
}
