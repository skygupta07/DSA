#include <iostream>
using namespace std;

void display(int arr[], int n, int idx){  // int arr[] pass hoga naki int arr
    if (idx == n) return;

    cout<<arr[idx]<<" ";
    
    display(arr, n, idx+1);
}

int main(){

    // int arr[]={1,4,5,6,8,90,13};
    // // 
    // int n=sizeof(arr)/sizeof(arr[0]);  // method to calculate the size of array..
    // for (int i=0; i<7; i++){ // traversing array element using arrays..
    //     cout<<arr[i]<<" ";
    // }
    // // arrays are passed by reference

    int arr[]={1,2,3,4,5,6,8,15};

    int n = sizeof(arr)/sizeof(arr[0]);

    display(arr, n, 0); 
    // array , size of array, starting index from where you want to print...
}


