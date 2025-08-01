// twoNumbersWithOddOccurences.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an unsorted array, Arr[] of size N and that contains even number of occurrences 
for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:

Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 

Explanation: 5 and 1 have odd occurrences.

Example 2:

Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}

Explanation: 7 and 1 have odd occurrences.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N 
as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 ≤ N ≤ 1e6
1 ≤ Arri ≤ 1e12

*/


// brute force
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoOddNum(vector<int> &arr, int n) {
        unordered_map<int, int> freq;
        vector<int> ans;

        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        // Collect elements with odd frequency
        for (const auto& el : freq) {
            int x = el.first;
            int f = el.second;

            if (f & 1)
                ans.push_back(x);
        }

        // Sort in decreasing order
        sort(ans.begin(), ans.end(), greater<int>());

        return ans;
    }
};



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoOddNum(vector<int> &arr) {
        int n = arr.size();
        int xorAll = 0;

        // Step 1: XOR all elements → result = x ^ y
        for (int i = 0; i < n; i++) {
            xorAll ^= arr[i];
        }

        // Step 2: Find rightmost set bit in xorAll
        int setBit = xorAll & -xorAll;

        int num1 = 0, num2 = 0;

        // Step 3: Divide elements in two groups based on the set bit
        for (int i = 0; i < n; i++) {
            if (arr[i] & setBit) num1 ^= arr[i];  // group 1
            else num2 ^= arr[i];  // group 2
        }

        // Step 4: Return in decreasing order
        if (num1 > num2) return {num1, num2};
        else return {num2, num1};
    }
};


class Solution {
public:

    vector <long long int> twoOddNum(long long int Arr[], long long int N) {
        // Step 1: XOR all elements of the array
        // Since all elements appear even number of times except two,
        // all even-occurring elements will cancel out, leaving a^b

        long long int xorr = 0;
        for(int i = 0; i < N; i++) xorr ^= Arr[i];
        

        // Now xorr = a ^ b (where a and b are the two odd-occurring numbers)
        // The next step is to find a bit that is different in a and b.
        // The rightmost set bit in xorr will help us separate a and b
        // xorr & ~(xorr - 1) isolates the rightmost set bit
        long long int setBit = xorr & ~(xorr - 1);

        // We will now divide all numbers into two groups based on the `setBit`
        // Group 1: numbers where this bit is set
        // Group 2: numbers where this bit is not set
        // Because a and b differ at this bit, they will fall into separate groups

        long long int num1 = 0;
        long long int num2 = 0;

        for (long long int i = 0; i < N; i++) {
            // If current element has the set bit, go into group 1

            // thoda isko digest karwao....
            if (Arr[i] & setBit) num1 ^= Arr[i];  // XOR all such elements
            else num2 ^= Arr[i];  // XOR elements in group 2
        }

        // After the loop:
        // num1 will contain one odd-occurring number
        // num2 will contain the other odd-occurring number

        // Return the numbers in decreasing order as required by the problem
        if (num1 > num2) return {num1, num2};
        
        else return {num2, num1};
    }
};

/*
🧠 Explanation in Steps:

1. XOR all elements to get a^b (because duplicates cancel each other).
2. Find any set bit in a^b — the rightmost set bit is easiest and fastest to compute.
3. Divide elements into two groups using that set bit:
   - a and b will fall into different groups.
   - All other elements (which appear even times) will also fall into one of the two groups, but XOR within each group will cancel them out.
4. XOR elements in each group to get the two odd-occurring numbers.
5. Return them in decreasing order.
*/
