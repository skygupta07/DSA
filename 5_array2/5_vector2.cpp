#include <iostream>
using namespace std;
int main(){
    vector <int> v;   // we don't need to mention the size of vector
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(3);
    cout<<v.capacity(); //4
    cout<<endl;

    //printing elements of vectors using for loop

    for (int i=0; i<v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}