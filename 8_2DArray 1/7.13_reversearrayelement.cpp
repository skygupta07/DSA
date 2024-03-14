#include <iostream>
using namespace std;
int main(){
    int arr[5]={1,3,6,8,2};
    int i=0;  // i ko first index pe aur j ko last index pe rakho...
    int j=sizeof(arr)/sizeof(arr[0])-1;  //j=5-1 = 4

    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // reversing elements of array...
    while (i<=j){  // akash-> while loop ki condition check kare...
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
        i++;
        j--;

    }
    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
        
    }
}