#include <bits/stdc++.h>
using namespace std;


int main(){

    string s;
    cout<<"enter the string: "<<endl;
    cin>>s;
    
    // precompute...very smart move -> pure keyboard ke characters ko hi map kar lega
    //  ...256 rupay mai to ....
    int hash[256] = {0};   
    
    for (int i=0; i<s.size(); i++){
        hash[s[i]]++;   // s[i] will be autocasted to integer...
    }

    int q;

    cout<<"enter number of queries: "<<endl;
    cin>>q;
    
    while (q--){
        char ch;
        cout<<"enter char to fetch its frequency: "<<endl;
        cin>>ch;

        cout<<hash[ch]<<endl;
    }

    return 0;
}

/*

enter the string: 
qz3w4xe5cdr6vft7bgy8nhujmopk123$%^&*()_@#$%^&*@#$%^&*


enter number of queries: 
1
enter char to fetch its frequency: 

$
3

*/