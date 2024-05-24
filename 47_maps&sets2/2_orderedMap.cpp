#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int, int> m;
    
    m[1] = 45;
    m[3] = 50;
    m[2] = 40;
    

    for (auto x : m){   // auto will see the key value pair coming...
        cout<< x.first<<" ";
    }
    cout<<endl;

    map <string,int> mp;
    
    mp["ak"] = 194;
    mp["bob"] = 49;
    mp["carry"] = 60;

    for(auto el: mp){
        cout<<el.first<<" "<<el.second<<" ";
    }
    cout<<endl;

}


/*
key ke basis pe sort karke hi print karega (imp) chahe aap key print karao ya value guru
lexicographically in case of string as key...



*/





