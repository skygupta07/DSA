#include <iostream>
#include <vector>
using namespace std;
void print(vector <int> v){
    for (int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

void reversePart(int i, int j, vector <int> &v){
    // ofcourse fn definition can take multiple parameters..
    // vector to pass karega hi tabhi to pta chalega ki kis vector ke elements print karne hai..
    while (i<=j){
        int t = v[i]; // good way (two pointer approach) to reverse is just swap ith and jth element using temp variable
        v[i]=v[j];
        v[j]= t;

        i++;
        j--;
    }
}

void rotate(vector<int> &v, int k){
    int n = v.size();
    k = k%n;
    reversePart(0,n-k-1, v);
    reversePart(n-k, n-1, v);
    reversePart(0,n-1,v);
}

int main(){
    int arr[] = {2,3,5,6,1,4,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> v(arr, arr+n);

    print(v);
    rotate(v,2);
    print(v);
    
}   

/*

2 3 5 6 1 4 8 9 , k = 2

reverse first n-k student, then reverse last k element , then reverse the whole array...
using reverse part of array....

*/