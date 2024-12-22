#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array then enter all the array element one by one..."<<endl;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    // precompute
    int hash[13] = {0}; // declared array of 13 size with name as hash and each element as 0
    // hashing matlab array ka sahara liya to memorise things...
    
    for (int i=0; i<n; i++){
        hash[arr[i]] += 1;      // hash[arr[i]]++;
    }
    int q;
    cout<<"enter number of queries: then write number whose frequency you want..."<<endl;
    cin>>q;

    while (q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
    
    return 0;
}