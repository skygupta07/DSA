#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *left, *right; // asked in interview..

    // constructors with varying use...(constructor overloading)
    Node(){
        this->data = 0;
        left = NULL;
    }
    Node(int data){
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};



Node* createTree(vector<int>&arr){
    int n = arr.size();
    
    queue <Node*> q;  // queue ki help se tree traverse karte hai (bfs).. 
    // chalo phir queue ki help se tree create bhi karte hai...

    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;  // zeroth index root h to obviously 1st index left child hoga and 
    //  2nd index right child hoga.....
    int j = 2;

    // bfs and creation
    while (q.size() > 0 &&
           i < n) { // i<n because aisa ho sakta hai ki queue mai element rah
                    // gaye but tree to puri construct ho chuki thi...(Raghav sir emphasised)
      Node *temp = q.front();
      q.pop();

      Node *l; // do naye node banaye waha lagane ke liye...
      Node *r;

      if (arr[i] != INT_MIN){ // if left child is valid 
          l = new Node(arr[i]);
      } 
      else
        l = NULL; // agar INT_MIN wala nikla array se to tree mai to bhai NULL
                  // hi hoga na attach

      // i last index pe ho but j aage nikal chuka hu...
      if (j != n && arr[j] != INT_MIN)
        r = new Node(arr[j]);
      else
        r = NULL;

      // establish connection with temp
      temp->left = l;
      temp->right = r;

      if (l != NULL)
        q.push(l); // wahi q ke front waale elements mai attach kiya..
      if (r != NULL)
        q.push(r);

      // increment i and j by 2 ofcourse
      i += 2;
      j += 2;
    }
    return root;
}


int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> v(arr, arr+n);

    createTree(v);
}