#include <bits/stdc++.h>
using namespace std;


int main(){
    int a;
    cout<<"enter first term: "<<endl;
    cin>>a;

    int r;
    cout<<"enter common difference: "<<endl;
    cin>>r;

    int n;
    cout<<"enter the term which you want : ";
    cin>>n;


    int nthTerm = a*pow(r,n-1);   
    cout<<"nth term is given by: "<<nthTerm<<endl;

    cout<<"all gp terms upto n are: "<<endl;


    for (int i=1; i<=n; i++){
        cout<<a<<" ";
        a *= r;
    }

}