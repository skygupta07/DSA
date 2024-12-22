#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printString(vector<string>& v){
        int n = v.size();
        int i = 0;
        
        int l = v[i].length();
        for (int j=0; j<l; j++){
            cout<<v[j];
        }
        cout<<" ";
        i++;        
}

int main(){
    vector <string> v;
    string s1 = "hello";
    string s2 = " world";
    string s3 = "fun";

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    printString(v);
}