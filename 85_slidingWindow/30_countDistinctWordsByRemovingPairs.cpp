// countDistinctWordsByRemovingPairs.cpp

/*

Problem Statement: Count Distinct Messages After Pair Removal
You are given a string message consisting of lowercase letters. 
Imagine that each character is placed inside a box, and you are allowed to separate exactly one pair 
of adjacent boxes (i.e., two consecutive characters).

Your task is to count how many distinct messages can be created by removing 
exactly one such pair from the string.

However, instead of literally removing the pair, 
you record the ASCII-sum of each pair of adjacent characters in the string 
and find how many unique such sums exist.


🧪 Example
Input:

message = "abba"
Explanation:

Pairs: "ab", "bb", "ba"

Their ASCII sums:
'a' + 'b' = 97 + 98 = 195
'b' + 'b' = 98 + 98 = 196
'b' + 'a' = 98 + 97 = 195

Distinct sums: {195, 196}
Output: 2


📌 Constraints
2 <= message.length() <= 1e5
message contains only lowercase English letters ('a' to 'z')


*/




#include <bits/stdc++.h>
using namespace std;

/*
    Function: count_distinct_words_by_removing_pairs

    Input:
    - message: ek string jisme har character ek box ko represent karta hai.

    Goal:
    - Consecutive 2 boxes (i.e., adjacent characters) ka ek pair banao.
    - Har pair ka ASCII sum nikalo → e.g. "ab" = 97 + 98 = 195
    - Aise sabhi consecutive pairs ke sum ka count nikalo jo unique hain.

    Example:
    message = "abba"
    Pairs: "ab", "bb", "ba"
    ASCII sums: 195, 196, 195
    Distinct sums = {195, 196}
    Output: 2
*/


int count_distinct_words_by_removing_pairs(const string& message) {
    int n = message.length();

    // Agar length 2 hai → sirf ek hi pair banega → return 1
    if (n == 2) return 1;

    // Set to store unique ASCII sums of adjacent character pairs
    unordered_set <int> uniqueSums;

    // Iterate through every pair of adjacent characters
    for (int i = 0; i < n - 1; i++) {

        int asciiSum = message[i] + message[i + 1]; // ASCII sum of current pair
        uniqueSums.insert(asciiSum);               // Add to set (duplicates automatically ignored)
    
    }

    return uniqueSums.size();  // Total unique sums = distinct messages

}

int main() {
    string message;

    // Input: ek line padho as message
    getline(cin, message);

    int result = count_distinct_words_by_removing_pairs(message);

    cout << result << endl;

    return 0;

}


