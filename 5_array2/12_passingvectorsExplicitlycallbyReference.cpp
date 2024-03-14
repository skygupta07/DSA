#include <iostream>
using namespace std;
void change(vector <int> &v){  // IMP-> just pass the address and now you are passing by call by reference
    v[0]=13;
}

int main(){
    vector <int> v;   // we don't need to mention the size of vector when we are pushing back
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(3);
    // cout<<v.capacity(); //4
    // cout<<v.size(); //4
    cout<<endl;

    //printing elements of vectors....
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // calling the change function and then printing the vectors element 
    change(v);

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    // since the vectors are passed by value so there is a change in the vectors element
}









