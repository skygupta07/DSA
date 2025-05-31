#include <bits/stdc++.h>
using namespace std;


/*

You are given an array with unique elements of stalls[], which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. 
Your task is to assign stalls to k cows such that the minimum distance between any two of them 
is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.


Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.


Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
2 <= k <= stalls.size()
*/


class Solution {
public:
  
    // Helper function to check: kya cows ko `distance` ka gap deke place kar sakte ho?
    bool canPlaceCow(vector <int> &stalls, int k, int distance){
        int count = 1;  // First cow ko hamesha pehle stall pe place karenge
        int lastPosition = stalls[0]; // Pehli cow yahan rakhi
 
        // Baaki stalls check karo
        for (int i = 1; i < stalls.size(); i++) {
            // Agar current stall aur last placed cow ke beech ka distance >= required distance hai {love line}
            if (stalls[i] - lastPosition >= distance) {
                count++;                    // Ek aur cow place kar do
                lastPosition = stalls[i];   // Update karo last placed position
            }
            if (count == k) return true; // Agar sab cows place ho gayi
        }

        return false; // Nahi ho payi cows place
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end()); // Sabse important: sort karna so that distance logic kaam kare

        int lo = 1; // Minimum possible distance (1 le sakte ho max tight spacing me)
        int hi = stalls[n - 1] - stalls[0]; // Maximum possible distance (corner pe cows rakho)

        int result = 0; // Isme store karenge best possible largest minimum distance

        // Binary search on distance
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // Yeh hum try kar rahe hai as minimum distance between cows

            // Check karo ki kya cows ko `mid` distance ka gap deke place kar sakte ho
            if (canPlaceCow(stalls, k, mid)) {
                result = mid;     // Agar ho gaya, to store karo answer
                lo = mid + 1;     // Aur try karo aur zyada distance ke liye
            } 
            else {
                hi = mid - 1;     // Nahi ho paya to distance kam karo
            }
        }

        return result;
    }
};


/*
sort stalls 

binary search on distances 
     if possible with mid distance to place all the cow then good 
     else lo = mid + 1 ,  hi = mid - 1 wala...

*/


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends