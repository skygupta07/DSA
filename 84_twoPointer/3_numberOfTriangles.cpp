// numberOfTriangles.cpp

/*

Given an integer array arr[]. Find the number of triangles that can be formed with three different array 
elements as lengths of three sides of the triangle. 

A triangle with three given sides is only possible if sum of any two sides is always greater 
than the third side.

Examples:

Input: arr[] = [4, 6, 3, 7]
Output: 3

Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. 
Note that [3, 4, 7] is not a possible triangle. 

Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6

Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]


Input: arr[] = [1, 2, 3]
Output: 0
Explanation: No triangles are possible.


Constraints:
1 <= arr.size() <= 1e3
0 <= arr[i] <= 1e5


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔁 Function to count total number of triplets (i, j, k)
    // such that arr[i] + arr[j] > arr[k] i.e., they can form a triangle
    int countTriangles(vector<int>& arr) {
        int n = arr.size();

        // 🔢 Step 1: Sort the array in ascending order
        // Taaki hum 2-pointer approach efficiently apply kar saken
        sort(arr.begin(), arr.end());

        int count = 0;

        // 🔁 Step 2: Fix the third (largest) side of triangle at index k
        // Aur fir 0 to (k-1) ke beech mein 2-pointer se valid pairs dhoondho
        for (int k = n - 1; k >= 2; k--) {

            // i aur j ko fix karte hain 0 aur (k-1) par
            int i = 0, j = k - 1;

            // 🔁 Step 3: 2-pointer approach
            // Check karte hain kitne pairs (i, j) aise hain ki:
            // arr[i] + arr[j] > arr[k]  -> Triangle condition satisfied

            while (i < j) {

                if (arr[i] + arr[j] > arr[k]) {
                    // ✅ Jab bhi triangle condition satisfy hoti hai,
                    // To i se leke (j-1) tak ke saare elements ke saath arr[j] valid triangle banayenge
                    count += (j - i);  // yeh sare valid pairs hain

                    // Ab j ko ek step left le chalo, aur naye pairs try karo
                    j--;
                } 
                
                else {
                    // ❌ Jab arr[i] + arr[j] <= arr[k] ho,
                    // Matlab sum badhaana padega => i++
                    i++;
                }
            }
        }

        // 🔚 Return final count of valid triangles
        return count;
    }
};


// Driver code for testing
int main() {
    vector<int> arr = {4, 6, 3, 7}; // Sample input

    Solution sol;
    cout << sol.countTriangles(arr) << endl; // Output: 3

    return 0;
}

