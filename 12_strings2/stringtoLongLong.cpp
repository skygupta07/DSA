#include <iostream>
using namespace std;
int main(){
    string s = "4557922343949484483";
    long long x = stoll(s);   // string to long long (a data type)
                              // leading zeroes are excluded.....  
    cout<<x<<endl;
}