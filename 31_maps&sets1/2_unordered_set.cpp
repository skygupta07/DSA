#include <bits/stdc++.h>
using namespace std;



int main(){
    unordered_set <int> st;
    st.insert(1); //inserting elements in random order(btw in reverse order jaate hai)
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    // set ki basic property ki usme repetition allowed nahi hoti..
    // set stores distinct element...
    st.insert(1);
    st.insert(5);
    st.insert(6);
    st.erase(3); // to erase/delete element from the unordered_set you need to mention which element basically 
                // you want to delete...
    st.begin();

    int target = 15;

    cout<<st.size()<<endl;   // distinct elements hi count hote hai

    // how to find if our target element exist in set or not?-> use find function
    // aakhri tak gaye aur ab tak nirasha nahi mili ....
    if(st.find(target) != st.end()){// target exist imp
        cout<<"target exists.."<<endl;
    }
    
    else{
        cout<<"target doesn't exists.."<<endl;
    }

    // s.find() searches in set and if not found returns s.end() which is iterator next 
    // to the last value in set
    
    // itne random hai to print kaise kare -> i.e. use of for each loop (ignore the warning)
    for (auto ele: st){
        cout<<ele<<" ";
    }

    cout<<endl;
}

/*

sets -> insertion deletion search all takes O(1) time
// sets ek jhola hai jisme elements randomly insert hote hai..


--- how to compile c++ file with different version of compiler manually?

g++ filename.cpp —std=c++14 -o run
./run

*/
