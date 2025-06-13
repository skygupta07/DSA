#include <iostream>
using namespace std;

int main(){
    // Given a sorted array where we assume arr[i] == i for each index `i`, 
    // but due to an issue one element is missing, and elements after that are shifted.
    int arr[] = {0,1,2,3,4,5,9}; // Here, ideally arr[6] should be 6 but it's 9. So from index 6 onward, the pattern breaks.
    
    int n = sizeof(arr)/sizeof(arr[0]); // Size of the array

    int lo = 0;
    int hi = n - 1;

    int ans = -1; // Default answer if no mismatch is found (i.e., all arr[i] == i)

    // Perform binary search to find the first index where arr[i] != i
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;  // Avoid overflow compared to (lo + hi) / 2

        if (arr[mid] == mid){  
            // If the value at current index is same as index (no mismatch yet)
            // This means everything before and including `mid` is correct
            // So, look in the right half for the first mismatch
            lo = mid + 1;
        } 
        else {
            // If value is not equal to index, we found a potential answer
            // But we want the *first* such index where this happens
            // So, store this index and keep looking in the left half
            ans = mid;
            hi = mid - 1;
        }
    }

    // Final answer: First index where arr[i] != i (i.e., first "missing" index)
    cout << ans << endl;
}





#include <iostream>
using namespace std;

int main(){
    int arr[]={0,1,2,3,4,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int lo = 0;
    int hi = n-1;

    int ans = -1;   // in case if not present 

    while (lo <= hi){
        int mid = lo + (hi-lo)/2;

        if (arr[mid] == mid){   // agar mid index wala element apne sahi index pe ho
            //  to..pehle ki bhi sahi hi honge.. aage badhte jao...
            lo = mid+1;
        } 
        else{
            ans = mid;  // yes update the answer each time...
            hi = mid-1; // ab aage jaane ki jarurat nahi culprits ko peeche hi search karo..
        }

    }
    cout<<ans<<endl;
}