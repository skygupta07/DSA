#include <bits/stdc++.h>
using namespace std;


void maxinArray(int arr[], int n, int idx, int max){
    if(idx == n){
        cout<<max<<endl;
        return;
    }
    
    if (arr[idx] > max){
        max = arr[idx];
    }

    maxinArray(arr, n, idx+1, max);    // current iteration mai max miley ya na miley 
                // aap next iteration check karo....
}

int main(){
    int arr[]={1,3,5,60,8,12,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxinArray(arr,n,0,INT_MIN);
}
