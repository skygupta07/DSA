#include <iostream>
#include <vector>
using namespace std;

int countSubseq(int idx, int s, int k, int arr[], int n){
    if (s>k) return 0;
    if (idx == n){  
        if (s == k) return 1;   // 1 valid subsequence mil gaya hai count mai include kar lo..
        else return 0; 
    }
    s += arr[idx];
    int l = countSubseq(idx+1,s,k,arr,n);   // just a visual representation of left and 
                // right recursive call in mind...
    s -= arr[idx];
    int r = countSubseq(idx+1,s,k,arr,n);
    return l+r;
}


int main(){
    int arr[] ={1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countSubseq(0,0,2,arr,n);
    cout<<endl;
}

// t.c. = O(2**n) 
















/*
base case
return 1 -> if condition satisfy
return 0 -> if condition doesn't satisfy

l = f();
r = f();

return l+r;
*/