#include <bits/stdc++.h>
using namespace std;



int main(){
    int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3; // window size

    vector <int> ans;

    for (int i=0; i<=n-k; i++){
        for (int j=i; j<=i+k-1; j++){
            if (arr[j] < 0){
                ans.push_back(arr[j]);
                break;
            }
        }
    }

    // display ans
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}