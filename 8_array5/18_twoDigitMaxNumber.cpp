#include <bits/stdc++.h>
using namespace std;

void user_logic(int n, std::vector<int> &arr) {
    if(n==1){
        cout<<0;
        return;
    }

    int min1=INT_MAX, min2=INT_MAX;

    for(int i=0;i<n;i++){
        if(arr[i]>=10 && arr[i]<=99){
            if(arr[i]<min1){
                min2=min1;
                min1=arr[i];
            }
            if(arr[i]<min2 && arr[i]!=min1){
                min2=arr[i];
            }
        }
    }
    
    if(min1==INT_MAX || min2==INT_MAX){
        cout<<0;
        return;
    }
    // cout<<"min1 = " << min1 <<" , min2 = " <<min2 <<"\n";
    string st = to_string(min1) + to_string(min2);
    sort(st.begin(), st.end(), greater<>());
    cout<<stoi(st);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    user_logic(N, arr);
    return 0;
}