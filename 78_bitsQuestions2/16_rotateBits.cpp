#include <bits/stdc++.h>
using namespace std;

/*

Given an integer N and an integer D, rotate the binary representation of the integer N 
by D digits to the left as well as right and return the results 
in their decimal representation after each of the rotation.

Note: Integer N is stored using 16 bits. 
i.e. 12 will be stored as 0000000000001100. 

Output array should follow {leftrotation, rightrotation}.

Examples :

Input: n = 28, d = 2
Output: [112, 7]

Explanation: 28 in Binary is: 0000000000011100. 
Rotating left by 2 positions, it becomes 0000000001110000 = 112 (in decimal). 
Rotating right by 2 positions, it becomes 0000000000000111 = 7 (in decimal).

Input: n = 29, d = 2
Output: [116, 16391]

Explanation: 29 in Binary is: 0000000000011101. 
Rotating left by 2 positions, it becomes 0000000001110100 = 116 (in decimal). 
Rotating right by 2 positions, it becomes 010000000000111 = 16391 (in decimal).


Input: n = 11, d = 10
Output: [11264, 704]


Constraints:
1 <= n <  2e16
1 <= d <= 1e5

*/


class Solution {
  public:
  
    vector<int> rotate(int n, int d) {
        // Step 1: Reduce rotation amount to within 0-15
        // Because binary representation is of 16 bits only
        // Rotating 16 or 32 or 48 times gives same result

        d = d % 16;

        /*
        Explanation:
        Let's say n = 28 (which is 0000 0000 0001 1100 in 16 bits)
        d = 2

        We want to rotate bits in circular fashion:
        - Left rotation means: bits pushed out from MSB (left side) re-enter at LSB (right side)
        - Right rotation means: bits pushed out from LSB re-enter from MSB
        */

        // Step 2: Perform left rotation
        // Logic: 
        // - Left shift n by d positions: (n << d)
        //     → this shifts bits left and adds 0s at the right end
        //     → but leftmost bits are lost, so we need to recover them
        // - To recover the lost bits, we do: (n >> (16 - d))
        //     → this brings the MSB bits to the LSB side
        // - Combine both with OR (|), then mask with 0xFFFF to ensure only 16 bits remain

        int left = ((n << d) | (n >> (16 - d))) & 0xFFFF;

        /*

        Example:
        n = 28 → binary = 0000 0000 0001 1100
        d = 2

        n << 2  → 0000 0000 0111 0000      = 112
        n >> 14 → 0000 0000 0000 0000      = 0
        OR      → 0000 0000 0111 0000      = 112
        
        left = 112
        
        */

        // Step 3: Perform right rotation
        
        // Logic: Same as left but reversed
        // - Right shift n by d positions: (n >> d)
        //     → this brings LSB to right and adds 0s at MSB
        // - Left shift n by (16 - d): (n << (16 - d))
        //     → brings LSB bits to MSB side
        // - OR them and apply mask

        int right = ((n >> d) | (n << (16 - d))) & 0xFFFF;

        /*
        Continuing same example:
        n = 28 → binary = 0000 0000 0001 1100
        d = 2

        n >> 2  → 0000 0000 0000 0111      = 7
        n << 14 → 0000 0000 0000 0000 (only last 2 bits move to MSB) = 0
        OR      → 0000 0000 0000 0111      = 7
        right = 7
        */

        // Step 4: Return result in vector {left rotation result, right rotation result}
        return {left, right};
    }
};
