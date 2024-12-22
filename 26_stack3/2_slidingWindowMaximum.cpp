#include <bits/stdc++.h>
using namespace std;


void slideMax(int arr[], int n, vector <int> &v, int k){ // k=windowSize
                                                        // n = size of Array
    int i = 0;
    int j = i+k-1;
    
    while(j<=n-1){
        int max = arr[i];
        for (int idx=i; idx<=j; idx++){  // idx is pointer to travel over sliding window
            if (arr[idx]>max){
                max = arr[idx];
            }

        }
        v.push_back(max);
        i++;
        j++;
    }

}


int main(){
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3; // sliding window size;
    vector <int> res;
    slideMax(arr,n,res,k);
    
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    for (int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}






















// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// well done Akash...Hard Question of Leetcode done in single run ...WOW!!!

// but time limit exceed in hard questions due to brute force implementation

//better option will be to use next Greater Element concept here
/*

create a array and put index of next greater element in that array
taken a window see if the nge(next greater element)which is present in the window itself
could replace the current element... repeat the replacing nge step until you reach the
end of array...

*/