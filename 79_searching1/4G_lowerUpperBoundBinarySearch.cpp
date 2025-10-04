#include <bits/stdc++.h>
using namespace std;

// Standard Binary Search function
int binarySearch(int arr[], int n, int target) {
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    // Target not found
    return -1;
}

// Function to find Lower Bound
int lowerBound(int arr[], int n, int target) {
    int lo = 0;
    int hi = n - 1;

    // isPresent batayega ki target array me tha ya nahi
    bool isPresent = false;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) {
            isPresent = true;
            // Lower bound: sabse bada element jo target se chhota ho
            // So, mid - 1 (but need to check if it's valid)
            return (mid - 1 >= 0) ? mid - 1 : -1;
        }

        else if (arr[mid] < target) {
            lo = mid + 1;
        }

        else {
            hi = mid - 1;
        }
    }

    // Agar target array me nahi tha to lower bound = hi (last index < target)
    return hi;
}

// Function to find Upper Bound
int upperBound(int arr[], int n, int target) {
    int lo = 0;
    int hi = n - 1;

    bool isPresent = false;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) {
            isPresent = true;
            // Upper bound: sabse chhota element jo target se bada ho
            return (mid + 1 < n) ? mid + 1 : -1;
        }
        else if (arr[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    // Agar target nahi mila, to lo index hamesha first index > target pe point karega
    return (lo < n) ? lo : -1;
}


int main() {
    int arr[] = {1, 3, 5, 7, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 10;

    // Standard Binary Search - {ha bhai index hi find karke deta h...}

    int idx = binarySearch(arr, n, target);

    if (idx != -1) cout << "Target element found at index: " << idx << endl;
    else cout << "Target element not found." << endl;

    // Lower Bound index
    int lbidx = lowerBound(arr, n, target);
    if (lbidx != -1)
        cout << "Lower Bound of target is: arr[" << lbidx << "] = " << arr[lbidx] << endl;
    
    else
        cout << "No valid lower bound found (all elements ≥ target)" << endl;

    // Upper Bound index
    int ubidx = upperBound(arr, n, target);
    
    if (ubidx != -1)
        cout << "Upper Bound of target is: arr[" << ubidx << "] = " << arr[ubidx] << endl;
    
    else
        cout << "No valid upper bound found (all elements ≤ target)" << endl;

    return 0;
}




/*

Lower Bound: max element < target
→ If target present: mid - 1
→ If not: hi


Upper Bound: min element > target
→ If target present: mid + 1
→ If not: lo

*/



// ---------- my code below ---

#include <bits/stdc++.h>
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



