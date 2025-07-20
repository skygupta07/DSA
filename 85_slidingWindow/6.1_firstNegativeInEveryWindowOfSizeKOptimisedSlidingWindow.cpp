#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2,3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3; // window size
    vector <int> ans(n-k+1);

    // display
    for (int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<"\n";

   
    int pni = -1;     // first negative index ...

    // threshold -> working for the very first window..
    for (int i=0; i<k; i++){
        if (arr[i] < 0){
            pni = i;
            break;
        }
    }
    
    // check if you found any negative number in the first window or not 

    if (pni == -1){
        ans[0] = 1; //  1 denotes no negative element found in that window...
    }
    else{
        ans[0] = arr[pni];
    }

    // now start sliding window (dusri khidki pe chale jao..)
    int i = 1;
    int j = k;

    while (j <= n-1){
        if (pni >= i) ans[i] = arr[pni];
        
        else{
            pni = -1;

            for (int x=i; x<=j; x++){
                if (arr[x] < 0){
                    pni = x;
                    break;
                }
            }

            if (pni != -1) ans[i] = arr[pni];
            else ans[i] = 1;

        }

        i++;
        j++;
    }


    // display ans
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}




