#include <iostream>
using namespace std; 
int main(){
    int arr[5];
    cout<<"enter the elements of array: ";
    for (int i=0; i<=4; i++){
        cin>>arr[i];     //taking input arrays element

    }
    
    for (int i=0; i<=4; i++){
        cout<<arr[i]<<" ";  //printing elements of array 

    }
    cout<<endl;
    int max= INT_MIN;
    for (int i=0; i<=4; i++){
        if (arr[i]>max){   // to find max element 
            max = arr[i];
        }
    }

    cout<<"maximum element is: "<<max<<endl;
    int smax = INT_MIN;     // better to take standard numbers instead of arr[0]
    for (int i=0; i<=4;i++){
        if (arr[i]!=max && arr[i]>smax){
            smax = arr[i];
        }
    }

    cout<<"second maximum element is: "<<smax<<endl; 



    // two pass method
}



// gfg  

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
       int fmax = INT_MIN;
       int smax = INT_MIN;
       
       for (int i=0; i<n; i++) fmax = max(fmax, arr[i]);
       
       for (int i=0; i<n; i++){
           if (arr[i] > smax && arr[i] != fmax) smax = max(smax, arr[i]);
       }
       
       if (smax == INT_MIN || smax == fmax ) return -1;
       return smax;
    }
};


------


// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        unordered_set <int> st(arr.begin(), arr.end());
        
        priority_queue <int> pq(st.begin() , st.end());
        int fmax = pq.top();
        pq.pop();
        int smax = pq.top();
        
        return (smax == fmax) ? -1: smax;
    }
};