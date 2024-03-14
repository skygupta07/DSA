#include <iostream>
using namespace std;
int main(){
    int arr[]={1,3,5,7,10,15,20};
    for (int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    int n=7;
    int lo=0;
    int hi=n-1;

    int target;
    cout<<"\nenter the target element. ";
    cin>>target;
    

    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (arr[mid]==target){
            cout<<"target element found at "<<mid<<" index.\n";
            break;
        }

        else if (arr[mid]<target){
            lo= mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return -1;
}