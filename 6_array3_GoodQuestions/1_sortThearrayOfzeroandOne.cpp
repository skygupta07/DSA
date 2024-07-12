#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    int countzero = 0;
    int countone =0;


    for (int i=0; i<v.size(); i++){
        if (v[i]==0) countzero++;
        else countone++;
    }
    
    for (int i=0; i<countzero; i++){
        cout<<"0"<<" ";
    }
    for (int i=0; i<countone; i++){
        cout<<"1"<<" ";
    }

}

/* 
two pass method-> 
pass1 -> count no. of zeroes and ones
pass2 -> iterate over array and fill first zero then 1

*/