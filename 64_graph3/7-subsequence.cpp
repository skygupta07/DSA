#include <iostream>
#include <vector>
using namespace std;

void printSubSeq(int idx, vector <int> &v, int arr[], int n){
    if (idx == n){  // last wali row issi se banti hai...
        for (auto it: v){
            cout<<it<<" ";
        }
        if (v.size() == 0){
            cout<< "{}";
        }
        cout<<endl;
        return;
    }
    
    v.push_back(arr[idx]);
    printSubSeq(idx+1, v, arr, n);  // not including the current element...

    // now take the current element into the subsequence... 
    v.pop_back();
    printSubSeq(idx+1, v, arr, n);  
      // to check new dress.(whether take or not take it)
                   //..remove the current one...
  
}

// t.c. = O(2^n * n)
// s.c. = O(n) ->recursion stack...


int main(){
    int arr[] = {13,14,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> v;
    printSubSeq(0,v,arr,n);
}


/*
a contiguous/non-contiguous sequence which follows the order is subsequences..
-> a null sequence is also a subsequence..
-> a subarray can be a subsequence.....
-> total 2^n subsequence can be formed...

-> at every index I have two option either take it or leave it...

//
{}
15 
14 
14 15 
13 
13 15 
13 14 
13 14 15

*/