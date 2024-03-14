// move all negative numbers at end  and positive to beginning with constant extra spaces
#include <iostream>
using namespace std; 
int main(){
    int arr[]={2,4,3,-1,5,-7,19,-43,87,90,-8};
    int i=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int j=n-1;  // trick to calculate the size of array
    
    while (i<j){

        if (arr[i]<0 and arr[j]>0){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        if (arr[i]>0) i++;
        if (arr[j]<0) j--;
        
    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}