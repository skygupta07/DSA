// insertDeleteGetRandom O(1) - DuplicatesAllowed.cpp

#include <bits/stdc++.h>
using namespace std;


/*

RandomizedCollection is a data structure that contains a collection of numbers, 
possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements 
and also reporting a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.

bool insert(int val) Inserts an item val into the multiset, even if the item is already present. 
Returns true if the item is not present, false otherwise.

bool remove(int val) Removes an item val from the multiset if present. 

Returns true if the item is present, false otherwise. 

Note that if val has multiple occurrences in the multiset, we only remove one of them.


int getRandom() Returns a random element from the current multiset of elements. 

The probability of each element being returned is linearly related to the number of the same values 
the multiset contains.

You must implement the functions of the class such that each function works on average 
O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least 
one item in the RandomizedCollection.


Example 1:

Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]

Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return true since the collection does not contain 1.
                                  // Inserts 1 into the collection.
randomizedCollection.insert(1);   // return false since the collection contains 1.
                                  // Inserts another 1 into the collection. Collection now contains [1,1].
randomizedCollection.insert(2);   // return true since the collection does not contain 2.
                                  // Inserts 2 into the collection. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should:
                                  // - return 1 with probability 2/3, or
                                  // - return 2 with probability 1/3.
randomizedCollection.remove(1);   // return true since the collection contains 1.
                                  // Removes 1 from the collection. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 or 2, both equally likely.
 

Constraints:

-2e31 <= val <= 2e31 - 1
At most 2 * 1e5 calls in total will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

*/


#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
private:

    // Stores all inserted values as (val, index in valIndices[val])
    vector <pair <int, int>> elements;

    // Maps each value to a list of indices in the 'elements' vector
    unordered_map <int, vector<int>> valIndices;


public:

    RandomizedCollection() {
        // Constructor: nothing to initialize explicitly
    }

    bool insert(int val) {
        // Check if the value already exists in the map
        bool isNew = valIndices.find(val) == valIndices.end();

        // Store the index where this val will be inserted
        valIndices[val].push_back(elements.size());

        // Store the value along with its index in valIndices[val]
        elements.emplace_back(val, valIndices[val].size() - 1);

        return isNew;
    }

    bool remove(int val) {
        // If val doesn't exist, return false
        if (valIndices.find(val) == valIndices.end()) return false;

        // Get index of val to remove from elements
        int removeIdx = valIndices[val].back();
        valIndices[val].pop_back();

        // Get the last element in elements
        auto last = elements.back(); // very very important to use this back - {otherwise iske liye tum phir 
        // ko alag hi datastructure lagane lagoge....}

        // Move last element to removed index if not already there
        elements[removeIdx] = last;

        // Update valIndices for the moved element
        valIndices[last.first][last.second] = removeIdx;

        // Remove last element
        elements.pop_back();

        // If valIndices[val] is empty, erase the entry
        if (valIndices[val].empty()) {
            valIndices.erase(val);
        }

        return true;

    }

    int getRandom() {
        int idx = rand() % elements.size();
        
        return elements[idx].first;
    }
    
};




/* * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */