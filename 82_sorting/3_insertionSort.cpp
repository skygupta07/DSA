// insertion sort
// take an element and insert it in its correct position...


#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// insertion sort me i=1 index se start kiya ,last tak gaye
// ek ith element ko pakda then usko swap (LEFT SIDE) karte chalo until it reaches its
// correct position

void insertionSort(int arr[], int n){
    for (int i=1; i<n; i++){
        int j=i;  // taki har pass ki starting me i aur j index same element ko point kare
        while(arr[j]<arr[j-1] && j>=1){
            swap(arr[j],arr[j-1]);
            j--;
        }    
    }
}


// worst: O(nsquare)
// best : O(N)




int main(){
    int arr[]={1,5,9,3,6,0,-5};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    insertionSort(arr,n);
    print(arr,n);

}

