#include <bits/stdc++.h>
using namespace std;


// auxiliary sum s
void printS(int arr[], int n, int k, vector <int> &ds, int s, int idx){
    
    if (idx == n){      // array completed...
        if (s == k){
            for (int i=0; i<ds.size(); i++) cout<<ds[i]<<" ";
            cout<<endl;
        }
        return; // base case hai to return to karoge hi...
    }

    // ek baari data structure bole to vector mai include karke fn call lagai..
    // next index ke liye...
    ds.push_back(arr[idx]);
    s += arr[idx];

    printS(arr,n,k,ds,s,idx+1);
    // ek baar then hata ke simply call laga di next index ke liye..  
    
    s -= arr[idx];
    ds.pop_back();
    
    // not pick..
    printS(arr,n,k,ds,s,idx+1);
}




int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;      // target sum
    vector <int> ds;    // data structure..
    printS(arr,n,k,ds,0,0);
    // array,size,targetsum, datastructure,auxiliarySum,idx
}
