#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Node{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};




Node* createTree(vector<int>&arr){
    int n = arr.size();
    
    queue <Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;  // zeroth index le liye 1 2 index se dekhna start karo...
    int j = 2;
    while (q.size() > 0 &&
           i < n) { // i<n because aisa ho sakta hai ki queue mai element rah
                    // gaye but tree to puri construct ho chuki thi...
      Node *temp = q.front();
      q.pop();
      Node *l; // do naye node banaye waha lagane ke liye...
      Node *r;

      if (arr[i] != INT_MIN)
        l = new Node(arr[i]);
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

      // increment i and j
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