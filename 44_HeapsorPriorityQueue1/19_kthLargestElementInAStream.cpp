#include <bits/stdc++.h>
using namespace std;

/*

You are part of a university admissions office and need to keep track of the kth highest test score 
from applicants in real-time. This helps to determine cut-off marks for interviews and admissions 
dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, 
maintains a stream of test scores and continuously returns the kth highest test score 
after a new score has been submitted. More specifically, we are looking for the kth highest score 
in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream 
of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing 
the kth largest element in the pool of test scores so far.


Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 10pow4
1 <= k <= nums.length + 1
-10pow4 <= nums[i] <= 10pow4
-10pow4 <= val <= 10pow4
At most 10pow4 calls will be made to add.

*/

class KthLargest {
public:
    int mk;
    priority_queue <int, vector<int>, greater<int>> pq; // Min-heap

    KthLargest(int k, vector<int>& nums) {
        mk = k;

        // Insert all elements from the initial list into the min-heap
        for (int num : nums) {
            pq.push(num);

            // tumhare kameene pan ke hum gulam ho gaye...
            if (pq.size() > mk) {
                pq.pop();  // Keep the size of the heap equal to k
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > mk) {
            pq.pop();  // Ensure the heap only contains the k largest elements
        }
        return pq.top();  // The top element is the k-th largest element
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


/*
data members ko different different member function ke through access karwana hota hai to 
.... data members ko public rakh diya karo....

Ensure the heap only contains the k largest elements -> 
iske liye minHeap banana padega... coz jaise hi element push ho aur meri k limit se cross kare 
to jo bhi min heap ka top hoga usey pop kar denge... 
issey mere heap mai hamesa k largest elements hi rahnge...
and then tab jab mai pq.top() karunga.. then I will get the kth largest element in a stream...



ha bhai k largest element banaye rakhne ke liye minheap ki jarurat hoti h...
*/