#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set <int> s;
    s.insert(1); //inserting elements in random order(btw in reverse order jaate hai)
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    // set ki basic property ki usme repetition allowed nahi hoti..
    // set stores distinct element...
    s.insert(1);
    s.insert(5);
    s.insert(6);
    s.erase(3); // to erase/delete element from the set
    s.begin();

    int target = 15;

    cout<<s.size()<<endl;   // distinct elements hi count hote hai

    // how to find if our target element exist in set or not?-> use find function
    // aakhri tak gaye aur ab tak nirasha nahi mili ....
    if(s.find(target)!=s.end()){// target exist imp
        cout<<"target exists.."<<endl;
    }else{
        cout<<"target doesn't exists.."<<endl;
    }

    // s.find() searches in set and if not found returns s.end() which is iterator next 
    // to the last value in set
    
    // itne random hai to print kaise kare -> i.e. use of for each loop (ignore the warning)
    for (auto ele: s){
        cout<<ele<<" ";
    }
    cout<<endl;
}

/*
sets -> insertion deletion search all takes O(1) time
// sets ek jhola hai jisme elements randomly insert hote hai..

g++ filename.cpp —std=c++14 -o run
./run

*/
