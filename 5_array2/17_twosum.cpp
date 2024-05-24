#include <iostream>
#include <vector>
using namespace std;
int main(){
    int x;
    cout<<"enter target: ";
    cin>>x;
    vector <int> v;
    int n;
    cout<<"enter array size: ";
    cin>>n;

    cout<<"enter array elements: ";
    for (int i=0; i<n; i++){
        int el;
        cin>>el;
        v.push_back(el);  // method to take input when vector size is not known..
    }

    for (int i=0; i<v.size()-2; i++){ // imp
        for (int j=i+1; j<=v.size()-1;j++){
            if (v[i]+v[j]==x){
                cout<<"("<<i<<","<<j<<")"<<endl;  //un elements ka index return kar do jinka sum 7 aa rha ho 

            }
        }
    }

}



// cin === cout === c++ mai hot hai (3 for a reason)