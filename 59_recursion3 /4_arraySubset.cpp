#include <bits/stdc++.h>
using namespace std;

void subsetarr(int arr[], int n, int idx, vector <int> &ans){
    // array , arraysize, index, ans store karne ke liye vector...
    
    // base case
    if (idx == n){ 
        
        for (int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }

        cout<<endl;
        return;
    }

    // once include it and call the next fn call 
    ans.push_back(arr[idx]);   
    subsetarr(arr, n, idx+1, ans);

    // remove and call the fn call...
    ans.pop_back();
    subsetarr(arr, n, idx+1, ans); 
}



int main(){
    int arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> v;  // to store the ans..

    subsetarr(arr,n,0,v);
    // important to pass index because tabhi to parameterised hoga and aagey tak traverse
    // hoga...
}