#include <bits/stdc++.h>
using namespace std;

int IsPartitionPossible(int arr[], int n){
    
    // prefix sum array
    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }

    int idx = -1;
    
    // traversing over arr which is now our prefix array.. see if partition possible
    for (int i=1; i<n; i++){
        if (2*arr[i] == arr[n-1]){  // important -> only single observation based question...
            idx = i;
            return idx;
        }
    }
}



int main(){
    int arr[] = {1,2,3,4,5,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int ans = IsPartitionPossible(arr,n);
    
    if (ans == -1){
        cout<<"partition not possible..";
    }
    else{
        cout<<"partition possible at index: "<<ans<<endl;
    }
}   



/*
arr
1,2,3,4,5,10,5

pref
1 3 6 10 15 25 30



2*pref[i] = pref[n-1] => ith index par aap partition kar sakte ho...

*/
