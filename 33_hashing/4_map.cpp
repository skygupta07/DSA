#include <bits/stdc++.h>
using namespace std;


int main(){

    map <int,int> mp;
    int n;

    cout<<"enter number of numbers: "<<endl;
    cin>>n;
    
    int arr[n];

    // while taking the array compute its frequency also...
    for (int i=0; i<n; i++){

        cin>>arr[i];
        mp[arr[i]]++;

        // mp[key]++  => map mai us corresponding key par rakhe elment ki ek frequency badha di....
        // -> map themselves are sorted on the basis of key        
    }

}


// in map insertion and fetching takes O(logn) time in worst avg best case..
// any data structure like even pairs they can be valid key in map... {Reason: Double Chabhi wala chawal...}

