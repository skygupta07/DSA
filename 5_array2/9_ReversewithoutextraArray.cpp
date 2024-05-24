//wap to reverse the array without using any extra array.
#include <iostream>
#include <vector>
using namespace std;

void display(vector <int> v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector <int> v;   // agar yaha v() likh diya to wo function nahi ho jaega
    // aur tab aapko size or optional default value bhi set karni pad sakti hai isliye 
                        // simple v use karo jab aapko push_back hi karna ho to..
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(0);
    v.push_back(68);
    v.push_back(48);

    // int i=0;
    // int j = v.size()-1;
    // while (i<=j){
    //     int t = v[i];
    //     v[i]=v[j];
    //     v[j]=t;

    //     i++;
    //     j--;
    

    display(v);
    cout<<endl;

    //using inbuilt function to reverse the array
    reverse(v.begin(), v.end());  //inbuilt fn to reverse the array ->imp

    display(v);
    
}