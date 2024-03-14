#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v(5);

    cout<<v[6]<<endl;
    cout<<v[1999]<<endl;

    v.push_back(62);

    for (int i=0; i<v.size(); i++){
        v[i] = 2;
    }
    cout<<endl;

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    

     for (int i=0; i<v.capacity(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}