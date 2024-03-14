#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int main(){
    string s;
    cout<<"enter the string: ";
    getline(cin , s);
    string temp;
    stringstream ss(s);  // ss yaha stringstream ka naam ho gya..
    while (ss>>temp)
        cout<<temp<<endl;
}