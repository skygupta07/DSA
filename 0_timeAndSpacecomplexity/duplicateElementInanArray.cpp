#include <iostream>

using namespace std; 
int main(){
    int arr[]={1,4,6,2,10,12,2,34,23,20};
    bool flag = false;   // initially assuming no duplicate is present..
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]==arr[j]){
                flag=true;           
            }
        }
        if (flag==true) break;
    }


    if (flag==true){
        cout<<"duplicate element is present "<<endl;
    }
    else{
        cout<<"no duplicacy found "<<endl;
    }

    //time consuming
    // brute force method or simple method..
    
}