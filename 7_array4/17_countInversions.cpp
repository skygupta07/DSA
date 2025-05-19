#include <bits/stdc++.h> 
using namespace std;


// yeh problem isliye bhi tough ho jaata h kyuki koi dekh ke bata hi nahi paega ki
//  ye merge sort ka question h..

/*

Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) 
the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

*/


long long merge(long long *arr, int lo, int mid, int hi){
    // int left = mid - lo + 1;
    // int right = hi - mid;

    // create two pointer to track two part... do part honge tabhi to merge karega ..
    int left = lo;
    int right = mid + 1;

    long long count = 0;
    
    vector <long long> temp(hi-lo+1,0);
    int k = 0;
    
    while(left <= mid && right <= hi){
        if(arr[left] < arr[right]){
            temp[k] = arr[left];
            k++;
            left++;
        }
        else{
            temp[k] = arr[right];
            k++;
            right++;

            count+= (long long)(mid - left + 1);   // use of this line ??
        }
    }

    
    while(left<=mid){
        temp[k] = arr[left];
        k++;
        left++;
    }
    
    while(right <= hi) temp[k++] = arr[right++];
        

    for(int i = lo; i<=hi; i++){
        arr[i] = temp[i-lo];
    }

    return count;
}


long long merge_sort(long long *arr, int lo , int hi){
    // base case
    if(lo >= hi) return 0;

    // ek tarika to ye hai ki ek count variable bana lo aur usko &karke then function mai hi pass kar dena..
    // aur ya dusra way h ki... function se pura calculate karwa lo and then count mai add kar do...

    long long count = 0;
    int mid = lo + ((hi-lo)>>1);

    count+=(long long)merge_sort(arr,lo,mid);
    count+=(long long)merge_sort(arr,mid+1,hi);
    count+=(long long)merge(arr,lo,mid,hi);

    return count;
}


long long getInversions(long long *arr, int n){
    if(n == 1) return 0;
    return merge_sort(arr, 0, n-1);
}


/*
t.c. = O(nlogn)
s.c. = O(n)
*/