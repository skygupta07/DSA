#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int, int> m;
    
    m[1] = 45;
    m[3] = 50;
    m[2] = 40;

    // kucch chutiye .first ke baad mai ye bracket() laga dete h.. unhe kaun bataye... ye koi function call 
    // nahi h simple method h ye...

    for (auto x : m){   // auto will see the key value pair coming...
        cout<< x.first<<" ";    // map se pehle pair isliye to padhaya tha ...
                        // taki .first     .second use kar sako...
    }
    cout<<endl;


    map <string, int> mp;
    
    mp["ak"] = 194;
    mp["bob"] = 49;
    mp["carry"] = 60;
    
    for(auto el: mp){
        cout<<el.first<<" "<<el.second<<" ";
    }

    cout<<endl;



    //  warning: decomposition declarations are a C++17 extension [-Wc++17-extensions]
    // but I will use coz I love this decomposition declarations...
    
    for (const auto &[str, freq] : mp){
        cout<<str<<" "<<freq<<" ";
    }

}


/*
key ke basis pe sort karke hi print karega (V. imp) chahe aap key print karao ya value guru
lexicographically in case of string as key...

tabhi kabhi kabhi mai key ko hi smartly design karta tha...taaki sorting mai easy ho...

*/





