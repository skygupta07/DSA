#include <bits/stdc++.h>
using namespace std;


int main(){
    string s = "furniture";

    string sub = s.substr(0,3);
    cout<<sub<<endl;

    int myNum = 7777;
    string myStr = to_string(myNum);
    cout<<myStr.substr(0,1)<<endl;

}

// to_string(num)  -> it converts integer num to string...




/*
s.substr(idx, len)
    matlab kis index se lena hai...and kitni length ka lena hai...

*/