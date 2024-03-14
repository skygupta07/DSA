//wap to reverse the part of array
#include <iostream>
using namespace std;
void display(vector <int> &v){  // print karane ke liye bhi aap reference se pass 
// kar do taaki copy na create ho ....it is mandatory to pass by reference in those cases
// where we need to do changes in the original array itself...
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

void reversepart(int i, int j, vector <int> &v){
    // ofcourse fn definition can take multiple parameters..
    // vector to pass karega hi tabhi to pta chalega ki kis vector ke elements print karne hai..
    while (i<=j){
        int t = v[i]; // good way to reverse is just swap ith and jth element using temp variable
        v[i]=v[j];
        v[j]= t;

        i++;
        j--;

    }
}


int main(){
    vector <int> v;   // agar yaha v() likh diya to wo function nahi ho jaega isliye 
                        // simple v use karo
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);  // vector me element bharne ka tarika..
    v.push_back(1);
    v.push_back(0);
    v.push_back(68);  // elements peeche peeche add hote jaate h pushback se
    v.push_back(48);

    int n = v.size();

    

    display(v);
    cout<<endl;
    reversepart(1,4,v); // to reverse from 1 index to 4th index..
    reversepart(0,n-1,v);  // to reverse the whole array..
    display(v);
    cout<<endl;
    
}

