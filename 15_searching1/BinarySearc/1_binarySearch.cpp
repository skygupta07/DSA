#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;   // we don't need to mention the size of vector when we are pushing back
    v.push_back(2);    // aur agar kewal size mention karke chod diya to wo saare elements
        // ko zero se initialise kar dega...to phir sabke index pe le jaake theek karna padega...
    v.push_back(5);
    v.push_back(3);
    v.push_back(10);
    v.push_back(15);
    v.push_back(18);
    v.push_back(50);

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    int lo = 0;
    int hi = v.size()-1;
    int mid= hi+(lo-hi)/2;   // taki int ya long me storage aur range ki problem na aae 
                            // isliye mid = (hi+lo)\2 -> mid = hi+(lo-hi)/2
    int target;
    cout<<"enter the element you want to search: ";
    cin>>target;

    while (lo<=hi){   // ye to binary ki condition hi hai..
        if (v[mid]==target ){
            // compare to hamesha middle wale element ko hi kiya karunga..
            return target;
        }
        else if (v[mid]<target){
            lo = mid+1;
        }
        else{  // v[mid]>target..
            hi = mid-1;
        }
    }
    // agar upar se kabhi fn return nahi kar paya matlab that particular element is not present
    // so simply return -1 in that case...

    return -1;
    cout<<endl;
}
/* 
reducing the search space by half in each step
-> works only if array is SORTED in either asc or desc order
-> t.c. = O(logn)

agar kahi bhi "given a sorted integer array" dikh jaye to binary search sochna hai...


*/