#include <iostream>
#include <vector>
using namespace std;
int main(){

}



class Solution {
public:
    vector<int> result;
    void f(int i, int n){   // [i,n] -> lexicographical order
        if (i>n) return;
        
        if (i<=n and i!=0)  result.push_back(i);
           
        
        for (int j = (i==0) ? 1 : 0 ; j<=9; j++){
            f(10*i + j, n);
        }
    }


    vector<int> lexicalOrder(int n) {
        f(0,n);
        return result;
    }
};





/*
if not mentioned in sorting => then by default sort in ascending order
lexicographical order means dictionary order


199 aapka 19 se suru hoke last word hai....
// bas zero se zero pe again call mat lagana else har number mai 10 ka multiply karke
1 2 3 4 5 6 7 8 9 sab add karte jaao....



recurrence relation
f(i,n) = { f(10*i + j, n) , if i != 0 for all j belonging to [0,9]
            f(10*i + j, n) , if i == 0 for all j belonging to [1,9]
         }
        
        if (i<=n) print 
        else return;


*/