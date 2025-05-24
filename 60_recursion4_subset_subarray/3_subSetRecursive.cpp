#include <bits/stdc++.h>
using namespace std;


void subSet(vector <int> v, int arr[], int n, int idx){
        // here vector passed without reference 
    if (idx == n){  // base case
        for (int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
 
    subSet(v,arr,n,idx+1);  // left call aise hi..
    v.push_back(arr[idx]);
    subSet(v,arr,n,idx+1);  // push back karne ke baad again call kiya...
}


int main(){
    int arr[] ={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector <int> v;
    subSet(v, arr, n, 0);
}


/*
left call mai kucch nahi kar rahe 
right call mai simply append kar do
{1,3} ko nahi push karenge because 3 se pehle waala element 2 not there

subset mai hamesha yahi hoga ek ko lenge dusre ko chhod denge
i.e. we have two option either take it or leave it...
*/