#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n = 7;
    vector <int> v(n , -1);

    cout<<v[10]<<endl;  // prints garabage value

    v.push_back(19);

    cout<<v.size()<<" "<<v.capacity();
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

/*
it means when you declare a vector with size only then it is initialised the whole 
vector with garbage value zero...and....

yes you can push_back the element in vector even exceeding its size in that case the 
vector increase its capacity to twice of initial capacity to hold it...




*/