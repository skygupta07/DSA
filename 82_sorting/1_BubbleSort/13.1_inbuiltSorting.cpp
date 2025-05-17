#include <bits/stdc++.h>
using namespace std;


int main(){

    vector <int> v(5);    // since neeche you are using loop so passing size of vector is must
    cout<<"enter 5 vector elements: ";
    for (int i=0; i<v.size(); i++){
        cin>> v[i];
    }

    cout<<v.size()<<endl;

    sort(v.begin(), v.end());  // tc = O(nlogn) -  .begin ke baad ye bracket () jarur lagana i.e. v.begin()
    reverse(v.begin(), v.end());

    for (int i=0; i<5; i++){
        cout<<v[i]<<" ";
    }
}

/*
vector ka size tab hi skip karte hai jab hum turant hi v.push_back use karne 
wale hote hai...

*/