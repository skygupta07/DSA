// selection sort
#include <iostream>
#include <climits>  // for INT_MAX and INT_MIN

using namespace std;
int main(){
    int arr[]={5,1,3,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n-1; i++){   // andar wala kaam n-1 times hoga..
        int min = INT_MAX;  // pehle badi value se initialise kiya
        int mindx = -1;     // to maintain the minIndex...
        
        for (int j=i; j<n; j++){  //aakhri tak dekhenge
            if (arr[j]<min){    // this loop is helping to find the minimum element in unsorted part
                min = arr[j];
                mindx = j;
            }
        }
        swap(arr[i], arr[mindx]);  // swapping the first element of orange box(unsorted part) with the minimum element in the orange box..

        //
        // 1. minimum element ko aage set karte chalo    
    }

    for (int ele : arr){
        cout<<ele<<" ";
    }
}


// for selection sort....
// maintain a sorted part and a unsorted part 
// in each iteration iterate over the unsorted part and find the min. element less than first 
// element of unsorted part and swap them, doing this increases the sorted part and decreases unsorted
// to find min. element in a array first assume min. element as INT_MAX then iterate 
// over the array to find minimum element...

// t.c. best = worst = avg = O(n^2)   // yaha optimised nahi hai koi soln
// random sorting hoti hai pehle mera 3 theek jagah tha ab to correct position se kaafi dur ho gya 
// UNSTABLe sort


// useful for: cost of swapping is less
// to find k min. element
// to sort small size array