#include<iostream>
using namespace std;

int partition(int arr[],int first, int last){  // fn returns the correct index of pivot Element
    int pivot = arr[last]; // considering last element as pivot
    int i = first - 1; 
    int j = first;

    for (int j=first; j<last-1; j++){
        if (arr[j]<pivot){
            i++;  // pehle i ko increment karke swap kar diya.. 
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return i+1;

     
}



void quickSort(int arr[], int first, int last){
    if(first>=last) return; // base case
    int pi = partition(arr,first,last);  // partition index

    //recursive call
    quickSort(arr,first,pi-1);
    quickSort(arr,pi+1,last);
}



int main(){
    int arr[]={5,2,9,10,1,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);

    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


/*
if all the students try to arrange themselves in the row then sorting will be really quick
-> smaller element will come quietly in the beginning and taller at the end then each element 
will try to arrange themselves by seeing others height

an element is said to be sorted if all the element to its left is smaller and all
the element to its right is larger

works on divide and conquer

put i on first index and j on last, i will search for element which are greater than pivot
and j will search for element lesser than pivot as soon as you get them increment them








*/