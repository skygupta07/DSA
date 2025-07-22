#include <bits/stdc++.h>
using namespace std;


/*
Given an array of integers arr[] representing inorder traversal of elements of a binary tree. 
Return true if the given inorder traversal can be of a valid Binary Search Tree.

Note - In a valid Binary Search Tree all keys are unique.

Examples :

Input: arr[] = [8, 14, 45, 64, 100]
Output: True
Input: arr[] = [5, 6, 1, 8, 7]
Output: False
Expected Time Complexity: O(n)

Expected Space Complexity: O(1)

*/

class Solution {
public:

      bool isBSTTraversal(vector<int>& arr) {

          for (int i=1; i<arr.size(); i++){
            // agar current element peechle element se chota ya even equal
            //  bhi ho gaya to BST not possibl at all...
              if (arr[i] <= arr[i-1]) return false;
          }
          
          return true;
      }
  };

  /*

   A subtree of the binary tree is considered a BST if for every node in that subtree, 
   the left child is less than the node, and the right child is greater than the node, 
   without any duplicate values in the subtree.
  */
  