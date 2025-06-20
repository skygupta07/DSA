#include <bits/stdc++.h>
using namespace std;


void printString(vector <string> &v){

    // ye auto wali statement se one bottle down wala scenario ho jaata h...
    for (auto str: v){

        for (auto ch: str){
            cout<<ch;
        }

        cout<<"\n";
    }
    
}



int main(){

    vector <string> v;
    string s1 = "hello";
    string s2 = "world";
    string s3 = "funny";

    v.push_back(s1);
    v.push_back(s3);
    v.push_back(s2);
    
    printString(v);

}