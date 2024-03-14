#include <iostream>
using namespace std;

void subsetarr(int arr[], int n, int idx, vector <int> &ans){
    // array , arraysize, index, ans store karne ke liye vector...
    if (idx == n){  // base case
        for (int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[idx]);   // once include it and call the fn call 
    subsetarr(arr, n, idx+1, ans );
    ans.pop_back();
    subsetarr(arr,n,idx+1,ans); // remove and call the fn call...
}

int main(){
    int arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> v;  // to store the ans..

    subsetarr(arr,n,0,v);
    // important to pass index because tabhi to parameterised hoga and aagey tak traverse
    // hoga...
}