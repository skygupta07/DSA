#include <bits/stdc++.h>
using namespace std;

void maxAndVal(int *arr, int n){
    int ans = 0;
    int maxi = INT_MIN;
    int count = 0;

    for (int i=0; i<n; i++){
        if (arr[i] > maxi){
            maxi = arr[i];
            count = 1;  // reset count 
        }
        else if (arr[i] == maxi){
            count++;
        }
        // always update the ans..i.e. length of longest subarray..
        ans = max(ans, count);
    }

    cout<<ans<<"\n";
}



int main(){
    int arr[] = {1, 2, 1, 3, 2, 5, 5, 9, 8, 8}; // Given array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    maxAndVal(arr,n);
    return 0; 
}

/*

given an integer array. find the length of longest subarray which has 
maximum possible bitwise AND value...

agar do number different hai to unka bitwise AND karne par wo element dono se 
bhi chhota aaega....


basically the problem reduces to find the consecutive count of max element in array...
*/