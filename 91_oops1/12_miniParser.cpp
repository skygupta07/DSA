// miniParser.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a string s represents the serialization of a nested list, 
implement a parser to deserialize it and return the deserialized NestedInteger.

Each element is either an integer or a list whose elements may also be integers or other lists.


Example 1:

Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.


Example 2:

Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
Explanation: Return a NestedInteger object containing a nested list with 2 elements:
1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789
 

Constraints:

1 <= s.length <= 5 * 104
s consists of digits, square brackets "[]", negative sign '-', and commas ','.
s is the serialization of valid NestedInteger.
All the values in the input are in the range [-106, 106].

*/




  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
};
 

class Solution {
    public:
        // Function to deserialize a string representing a nested integer structure
        NestedInteger deserialize(string s) {
            istringstream in(s); // Create an input string stream from the given string
            return deserialize1(in); // Call the helper function to process the stream
        }
    
    private:
        // Helper function to recursively deserialize the nested integer structure
        NestedInteger deserialize1(istringstream &in) {
            int number;
            
            // Try reading an integer from the stream
            if (in >> number)
                return NestedInteger(number); // If successful, return it as a NestedInteger
            
            in.clear(); // Clear any error flags if reading an integer failed
            in.get(); // Consume the opening '[' character for a nested list
            
            NestedInteger list; // Create a NestedInteger object to store the list
    
            // Process elements inside the nested list until we reach the closing ']'
            while (in.peek() != ']') { 
                list.add(deserialize1(in)); // Recursively process nested elements
                
                // If the next character is a comma, consume it
                if (in.peek() == ',')
                    in.get();
            }
    
            in.get(); // Consume the closing ']' character
            return list; // Return the constructed nested list
        }
    };
    