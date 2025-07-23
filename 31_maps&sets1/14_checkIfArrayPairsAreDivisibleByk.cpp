// checkIfArrayPairsAreDivisibleByK.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return true If you can find a way to do that or false otherwise.

 
Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true

Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).


Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true

Explanation: Pairs are (1,6),(2,5) and(3,4).


Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs 
each with sum divisible by 10.
 

Constraints:

arr.length == n
1 <= n <= 1e5
n is even.

-109 <= arr[i] <= 1e9
1 <= k <= 1e5

*/

/*

Intuition

Sum divisible by k means (a + b) % k == 0
Using modulo properties:
(a + b) % k == 0 ⇒ a % k + b % k == k or 0
So:

If a % k == r, then to make pair with sum divisible by k, we need a number with b % k == (k - r) % k

That’s why:
remainder 0 → must be paired with itself ⇒ count must be even
remainder r → must have same count as remainder k - r

*/


class Solution {
public:

    bool canArrange(vector <int> &arr, int k) {
        vector <int> v;
        int cnt = 0;

        for(auto it:arr){
            int rem = it%k;

            if(rem == 0) cnt++;

            if (rem < 0) rem += k;

            v.push_back(rem);

        }

        if(cnt%2 != 0)return false;

        sort(v.begin(),v.end());

        int i =0;
        int j = v.size()-1;

        while(i<j){

            if(v[i] + v[j] != k)return false;

            else {
                i++;
                j--;
            }
        }

        return true;
    }

};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canArrange(vector <int> &arr, int k) {
        unordered_map <int, int> freq; // remainder -> count

        // Step 1: Count frequency of remainders
        for (auto el : arr) {
            int rem = el % k;

            // Handle negative remainders: -1 % 5 = -1 --> fix it to 4
            if (rem < 0) rem += k;

            freq[rem]++;
        }

        // Step 2: Special case: remainder 0 (means number is divisible by k)
        // It can only be paired with another number with remainder 0
        if (freq[0] % 2 != 0) return false;

        // Step 3: For all other remainders, check pairing condition
        for (int r = 1; r <= k / 2; r++) {

            // remainder i and remainder k - i must have same frequency
            // because they pair to form a multiple of k
            if (freq[r] != freq[k - r]) {
                return false;
            }
        }

        return true;
    }
};


// sort karke