#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map <string,int> m;   // map matlab <key,value> pair

    pair<string,int> p1;    // Pair provides a way to store two heterogeneous objects as a single unit.
    p1.first = "akash"; // strings are always written in "double quotes"
    p1.second = 1;

    pair <string,int> p2;
    p2.first = "apple";
    p2.second = 2;

    pair <string,int> p3;
    p3.first = "orange";
    p3.second = 3;

    m.insert(p1); // inserting *pairs* into maps
    m.insert(p2); 
    m.insert(p3);

    m["banana"] = 5; // good method to allocate map elements
    // map m me aap banana key ko 5 value assign kar do
    m["mango"] = 8;
    for (auto p: m){    // auto recognises actually what you want to print i.e. fetches the key value pair..
        // for pair p in map m
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    cout<<"size of map is:"<<m.size()<<endl;

    cout<<m["mango"]<<endl;
    
    m.erase("apple");  // erases apple key value pair from map
    cout<<endl;

    for (auto p: m){    // auto recognises actually what data type to fetch..
        // for pair p in map m
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.size()<<endl;
}



// ek tarah se yahi hash maps are simply ordered map or simply the map aur hash sets hai...
// maps -> frequency array/set   or   key , value/index
// matlab map me aapka do value/parameter dalenge
// hash maps providing unlimited size can record employee data
// map mai insert karne ke liye pehle key value pair banao then p1.first karke key daal then p1.second karke value