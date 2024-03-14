#include <iostream>
#include <string>
#include<algorithm>

using namespace std;
int main(){
    string s;
    cout<<"enter the string: ";

    getline(cin,s); // to take input a string i.e. aapka space bhi include hoga..
    cout<<s<<endl;
    sort (s.begin(), s.end());   // lexographical order is ascii value order....
    
    cout<<s<<endl;
}