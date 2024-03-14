#include <iostream>
#include <string>
using namespace std;
int main(){
    int x = -121;
    string s = to_string(x);

    for (int i=0; i<s.length(); i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    cout<<s<<endl;

    int i=0;
    string a = "applying";

    for (int i=0; i<a.length(); i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;

}