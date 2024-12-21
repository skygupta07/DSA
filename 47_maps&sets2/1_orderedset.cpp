#include <iostream>
#include <set>  // ab tujhe ordered set mai bhi order batana padega kya .....
#include <map>
using namespace std;



int main(){
    set <int> s;    
    s.insert(5);    // set mai insert hota hai..... fools try to push
    s.insert(9);
    s.insert(1);

    for (int el: s){    // auto apne aap data type fetch kar leta tha....
        cout<<el<<" ";
    }
    cout<<endl;

}

// ordered set mai aap kaise bhi element ko insert karo wo apne aap ko DISTINCT SORTED 
// form mai le hi aaega as soon as aap element daalo..(Very Very IMP)
/*
-> but yaha O(logn) time lagta hai insertion wagera mai...(bst soch sakte ho)
-> unordered map mai ya unordered_set -> O(1) mai saara kaaam(insert, find , erase) ho jaata hai..

*/

