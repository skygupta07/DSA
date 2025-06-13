#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int lo=0;
    int hi=n-1;

    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        if (arr[mid] == target) return mid;
        
        else if (arr[mid] < target) lo = mid+1;
        else hi = mid-1;
    }

    return -1;
}

int lowerBound(int arr[], int n, int target){
    int lo=0;
    int hi=n-1;

    // flag variable to check if the target element is present in array or not.
    bool flag = false; 

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;

        if (arr[mid] == target){
             flag = true;
             return mid-1;  // main point to yahi h -- lower bound index...
        }

        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    
    if (flag == false) return hi;
}


int upperBound(int arr[], int n, int target){
    int lo = 0;
    int hi = n-1;

    bool flag = false; // flag variable to check if the target element is present in array or not.
    
    while(lo <= hi){
        
        int mid = lo + (hi-lo)/2;

        if (arr[mid] == target) {
            flag = true;
            return mid+1;   // main point for upper bound
        }
        
        else if (arr[mid]<target) lo = mid+1;
        else hi = mid-1;
    }
    
    // so basically if the target element {for which you were finding upper bound} is not present, 
    // then we need to return false...

    if (flag == false) return lo;

}






int main(){
    int arr[]={1,3,5,7,10,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    int idx = binarySearch(arr,n,7);
    cout<<"target element found at index: "<<idx<<endl;

    int lbidx = lowerBound(arr,n,10);
    cout<<"lower bound of target element is: "<<lbidx<<endl;

    int ubidx = upperBound(arr,n,10);
    cout<<"upper bound of target element is: "<<ubidx<<endl;

}



// lower and upper bound of element -> if the lower bound is present directly in the array 
// then apply ditto same code of binary search for both upper and lower bound...and return 
// finally arr[mid-1] for lower    and arr[mid+1] for upper


/*
// but if lower and upper bound of element -> if the lower bound is not present directly in the array 
// then apply ditto same code of binary search for both upper and lower bound...but return 
// finally arr[hi] for lower bound    and arr[lo] for upper
because condition tab hi break hui hogi jab lo hi  ko cross kar chuka hoga....

*/



