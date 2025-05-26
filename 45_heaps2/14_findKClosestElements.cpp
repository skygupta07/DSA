#include <bits/stdc++.h>
using namespace std;

/*


Given a sorted integer array arr, two integers k and x, 
return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 10

*/

class Solution {
public:
    vector <int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0; // Starting index
        int hi = arr.size() - k; // Last possible starting index for k elements

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; // Midpoint to check

            // Check whether left side or right side is closer to x
            if (x - arr[mid] <= arr[mid + k] - x) hi = mid; // Move to the left part
            
            else lo = mid + 1; // Move to the right part
        }

        // Return the k closest elements starting from 'lo'
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};

/*
### Intuition:
1. **Binary Search for the Starting Point**:
   - Hume continuous k elements chahiye jo `x` ke sabse kareeb ho.
   - Ek tarika yeh hai ki arr ke har subarray ka distance x se calculate karein, but yeh inefficient hai.
   - Binary search ka use karke efficiently "starting point" dhundhte hain jaha se k elements shuru hote hain aur sabse kareeb hain.

2. **Midpoint Check**:
   - Agar `x - arr[mid]` (left side ka distance) <= `arr[mid + k] - x` (right side ka distance), iska matlab left side zyada kareeb hai, to `hi = mid`.
   - Warna right side zyada kareeb hai, to `lo = mid + 1`.

3. **Result**:
   - Final result wo subarray hoga jo `arr[lo]` se shuru hoke `arr[lo + k - 1]` tak jaata hai.

---

### Algorithm (Hindi Wali English):
1. **Binary Search Range**:
   - Low index ko `0` rakha aur high index ko `arr.size() - k`.
   - Yeh range isliye rakhi kyunki agar humein k elements select karne hain, to maximum starting index `arr.size() - k` hoga.

2. **Binary Search Logic**:
   - Jab tak `lo < hi` ho, ek midpoint calculate karo (`mid = lo + (hi - lo) / 2`).
   - Check karo ki `mid` ke aas-paas ka subarray (size k) kaunsa `x` ke zyada kareeb hai:
     - Agar left side (`x - arr[mid]`) zyada kareeb hai ya barabar hai, to `hi = mid`.
     - Agar right side (`arr[mid + k] - x`) zyada kareeb hai, to `lo = mid + 1`.

3. **Return Result**:
   - Jab binary search complete ho jaye, `lo` ke index se start karke `k` elements ka subarray return karo.

---

### Example:
#### Input:
`arr = [1, 2, 3, 4, 5], k = 4, x = 3`

#### Steps:
1. Initial range: `lo = 0, hi = 1` (`arr.size() - k = 5 - 4 = 1`)
2. First mid: `mid = 0`  
   - Check: `x - arr[mid] = 3 - 1 = 2`, `arr[mid + k] - x = 5 - 3 = 2`  
   - Since `2 <= 2`, move left: `hi = mid = 0`.
3. Final range: `lo = hi = 0`.
4. Return: Subarray from index `0` to `3`: `[1, 2, 3, 4]`.

#### Output:
`[1, 2, 3, 4]`

*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <int, vector <int> , greater<int> > pq;

        for (int i=0; i<arr.size(); i++){
            if (pq.size() != k) pq.push(arr[i]);
            
            else{
                if (abs(arr[i] - x) < abs(pq.top() - x)){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }

        // now priority queue contains exactly k closest element
        vector <int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};


/*
take a minheap 
iterate over arr, if minHeap size is not equal to k then simply put element inside minHeap
else{
    then check if (abs(arr[i] - x) < abs(pq.top() - x)) then pop and then push current arr
}

*/