#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cout<<"enter the string: ";

    getline(cin,s); // to take input a string (katha) i.e. aapka space separated strings bhi include hoga..
    cout<<s<<endl;
    sort (s.begin(), s.end());   // lexographical order is actually  ascii value order mai sort kar dega..
    // tabhi capital letters wale char pehle aa gaye and spaces bhi pehle hi aa gaye...
    cout<<s<<endl;

    char ch = ' ';
    cout<<(int)ch<<endl;    // will give ascii value of space

    char hash = '#';
    cout<<(int)hash<<endl;  //   // will give ascii value of hash
}


/*

enter the string: hey gpt how are you doing?
hey gpt how are you doing?
     ?adeegghhinoooprtuwyy
32
35

*/