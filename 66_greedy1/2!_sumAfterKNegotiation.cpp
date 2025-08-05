// sumAfterKNegotiation.cpp // easy marked

/*

Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You *should* apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.

 

Example 1:

Input: nums = [4,2,3], k = 1
Output: 5

Explanation: Choose index 1 and nums becomes [4,-2,3].


Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6

Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].


Example 3:

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13

Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
 

Constraints:

1 <= nums.length <= 1e4

-100 <= nums[i] <= 100

1 <= k <= 1e4

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestSumAfterKNegations(vector<int> &nums, int k) {

        // Step 1: Create a Min Heap using all elements of the array
        // Min heap banana ka *maksad* yeh hai ki 
        // hum har baar sabse chhota element efficiently nikal saken
        
        // declaration + initialisation
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); // O(n)

        // Step 2: Calculate initial sum of all elements
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];  // O(n)
        

        // Step 3: Perform k operations 

        // for safer end always write {while (k-- & !pq.empty())}
        while (k--) {   // O(k log n)
            
            int el = pq.top();  // sabse chhota element le lo
            pq.pop();

            // Important check: agar 0 mil gaya, toh aur negate karne se koi farq nahi padega
            // e.g. - flip(0) → 0 → flip again → 0 → repeat...
            if (el == 0) break;

            // Flip the element's sign:
            // Example: el = -3 → after flip = 3
            sum -= el;       // pehle negative tha toh sum mein minus ho raha tha, ab usko minus kar ke nikal diya
            pq.push(-el);    // flip kar ke heap mein wapas daal diya
            sum += -el;      // ab woh positive ban gaya hai toh sum mein add kar diya

            // Alternate single line: sum = sum - el + (-el) = sum - 2*el
        }

        // Step 4: Final sum return karo
        return sum;
    }
};





#include <bits/stdc++.h>
using namespace std;


// negative mai jo chota element hoga wo agar positive kar diya to jyada helpful rahega...
// isliye minheap banayi...


class Solution {
public:

    // O(klogn + n)
    int largestSumAfterKNegations(vector <int> &nums, int k) {   
        
        priority_queue <int, vector<int>, greater<int> > pq(nums.begin() , nums.end()); //O(n)
        
        int sum = 0;

        for (int i=0; i<nums.size(); i++) sum += nums[i];   // O(n)

        while (k--){    // O(klogn)
            
            // it will be minimum available element of array since min heap...
            int el = pq.top();  
            pq.pop();
            
            if (el == 0) break;   // no further operation required if you encountered zero
            // kyuki iss moment pe phir saare negative elements process ho gaye honge...
            // aap ye bhi keh sakte ho ki ho sakta h iss moment par abhi k bacha to ...
            // to suno actually ye zero hi mil chuka h to ye to kitne bhi k to absorb to kar hi leta na..
            // isliye consider nahi kiya ...


            sum -= el;
            pq.push(-1*el);
            sum += -el;

        }

        return sum;    
    }

};

// using priority queue to get the min. element of the available array
