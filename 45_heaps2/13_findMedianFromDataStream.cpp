#include <bits/stdc++.h>
using namespace std;

/*

The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, 
and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.

void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. 
Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]

Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-10pow5 <= num <= 10pow5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], 
how would you optimize your solution?

If 99% of all integer numbers from the stream are in the range [0, 100], 
how would you optimize your solution?

*/

class MedianFinder {
public:

    // Declare two heaps:
    // maxHeap: Stores the smaller half of the elements, with the largest element at the top.
    // minHeap: Stores the larger half of the elements, with the smallest element at the top.
    priority_queue <int> maxHeap; 
    priority_queue <int, vector<int>, greater<int>> minHeap; 

    // Constructor: Initializes the MedianFinder object.
    MedianFinder() { }

    // Function to add a number to the data structure
    void addNum(int num) {
        
        // If minHeap is empty or the number is greater than or equal to the smallest number in minHeap,
        // add the number to minHeap.

        if (minHeap.empty() || num >= minHeap.top()) {
            minHeap.push(num);

            // Balance the heaps: If minHeap has more than one extra element compared to maxHeap,
            // move the top of minHeap to maxHeap.
            if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

        } 

        // Else, add the number to maxHeap
        else {
            maxHeap.push(num);

            // Balance the heaps: If maxHeap has more elements than minHeap,
            // move the top of maxHeap to minHeap.
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    // Function to find the median
    double findMedian() {
        
        // If the total number of elements is even, the median is the average of the two middle elements.
        if ((maxHeap.size() + minHeap.size()) % 2 == 0) {
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        } 
        // If the total number of elements is odd, the median is the top element of minHeap
        // (since minHeap always contains the extra element when sizes differ).
        else {
            return minHeap.top();
        }
    }
};

/**
 * Usage:
 * 1. Create an instance of the MedianFinder class:
 *      MedianFinder* obj = new MedianFinder();
 * 
 * 2. Add numbers using the addNum method:
 *      obj->addNum(num);
 * 
 * 3. Find the current median using the findMedian method:
 *      double median = obj->findMedian();
 */
