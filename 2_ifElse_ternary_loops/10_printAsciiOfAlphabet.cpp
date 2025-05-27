#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;


int main(){
    int i = 0;

    while(i<26){
        cout<<char(i + 'a')<<"-->"<<i+'a'<<endl;
        i++;
    }

    cout<<"uppper case alphabets: "<<endl;

    i = 0;
    while(i<26){
        cout<<char(i + 'A')<<"-->"<<i+'A'<<endl;
        i++;
    }


    char ch2 = 'h';
    cout<<ch2-'a'<<endl;


    char ch = 'a';
    int num = ch - 'a';

    cout<<num<<endl;
}