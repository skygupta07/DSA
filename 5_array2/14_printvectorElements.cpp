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

    v.at(2)= 14;   // 2nd index pe value update karke 14 kardo
    v.at(1)= 19;
    v[2] = 48;

    for (int i=0; i<v.size(); i++){
        cout<<v.at(i)<<" ";
    }
}