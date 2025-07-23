// allOONeDataStructure.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Design a data structure to store the strings' count with the ability to return the strings 
with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. 
If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. 
If the count of key is 0 after the decrement, remove it from the data structure. 
It is guaranteed that key exists in the data structure before the decrement.

getMaxKey() Returns one of the keys with the maximal count. 
If no element exists, return an empty string "".

getMinKey() Returns one of the keys with the minimum count. 
If no element exists, return an empty string "".

Note that each function must run in O(1) average time complexity.


Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]

Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
 

Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 1e4 calls will be made to inc, dec, getMaxKey, and getMinKey.

*/


class AllOne {
public:

    unordered_map <string, int> mp;  // har key ka frequency store karta hai
    set <pair <int, string>> st;      // ordered set: (frequency, key)

    // Constructor
    AllOne() {
        mp.clear(); // freq map reset (though it's already empty initially)
    }

    // Increment frequency of given key
    void inc(string key) {
        int n = mp[key];  // current frequency (0 if key doesn't exist)
        mp[key]++;        // increase frequency

        st.erase({n, key});     // pehle purane freq waali entry hatao
        st.insert({n + 1, key}); // naye freq ke saath insert karo
    }

    // Decrement frequency of given key
    void dec(string key) {
        int n = mp[key];  // current frequency
        mp[key]--;        // decrease frequency

        st.erase({n, key});      // purani frequency waali entry hatayi

        if (mp[key] > 0) {
            st.insert({n - 1, key});  // agar frequency abhi bhi > 0 hai toh insert karo
        } 
        
        else {
            mp.erase(key);  // agar frequency 0 ho gayi toh map se bhi hata do
        }
    }

    // Return any key with maximum frequency
    string getMaxKey() {
        if (!st.empty()) {
            return st.rbegin()->second;  // set ka last element -> highest freq
        }

        return "";  // agar set empty hai toh return empty string
    }

    // Return any key with minimum frequency
    string getMinKey() {
        if (!st.empty()) {
            return st.begin()->second;  // set ka first element -> lowest freq
        }
        
        return "";  // agar set empty hai toh return empty string
    }
};



/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */