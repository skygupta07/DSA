#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr[] of size, N. 
Find the subarray with maximum XOR. A subarray is a contiguous part of the array.

Example 1:

Input:

N = 4
arr[] = {1,2,3,4}
Output: 7
Explanation: 
The subarray {3,4} has maximum xor 
value equal to 7.

Example 2:

Input:
N = 3
arr[] = {1,4,3}
Output: 7

Explanation: 
There are 6 possible subarrays:
 subarray            XOR value
 [1]                     1
 [4]                     4
 [3]                     3
 [1, 4]                  5 (1^4)
 [4, 3]                  7 (4^3)
 [1, 4, 3]               6 (1^4^3)

 [4, 3] subarray has maximum XOR value. So, return 7.
Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function maxSubarrayXOR() which takes the array arr[], 
its size N as input parameters and returns the maximum xor of any subarray. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= N <= 1e5
1 <= arr[i] <= 1e5

*/


// User function Template for C++
class Solution {
    
    // Trie node representing a bit (0 or 1)
    struct TrieNode {
        TrieNode* child[2];  // Two children: child[0] for 0, child[1] for 1
        
        TrieNode() {
            child[0] = child[1] = nullptr;  // Initialize both to NULL
        }

    };

    TrieNode* root;

    // Inserts the given number into the Trie (as a 32-bit binary number)
    void insert(int num) {

        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) { // Loop through all 32 bits from MSB to LSB
            
            int bit = (num >> i) & 1; // Extract the i-th bit
            
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode(); // Create new node if path doesn't exist
            }
            
            node = node->child[bit]; // Move to the next level in the Trie
        }
    }

    // For a given number, find the maximum XOR with any prefix in the Trie
    int getMaxXOR(int num) {

        TrieNode* node = root;

        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;          // Get the i-th bit of num
            int desired = 1 - bit;             // To maximize XOR, we want the opposite bit

            if (node->child[desired]) {
                // If desired bit is available, it contributes 1 to the XOR at this position
                maxXor |= (1 << i);            // Set the i-th bit in result
                node = node->child[desired];   // Move to desired path
            } 
            
            else {
                // Otherwise, move to existing bit
                node = node->child[bit];
            }

        }

        return maxXor;
    }

public:

    // Main function to find the maximum XOR of any subarray
    int maxSubarrayXOR(int N, int arr[]) {

        root = new TrieNode();  // Initialize Trie
        insert(0);              // Insert 0 to handle subarray starting from index 0

        int maxXor = 0;
        int prefixXor = 0;

        for (int i = 0; i < N; i++) {
            prefixXor ^= arr[i];                       // Calculate prefix XOR up to index i
            
            maxXor = max(maxXor, getMaxXOR(prefixXor)); // Query for best XOR with any previous prefix
            
            insert(prefixXor);                         // Insert current prefixXOR into the Trie
        }

        return maxXor;
    }

};
