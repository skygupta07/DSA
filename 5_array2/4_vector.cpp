#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v;   // we don't need to mention the size of vector -> experience unlimited 
                        // size
    v.push_back(2); // ha bhai push_back(argument necessary) karna jaruri hai..
    v.push_back(5);
    v.push_back(10);
    v.push_back(3);
    cout<<v.capacity(); //4
    cout<<endl;

    cout<<v.size()<<endl;

    
    cout<<v[0]<<" ";
    cout<<v[1]<<" ";
    cout<<v[2]<<" ";
    cout<<v[3]<<" "<<endl;

    cout<<v.capacity(); //4
    return 0;

        
}