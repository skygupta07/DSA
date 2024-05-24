#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b){
    return a >= b; // pehla waala element bada => descending order sorting
}

int main(){
    vector <int> v;   
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(3);
    v.push_back(2);
    v.push_back(9);
    v.push_back(-1);
    cout<<endl;
    cout<<"vector in descendig order is: "; 
    sort(v.begin(), v.end(),cmp);       // sorting is bydefault always in ascending order by inbuilt fns
        // although you may sort as per your convenience using custom comparator..(#CP)

    // more quick way is to pass the third paramater as greater <int> () into the sort 
    // function itself...

    // sort(v.begin() , v.end(), greater <int>());

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
}