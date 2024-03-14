#include <iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void shellSort(int arr[], int n){
    for(int gap=n/2 ; gap>=1; gap = gap/2){
        for (int j=gap; j<n; j++){
            for (int i=j-gap; i>=0; i = i-gap){
                if (arr[i+gap]>arr[i]){
                    break;
                }
                else{
                    swap(arr[i+gap], arr[i]);
                }
            }
        }
    }
    

}



int main(){
    int arr[]={92,34,56,12,80,68,2,4,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    shellSort(arr,n);
    print(arr,n);

}






/*

shell sort different intuition arises from insertion sort fallback.....
due to the adjacent swap property of insertion sort if by chance any smaller element is
present at the end of array then a lot of swap is required to put it at its correct position
----> to overcome this how about now comparing the distant elements at some gap

decrement the gap until gap reaches to 1, and if gap=1, shell sort work exactly as 
insertion sort,(although last tak jaate jaate there will be very less number of swaps)
you can take any gap pattern let's take gap=n/2 , divide the gap till it gap reaches to 1

take two variabe i and j(at gap initially) swap them and increment i and j
if somehow forward swapping has been done there then you need to check for the backward swapping also
if no swapping then simply increment i and j
all the changes will be done in the same array

teen loops chalenge... bahar wala j ka andar i ka loop
j wala loop suru se end tak jaega, i wala j-gap se zero tak 

no. of passes is being decided by the number of steps required to make the count=1;

t.c. O(n^2)      depends on the gap sequence 



















*/