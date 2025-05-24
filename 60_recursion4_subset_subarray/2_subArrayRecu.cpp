#include <bits/stdc++.h>
using namespace std;


void subArray(vector <int> v, int arr[], int n, int idx){
    if (idx == n){  // base case

        for (int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
        return;
    }

    subArray(v,arr,n,idx+1);

    // but now for subArray-> pushback tab hi karenge jab ya to vector v empty ho ya 
    // jisse push kar rahe hai ussey ek kam wala element already present ho
    if (v.size()==0 || arr[idx-1] == v[v.size()-1]){
        v.push_back(arr[idx]);
        subArray(v,arr,n,idx+1);
    } 
    // will work only for unique element
}



int main(){
    int arr[] ={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> v;
    subArray(v,arr,n,0);
}