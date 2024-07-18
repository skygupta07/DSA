#include <iostream>
using namespace std;
int main(){
    int arr[]={0,1,2,3,4,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int lo = 0;
    int hi = n-1;
    int ans = -1;   // in case if not present 

    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == mid){   // agar wo apne sahi index pe ho to..pehle ki bhi sahi hi honge.. aage badhte jao...
            lo = mid+1;
        } 
        else{
            ans = mid;  // yes update the answer each time...
            hi = mid-1;
        }
    }
    cout<<ans<<endl;
}