#include <iostream>
#include <string>
using namespace std;

int main(){
    int x = -121;
    string s = to_string(x);

    for (int i=0; i<s.length(); i++){
        cout<<s[i]<<" "; // - 1 2 1 
    }
    
    cout<<endl;
    cout<<s<<endl; // -121

    // iska to gajab hi output aa rha h..
    cout<<typeid(s).name()<<endl; // NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE

    int i = 0;
    string a = "applying";

    for (int i=0; i<a.length(); i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;

}