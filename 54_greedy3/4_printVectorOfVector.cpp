#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <vector <int> > v;
    
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,6,7};
    int arr3[] = {8,9,10,11,12};

    vector <int> v1(arr1, arr1 + sizeof(arr1));
    vector <int> v2(arr2, arr2 + sizeof(arr2));
    vector <int> v3(arr3, arr3 + sizeof(arr3));   

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    cout<<v.size()<<endl;   // 3 since vector of vector khud teen vector kha ke baitha hai..

    for (int i=0; i<v.size(); i++){
        int n = v[i].size()/sizeof(int);    // jo bhi ith vector aaega uska size nikala...
                                // v is vector of vector and its each element is a vector itself..

        // int n = v[i].size()/sizeof(v[i][0]);   // size ko kisi bhi element se uss type(int) 
        for (int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    } 
}   