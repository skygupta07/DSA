#include <bits/stdc++.h>
using namespace std;


bool printS(int idx, vector <int> &ds, int s, int k, int arr[], int n){ // change1-> void to bool
    if (idx == n){  // base case
        if (s == k){
            for (int i=0; i<ds.size(); i++) cout<<ds[i]<<" ";
            cout<<endl;
            return true;
        }else return false;     // change 2
    }

    // take the current element and call the fn call..
    ds.push_back(arr[idx]);
    s += arr[idx];
    if ( printS(idx+1,ds,s,k,arr,n) ) return true; //CHANGE 3 now fn call ko bhi condition ki tarah likho...

    // pop the current element and call the fn call...
    ds.pop_back();  // sorry ..pop_back() kucch nahi leta..
    s-=arr[idx];

    if ( printS(idx+1,ds,s,k,arr,n) ) return true;
    return false;   // change 4..finally return false... 
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> ds;    // initially empty..
    int k = 2;
    printS(0,ds,0,k,arr,n);
}




/*
in base case-> if the condition is satisfied then return true...else return false...
if (f() == true) return 
else return false...
fn output type will be boolean...

*/