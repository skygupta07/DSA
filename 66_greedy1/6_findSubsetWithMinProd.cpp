#include <bits/stdc++.h>
using namespace std;


int cn = 0, cp = 0, cz = 0;

int minProduct(vector <int> &v) {

    int n = v.size();

    sort(v.begin(),v.end());
    
    int min = INT_MAX;
    
    for (int i=0; i<n; i++){
        if (v[i] < 0) cn++;

        else if (v[i]==0) cz++;

        else cp++;

        if (v[i] < min) min = v[i];
    }

    // if array contain all postive then return the first array element 
    if (cn == 0) return v[0];
    

    if (cn%2 !=0){ // odd no. of negative elements
        int neg_prod = 1;

        for (int i=0; i<n; i++){

            if (v[i] == 0) continue;

            else neg_prod *= v[i];
        }

        return neg_prod;
    }

    if (cn %2 == 0){
        int pos_prod = 1;

        // leave smallest negative element and mulitply all
        for(int i=0; i<n; i++){
            if (v[i] == min) continue;

            else pos_prod *= v[i];
        }

        return pos_prod;   
    }
    
}




int main(){
    int arr[] ={1,2,3,4,5,0,3,8,-17};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector <int> v(arr , arr+n);

    int ans = minProduct(v);
    cout<<ans<<endl;
}   



/*
minimum subset of array
ek baar puri array pe iterate kara and maintain cn (count negative) cp, cz 
min_negative


*/