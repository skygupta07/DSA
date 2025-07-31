// countInversion.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3

Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).


Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.


Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.


Constraints:
1 ≤ arr.size() ≤ 1e5
1 ≤ arr[i] ≤ 1e4

*/


int main(){
    int arr[]={4,7,1,3,8,10,5};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    int count = 0;

    for (int i=0; i<n; i++){  // fundamental loop structure when you want to compare each
                                // value with other every value...
        for (int j=i+1; j<n; j++){
            
            if (arr[i] > arr[j] && i < j){
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


#include <bits/stdc++.h>
using namespace std;

/*

------------------------------------
Helper Function: merge() - ye jitna bhi khel hona h yahi hoga... 
otherwise mergesort aur sab to ekdum hi standard likhna h....

------------------------------------
This function merges two sorted halves of the array and counts
the number of inversions during the merge step.

Inversions occur when an element from the left half is greater
than an element from the right half.

*/

long long merge(long long* arr, int low, int mid, int high) {
    vector <long long> temp;  // Temporary array to store sorted elements

    int left = low;
    int right = mid + 1;

    long long count = 0;

    // Merge the two halves while counting inversions
    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } 
        
        else {
            temp.push_back(arr[right]);
            right++;

            // All remaining elements from left to mid are greater than arr[right]
            count += (mid - left + 1);
        }
        
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted values back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return count;
}

/*
------------------------------------
Recursive Function: merge_sort()
------------------------------------
This function recursively divides the array and merges it
while counting inversions at each step.
*/

long long merge_sort(long long* arr, int low, int high) {
    if (low >= high) return 0;

    long long count = 0;

    int mid = low + (high - low) / 2;

    // Count inversions in left half
    count += merge_sort(arr, low, mid);

    // Count inversions in right half
    count += merge_sort(arr, mid + 1, high);

    // Count inversions while merging
    count += merge(arr, low, mid, high);

    return count;
}

/*
------------------------------------
Main Function: getInversions()
------------------------------------
This function is the entry point for counting inversions
using the optimized Merge Sort technique.
*/

long long getInversions(long long* arr, int n) {
    return merge_sort(arr, 0, n - 1);
}
