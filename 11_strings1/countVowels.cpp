#include <iostream>
using namespace std;
int main(){
    string s = "Ocean is so deep to understand.."; // matlab string bhi ek data type hai..
    int count = 0;
    for (int i=0; s[i]!='\0';i++){   // way to traverse over the whole string...
        if (s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o'|| s[i]=='u'|| s[i]=='A' || s[i]=='E' ||s[i]=='O'|| s[i]=='U'|| s[i]=='I'){
            count++;
            cout<<s[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"number of vowels is: "<<count<<endl;

    return 0;
}
