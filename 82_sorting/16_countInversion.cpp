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



#include <bits/stdc++.h>    // coding ninjas

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