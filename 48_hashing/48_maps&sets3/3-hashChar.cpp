#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    cout<<"enter the string: "<<endl;
    cin>>s;

    // precompute...
    int hash[256] = {0};    // very smart move -> pure keyboard ke characters ko hi map kar lega...256 rupay mai to ....
    for (int i=0; i<s.size(); i++){
        hash[s[i]]++;   // s[i] will be autocasted to integer...
    }

    int q;
    cout<<"enter number of queries: "<<endl;
    cin>>q;
    while (q--){
        char c;
        cout<<"enter char to fetch its frequency: "<<endl;
        cin>>c;

        cout<<hash[c]<<endl;
    }
    return 0;
}