#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree with n nodes, find the number of pairs violating the BST property.
BST has the following properties:-

Every node is greater than its left child and less than its right child.
Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.

The maximum in the left sub-tree must be less than the minimum in the right subtree.

*/


struct Node{
    int data;
    struct Node *left, *right;
};


class Solution {
  public:
  
  int ans = 0;
  
  int merge(vector <int> &arr, int st, int mid, int end){
      vector <int> temp1, temp2;

      for (int i=st; i<=mid; i++){
          temp1.push_back(arr[i]);
      }
      
      for (int i=mid+1; i<=end; i++){
          temp2.push_back(arr[i]);
      }
      
      int i=0, j=0, k = st;
      
      while (i<temp1.size() && j<temp2.size() && k<=end){

          if (temp1[i] <= temp2[j]){
              arr[k] = temp1[i];
              i++;
              k++;
          }

          else{
              ans += (temp1.size() - i);
              arr[k] = temp2[j];
              j++;
              k++;
          }

      }
      
      // say temp2 array exhausted then 
      
      while (i<temp1.size() && k<=end){

          arr[k] = temp1[i];
          i++;  // whomsoever helped you increment him...
          k++;

      }
      
      // say temp1 array has been exhausted then temp2 array will help...
      
      while(j<temp2.size() && k<=end){
          arr[k] = temp2[j];
          
          j++;
          k++;
      }
    }
      
      // merger sort fn.... (taki bas wo bad mai galtiya meri O(nlogn) mai search kar de bas)
      
      void mergeSort(vector <int> &arr, int st, int end){
          if (st >= end) return;
          int mid = (st + end)/2;
          
          mergeSort(arr,st,mid);
          mergeSort(arr, mid+1, end);
          
          merge(arr,st, mid,end);
      }
      
      // fn to create inorder array.....
      
      void inorder(vector <int> &arr, Node* root){
          if (root == NULL) return;

          inorder(arr, root->left);
          arr.push_back(root->data);
          inorder(arr, root->right);
      }
      
      

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector <int> arr;
        inorder(arr,root);
        mergeSort(arr,0,n-1);
        return ans;
    }
};