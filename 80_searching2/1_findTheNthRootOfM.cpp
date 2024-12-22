#include <bits/stdc++.h> // agar coding ninja par code directly nahi run kare 
// to issey include karna mat bhulna...
using namespace std;


int NthRoot(int n, int m) {
  int lo = 0;
  int hi = m; 

  while (lo <= hi){
    int mid = lo + (hi - lo)/2;

    if (pow(mid,n) == m) return mid;
    else if (pow(mid,n) < m){
      lo = mid + 1;
    }
    else hi = mid - 1;
  }

  return -1;

}