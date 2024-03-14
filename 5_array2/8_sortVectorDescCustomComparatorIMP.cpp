#include <iostream>
using namespace std;

bool cmp(int a, int b){
    return a>b; // pehla waala element bada => descending order sorting
}

int main(){
    vector <int> v;   
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(3);
    cout<<endl;

    
    cout<<"vector in descendig order is: "; 
    sort(v.begin(), v.end(),cmp);       // sorting is bydefault always in ascending order by inbuilt fns
        // although you may sort as per your convenience using custom comparator..
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}