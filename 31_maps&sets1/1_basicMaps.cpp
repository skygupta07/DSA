#include <bits/stdc++.h>
using namespace std;



int main(){

    unordered_map <string,int> mp;   // map matlab <key,value> pair

    // Pair provides a way to store two heterogeneous objects as a single unit.
    
    pair <string,int> p1;   

    // .first se first parameter pair ka fetch hota h i.e. the key here...
    // .second se second parameter pair ka fetch hota h i.e. the value here...

    p1.first = "akash"; // strings are always written in "double quotes"
    p1.second = 1;

    pair <string, int> p2;

    p2.first = "apple";
    p2.second = 2;

    pair <string,int> p3;
    p3.first = "orange";
    p3.second = 3;

    mp.insert(p1); // inserting *pairs* into maps
    mp.insert(p2); 
    mp.insert(p3);

    // good method to allocate map elements i.e {mp[key] gives value}
    mp["banana"] = 5; 
    
    // map m me aap banana key ko 5 value assign kar do
    mp["mango"] = 8;

    for (auto p: mp){    // auto recognises actually what you want to print i.e. fetches the key value pair..
        // for pair p in map m
        cout<<p.first<<" "<<p.second<<endl;
    }

    cout<<endl;
    cout<<"size of map is:"<<mp.size()<<endl;

    cout<<mp["mango"]<<endl; // mp[key] = value
    

    // erases apple key value pair from map ... {ha bhai erase karne ke liye key hi pass karna hota h...}
    mp.erase("apple");  
    cout<<endl;

    for (auto p: mp){    // auto recognises actually what data type to fetch..
        // for pair p in map m
        cout<<p.first<<" "<<p.second<<endl;
    }

    cout<<mp.size()<<endl;

}



// ek tarah se yahi hash maps are simply ordered map or simply the map aur hash sets hai...
// maps -> frequency array/set   or   key , value/index

// matlab map me aapka do value/parameter dalenge
// hash maps providing unlimited size can record employee data

// map mai insert karne ke liye pehle key value pair banao then 
// p1.first karke key daal then p1.second karke value