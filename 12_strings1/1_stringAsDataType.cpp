#include <bits/stdc++.h>
using namespace std;

int main(){
    string name = "akash";
    
    cout<<name.length()<<endl;
    cout<<name[5];  // null character prints nothing at all...

    char str[] = {'a', 'n', 't', 'm', 'a', 'n'};
    cout<<str[0]<<endl;

    int arr[] = {1,2,3};
    cout<<arr[0]<<endl;




    char myStr[] = {'m', 'a','n','\0','g','0'};
    cout<<myStr<<endl;

    string str3 = "rockstar games presents";
    int i=0; 
    while(str3[i] != '\0'){
        cout<<str3[i];
        i++;
    }
    cout<<endl;


/*
    string str3 = "rockstar games presents";
    int i = 0; 
    while (str3[i] != '\0') {
        cout << str3[i++];
    }
    cout << endl;

*/


// ----- space ya enter se cin aapka separate ho jaata hai....




}
