/*

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b){
    int m = a.size();
    int n = b.size();
    vector < int > ans;
    set <int> st;

    for (int i=0; i<m; i++){
        st.insert(a[i]);
    }
    for (int i=0; i<n; i++){
        st.insert(b[i]);
    }
    for (auto it: st){
        ans.push_back(it);
    }
    return ans;
}

// method 2 

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector < int > unionArr;
    int m = a.size();
    int n = b.size();
    int i = 0;
    int j = 0;

    while (i<m && j<n){   // both of the arrays have some elements left...
        if (a[i] <= b[j]){
            // repetition ki condition aur zero size 
            // if the size is zero just take it...
            if (unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++; // chahe include kiya ho ya na simply go to next idx

        }else{      // a[i] > b[j]
            // repetition ki condition aur zero size 
            if (unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++; // chahe include kiya ho ya na simply go to next idx
        }
    }

        while (j<n){
            if (unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;    
        }

        while (i<m){
            if (unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++; 
        }     
    
    return unionArr;    
}

*/ 



