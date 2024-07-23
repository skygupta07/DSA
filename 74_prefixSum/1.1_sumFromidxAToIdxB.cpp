#include <bits/stdc++.h>
using namespace std;


int sumAToB(vector <int> v, int a, int b){
    vector <int> pref(v.size());
    pref[0] = v[0];

    for (int i=1; i<v.size(); i++){
        pref[i] = v[i] + pref[i-1];
    }

    if (a == 0) return pref[b];
    else{
        return pref[b] - pref[a-1];
    }
}


int main(){
    int arr[] = {9 , 1 , 8 , 6 , 5 , 2 , 4 , 3 , 10};   
    int n = sizeof(arr)/sizeof(arr[0]);

    vector <int> v(arr, arr+n);

    // sum from index a to b
    cout<<sumAToB(v,0,3)<<endl;
}

/*
sum from a to b  === pref[b] - pref[a-1]
*/