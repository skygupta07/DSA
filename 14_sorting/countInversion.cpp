#include<iostream>
using namespace std;
int main(){
    int arr[]={4,7,1,3,8,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;

    for (int i=0; i<n; i++){  // fundamental loop structure when you want to compare each
                                // value with other every value...
        for (int j=i+1; j<n; j++){
            if (arr[i]>arr[j] && i<j){
                count++;
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
            }
        
    }
    
    }
    cout<<"\nnumber of count inversion is: "<<count;

    cout<<endl;
}

// int arr[]={4,7,1,3,8,10,5};
// two elements of an array a i.e. a[i] and a[j] form an inversion if a[i]>a[j] and (i<j)
// matlab valuewise to element bada ho but indexing wise chotta ho...

// t.c. = O(n^2)
// s.c. = O(1)

