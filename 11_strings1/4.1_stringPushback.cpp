#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "kak";
    cout<<str<<endl;
    str.push_back('a'); // ji ha aap push_back ek single character hi kar sakte ho...
    cout<<str<<endl;


    string s = "firstString";
    string t = "secondString";

    cout<<s + t <<endl;
    cout<<t + s <<endl;

    reverse(s.begin() , s.end());
    cout<<s<<endl;

    // given a string engineering reverse the part of string from index 4 to 6 -> 
    // so we will pass here from 4 to 7...

    string branch = "mechanical engineering";
    reverse(branch.begin() + 4 , branch.begin() + 7);
    cout<<branch<<endl;
    
    
}