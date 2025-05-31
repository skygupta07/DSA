#include <bits/stdc++.h>
using namespace std;

/*

You are given an array arr[] of integers, 
where each element arr[i] represents the number of pages in the ith book. 
You also have an integer k representing the number of students. 

The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. 

In other words, out of all possible allocations, find the arrangement where the student 
who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, 
and allotment should be in contiguous order 
(see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.


Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.


Input: arr[] = [22, 23, 67], k = 1
Output: 112


Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103 

*/

class Solution {
public:

    // 📌 Helper function to check if allocation is possible with maxPages limit
    bool isPossible(vector<int> &arr, int k, int maxPages) {
        int students = 1;
        int currentSum = 0;
        
        for (int pages : arr) {

            // Agar kisi book ka pages hi maxPages se zyada hai -> allocation hi possible nahi
            if (pages > maxPages) return false;

            // Agar current student ko aur pages diye toh max cross ho jayega
            if (currentSum + pages > maxPages) {
                students++;            // Naya student chahiye
                currentSum = pages;    // Usko yeh book de do

                // Agar students zyada ho gaye k se → allocation fail
                if (students > k) return false;
            } 
            else {
                currentSum += pages;   // Add to current student's pages
            }
        }
        
        return true;  // Possible to allocate with current maxPages
    }

    // 📌 Main function to find minimum possible max pages
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        // Edge case: Students > Books
        if (k > n) return -1;

        int lo = *max_element(arr.begin(), arr.end());     // Minimum value of maxPages
        int hi = accumulate(arr.begin(), arr.end(), 0);    // Maximum value of maxPages

        int result = -1;

        // Binary Search on the range [lo, hi]
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Check if allocation is possible with mid as maxPages
            if (isPossible(arr, k, mid)) {
                result = mid;         // Store current answer
                hi = mid - 1;         // Aur chhoti value try karo
            } 
            else {
                lo = mid + 1;         // Aur badi value try karo
            }
        }

        return result;  // Minimum value of maximum pages possible
    }
};










/*


TC = O(n * log(sum - max))
✅ Space Complexity:
No extra space used → O(1) (excluding input vector)

*/
