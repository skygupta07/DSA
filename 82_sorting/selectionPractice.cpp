#include <bits/stdc++.h>
using namespace std;


void print(vector <int> &v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
     cout<<endl;
}

void selectionSort(vector<int> &v){
    int n = v.size();
    
    // bahar wala loop second last tak
    for (int i=0; i < n-1; i++){
        int minidx = -1;  // since we want ki har pass ke baad values update hoti rahe
                        // isliye pehle waale loop ke andar likha
        int min = INT_MAX;

        // andar wala i se n tak chalega...
        for(int j=i; j<n; j++){
            
            if (v[j]<min){
                min = v[j];
                minidx = j;
            }
           
            swap(v[i],v[minidx]);
        }
    }
}

// pure arr me iterate karke min. element nikalke first element ke saath swap karna hai

int main(){
    int arr[]={4,51,3,9,1,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    print(v);
   
    selectionSort(v);

    print(v);

}


