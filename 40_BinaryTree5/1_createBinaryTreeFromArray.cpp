#include <bits/stdc++.h>
using namespace std;


class TreeNode{ 
public:
    // data members
    int data;
    TreeNode *left, *right; // asked in interview..

    // constructors with varying use...(constructor overloading)
    TreeNode(){
        this->data = 0;
        left = NULL;
    }
    TreeNode(int data){
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int data, TreeNode* left, TreeNode* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};



TreeNode* createTree(vector <int> &arr){
    int n = arr.size();
    
    queue <TreeNode*> q;  // queue ki help se tree traverse karte hai (bfs).. 
    // chalo phir queue ki help se tree create bhi karte hai...

    // threshold
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;  // zeroth index root h to obviously 1st index left child hoga and 
    //  2nd index right child hoga.....
    int j = 2;

    // bfs and creation
    while (q.size() > 0 && i < n) { // i<n because aisa ho sakta hai ki queue mai element rah
                    // gaye but tree to puri construct ho chuki thi...(Raghav sir emphasised)
                    // or simply left child wale pe hi constraint laga diya ki tu bahar nahi jaega.. to phir
                    // obviously phir right child bhi nahi jaega...

      TreeNode *curr = q.front(); // curr or temp
      q.pop();

    //   important to declare and then initialise..
      TreeNode *l; 
      TreeNode *r;

       // if left child is valid 
      if (arr[i] != INT_MIN) l = new TreeNode(arr[i]);
      
      else l = NULL; // agar INT_MIN wala nikla array se to tree mai to bhai NULL
                  // hi hoga na attach

      // i last index pe ho but j aage nikal chuka hu...
      if (j != n && arr[j] != INT_MIN) r = new TreeNode(arr[j]);
      else r = NULL;

      // establish connection with curr
      // wahi q ke front waale elements mai attach kiya.. curr pe attach kiya..
      curr->left = l;
      curr->right = r;
    
    // mai yaha tak aate aate jyada khush ho jaata hu... and next iteration ke baare mai bhul jaata hu..
    // arey bhai next iteration ke liye bhi parameters ko ready karega...like queue mai daal indono l, r ko 
    // and index bhi increment array ka jissey tu tree bana raha h...
      if (l != NULL) q.push(l); 
      if (r != NULL) q.push(r);

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