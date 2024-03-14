#include <iostream>
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
    
    int i=0;
    int j=v.size()-1;  // j pointer pointing at the last index initially
    while (i<j){
        if (v[i]==1 and v[j]==0){   // and === &&
            v[i]=0;
            v[j]=1;
            i++;
            j--;  
        }

        if (v[j]==1) j--;
            
        if (v[i]==0) i++;
        
    }

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";

    }
}

/*
two pointer or two variable
condition of loop is checked only when all the below line of code get executed...




*/