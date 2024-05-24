#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v(5);  // 5 size ka banaya sabko zero se initialise kiya
    cout<<v.size()<<endl;

    cout<<v[6]<<endl;   // out of index puccha to bhi zero hi answer diya..
    cout<<v[1999]<<endl;

    v.push_back(62);
    // push_back kiya to turant vector ne jitna uska size tha utna hi aage aur badha liya..
    // and ek element push bhi kar diya...

    cout<<v.size()<<endl;
    cout<<"vector capacity is:" <<v.capacity()<<endl;

    for (int i=0; i<v.size(); i++){
        v[i] = 2;
    }
    cout<<endl;
    cout<<"vector size is :"<<v.size()<<endl;

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    

    for (int i=0; i<v.capacity(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}