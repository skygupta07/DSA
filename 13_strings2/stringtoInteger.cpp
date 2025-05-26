#include <iostream>
#include <string>
using namespace std;


int main(){
    
    string s= "12345";
    int n = stoi(s);  // string to integer function...takes string as input and gives integer as output..
    cout<<n+2<<endl;

    int x = 5432;
    string str = to_string(x);
    cout<<str<<endl;
    string t ="mathematics";
    cout <<str+t<<endl;

}