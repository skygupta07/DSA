#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v(2);
    v.push_back(45);
    cout<<v.size()<<" "<<v.capacity()<<endl;
}

// to reduce the time complexity vector increase its size and capacity.....