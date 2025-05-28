#include <bits/stdc++.h>
using namespace std;

/*

You are given a nested list of integers nestedList. 
Each element is either an integer or a list whose elements may also be integers or other lists. 
Implement an iterator to flatten it.

Implement the NestedIterator class:

NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
int next() Returns the next integer in the nested list.
boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
Your code will be tested with the following pseudocode:

initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
If res matches the expected flattened list, then your code will be judged as correct.

 

Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 

Constraints:

1 <= nestedList.length <= 500
The values of the integers in the nested list is in the range [-106, 106].


*/





  // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
};
 

class NestedIterator {
private:
    vector<int> flattened; // Yeh ek flattened list store karega, jo nested list ko ek single vector mein convert karega
    int index; // Yeh iterator ka current index track karega

    // Yeh function ek nested list ko ek single flattened vector mein convert karega
    vector<int> flatten(const std::vector<NestedInteger>& nested) {
        vector<int> result; // Flattened integers yahan store honge

        // Har element ke liye check karenge ki woh integer hai ya ek aur nested list
        for (const auto& ni : nested) {
            if (ni.isInteger()) { // Agar yeh ek integer hai toh seedha result mein daal do
                result.push_back(ni.getInteger());
            } else { // Agar yeh ek nested list hai toh recursion se usko bhi flatten karo
                auto subList = flatten(ni.getList()); // Recursive call
                result.insert(result.end(), subList.begin(), subList.end()); // Flattened sublist ko result mein add karo
            }
        }
        return result; // Flattened list return karo
    }

public:
    // Constructor: Nested list ko flatten karke vector mein store karega
    NestedIterator(vector <NestedInteger> nestedList) {
        flattened = flatten(nestedList); // Flattened list create karo
        index = 0; // Index ko 0 se initialize karo
    }

    // Next integer return karega aur index badha dega
    int next() {
        return flattened[index++]; // Current index ka integer return karo aur index aage badhao
    }

    // Check karega ki koi next integer bacha hai ya nahi
    bool hasNext() {
        return index < flattened.size(); // Agar index flattened vector ke size se chhota hai toh true return karo
    }
};
