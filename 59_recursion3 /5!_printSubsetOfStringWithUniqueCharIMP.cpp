#include <bits/stdc++.h>
using namespace std;


void printsubset(string ans, string original){

    if(original == ""){ // base case
        cout<<ans<<endl;
        return;
    }

    char ch = original[0];

    printsubset(ans+ch ,original.substr(1));
    
    // used substr so to omit the zeroth character...
    printsubset(ans, original.substr(1)); 
}


int main(){
    string str = "abcd";
    printsubset("",str);
}


// agar fn call void hai tab print kaise karaye....