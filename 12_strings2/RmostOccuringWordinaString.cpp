#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
int main(){
    string str = "clouds are part of sky and sky surrounds us. ";
    stringstream ss(str);
    string temp;

    vector <string> v;  // yes u can make vector of string..
    while (ss>>temp){
        v.push_back(temp);
    }
    cout<<endl;

    sort (v.begin(), v.end());  // sort the vector and see its magic...
                                // now you don't have to compare with all just compare with the neighbours..
    int maxcount = 1;
    int count = 1;
    for (int i=1; i<v.size(); i++){
        if (v[i]==v[i-1]) count++;
        else count =1;
        maxcount = max(maxcount,count);


    }
    count =1;
    for (int i=1; i<v.size(); i++){
        if (v[i]==v[i-1]) count++;
        else count =1;
        if (count==maxcount){
            cout<<v[i]<<" "<<maxcount<<endl; 
        }

    }



}