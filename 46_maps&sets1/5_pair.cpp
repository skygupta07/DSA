#include <bits/stdc++.h>
using namespace std;


int main(){
    vector <pair <string,int> > v;

    pair <string,int> p1;   
    pair <string,int> p2; 

    // p.first aur p.second karke hi aap values fetch insert delete kar sakte ho..

    p1.first = "amazon";
    p1.second = 60;

    p2.first = "flipkart";
    p2.second = 55;

    v.push_back(p1);
    v.push_back(p2);

    for (auto p : v){
        string platform = p.first;
        int price = p.second;

        cout<<"available at "<<platform<<" for "<<price<<" Rupees"<<endl;
    }

    return 0;
}