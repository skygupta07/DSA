#include <iostream>
#include<climits>
#include <vector>
using namespace std;

void print(vector <int> v){
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


// input count output
vector<int> countSort(vector<int> &input){
    int n = input.size();

    // find max. element(m) in input vector then create count vector of size+1
    // and initialie it with zero
    int m=0; // m=max
    for(int i=0; i<n; i++){
        m = max(m,input[i]);
    }

    vector<int> count(m+1 , 0); 

    // now fill the frequency of each distinct element in the count array
    for(int i=0; i<n; i++){
        count[input[i]]++;    // imp-> ith element of input array me jao and waha par 
                            // jo value hai uss value ko as a index treat karte hue 
                            // correspondingly count vector me fill kar do...
    }


    // now modify the count array to commulative array to get the actual position of element
    for (int i=1; i<=m; i++){
        count[i]+=count[i-1];
    }

    // declaring output array
    vector<int> output(n); // size equal to input vector, since only you are sorting 
                                    // the vector elements
    
    // ab ulta for loop lagao(to maintain stability of count sort) then fill the output vector by input count output relation

    for (int i=n-1; i>=0; i--){
        output[count[input[i]-1]] = input[i];
        count[input[i]]--;
    }

    return output;

}






int main(){
    int arr[] = {3,1,8,9,1,2,6,7,8,2,2,0,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);

    print(v);

    vector<int> ans = countSort(v); // principle of homogenity
    print(ans);
    

    

}