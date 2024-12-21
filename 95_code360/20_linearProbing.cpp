#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<int> linearProbing(vector<int> keys){
    int n = keys.size();
    vector <int> visited(n, -1);
    
    vector <int> ans(n, -1);

    for (int i=0; i<n; i++){
        int correctIndex = keys[i]%n;

        while (ans[correctIndex] != -1){
            correctIndex = (correctIndex + 1)%n;
        }

        ans[correctIndex] = keys[i];
    }

    return ans;
    // if already there is someone then try next index until you get empty place ...
}
