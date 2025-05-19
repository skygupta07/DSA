#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);

    cout<<v.size()<<endl; // 5
    cout<<v.capacity()<<endl; // 8
}