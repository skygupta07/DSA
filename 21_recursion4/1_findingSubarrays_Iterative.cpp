#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++){ //start of subarray
        for (int j=i; j<n; j++){ // below two loops to print as usual pyramids...
                                    // j denotes number of rounds in loop
            for (int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }   
        cout<<endl;
    }

}



/*
subsequence mai ordering matter karti hai....
subarrays are the subsequences which are in continuous fashion...


1 
1 2 
1 2 3 
1 2 3 4 

2 
2 3 
2 3 4 

3 
3 4 

4 

*/