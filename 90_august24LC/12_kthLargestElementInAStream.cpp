#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int mk;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    KthLargest(int k, vector<int>& nums) {
        mk = k;

        // Insert all elements from the initial list into the min-heap
        for (int num : nums) {
            pq.push(num);
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
data members ko different different member function ke through access karwana hota hai to .... data members ko public rakh diya karo....


Ensure the heap only contains the k largest elements -> iske liye minHeap banana padega... coz jaise hi element push ho aur meri k limit se cross kare to jo bhi min heap ka top hoga usey pop kar denge... issey mere heap mai hamesa k largest elements hi rahnge...and then tab jab mai pq.top() karunga.. then i will get the kth largest element in a stream...

*/