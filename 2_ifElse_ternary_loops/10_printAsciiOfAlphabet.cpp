#include <iostream>
#include <vector>
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
}