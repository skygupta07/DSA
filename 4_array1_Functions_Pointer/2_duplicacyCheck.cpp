#include <iostream>
using namespace std; 

bool isUnique(int arr[], int n){
    sort(arr,arr+n);        // vector <int> v(arr,arr+n)
    for (int i=1; i<n; i++){
        if (arr[i] == arr[i-1]){
            return false;
        }
    }
    return true;

}



int main(){ // O(n^2)
    int arr[]={1,4,6,2,10,12,2,34,23,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool flag = false;
    for (int i=0; i<10; i++){   
        for (int j=i+1; j<10; j++){
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


    //time consuming -> O(n^2)  

    bool ans = isUnique(arr,n);
    cout<<ans<<endl;

}