#include <bits/stdc++.h> 
using namespace std;

long long merge(long long*arr, int low, int mid, int high){
    // int left = mid - low + 1;
    // int right = high - mid;

    int left = low;
    int right = mid + 1;

    long long count = 0;
    
    vector<long long>temp(high-low+1,0);
    int k = 0;
    
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp[k] = arr[left];
            k++;
            left++;
        }
        else{
            temp[k] = arr[right];
            k++;
            right++;
            count+= (long long)(mid - left + 1);
        }
    }

    
    while(left<=mid){
        temp[k] = arr[left];
        k++;
        left++;
    }
    
    while(right<=high){
        temp[k] = arr[right];
        k++;
        right++;
    }

    for(int i = low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return count;
}


long long merge_sort(long long *arr, int low , int high){
    if(low>=high) return 0;

    long long count = 0;
    int mid = low+((high-low)>>1);
    count+=(long long)merge_sort(arr,low,mid);
    count+=(long long)merge_sort(arr,mid+1,high);
    count+=(long long)merge(arr,low,mid,high);

    return count;
}


long long getInversions(long long *arr, int n){
    
    if(n==1) return 0;

    return merge_sort(arr,0,n-1);
}


/*
t.c. = O(nlogn)
s.c. = O(n)
*/