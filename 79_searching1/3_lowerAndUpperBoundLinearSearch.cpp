#include <bits/stdc++.h>
using namespace std;


int main(){

    int arr[] = {1,3,5,7,10,12,15,18,20,22,26,30};
    int n = sizeof(arr)/sizeof(arr[0]);     // n = 12

    int i = 0;
    int target = 19; 

    // agar target element hota to wo kaha fit hota
    while(arr[i] < target){
        i++;
    }

    cout<<"upper bound is: "<<arr[i]<<endl; // very much interesting to remember this result that upper bound pe loop break hota h..
    cout<<"lower bound is: "<<arr[i-1]<<endl;
    

}    