#include <iostream>
using namespace std;

void  change2dvector(vector < vector <int> > &v){ 
    // to see the changes in original vector => pass it by reference...
    v[1][0]=89;
}

int main(){
    vector <int> v1;
    vector <int> v2;
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);

    vector < vector <int> > v;

    v.push_back(v1);
    v.push_back(v2);

    /*
    v = {{1,2,3,4,5},
         {6,7,8,9}

        }
    
    */

    // cout<<v[0][0];

    cout<<v[1][0]<<endl;

    change2dvector(v);

    cout<<v[1][0]<<endl;
    cout<<v[1][4]<<endl;    // uninitialised indexes are filled with zero in case of vectors...

}

/*
to create a 2d vector => simply push a vector into a vector....
*/