#include <iostream>
using namespace std;
#include <string>
int main(){
    // char str[]="Akash Gupta";
    // for (int i=0; str[i]!='\0'; i++){
    //     if (str[i]=='a'|| str[i]=='A'){
    //         continue;
    //     }
    //     else cout<<str[i];
    // }
    // cout<<endl;

    string str="Akash Gupta";
    cout<<str.substr(1)<<endl; //starting from 1st index,,aage ke elements print kardo..

    cout<<str.substr(4)<<endl;

    
     // either use character array as string wala concept 
                                // or directly use the string..
    for (int i=0; i<str.length(); i++){
        if (str[i]=='a'|| str[i]=='A'){ // a single char in single quote only
            continue;
        }
        else cout<<str[i];
    }
    cout<<endl;

}