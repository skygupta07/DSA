#include <iostream>
#include <vector>
using namespace std;


int main(){
    int year;
    cout<<"enter the year: "<<endl;
    cin>>year;


    if (year%400 == 0) cout<<"leap"<<endl;
    else if (year%100 ==0) cout<<"non-leap"<<endl;  // not div by 400 by div by 100....
    else if (year%4 == 0) cout<<"leap"<<endl;
    else cout<<"non-leap"<<endl; 

    /*
    leap year ka matlab wo year ya to 400 se divisible hoga....
    magar agar 400 se divisible nahi tha and 100 se divisible tha to...(like 1900)... then also not leap year...
    but agar 400 se nahi hai 100 se bhi divisible nahi hai but neeche aake wo kewal 4 se bhi divisible hai to wo
    leap year hai ....
            else  not a leap year....


    line se padhte huye aao...this is the reason why we say if else ka ladder...
    
    i.e. sequencing of statements matters a lot...
    
    */

}