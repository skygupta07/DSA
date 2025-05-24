#include <bits/stdc++.h>
using namespace std;



// accha to ye index wali kahani and take not take wali kahani subset wale question ki h ...
// mujhe yaad h mene ye kahani permutation mai bhi lagane ki kosis ki thi...aur ha waha bhi ye cheej lag jaegi...
void subsetSum(vector <int> &v, int n, vector<int> &ans, int sum, int idx){
    // base case-> if idx>n   => store the sum value in v and return;
    if (idx == n){
        ans.push_back(sum);
        return;
    }
    // left recursion->pick up-> sum add with current idx...
    subsetSum(v,n,ans,sum+v[idx],idx+1);

    // right recursion->not pick up -> sum remain as it is...
    subsetSum(v,n,ans,sum,idx+1);
}


int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector <int> v(arr,arr+n);
    vector <int> ans;

    int sum;
    int idx;

    subsetSum(v,n,ans,0,0);
    // arr,n,v,sum,idx
    for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
}

// here no need to pop_back the element from the sum...nahi to jab tak right recursion
// ki baat aaegi tab tak to pura empty ho chuka hoga....
// as soon as your first base case hit ..try there don't wait for more...